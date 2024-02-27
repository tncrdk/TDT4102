#include "std_lib_facilities.h"
#include <memory>
// #include <unistd.h>

struct Point {
    int x = 0;
    int y = 0;
};

class A {
  public:
    A(int a, Point b) : a{a}, b{b} {
        cout << "A (b): " << &(this->b) << "\n";
        cout << "A (a): " << &(this->a) << "\n";
        cout << "A (this): " << this << "\n";
    }

    void print() {
        cout << "a: " << a << "\nb.x: " << b.x << ", b.y: " << b.y
             << "\n---------------------------\n";
    }

    virtual void foo() = 0;

  protected:
    int a;
    Point b;
};

class B : public A {
  public:
    B(int a, Point b, int c, int d) : A{a, b}, c(c), d(d) {
        cout << "B (b): " << &(this->b) << "\n";
        cout << "B (a): " << &(this->a) << "\n";
        cout << "B (this): " << this << "\n";
    }
    B(int a, Point b) : B(a, b, 3, 4) {}

    void print() {
        cout << "a: " << a << "\nb.x: " << b.x << ", b.y: " << b.y
             << "\nc: " << c << "\nd: " << d << "\n-----------------------\n";
    }

    void foo() { cout << "Foo\n"; }

  protected:
    int c, d;
};

class C : public A {
  public:
    C(int a, Point b, int c, int d) : A{a, b}, c(c), d(d) {
        cout << "C (b): " << &(this->b) << "\n";
        cout << "C (a): " << &(this->a) << "\n";
        cout << "C (this): " << this << "\n";
    }
    C(int a, Point b) : C(a, b, 3, 4) {}

    void print() {
        cout << "a: " << a << "\nb.x: " << b.x << ", b.y: " << b.y
             << "\nc: " << c << "\nd: " << d << "\n-----------------------\n";
    }
    void foo() { cout << "Foo\n"; }

  protected:
    int c, d;
};

int main() {
    B obj1(1, Point{4, 4});
    obj1.print();

    B obj2(1, Point{4, 4}, 3, 4);
    obj2.print();

    C obj3(1, Point{4, 4});
    obj3.print();

    return 0;
}
