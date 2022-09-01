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

#define N 100000000

void add() {
    for (int i = 0; i < N; i++) {
        g_num++;
    }
}

void sub() {
    for (int i = 0; i < N; i++) {
        g_num--;
    }
}

/* 
非原子操作，无锁
结果居然正确，挺奇怪的
 */

int main() {
    clock_t begin = clock();

    thread t1(add);
    thread t2(sub);
    t1.join();
    t2.join();

    clock_t end = clock();

    cout << "time consuming : " << end-begin << endl;
    cout << "calculated value: " << g_num << endl;
    return 0;
}
