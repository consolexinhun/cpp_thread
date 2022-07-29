#include <iostream>
#include <thread>

using std::cout;
using std::endl;
using std::thread;
class Base {
public:
    explicit Base(int i = 0) : m_i(i) { cout << "Base(int i)" << m_i << endl; }

    Base(const Base& obj) : m_i(obj.m_i) { cout << "Base(const Base& obj)" << m_i << endl; }
    ~Base() { cout << "~Base()" << m_i << endl; }

public:
    int m_i;
};

void thread_func(const Base& obj) {
    cout << "func begin" << endl;

    cout << "i = " << obj.m_i << endl;
    for (int i = 0; i < 10000; i += 1) {
    }

    cout << "func end" << endl;
}

int main() {
    cout << "main begin" << endl;

    Base obj1{1};
    Base obj2{2};

    thread t1(thread_func, obj1);
    t1.join();
    // t1.detach() // 实参被拷贝，子线程可以正常运行

    cout << " -------------------------------\n";

    thread t2(thread_func, std::ref(obj2));
    t2.join();
    // t2.detach() // 实参被引用，主线程结束释放 obj2，子线程引用已经释放的资源，行为未定义

    cout << "main end" << endl;
    return 0;
}
