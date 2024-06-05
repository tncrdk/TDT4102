#include "std_lib_facilities.h"
#include <memory>

enum class PaintColour { Red, Yellow, Blue };

void printNumber(PaintColour colour) {
    cout << static_cast<int>(colour) << endl;
}

int main() {
    PaintColour paint = 1;
    printNumber(paint);
    return 0;
}
