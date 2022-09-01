#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <condition_variable>

using std::cout;
using std::endl;
using std::mutex;
using std::thread;
using std::vector;

mutex mtx;
std::condition_variable cv;

bool ready = false;

void print_id(int id) {
    std::unique_lock<mutex> lck(mtx);

    while (!ready) {
        cv.wait(lck);
    }

    cout << "thread " << id << endl;
}

void go() {
    std::unique_lock<mutex> lck(mtx);
    ready = true;
    cv.notify_all();
}

int main() {
    thread threads[10];
    for (int i = 0; i < 10; i++) {
        threads[i] = thread(print_id, i);
    }

    cout << "10 thread ready to race..." << endl;
    go();

    for (thread& th : threads) {
        th.join();
    }
    return 0;
}
