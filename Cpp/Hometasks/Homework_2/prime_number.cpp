#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int num;
    cin >> num;

    for (int i = 2; i <= sqrt(num)+1; i++){
        if (num % i == 0){
            cout << "Is not prime num" << endl;
            return 0;
        }
    }

    cout << "Is prime num" << endl;
}