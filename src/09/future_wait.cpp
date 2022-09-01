#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <future>
#include <utility>
#include <chrono>

using std::cout;
using std::endl;
using std::mutex;
using std::thread;
using std::vector;

bool is_prime(int x) {
    for (int i = 2; i < x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    std::future<bool> fut = std::async(is_prime, 194232491);
    cout << "checking\n";

    fut.wait();

    cout << "\n194232491 ";
    if (fut.get()) {
        cout << "is prime\n";
    } else {
        cout << "is not prime\n";
    }
    return 0;
}
