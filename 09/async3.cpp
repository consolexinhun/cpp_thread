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
    cout << "async_func begin " << std::this_thread::get_id() << endl;

    cout << "async_func end\n"; 
    return true;
}

int main() {
    cout << "main begin " << std::this_thread::get_id() <<endl;
    std::future<bool> fut = std::async(std::launch::deferred, async_func);
    if (fut.wait_for(std::chrono::milliseconds(10)) == std::future_status::deferred) {
        cout << "---\n";
        fut.wait(); 
    }
    cout << "main end\n";
    return 0;
}
