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

  std::future<bool> fut = std::async (launch::deferred, async_func);

  if (fut.wait_for(std::chrono::microseconds(0)) == std::future_status::deferred)   // 检查是否是 launch::deferred 
  {
    cout << "std::future_status::deferred" << endl;
  }

  cout << fut.get() << endl;    // 入口函数被调用

  cout << "main end" << endl;

  return 0;
}