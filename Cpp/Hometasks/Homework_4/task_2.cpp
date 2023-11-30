/*
Инкапсуляция:
- Создайте класс "БанковскийСчет" с атрибутами: баланс и номер счета.
- Организуйте доступ к атрибуту баланс через методы "пополнить" и "снять".
*/
#include <utility>

#include "iostream"

using namespace std;

class BankAccount {
private:
    double balance;
    string number;

public:
    BankAccount(double balance, string number) : balance(balance), number(std::move(number)) {}

    void addMoney(double money){
        balance += money;
    }

    void removeMoney(double money){
        balance -= money;
    }
};