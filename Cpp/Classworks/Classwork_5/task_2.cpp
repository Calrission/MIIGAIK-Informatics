#include "iostream"
#include <cmath>

using namespace std;

class Figure {
    public:
        virtual double calcArea(){
            throw runtime_error("Calling origin virtual method");
        }
};

class Rectangle: public Figure{
    public:
        double w, h;

        explicit Rectangle(double w, double h) : w(w), h(h) {}

        double calcArea() override {
            return w * h;
        }
};

class Circle: public Figure{
    public:
        double r;

        explicit Circle(double r) : r(r) {}

        double calcArea() override {
            return M_PI * r;
        }
};

int main(){
    auto rectangle = Rectangle(2.2, 5);
    auto circle = Circle(5.1);

    cout << "Площадь круга " << circle.calcArea() << endl;
    cout << "Площадь прямоугольника " << rectangle.calcArea() << endl;

    return 0;
}