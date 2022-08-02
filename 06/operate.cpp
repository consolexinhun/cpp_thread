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

void print_fifty() {
    std::unique_lock<mutex> lck;  // 默认构造函数
    lck = std::unique_lock<mutex>(mtx);
    for (int i = 0; i < 50; i++) {
        if (lck.owns_lock()) {
            cout<< '*';
        } else {
            cout<< '#';
        }
    }
    cout << endl;
}

int main() {
    thread th(print_fifty);
    th.join();

    return 0;
}
