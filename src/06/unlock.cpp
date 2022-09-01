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

void print_thread_id(int id) {
    std::unique_lock<mutex> lck(mtx, std::defer_lock);
    // defer_lock 初始化时没有锁

    lck.lock();
    cout << "thread id: " << id << endl;
    lck.unlock();
}

int main() {
    thread threads[10];
    for (int i = 0; i < 10; i++) {
        threads[i] = thread(print_thread_id, i + 1);
    }
    for (thread& th : threads) {
        th.join();
    }

    return 0;
}
