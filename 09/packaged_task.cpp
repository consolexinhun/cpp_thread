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

int countdown(int from, int to) {
    for (int i = from; i != to; --i) {
        cout << i << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    cout << "lift off!\n";
    return from-to;
}

int main() {
    std::packaged_task<int(int, int)> task(countdown);
    std::future<int> ret = task.get_future();

    thread th(std::move(task), 10, 0);
    int value = ret.get();
    cout << "the countdown lasted for " << value << "seconds\n";
    th.join();
    return 0;
}
