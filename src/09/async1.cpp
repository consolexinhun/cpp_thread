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
    cout << "checking\n";
    for (int i = 2; i < x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    std::future<bool> fut = std::async(is_prime, 313222313);
    printf("Checking whether 313222313 is prime.\n");

    bool ret = fut.get();
    printf("313222313 %s\n", ret ? "is prime" : "is not prime");
    return 0;
}
