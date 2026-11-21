#include <iostream>
using namespace std;

const int MAX_SIZE = 6;
int S[MAX_SIZE + 1]; // Индексы от 1 до 6
int top = 0;

void printState(const string& op) {
    cout << op << ": [ ";
    for (int i = 1; i <= MAX_SIZE; i++) {
        if (i <= top) cout << S[i] << " ";
        else cout << "_ ";
    }
    cout << "] top = " << top << endl;
}

void PUSH(int x) {
    if (top == MAX_SIZE) {
        cout << "Ошибка: переполнение стека!" << endl;
        return;
    }
    top++;
    S[top] = x;
}

int POP() {
    if (top == 0) {
        cout << "Ошибка: стек пуст!" << endl;
        return -1;
    }
    int x = S[top];
    top--;
    return x;
}

int main() {
    cout << "Изначально: [ _ _ _ _ _ _ ] top = 0" << endl;
    PUSH(4); printState("PUSH(4)");
    PUSH(1); printState("PUSH(1)");
    PUSH(3); printState("PUSH(3)");
    int val = POP(); printState("POP() -> " + to_string(val));
    PUSH(8); printState("PUSH(8)");
    val = POP(); printState("POP() -> " + to_string(val));
    
    return 0;
}