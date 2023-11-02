#include <iostream>
#include <functional>

using namespace std;

// Что выведено на экран? (прокомментируйте код)

int main() {
    int N = 0;
    std::function<int(int)> fact = [&fact](int N) {
        if (N < 0) {
            return 0;
        } else if (N == 0) {
            return 1;
        } else {
            return N * fact(N - 1);
        }
    };

    cout << "Input number: ";
    cin >> N;

    cout << "for number " << N << " = " << fact(N) << endl;

    return 0;
}