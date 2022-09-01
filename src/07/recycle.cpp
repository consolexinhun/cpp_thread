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
    struct Recycle {
        ~Recycle() {
            if (instance != nullptr) {
                delete instance;
                instance = nullptr;
            }
        }
    };

public:
    static Singleton* getInstance();

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

private:
    Singleton() = default;
    ~Singleton();

    static Singleton* instance;
    static mutex mtx;
};

Singleton* Singleton::instance = nullptr;

mutex Singleton::mtx;

Singleton* Singleton::getInstance() {
    if (instance == nullptr) {
        std::lock_guard<mutex> lck(mtx);
        if (instance == nullptr) {
            instance = new Singleton();
        }
    }
    return instance;
}

Singleton::~Singleton() {
    // 单例类的资源清理
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
