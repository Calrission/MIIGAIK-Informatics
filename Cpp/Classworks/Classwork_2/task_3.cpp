#include <iostream>
using namespace std;
int main() {
    // Блок инициализации

    //  0000 1001
    int x1 = 9;

    // 0000 0101
    int y1 = 5;

    // Побитое сложение (OR)
    // При сложении получиться 0000 1101, что в десятичной системе - 13
    int result = x1 | y1;

    cout << "x1: " << x1 << endl; // Выводим x
    cout << "y1: " << y1 << endl; // Выводим y
    cout << "Result of x1 | y1: " << result << endl;    // Выводим result
}