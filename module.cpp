#include <cmath>
#include <ctime>

// Функция для вычисления синуса N раз и измерения времени выполнения
double calculateSinusNTimes(
    int N
) {
    clock_t start_time = clock();

    // Вычисление синуса N раз
    for (int i = 0; i < N; ++i) {
        double result = std::sin(0.5);
    }

    clock_t end_time = clock();
    double time_taken = double(end_time - start_time) / CLOCKS_PER_SEC;

    return time_taken;
}

int test(){
    return 100;
}