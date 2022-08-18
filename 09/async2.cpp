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

bool async_func() {
    printf("async_func begin\n");

    printf("async_func end\n");
    return true;
}

int main() {
    printf("main begin\n");
    std::future<bool> fut = std::async(async_func);
    printf("main end\n");
    return 0;
}
