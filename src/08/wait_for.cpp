#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <condition_variable>
#include <chrono>

using std::cout;
using std::endl;
using std::mutex;
using std::thread;
using std::vector;

std::condition_variable cv;

int value;

void read_value() {
    std::cin >> value;
    cv.notify_one();
}


int main() {
    cout << "please enter an integer :" <<endl;

    thread th(read_value);

    mutex mtx;
    std::unique_lock<mutex> lck(mtx);
    while (cv.wait_for(lck, std::chrono::seconds(1)) == std::cv_status::timeout) {
        cout << "." <<endl;
    }
    cout << "you enter:" << value << endl;
    th.join();
    return 0;
}
