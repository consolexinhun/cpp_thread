#include <iostream>
#include <future>
#include <thread>

using namespace std;

bool async_func () {

    cout << "async_func begin " << std::this_thread::get_id() << endl;

    cout << "async_func end" << endl;

    return true;
}

int main ()
{
  cout << "main begin " << std::this_thread::get_id() << endl;

  std::future<bool> fut = std::async (launch::async, async_func);   // 创建新线程并调用线程入口函数

  cout << fut.get() << endl;

  cout << "main end" << endl;

  return 0;
}