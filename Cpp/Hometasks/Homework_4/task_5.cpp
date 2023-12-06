/*
Иерархия классов:
- Создайте класс "Транспортное Средство" с атрибутами:
 скорость и тип (например, автомобиль, велосипед).
- Создайте подклассы для разных типов транспортных средств и
 добавьте им свои атрибуты и методы.
*/

#include <utility>

#include "iostream"

using namespace std;

class Vehicle{
public:
    int speed;
    string type;

    Vehicle(int speed, const string& type) {
        this->type = type;
        this->speed = speed;
    }

    virtual void move() const {
        cout << "Vehicle move" << endl;
    }

    void bep_bep() const {
        cout << "Sound of vehicle " << type << endl;
    }
};

class Car: public Vehicle{
public:
    string brand;

    Car(int speed, string& brand) : Vehicle(speed, "car") {
        this->brand = brand;
    }

    void move() const override {
        cout << brand << " move" << endl;
    }
};

class Plane: public Vehicle{
public:
    string company;
    bool is_fly;

    Plane(int speed, const string &company, bool isFly) : Vehicle(speed, "Plain"){
        this->company = company;
        this->is_fly = isFly;
    }

    void move() const override {
        if (is_fly){
            cout << "Plain is fly" << endl;
        }else{
            cout << "Plain is moving" << endl;
        }
    }
};