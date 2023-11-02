#include "iostream"
#include "vector"

using namespace std;

vector<int> queue;

void enqueue(int elem){
    queue.push_back(elem);
}

int dequeue(){
    int elem = queue.front();
    queue.erase(queue.begin());
    return elem;
}

void show(){
    for (int& i: queue){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    enqueue(1);
    show();
    enqueue(2);
    show();
    enqueue(3);
    show();
    cout << dequeue() << endl;
    show();
}
