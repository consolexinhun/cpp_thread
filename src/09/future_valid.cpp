#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <future>
#include <utility>

using std::cout;
using std::endl;
using std::mutex;
using std::thread;
using std::vector;

int get_value() {
    return 10;
}

int main() {
    std::future<int> foo, bar;
    foo = std::async(get_value);
    bar = std::move(foo);

    if (foo.valid()) {
        cout << "foo value:" << foo.get() << "\n";
    } else {
        cout << "foo is not valid\n";
    }

    if (bar.valid()) {
        cout << "bar value: " << bar.get() << "\n";
    } else {
        cout << "bar is not valid\n";
    }
    return 0;
}
