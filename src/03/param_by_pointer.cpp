#include <iostream>
#include <thread>

using std::cout;
using std::endl;
using std::thread;

void thread_func(const char* ptr) {
    cout << "func begin" << ptr[0] << endl;
    cout << "ptr addr : " << static_cast<const void*>(ptr) << endl;
    for (int i = 0; i < 10000; i += 1) {
    }

    cout << "func end" << endl;
}

int main() {
    cout << "main begin" << endl;

    const char* ptr1 = "1";
    const char* ptr2 = new char('2');

    thread t1(thread_func, ptr1);
    t1.join();
    // t1.detach() // 实参形参指向🤝资源，引发未定义行为

    thread t2(thread_func, ptr2);
    t2.join();
    // t2.detach() // 实参形参指向🤝资源，引发未定义行为

    cout << "ptr1 addr : " << static_cast<const void*>(ptr1) << endl;
    cout << "ptr2 addr : " << static_cast<const void*>(ptr2) << endl;
    delete ptr2;

    cout << "main end" << endl;
    return 0;
}
