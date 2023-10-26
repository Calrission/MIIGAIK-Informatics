#include <iostream>
#include <cstdio>

using namespace std;
int main() {
    int a = 17;
    bool f = a<18 && a>5; // 17<18=True и 17>5=True => True и True = True
    if (f){
        // Всегда f=True => Всегда падает в блок if, а не в блок else
        cout << (a % 10 < 5 ? a / 10 * 2 : a / 5 + 3);  // Тернарный оператор - быстрая запись if
        // Можно переписать как
        // if (a % 10 < 5) {
        //  cout << a / 10 * 2;
        // }else{
        //  cout << a / 5 + 3;
        // }
        // Т.к. a % 10 = 7 => 7<5=False
        // то выводится результат вырожения 17/5+3, т.е "6"
    }else{
        // Блок else никогда не вызовится
        cout << a << endl;
    }
    getchar();
}