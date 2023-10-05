#include <iostream>
using namespace std;
int main() {
    // Блок инициализации
    int x = 2147483647;
    int y = 1;
    int result = x + y; // Т.к. диапозон Int от -2 147 483 648 до 2 147 483 647, то x+y = 2 147 483 648, что не допустимо.
    // Поэтому result "переходит" в начало диапазона Int, т.е. -2 147 483 648

    // Блок вывода
    cout << "x: " << x << endl; // Выводим x
    cout << "y: " << y << endl; // Выводим y
    cout << "Result of x + y: " << result << endl; // Выводим result
}