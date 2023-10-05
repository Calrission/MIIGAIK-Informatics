#include <iostream>

using namespace std;

// Программа, которая определяет, является ли число четным или нечетным

int main() {
    int num;
    cin >> num;
    if (num % 2 == 0)
        cout << "Четное число" << endl;
    else
        cout << "Нечетное число" << endl;
    return 0;
}
