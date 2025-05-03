// Basic shared_ptr.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

void basicUsage();
void container();
void passByValue(shared_ptr<Resource> ptr);
void passByRef(shared_ptr<Resource>& ptr);

int main()
{
    //basicUsage();
    //container();
    auto ptr = make_shared<Resource>(1);
    cout << " > ref count " << ptr.use_count() << endl;
    passByValue(ptr);
    passByRef(ptr);
    
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

void basicUsage()
{
    shared_ptr<Resource> ptr;

    {
        ptr = make_shared<Resource>(1);
        cout << " > ref count " << ptr.use_count() << endl;

        {
            cout << " > enter scope AB" << endl;

            shared_ptr<Resource> ptr2 = ptr;
            cout << " > ref count " << ptr.use_count() << endl;
            cout << " > ref count " << ptr2.use_count() << endl;

            {
                cout << " > enter scope ABC" << endl;

                shared_ptr<Resource> ptr3 = ptr;
                cout << " > ref count " << ptr.use_count() << endl;
                cout << " > ref count " << ptr2.use_count() << endl;
                cout << " > ref count " << ptr3.use_count() << endl;
            }

            cout << " > OUT OF SCOPE ABC" << endl;
            cout << " > ref count " << ptr.use_count() << endl;
            cout << " > ref count " << ptr2.use_count() << endl;
        }

        cout << " > OUT OF SCOPE AB" << endl;
        cout << " > ref count " << ptr.use_count() << endl;
    }

    cout << " > OUT OF SCOPE A" << endl;
    cout << " > ref count " << ptr.use_count() << endl;
}

void container()
{
    vector<shared_ptr<Resource>> arr;
    shared_ptr<Resource> ptr1 = make_shared<Resource>(1);
    shared_ptr<Resource> ptr2 = make_shared<Resource>(2);

    cout << " > ref count " << ptr1.use_count() << " " << ptr2.use_count() << endl;

    arr.push_back(ptr1);
    cout << " > ref count " << ptr1.use_count() << " " << ptr2.use_count() << endl;

    arr.push_back(ptr2);
    arr.push_back(ptr1);
    cout << " > ref count " << ptr1.use_count() << " " << ptr2.use_count() << endl;

    arr.clear();
    cout << " > ref count " << ptr1.use_count() << " " << ptr2.use_count() << endl;

    cout << " > EXITING..." << endl;
}

void passByValue(shared_ptr<Resource> ptr)
{
    cout << " > (Copy) ref count " << ptr.use_count() << endl;
    if (ptr)
        ptr->use();
    
    cout << " > leaving copy scope..." << endl;
}

void passByRef(shared_ptr<Resource>& ptr)
{
    cout << " > (Ref) ref count " << ptr.use_count() << endl;
    if (ptr)
        ptr->use();
    
    cout << " > leaving ref scope..." << endl;
}
