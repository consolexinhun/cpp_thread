#include <iostream>
#include <thread>

using std::cout;
using std::endl;
using std::thread;

void thread_func(const int& i) {
    cout << "func begin" << endl;

    cout << "i = " << i << endl;
    const_cast<int&>(i) = i * 2;
    for (int i = 0; i < 10000; i += 1) {
    }
    cout << "i = " << i << endl;

    cout << "func end" << endl;
}

int main() {
    cout << "main begin" << endl;

    int i1 = 10;
    cout << i1 << endl;

    thread t1(thread_func, i1);
    t1.join();
    cout << i1 << endl;

    cout << " -------------------------------\n";

    int i2 = 10;
    cout << i2 << endl;
    thread t2(thread_func, std::ref(i2));
    t2.join();

    cout << i2 << endl;

    cout << "main end" << endl;
    return 0;
}
