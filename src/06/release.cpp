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
int count = 0;

void print_count_and_unlock(mutex* p_mtx) {
    cout<< "count:" << count << endl;
    p_mtx->unlock();
}

void task() {
    std::unique_lock<mutex>lck(mtx);
    ++count;
    print_count_and_unlock(lck.release());
}

int main() {
    // thread threads[10];
    vector<thread> threads;
    for (int i = 0; i < 10; i++) {
        threads.emplace_back(task);
    }

    for (thread& th : threads) {
        th.join();
    }

    return 0;
}
