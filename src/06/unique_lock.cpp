#include <iostream>
#include <thread>
#include <mutex>

using std::cout;
using std::endl;
using std::mutex;
using std::thread;

mutex mtx;

void print(int n, char c) {
    std::unique_lock<mutex> lck(mtx);

    for (int i = 0; i < n; i++) {
        cout << c;
    }

    cout << endl;
}

int main() {
    thread t1(print, 50, '*');
    thread t2(print, 50, '$');

    t1.join();
    t2.join();
    return 0;
}
