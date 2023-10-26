#include <iostream>
#include <set>
#include <algorithm>

/*
Ответьте каким будет пересечение всех множеств?
Правда, что разность множества 1 и 2 будет: 1 2 3 4 5 ?
Выведите объединение множества 1 и 2
*/

using namespace std;

int main() {
    std::set<int> set1, set2, set3; // Заполняем первое множество
    for (int i = 1; i <= 10; i++) {
        set1.insert(i);
    }
    // Заполняем второе множество
    for (int i = 6; i <= 15; i++) {
        set2.insert(i);
    }
    // Заполняем третье множество
    for (int i = 11; i <= 20; i++) {
        set3.insert(i);
    }

    cout << "1: " << endl;

    set<int> new_set_0;
    set<int> new_set_0_1;
    set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(new_set_0, new_set_0.begin()));
    set_intersection(new_set_0.begin(), new_set_0.end(), set3.begin(), set3.end(), inserter(new_set_0_1, new_set_0_1.begin()));
    for (auto i: new_set_0_1){
        cout << i << " ";
    }

    cout << "2: ";
    set<int> new_set;
    set_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(new_set, new_set.begin()));
    for (auto i: new_set){
        cout << i << " ";
    }

    cout << endl << "3: ";
    set<int> new_set_2;
    set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(new_set_2, new_set_2.begin()));
    for (auto i: new_set_2){
        cout << i << " ";
    }
}