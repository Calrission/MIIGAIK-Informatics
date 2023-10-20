#include <iostream>

using namespace std;

int main() {
    int year;
    cin >> year;
    if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0){
        cout << "Leap year" << endl;
        return 0;
    }
    cout << "Not leap year" << endl;
}