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
std::condition_variable produce, consume;

int cargo = 0;

void consumer() {
    std::unique_lock<mutex> lck(mtx);
    while (cargo == 0) {
        consume.wait(lck);
    }

    cout << cargo << endl;
    cargo = 0;
    produce.notify_one();
}

void producer(int id) {
    std::unique_lock<mutex> lck(mtx);
    while (cargo != 0) {
        produce.wait(lck);
    }
    cargo = id;

    consume.notify_one();
}

int main() {
    thread consumers[10], producers[10];
    for (int i = 0; i < 10; i++) {
        consumers[i] = thread(consumer);
        producers[i] = thread(producer, i+1);
    }

    for (int i = 0; i < 10; i++) {
        producers[i].join();
        consumers[i].join();
    }
    return 0;
}
