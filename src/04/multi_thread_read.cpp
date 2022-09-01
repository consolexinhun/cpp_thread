#include <iostream>
#include <thread>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::thread;

vector<int> g{1, 2, 3};

void thread_fun() {
    cout << "thread fun id: " << std::this_thread::get_id() << " | " << g[0] << " " << g[1] << " " << g[2] << endl;
}

int main() {
    cout << "main begin" << endl;

    thread t1(thread_fun);
    thread t2(thread_fun);

    t1.join();
    t2.join();

    cout << "main end" << endl;
    return 0;
}
