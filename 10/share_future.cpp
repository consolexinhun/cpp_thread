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

int mythread() {
    cout << "mythread begin" << endl;

    std::this_thread::sleep_for(std::chrono::microseconds(5000));

    cout << "mythread end" << endl;
    return 5;
}

int main() {
    cout << "main begin" << endl;

    std::future<int> result = std::async(std::launch::async, mythread);

    std::shared_future<int> result_shared = result.share();
    /* 等价于  */
    // std::shared_future<int> result_shared = std::async(std::launch::async, mythread);

    if (result_shared.valid()) {
        cout << result_shared.get() << endl;
        cout << result_shared.get() << endl;
        cout << result_shared.get() << endl;
    }

    cout << "main end" << endl;
    return 0;
}
