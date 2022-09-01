#include <iostream>
#include <thread>
#include <vector>
#include <queue>
#include <mutex>

using std::cout;
using std::endl;
using std::queue;
using std::thread;
using std::vector;

class Handle {
public:
    void inMsgQueue() {
        for (int i = 0; i < 100000; i++) {
            m_mutex.lock();

            cout << "inMsgQueue():" << i << endl;
            m_queue.push(i);

            m_mutex.unlock();
        }
    }

    void outMsgQueue() {
        for (int i = 0; i < 100000; i += 1) {
            std::lock_guard<std::mutex> lck(m_mutex);
            if (!m_queue.empty()) {
                cout << "outMsgQueue():" << m_queue.front() << endl;
                m_queue.pop();
            }
        }
    }

private:
    queue<int> m_queue;
    std::mutex m_mutex;
};

int main() {
    cout << "main begin" << endl;

    Handle handle;

    thread t1(&Handle::inMsgQueue, std::ref(handle));
    thread t2(&Handle::outMsgQueue, std::ref(handle));

    t2.join();
    t1.join();

    cout << "main end" << endl;
    return 0;
}
