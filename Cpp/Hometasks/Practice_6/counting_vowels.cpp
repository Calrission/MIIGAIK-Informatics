#include <iostream>
#include "string"

using namespace std;

int main() {
    string vowels = "aeyuoiёуеэоаыяию";
    string line;
    getline(cin, line);
    unsigned count = 0;
    for (char& i: line){
        if (vowels.contains(i)){
            count ++;
        }
    }
    cout << count << endl;
}