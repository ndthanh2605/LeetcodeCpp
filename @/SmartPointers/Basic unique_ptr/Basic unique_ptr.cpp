// Basic unique_ptr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Resource {
    int mId = 0;
public:
    Resource() {
        cout << "Resource acquired" << endl;
    }

    Resource(int id) : mId(id) {
        cout << "Resource " << mId << " acquired" << endl;
    }

    ~Resource() {
        cout << "Resource " << mId << " destroyed" << endl;
    }

    void use() {
        cout << "Resource " << mId << " used" << endl;
    }
};

unique_ptr<Resource> createResource(int id) {
    cout << " > create resource " << id << endl;
    return make_unique<Resource>(id);
}

// take resouce by 'move'
void takeResource(unique_ptr<Resource> ptr) {
    if (!ptr) {
        cout << " > null ptr" << endl;
        return;
    }
    cout << " > take ownership of ptr" << endl;
    ptr->use();
    cout << " > done using ptr" << endl;
}

int main()
{
    // reset & release (for manual deletion)
    {
        unique_ptr<Resource> ptr = make_unique<Resource>(10);

        cout << " > reset to new resouce" << endl;
        ptr.reset(new Resource(11));

        cout << " > release (detach) ownership" << endl;
        Resource* src = ptr.release();

        if (!ptr) {
            cout << " > ptr is now NULL (after release)" << endl;
        }
        if (src) {
            delete src; src = nullptr;
        }

        ptr = make_unique<Resource>(12);
        ptr.reset();
        if (!ptr) {
            cout << " > ptr is now NULL (after reset)" << endl;
        }
    }
    cout << "--------" << endl << endl;

    // containers
    {
        vector<unique_ptr<Resource>> resources;
        resources.push_back(createResource(2));
        resources.push_back(createResource(3));
        resources.push_back(createResource(4));

        cout << " > using resources" << endl;
        for (const auto& ptr : resources) {
            ptr->use();
        }
        cout << " > clearing...." << endl;
        resources.clear();
        cout << " > done clearing!" << endl;
    }
    cout << "--------" << endl << endl;

    // take ownership
    {
        unique_ptr<Resource> ptr = createResource(1);
        takeResource(std::move(ptr));

        if (!ptr) {
            cout << " > ptr is now null" << endl;
        }
        else {
            cout << " > ptr is NOT null" << endl;
        }
    }
    cout << "--------" << endl << endl;

    {
        cout << " > enter scope" << endl;
        unique_ptr<Resource> ptr(new Resource);
    }
    cout << " > out of scope" << endl;


    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
