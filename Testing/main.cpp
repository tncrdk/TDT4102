#include "AnimationWindow.h"
#include "std_lib_facilities.h"

struct Base {
  public:
    int n;
};

struct Class : public Base {
  public:
    int a;
    int b;
    int c;

    Class(int i) {}
    Class(int i, int j) try : Class(i) {
    } catch (bad_alloc) {
    }
};

int main() {
    AnimationWindow win{100, 100, 300, 200, "P"};
    win.wait_for_close();
    return 0;
}
