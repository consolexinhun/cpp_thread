#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <condition_variable>
#include <chrono>
#include <atomic>

using std::cout;
using std::endl;
using std::mutex;
using std::thread;
using std::vector;

// using namespace std::chrono_literals;
using std::chrono_literals::operator"" ms;
std::condition_variable cv;
mutex cv_m;
std::atomic<int> i{0};

void waits(int idx) {
    std::unique_lock<mutex> lk(cv_m);
    auto now = std::chrono::system_clock::now();

    if (cv.wait_until(lk, now + idx * 100ms, []() { return i == 1; })) {
        std::cerr << "thread " << idx << "finished waiting, i = " << i << endl;
    } else {
        std::cerr << "thread " << idx << "time out, i=" << i << endl;
    }
}
void signals() {
    std::this_thread::sleep_for(120ms);
    std::cerr << "notifying.. " << endl;

    cv.notify_all();
    std::this_thread::sleep_for(100ms);
    i = 1;
    std::cerr << "notify again..." << endl;
    cv.notify_all();
}
int main() {
    std::thread t1(waits, 1), t2(waits, 2), t3(waits, 4), t4(signals);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    return 0;
}
