#include <iostream>

using namespace std;

int main() {
    unsigned int num;
    cin >> num;
    for (int i = 1; i <= 10; i++){
        cout << i << "*" << num << "=" << num * i << endl;
    }
    return 0;
}
