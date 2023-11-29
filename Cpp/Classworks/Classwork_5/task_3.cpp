#include "iostream"

using namespace std;

class Home {
    public:
        int count_rooms = 0;
        string address;
};

class Human {
    public:
        string name;
        int age;

        Human(const string& name, int age){
            this->name = name;
            this->age = age;
        }
};

class Resident: public Human {
    public:
        Home home;

        Resident(const string &name, int age) : Human(name, age) {}

        void connectToHome(const Home& new_home){
            this->home = new_home;
        }

        string& getAddress(){
            return home.address;
        }
};

int main(){
    auto home = Home();
    home.count_rooms = 10;
    home.address = "My address";
    auto resident = Resident("Resident name", 20);
    resident.connectToHome(home);
    cout << resident.getAddress() << endl;
    return 0;
}