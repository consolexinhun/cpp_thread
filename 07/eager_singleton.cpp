#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

using std::cout;
using std::endl;
using std::mutex;
using std::thread;
using std::vector;

class Singleton {
public:
    static Singleton* getInstance();

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

private:
    Singleton() = default;

    static Singleton* instance;
};

Singleton* Singleton::instance = new Singleton();

Singleton* Singleton::getInstance() {
    return instance;
}


void thread_func() {
    Singleton* p = Singleton::getInstance();
}


int main() {
    thread th1(thread_func);
    thread th2(thread_func);

    th1.join();
    th2.join();

    return 0;
}
