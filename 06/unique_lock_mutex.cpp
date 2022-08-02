#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

using std::cout;
using std::endl;
using std::mutex;
using std::thread;
using std::vector;

class MyMutex: public mutex {
private:
    int _id;

public:
    explicit MyMutex(int id): _id(id) {}
    int id() { return _id; }
};

MyMutex mtx(101);

void print_ids(int id) {
    std::unique_lock<MyMutex> lck(mtx);
    cout << "thread #" << id << " locked mutex " << lck.mutex()->id() << endl;
}


int main() {
    // thread threads[10];
    vector<thread> threads;
    for (int i = 0; i < 10; i++) {
        threads.emplace_back(thread(print_ids, i+1));
    }

    for (thread& th : threads) {
        th.join();
    }

    return 0;
}
