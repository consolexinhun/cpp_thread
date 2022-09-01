#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

using std::cout;
using std::endl;
using std::mutex;
using std::thread;
using std::vector;

mutex mtx;

void print_star() {
    std::unique_lock<mutex> lck(mtx, std::defer_lock);
    // defer_lock 初始化时没有锁

    if (lck.try_lock()) {
        cout << "*";
    } else {
        cout << "x";
    }
    cout << endl;
}

int main() {
    // thread threads[10];
    vector<thread> threads;
    for (int i = 0; i < 10; i++) {
        threads.emplace_back(print_star);
    }

    for (thread& th : threads) {
        th.join();
    }

    return 0;
}
