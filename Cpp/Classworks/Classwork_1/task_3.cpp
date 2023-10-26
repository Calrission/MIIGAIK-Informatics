#include "iostream"

using namespace std;

// Решение уравнения ах+b = 0

int main(){
    double a, b;
    cin >> a >> b;
    if (a == 0) {
        cerr << "Error 1" << endl;
        return 1;
    };
    cout << "x = " << -b/a << endl;
    return 0;
}