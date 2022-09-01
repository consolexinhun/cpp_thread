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

int cargo = 0;

bool shipment_available() {
    return cargo != 0;
}

void consume(int n) {
    for (int i = 0; i < n; i++) {
        std::unique_lock<mutex> lck(mtx);
        cv.wait(lck, shipment_available);

        cout << cargo << endl;
        cargo = 0;
    }
}

int main() {
    thread consumer_thread(consume, 10);
    for (int i = 0; i < 10; i += 1) {
        while (shipment_available()) {
            std::this_thread::yield();
        }
        std::unique_lock<mutex> lck(mtx);
        cargo = i+1;
        cv.notify_one();
    }
    consumer_thread.join();
    return 0;
}
