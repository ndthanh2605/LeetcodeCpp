// Overload.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <thread>
#include <chrono>

int main() {
    // Continuously spawn detached threads that sleep for a long time.
    // Before any can finish, you'll exhaust system/thread‑library resources.
    for (int i = 0; ; ++i) {
        std::thread([](int id) {
            // Keep the thread alive a while so they accumulate
            std::this_thread::sleep_for(std::chrono::hours(1));
            }, i).detach();
        std::cout << "Spawned thread #" << i << "\n";
    }
    return 0;
}