// Deadlock.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::mutex mtx1, mtx2;

void task1() {
    // Lock mtx1 first, then (after a pause) try to lock mtx2
    std::lock_guard<std::mutex> lock1(mtx1);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::lock_guard<std::mutex> lock2(mtx2);
    std::cout << "Task1 acquired both locks\n";
}

void task2() {
    // Lock mtx2 first, then (after a pause) try to lock mtx1
    std::lock_guard<std::mutex> lock2(mtx2);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::lock_guard<std::mutex> lock1(mtx1);
    std::cout << "Task2 acquired both locks\n";
}

int main() {
    std::thread t1(task1);
    std::thread t2(task2);

    // both threads will block forever trying to acquire the other's mutex
    t1.join();
    t2.join();
    return 0;
}