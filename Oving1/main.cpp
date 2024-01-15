#include "std_lib_facilities.h"

int MaxOfTwo(int a, int b) {
    if (a > b) {
        cout << "A > B\n";
        return a;
    } else {
        cout << "B >= A\n";
        return b;
    }
}

int Fibonacci(int n) {
    int a = 0;
    int b = 1;
    cout << "Fibonacci numbers: \n";
    for (int i = 0; i <= n; i++) {
        cout << i << " " << b;
        int temp = b;
        b += a;
        a = temp;
        cout << "\n------------------------\n";
    }
    return b;
}

int squareNumberSum(int n) {
    int totalSum = 0;
    for (int i = 0; i <= n; i++) {
        totalSum += pow(i, 2);
        cout << pow(i, 2) << "\n";
    }
    cout << totalSum << "\n";
    return totalSum;
}

void triangleNumbersBelow(int n) {
    int acc = 1;
    int num = 2;
    cout << "Triangle numbers below" << n << ":\n";
    while (acc < n) {
        cout << acc << "\n";
        acc += num;
        num += 1;
    }
    cout << "\n";
}

bool isPrime(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void primeNumberSearch(int n) {
    for (int number = 2; number < n; number++) {
        if (isPrime(number)) {
            cout << number << " is a prime\n";
        }
    }
}

void nameAndAge() {
    string name;
    int age;
    cout << "Skriv inn et navn: ";
    cin >> name;
    cout << "Skriv inn alderen til " << name << ": ";
    cin >> age;
    cout << name << " er " << age << " år gammel\n";
}

int main() {
    // cout << "Oppg. a\n";
    // cout << MaxOfTwo(5, 6) << "\n";
    // cout << "Oppg. c\n";
    // cout << Fibonacci(5) << "\n";
    // cout << "Oppg. d\n";
    // cout << squareNumberSum(5) << "\n";
    // cout << "Oppg. e\n";
    // triangleNumbersBelow(5);
    // cout << "Oppg. f\n";
    // cout << isPrime(5) << "\n";
    // cout << "Oppg. g\n";
    // primeNumberSearch(10);
    // cout << "Oppg. h\n";
    nameAndAge();
    int age = 10;
    // printf("Jeg er %d år gammel", age);

    switch (age) {
        case 10:
            cout << "Hei";
            break;
        case 11:
            cout << "Hello";
        default:
            break;
    }
    return 0;
}