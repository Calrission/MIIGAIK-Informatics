/*
Создайте класс Product, представляющий базовый класс для продуктов, с атрибутами цены (price) и веса (weight).
Реализуйте метод getTotalPrice(), возвращающий общую стоимость продукта.
От класса Product унаследуйте классы Apple и Orange, представляющие яблоко и апельсин соответственно.
В каждом из этих классов добавьте дополнительные характеристики,
такие как сорт (variety) для яблока и страна происхождения (origin) для апельсина.
Реализуйте обработку исключений в конструкторах классов Product, Apple и Orange.
Если переданные значения цены или веса являются отрицательными или нулевыми,
должно возникать исключение std::invalid_argument.
В блоке main() создайте объекты Apple и Orange, передав некорректные значения (например,
отрицательные цены или веса) при их создании. Обработайте исключения, которые могут возникнуть при этом,
и выведите сообщение об ошибке в случае их возникновения. Запустите программу и проверьте корректность
обработки исключений при создании объектов Apple и Orange с неправильными значениями
*/


#include "iostream"
#include <stdexcept>

using namespace std;

class Product {
    public:
        double price;
        double weight;

        Product(double price, double weight) : price(price), weight(weight) {
            if (price < 0){
                throw invalid_argument("Price of product is negative");
            }else if (weight < 0){
                throw invalid_argument("Weight of product is negative");
            }
        }

        virtual double getTotalPrice(){
            throw runtime_error("Calling origin virtual getTotalPrice");
        }
};

class Apple: public Product {
    string variety;

    public:
        Apple(double price, double weight, const string& variety) : Product(price, weight){
            this->variety = variety;
        }
};

class Orange: public Product {
    string origin;

    public:
        Orange(double price, double weight, const string& origin) : Product(price, weight){
            this->origin = origin;
        }
};

int main() {
    try {
        Apple apple_1 = Apple(120, -1, "Яблочный спас");
        cout << apple_1.getTotalPrice() << endl;
    }catch(exception& e){
        cout << e.what() << endl;
    }

    try{
        Apple apple_2 = Apple(-1, 1, "Golding");
        cout << apple_2.getTotalPrice() << endl;
    }catch(exception& e){
        cout << e.what() << endl;
    }

    try{
        Orange orange_1 = Orange(-1, 100, "Бразилия");
        cout << orange_1.getTotalPrice() << endl;
    }catch(exception& e){
        cout << e.what() << endl;
    }

    try{
        Orange orange_2 = Orange(120, -1, "Бразилия");
        cout << orange_2.getTotalPrice() << endl;
    }catch(exception& e){
        cout << e.what() << endl;
    }
}