#include <iostream>

// Дополните код программы. Организуйте ввод массива с клавиатуры. См. Слайд 70-71

int sumOfEvenNumbers(ЧТО ЖЕ СЮДА ВПИСАТЬ?) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        if (arr[i] % 2 == 0) {
            sum += arr[i];
        }
    }
    return sum;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int length = sizeof(arr) / sizeof(arr[0]);

    int result = sumOfEvenNumbers(arr, length);

    std::cout << "Sum of even numbers: " << result << std::endl;

    return 0;
}