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
  thread t1([](int id, int numIterations) {
            for (int i = 0; i < numIterations; ++i) {
              cout << "Counter " << id << " has value ";
              cout << i << endl;
            }
          }, 1, 5);

  t1.join();
  return 0;
}
