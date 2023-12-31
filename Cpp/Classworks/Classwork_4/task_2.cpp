#include <iostream>
#include <functional>

using namespace std;

// Что выведено на экран? (прокомментируйте код)

int main() {
    int N = 0;                                              // Иницализация N равного 0
    function<int(int)> fact = [&fact](int N) {
        // Объявление lambda функции fact c явным типом function<int(int)>
        // которая захватывает локальные объекты в области видимости по значению. Т.е. использование локальных переменных и параметров, но не изменяя их.
        // при вызове принимает целочисленный N
        if (N < 0) {
            // Если N меньше 0, то возвращаем 0 (по определению факториала)
            return 0;
        } else if (N == 0) {
            // Если N равно 0, то возвращаем 1 (по определению факториала)
            return 1;
        } else {
            // Иначе, вычисляем по определению нахождение факториала N числа: текущее N умножаем на факториал N-1 (факториал предыдущего числа)
            return N * fact(N - 1);
        }
    };

    // Принимает от пользователя число N
    cout << "Input number: ";
    cin >> N;

    // Выводим факториал числа N используя lambda функцию fact
    cout << "for number " << N << " = " << fact(N) << endl;

    return 0;
}