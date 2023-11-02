#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

// Что выведено на экран? (прокомментируйте код)

int main() {
    vector<int> arr(20, 0);
    int i = 23;
    for (auto &x : arr) {
        x = i++;
        i *= 33;
    }

    auto isEven = [](int i) {
        return (i % 2 == 0);
    };

    auto any = [isEven](vector<int> &a) {
        return any_of(a.begin(), a.end(), isEven);
    };

    auto all = [isEven](vector<int> &a) {
        return all_of(a.begin(), a.end(), isEven);
    };

    cout << any(arr) << " " << all(arr);

    return 0;
}