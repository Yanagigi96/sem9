#include <iostream>
using namespace std;

const int MAX_SIZE = 3;
int Q[MAX_SIZE];
int head = 0;
int tail = 0;
int count = 0;

void ENQUEUE(int x) {
    if (count == MAX_SIZE) {
        cout << "  [Ошибка] Очередь переполнена! Не удалось добавить " << x << endl;
        return;
    }
    Q[tail] = x;
    tail = (tail + 1) % MAX_SIZE;
    count++;
    cout << "  Добавлено " << x << ". Элементов: " << count << endl;
}

void DEQUEUE() {
    if (count == 0) {
        cout << "  [Ошибка] Очередь пуста! Невозможно извлечь." << endl;
        return;
    }
    int x = Q[head];
    head = (head + 1) % MAX_SIZE;
    count--;
    cout << "  Извлечено " << x << ". Элементов: " << count << endl;
}

int main() {
    cout << "Проверка пустой очереди:" << endl;
    DEQUEUE();

    cout << "\nЗаполнение до предела:" << endl;
    ENQUEUE(10);
    ENQUEUE(20);
    ENQUEUE(30);

    cout << "\nПопытка переполнения:" << endl;
    ENQUEUE(40);
    
    return 0;
}