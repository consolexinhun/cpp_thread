#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <future>
#include <utility>
#include <chrono>
#include <cstdio>

using std::cout;
using std::endl;
using std::mutex;
using std::thread;
using std::vector;

void print_int(std::future<int>& fut) {
    cout << "print_int begin" << endl;;
    int x = fut.get();
    cout << "value:" << x << endl;;
    cout << "print_int end" << endl;;
}

int main() {
    std::promise<int> prom;
    std::future<int> fut = prom.get_future();
    thread th1(print_int, std::ref(fut));
    cout << "set_value begin" << endl;;

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    prom.set_value(10);

    cout << "set_value end" << endl;
    th1.join();
    return 0;
}
