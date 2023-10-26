#include <iostream>

using namespace std;

int main() {
    int num;
    cin >> num;
    unsigned long long sum = 1;
    for (int i=1; i <= num; i++){
        sum *= i;
    }
    cout << num << "!" << " = " << sum << endl;
}