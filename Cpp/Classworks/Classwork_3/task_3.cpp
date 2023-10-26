#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    int arr[n];
    cout << "Введите элементы массива:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Элемент " << i << ": ";
        cin >> arr[i];
    }

    int k, l, sum = 0;
    cout << "Введите k, затем l: " << endl;
    cin >> k >> l;

    cout << "Среднее арифметическое чисел между k и l (включительно): ";
    for (int i = k; i <= l; i++) {
        sum += arr[i];
    }
    cout << ((float) sum) / ((float) (l - k + 1));
    return 0;
}