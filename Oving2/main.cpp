#include "AnimationWindow.h"
#include "interest.h"
#include "loops.h"
#include "menu.h"
#include "quad.h"
#include "std_lib_facilities.h"
#include <complex>

void menu_func() {
    while (true) {
        cout << "\nVelg en funksjon:\n"
             << "0) Avslutt\n"
             << "1) InputInteger [menu]\n"
             << "2) Odde tall [menu]\n"
             << "3) printSum [loops]\n"
             << "4) readTilZero [loops]\n"
             << "5) convertNokEur [loops]\n"
             << "6) multTable [loops]\n"
             << "7) quad [quad]\n"
             << "8) interest [interest]\n"
             << "Angi valg: ";
        int index = 0;
        cin >> index;

        switch (index) {
            case 0:
                return;
                break;
            case 1: {
                int a = menu::inputInteger();
                cout << "Du skrev: " << a << "\n";
                break;
            }
            case 2: {
                for (int i = 0; i <= 15; ++i) {
                    bool res = menu::isOdd(i);
                    cout << i << " er et " << (res ? "oddetall" : "partall")
                         << "\n";
                }
                break;
            }
            case 3: {
                int count = 0;
                cout << "Hvor mange tall skal du summere?: ";
                cin >> count;
                loops::printSum(count);
                break;
            }
            case 4: {
                loops::readTilZero();
                break;
            }
            case 5: {
                loops::convertNokEur();
                break;
            }
            case 6: {
                loops::multTable();
                break;
            }
            case 7: {
                quad::solveQuadratic();
                break;
            }
            case 8: {
                std::vector<int> balance_vector =
                    interest::getBalance(5000, 30, 5);
                interest::printBalance(balance_vector);
                break;
            }
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void pythgoras() {
    int WIDTH = 500;
    int HEIGHT = 500;
    AnimationWindow win{200, 200, WIDTH, HEIGHT, "Pythagoras"};

    // Triangle
    Point t1{WIDTH * 2 / 5, HEIGHT * 2 / 5};
    Point t2{WIDTH * 3 / 5, HEIGHT * 3 / 5};
    Point t3{WIDTH * 2 / 5, HEIGHT * 3 / 5};

    int A = abs(t2.x - t3.x);
    int B = abs(t3.y - t1.y);

    // Square 1
    Point s13{t3.x - B, t3.y};
    Point s14{t1.x - B, t1.y};

    // Square 2
    Point s23{t2.x, t2.y + A};
    Point s24{t3.x, t3.y + A};

    // Square 3
    Point s33{t1.x + B, t1.y - A};
    Point s34{t2.x + B, t2.y - A};

    win.draw_triangle(t1, t2, t3, Color::red);
    win.draw_quad(t1, t3, s13, s14, Color::green);
    win.draw_quad(t3, t2, s23, s24, Color::yellow);
    win.draw_quad(t2, t1, s33, s34, Color::blue);
    win.wait_for_close();
}

int main() {
    pythgoras();
    // menu_func();
    // FEILMELDING: Du kan ikke printe en vector direkte: ingen overload for
    // '<<' som tar inn en vektor
    // DEBUGGING: i<=v.size() fører til at i blir for stor i siste iterasjon
    return 0;
}
