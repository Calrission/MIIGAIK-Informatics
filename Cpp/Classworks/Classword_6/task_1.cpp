/*
Создайте интерфейс (абстрактный класс) "Фигура" с методом для расчета площади.
Реализуйте этот интерфейс в классах "Прямоугольник" и "Круг".

Создайте массив объектов типа "Фигура" и вызовите для каждого метод расчета площади.
Не забудьте освободить память!

Сделайте обработку исключений:
- «1» - Фигура с отрицательными сторонами
- «2» - Фигура с нулевой площадью

Используйте модули
include <iostream> для ввода/вывода
include <cmath> для использования математических функций, таких как M_PI
include <stdexcept> для обработки исключений

class Figure {
    public:
        // Виртуальный метод для расчета площади
        virtual double calculateArea() const = 0;

        // Виртуальный деструктор
        virtual ~Figure() {}
};
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
    Rectangle rect = Rectangle(2.2, 12);
    cout << "Area rectangle: " << rect.calculateArea() << endl;
    Circle circle = Circle(20);
    cout << "Area circle: " << circle.calculateArea() << endl;

    try{
        Rectangle bad_rect = Rectangle(0, 0);
        double bad_rect_area = bad_rect.calculateArea();
        cout << "Area bad rectangle: " << bad_rect_area << endl;

        Circle bad_circle = Circle(0);
        double bad_circle_area = bad_circle.calculateArea();
        cout << "Area bad circle: " << bad_circle_area << endl;

        Rectangle bad_rect_2 = Rectangle(-1, -1);
        double bad_rect_area_2 = bad_rect_2.calculateArea();
        cout << "Area bad rectangle: " << bad_rect_area_2 << endl;

        Circle bad_circle_2 = Circle(0);
        double bad_circle_area_2 = bad_circle_2.calculateArea();
        cout << "Area bad circle: " << bad_circle_area_2 << endl;
    }catch (invalid_argument& e){
        return 1;
    }catch (runtime_error& e){
        return 2;
    }
    return 0;
}