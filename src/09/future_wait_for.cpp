#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <future>
#include <utility>
#include <chrono>
#include <cstdio>

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
    std::future<bool> fut = std::async(is_prime, 700020007);
    cout << "checking\n";

    // fut.wait();
    std::chrono::milliseconds span(100);
    while (fut.wait_for(span) == std::future_status::timeout) {
        cout << '.';
    }

    bool ret = fut.get();
    printf("\n700020007 %s\n", ret ? "is prime" : "is not prime");
    return 0;
}
