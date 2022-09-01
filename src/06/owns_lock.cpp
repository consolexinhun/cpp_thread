#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

using std::cout;
using std::endl;
using std::mutex;
using std::thread;
using std::vector;

std::mutex mtx;

void print() {
    std::unique_lock<std::mutex> lck(mtx, std::try_to_lock);

    if (lck.owns_lock()) {
        cout << "*";
    } else {
        cout << "x";
    }

    cout << endl;
}

int main() {
    vector<thread> threads;
    for (int i = 0; i < 10; i++) {
        threads.emplace_back(print);
    }

    for (auto& x : threads) {
        x.join();
    }
    return 0;
}
