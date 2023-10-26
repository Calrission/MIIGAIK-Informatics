#include "iostream"
#include <cmath>

using namespace std;

// Извлечение квадратного корня из числа

int main(){
    double num;
    cin >> num;
    if (num >= 0){
        cout << sqrt(num);
    }else{
        cerr << "Error 1";
        return 1;
    }
    return 0;
}
