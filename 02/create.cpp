#include <iostream>
#include <thread>

using namespace std;

void thread_func() {
    cout<< "thread func begin" <<endl;
    for(int i = 0; i < 10000; i++) {}
    cout<< "thread func end" << endl;
}

auto thread_lambda = []{
    cout<< "thread_lambda begin"<<endl;
    for(int i = 0; i < 10000; i++) {}
    cout<< "thread_lambda end"<<endl;
};


class thread_class {
public:
    thread_class() {
        cout<< "thread_class" << this <<endl;
    }

    thread_class(const thread_class&) {
        cout<< "thread_class(const thread_class&)" <<this<<endl;
    }

    ~thread_class() {
        cout<< "~thread_class()" <<this<<endl;
    }

    void operator() () {
        cout<< "thread class begin" <<endl;
        for(int i = 0; i < 10000; i++) {}
        cout<< "thread class end" <<endl;
    }
};

class base {
public:
    void func() {
        cout<< "base:func() begin" <<endl;
        for(int i = 0; i < 10000; i++) {}
        cout<< "base:func() end" <<endl;
    }
};

int main() {
    cout<< "main begin" <<endl;

    cout<< "function:" <<endl;

    thread thread1(thread_func);
    if(thread1.joinable()) {
        thread1.join();
    }

    cout<< "lambda:" <<endl;
    thread thread2(thread_lambda);
    if(thread2.joinable()) {
        thread2.join();
    }

    cout<< "class:" <<endl;

    thread_class c;
    thread thread3(c);
    if(thread3.joinable()) {
        thread3.join();
    }

    cout<< "class function:"<<endl;
    base b;
    thread thread4(&base::func, &b);
    if(thread4.joinable()) {
        thread4.join();
    }

    cout<< "main end" <<endl;
}