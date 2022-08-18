#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <future>
#include <utility>
#include <exception>

using std::cout;
using std::endl;
using std::mutex;
using std::thread;
using std::vector;

int get_int() {
    std::cin.exceptions(std::ios::failbit);
    int x;
    std::cin >> x;
    return x;
}

int main() {
    std::future<int> fut = std::async(get_int);

    cout << "please enter an integer :";
    try {
        int x = fut.get();
        cout << "you entered: " << x << "\n";
    } catch (std::exception &) {
        cout << "[exception caught]\n";
    }
    return 0;
}
