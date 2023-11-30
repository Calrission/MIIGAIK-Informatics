/*
Полиморфизм:
- Создайте класс "Фрукт" с методом "получить_витамины".
- Создайте подклассы: "Яблоко" и "Апельсин", переопределите метод "получить_витамины" для каждого из них.
- Создайте массив объектов разных фруктов и вызовите для каждого метод "получить_витамины".
*/

#include "iostream"

using namespace std;

class Fruit{
public:
    virtual string get_vitamins(){
        return "Fruit vitamins";
    }
};

class Apple: public Fruit {
public:
    string get_vitamins() override {
        return "Apple vitamins";
    }
};

class Orange: public Fruit {
public:
    string get_vitamins() override {
        return "Orange vitamins";
    }
};

int main(){
    Apple apple = Apple();
    Orange orange = Orange();

    Fruit* data[2] = {&orange, &apple};

    for (auto& i: data){
        cout << i->get_vitamins() << endl;
    }
}