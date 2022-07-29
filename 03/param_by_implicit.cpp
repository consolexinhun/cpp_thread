#include <iostream>
#include <thread>

using namespace std;

class Base {
public:
    Base(int i = 0): m_i(i) {
        cout<< "Base(int i)" << this_thread::get_id() <<endl;
    }

    Base(const Base &obj): m_i(obj.m_i) {
        cout<< "Base(const Base& obj)" << this_thread::get_id() <<endl;
    }
    ~Base() {
        cout<< "~Base()" << this_thread::get_id() <<endl;
    }

public:
    int m_i;
};

void thread_func(const Base &) {

}

int main() {
    cout<< "main begin" <<endl;

    cout<< "main thread id" << this_thread::get_id() <<endl;

    int i = 10;
    thread t1(thread_func, i);
    t1.join();
    // t1.detach() // 隐式转换发生在子线程中，无法保证主线程初始资源有效

    cout<< " -------------------------------\n";

    thread t2(thread_func, Base(i)); // 主动生成临时对象
    t2.join();
    //t2.detach() // 

    cout<<"main end"<<endl;
    return 0;
}

// 因此需要避免发生隐式类型转换，而是生成临时对象，在子线程中引用接收