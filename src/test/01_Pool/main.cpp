//
// Created by Admin on 26/02/2025.
//

#include <MyBL/Pool.h>

#include <iostream>

using namespace std;
using namespace My;

class C {
 public:
  C(size_t n) : n{n} {}

  ~C() { cout << this << ": " << n << endl; }

 private:
  size_t n;
};

int main() {
  Pool<C> pool;
  for (size_t i = 0; i < 100; i++)
    pool.Request(i);
  cout << "move" << endl;
  Pool<C> d(move(pool));
  cout << "pool Clear" << endl;
  pool.Clear();
  cout << "d Clear" << endl;
  d.Clear();
  return 0;
}
