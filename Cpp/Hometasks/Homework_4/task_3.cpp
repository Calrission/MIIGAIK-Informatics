/*
Наследование:
- Создайте базовый класс "Фигура" с методом для расчета площади.
- Создайте подклассы: "Прямоугольник" и "Круг", которые унаследуют метод расчета площади от базового класса.
- Создайте объекты обоих подклассов и выведите их площади.
*/

#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

class Figure {
public:
    // Виртуальный метод для расчета площади
    [[nodiscard]] virtual double calculateArea() const = 0;

    // Виртуальный деструктор
    virtual ~Figure() = default;
};

class Rectangle: public Figure {
public:
    double w;
    double h;

    Rectangle(double w, double h) : w(w), h(h) {
        if (w < 0 || h < 0){
            throw invalid_argument("Width or height is negative");
        }
    }

    [[nodiscard]] double calculateArea() const override {
        if (w == 0 || h == 0){
            throw runtime_error("Area will be zero");
        }
        return w * h;
    }
};

class Circle: public Figure {
public:
    double r;

    explicit Circle(double r): r(r){
        if (r < 0){
            throw invalid_argument("Radius is negative");
        }
    }

    [[nodiscard]] double calculateArea() const override {
        if (r == 0){
            throw runtime_error("Area will be zero");
        }
        return M_PI * r * r;
    }
};

int main(){
    Rectangle rectangle = Rectangle(20, 2);
    Circle circle = Circle(5);

    cout << "Площадь круга " << circle.calculateArea() << endl;
    cout << "Площадь прямоугольника " << rectangle.calculateArea() << endl;
}