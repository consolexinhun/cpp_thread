#include <iostream>
#include <thread>

using namespace std;

void thread_func() {
    cout<< "thread func begin" <<endl;
    for(int i = 0; i < 10000; i++) {}
    cout<< "thread func end" << endl;
}

int main() {
    cout<< "main begin" <<endl;

    thread mythread(thread_func);
    if(mythread.joinable()) {
        cout<< "mythread is joinable() : " << mythread.joinable() <<endl;
        mythread.join();
    }

    cout<< "mythread is joinable() : " << mythread.joinable() <<endl;
    cout<< "main end" <<endl;
}