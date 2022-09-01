#include <thread>
#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::thread;
using std::vector;

void thread_fun(int i) { cout << "thread fun id: " << std::this_thread::get_id() << " " << i << endl; }

int main() {
    cout << "main begin" << endl;

    vector<thread> threads;
    for (int i = 0; i < 10; i++) {
        threads.emplace_back(thread(thread_fun, i));
    }

    for (int i = 0; i < 10; i++) {
        threads.at(i).join();
    }

    cout << "main end" << endl;
    return 0;
}
