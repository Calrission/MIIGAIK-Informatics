#include <iostream>
#include "string"

using namespace std;

int main() {
    string line;
    getline(cin, line);
    for (int i = static_cast<int>(line.length()-1); i >= 0; i--){
        cout << line[i];
    }
}