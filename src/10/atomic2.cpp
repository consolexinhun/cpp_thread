#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <future>
#include <utility>
#include <exception>
#include <cstdio>
#include <chrono>

using std::cout;
using std::endl;
using std::mutex;
using std::thread;
using std::vector;

int g_num = 0;
mutex g_mutex;

void add() {
    for (uint32_t i = 0; i < 10000000; i++) {
        g_mutex.lock();
        g_num++;
        g_mutex.unlock();
    }
}

/* 
非原子操作，有锁
速度特别慢
 */

int main() {
    clock_t begin = clock();

    thread t1(add);
    thread t2(add);
    t1.join();
    t2.join();

    clock_t end = clock();

    cout << "time consuming : " << end-begin << endl;
    cout << "calculated value: " << g_num << endl;
    return 0;
}
