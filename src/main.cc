#include <iostream>
#include <vector>
#include <thread>
#include <functional>
#include <atomic>

using namespace std;

class Counter {
  public:
    Counter(int id, int numIterations)
      : id_(id), numIterations_(numIterations)
    {}

    void operator()() const {
      for (int i = 0; i < numIterations_; ++i) {
        cout << "Counter " << id_ << " has value ";
        cout << i << endl;
      }
    }

  private:
    int id_;
    int numIterations_;
};

int main() {
  cout.sync_with_stdio(true);

  thread t1{Counter(1, 20)};

  Counter c(2, 12);
  thread t2(c);

  thread t3(Counter(3, 10));

  t1.join();
  t2.join();
  t3.join();

  return 0;
}
