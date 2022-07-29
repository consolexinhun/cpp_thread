#include <iostream>
#include <thread>

using namespace std;

std::thread::id main_thread_id = std::this_thread::get_id();

void is_main_thread() {
    cout<< std::this_thread::get_id() <<endl;

    if(main_thread_id == std::this_thread::get_id()) {
        cout<< "this is main thread" <<endl;;
    }
    else {
        cout<< "this is not main thread" <<endl;
    }
}

int main() {
    
    is_main_thread();

    thread th(is_main_thread);

    th.join();

    return 0;
}