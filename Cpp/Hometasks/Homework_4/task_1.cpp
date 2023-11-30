/*
Создание класса и объекта:
- Создайте класс "Собака" с атрибутами: имя, возраст.
- Создайте объекты этого класса для нескольких собак.
- Выведите информацию о каждой собаке на экран.
*/

#include <utility>

#include "iostream"

using namespace std;

class Dog{
public:
    string name;
    int age;

    Dog(string  name, int age) : name(std::move(name)), age(age) {}

    void show() const {
        cout << name << " " << age << endl;
    }
};

int main(){
    Dog dog1 = Dog("Rex", 3);
    dog1.show();

    Dog dog2 = Dog("Laila", 5);
    dog2.show();

    Dog dog3 = Dog("Maxim", 10);
    dog3.show();
    return 1;
}