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

std::atomic<bool> g_isEnd {false};
void mythread() {
    cout << "mythread begin" << endl;

    std::chrono::microseconds dura(1000);

    while (!g_isEnd) {
        cout << "mythread is : " << std::this_thread::get_id() << endl;
        std::this_thread::sleep_for(dura);
    }

    cout << "mythread end" << endl;
}


/* 
非原子操作，无锁
结果居然正确，挺奇怪的
 */

int main() {
    cout << "main begin" << endl;
    thread th(mythread);

    std::this_thread::sleep_for(std::chrono::microseconds(5000));

    g_isEnd = true;

    th.join();
    
    cout << "main end" << endl;
    return 0;
}
