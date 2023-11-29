/*
Создать иерархию классов, отражающую различные этапы жизни кошки:
от маленького котенка до взрослой кошки.

Реализовать классы на языке программирования C++.
Все классы должны наследоваться от базового класса Cat (кошка).

Класс Cat:
    Атрибуты:
        breed (порода) - строка, определяющая породу кошки.
        color (цвет) - строка, обозначающая цвет шерсти кошки.
    Методы:
        getBreed() - метод для получения породы кошки.
        getColor() - метод для получения цвета шерсти кошки.
        sleep() - виртуальный метод, выводящий сообщение о спящей кошке
        (переопределяется в потомках).

Класс Potat, наследуется от Cat:
    Уникальные атрибуты:
        name (кличка) - строка, содержащая кличку кошки.
        age (возраст) - целое число, определяющее возраст котенка.
        curiosity (любознательность) - булево значение (по умолчанию true).
    Методы:
        play() - выводит сообщение об игре кошки.
        Переопределяет метод sleep(), выводя сообщение о спящем котенке

Класс LongTeen, наследуется от Potat:
    Методы:
        walk() - выводит сообщение о прогулке подростка.
        Переопределяет метод sleep(), выводя сообщение о спящей зрелой кошке.

Класс BigLong, наследуется от LongTeen:
    Методы:
        Переопределяется метод sleep(), выводя сообщение о спящей большой длинной кошке.

Класс BigPotat, наследуется от BigLong.
    Методы:
        Переопределяет метод sleep(), выводя сообщение о спящей большой картошке.
*/


#include "iostream"

using namespace std;

class Cat {
    protected:
        string breed;
        string color;

    public:
        Cat(string& breed, string& color){
            this->breed = breed;
            this->color = color;
        }

        string& getBreed() {
            return breed;
        }

        string& getColor() {
            return color;
        }

        virtual void sleep() {
            cout << "Кошка спит" << endl;
        }
};

class Potat: public Cat{
    protected:
        string name;
        int age;
        bool curiosity;

    public:
        void play(){
            cout << "Котенок по кличке " << name << " играет" << endl;
        }

        void sleep() override {
            cout << "Котенок по кличке " << name << " спит" << endl;
        }

        bool getCuriosity() {
            return curiosity;
        }

        int getAge(){
            return age;
        }

        string& getName(){
            return name;
        }


    Potat(string& breed, string& color, string& name, int age, bool curiosity = true):
        Cat(breed, color), name(name), age(age), curiosity(curiosity){}
};

class LongTeen: public Potat {
    public:
        LongTeen(string& breed, string& color, string& name, int age): Potat(breed, color, name, age) {}

        void walk(){
            cout << "Кот подросток по кличке " << name << " на прогулке" << endl;
        }

        void sleep() override {
            cout << "Зрелая кошка по кличке " << name << " спит" << endl;
        }
};

class BigLong: public LongTeen{
    public:
        BigLong(string& breed, string& color, string& name, int age): LongTeen(breed, color, name, age) {}

        void sleep() override {
            cout << "Большая длинная кошка по кличке " << name << " спит" << endl;
        }
};

class BigPotat: public BigLong{
    public:
        BigPotat(string& breed, string& color, string& name, int age): BigLong(breed, color, name, age) {}

        void sleep() override {
            cout << "Большая картошка по кличке" << name << " спит" << endl;
        }
};

int main() {
    Potat myPotat = Potat((string &) "Мейн-кун", (string &) "Черный",(string &) "Барсик", 1);
    LongTeen myLongTeen = LongTeen((string &) "Сиамская", (string &) "Коричневый",(string &) "Том", 5);
    BigLong myBigLong = BigLong((string &) "Британская", (string &)"Серый", (string &) "Мурзик", 8);
    BigPotat myBigPotat = BigPotat((string &) "Персидская", (string &)"Белый", (string &) "Васька", 10);

    myPotat.play();
    myLongTeen.walk();
    myBigLong.sleep();
    myBigPotat.sleep();

    cout << myPotat.getBreed() << " " << myPotat.getColor() << " " << myPotat.getCuriosity() << endl;
    cout << myLongTeen.getBreed() << " " << myLongTeen.getColor() << " " << myLongTeen.getCuriosity() << endl;
    cout << myBigLong.getBreed() << " " << myBigLong.getColor() << " " << myBigLong.getCuriosity() << endl;
    cout << myBigPotat.getBreed() << " " << myBigPotat.getColor() << " " << myBigPotat.getCuriosity() << endl;

    return 0;
}
