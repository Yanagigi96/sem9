#include <iostream>
using namespace std;

const int MAX_SIZE = 10;
int D[MAX_SIZE];
int head = 5;
int tail = 5;
int count = 0;

void push_front(int x) {
    if (count == MAX_SIZE) return;
    head = (head - 1 + MAX_SIZE) % MAX_SIZE;
    D[head] = x;
    count++;
    cout << "  push_front(" << x << "): head = " << head << ", tail = " << tail << endl;
}

void push_back(int x) {
    if (count == MAX_SIZE) return;
    D[tail] = x;
    tail = (tail + 1) % MAX_SIZE;
    count++;
    cout << "  push_back(" << x << "): head = " << head << ", tail = " << tail << endl;
}

void pop_front() {
    if (count == 0) return;
    cout << "  pop_front() -> " << D[head] << endl;
    head = (head + 1) % MAX_SIZE;
    count--;
}

void pop_back() {
    if (count == 0) return;
    tail = (tail - 1 + MAX_SIZE) % MAX_SIZE;
    cout << "  pop_back() -> " << D[tail] << endl;
    count--;
}

int main() {
    cout << "Демонстрация работы дека:" << endl;
    push_back(10);  
    push_front(20); 
    push_back(30);  
    push_front(40); 
    
    pop_front();    
    pop_back();     
    
    return 0;
}