#include <iostream>
using namespace std;

const int MAX_SIZE = 6;
int Q[MAX_SIZE + 1]; // Индексы от 1 до 6
int head = 1;
int tail = 1;

void printState(const string& op) {
    cout << op << ": [ ";
    for (int i = 1; i <= MAX_SIZE; i++) {
        cout << Q[i] << " ";
    }
    cout << "] head = " << head << ", tail = " << tail << endl;
}

void ENQUEUE(int x) {
    Q[tail] = x;
    if (tail == MAX_SIZE) tail = 1;
    else tail++;
}

int DEQUEUE() {
    int x = Q[head];
    if (head == MAX_SIZE) head = 1;
    else head++;
    return x;
}

int main() {
    for (int i = 1; i <= MAX_SIZE; i++) Q[i] = 0;
    
    ENQUEUE(4); printState("ENQUEUE(4)");
    ENQUEUE(1); printState("ENQUEUE(1)");
    ENQUEUE(3); printState("ENQUEUE(3)");
    int val = DEQUEUE(); printState("DEQUEUE() -> " + to_string(val));
    ENQUEUE(8); printState("ENQUEUE(8)");
    val = DEQUEUE(); printState("DEQUEUE() -> " + to_string(val));
    
    return 0;
}