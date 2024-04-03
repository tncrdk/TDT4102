#include "std_lib_facilities.h"
#include <memory>

class A {
  private:
    int a;

  public:
    A(int a) : a{a} {}
    void print() { cout << a << "\n"; }
    ~A() { cout << "DESTROY!!!!!\n"; }
};

int main() {
    A a(3);
    shared_ptr<A> A_ptr = shared_ptr<A>(&a);
    A_ptr->print();
    return 0;
}
