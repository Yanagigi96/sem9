#include <iostream>
using namespace std;

const int MAX_SIZE = 10;
int A[MAX_SIZE];
int top1 = 0;            // Указатель для первого стека (растет вправо)
int top2 = MAX_SIZE + 1; // Указатель для второго стека (растет влево)

void printState() {
    cout << "Массив: [ ";
    for (int i = 1; i <= MAX_SIZE; i++) {
        if (i <= top1 || i >= top2) cout << A[i] << " ";
        else cout << "_ ";
    }
    cout << "] top1 = " << top1 << ", top2 = " << top2 << endl;
}

void PUSH1(int x) {
    if (top1 + 1 == top2) {
        cout << "Ошибка: Переполнение (стеки встретились)!" << endl;
        return;
    }
    A[++top1] = x;
}

void PUSH2(int x) {
    if (top1 + 1 == top2) {
        cout << "Ошибка: Переполнение (стеки встретились)!" << endl;
        return;
    }
    A[--top2] = x;
}

int POP1() {
    if (top1 == 0) {
        cout << "Ошибка: Стек 1 пуст!" << endl;
        return -1;
    }
    return A[top1--];
}

int POP2() {
    if (top2 == MAX_SIZE + 1) {
        cout << "Ошибка: Стек 2 пуст!" << endl;
        return -1;
    }
    return A[top2++];
}

int main() {
    PUSH1(10); printState();
    PUSH1(20); printState();
    PUSH2(99); printState();
    PUSH2(88); printState();
    
    cout << "POP1() -> " << POP1() << endl; printState();
    cout << "POP2() -> " << POP2() << endl; printState();
    
    // Демонстрация заполнения до предела
    PUSH1(30); PUSH1(40); PUSH1(50); PUSH1(60); 
    printState(); 
    PUSH1(70); // Должна сработать защита
    return 0;
}