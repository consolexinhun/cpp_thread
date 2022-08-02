#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

using std::cout;
using std::endl;
using std::mutex;
using std::thread;
using std::vector;

// template<class Fn, class... Args>
// void call_once(std::once_flag& flag, Fn&& fn, Args&&... args);

class Singleton {
public:
    static Singleton* getInstance();

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

private:
    Singleton() = default;

    static void createInstance();

    static Singleton* instance;
    static std::once_flag onceFlag;
};

Singleton* Singleton::instance = nullptr;
std::once_flag Singleton::onceFlag;

void Singleton::createInstance() {
    instance = new Singleton();
}

Singleton* Singleton::getInstance() {
    std::call_once(onceFlag, createInstance);
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
