#include <iostream>
#include <vector>
using namespace std;

class Array {
private:
    int size;
    vector<int> arr;
    int front = -1, rear = -1;

public:
    Array(int value) : size(value) {
        arr.resize(value);
    }

    void insert(int value) {
        if (front == (rear + 1) % size) {
            cout << "Array is Full" << endl;
            return;
        }
        if (front == -1) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % size;
        }
        arr[rear] = value;
    }

    void remove() {
        if (front == -1) {
            cout << "Array is empty" << endl;
            return;
        }
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }

    void display() {
        if (front == -1) {
            cout << "Array is empty" << endl;
            return;
        }
        int i = front;
        while (i != rear) {
            cout << arr[i] << " ";
            i = (i + 1) % size;
        }
        cout << arr[rear] << endl;
    }
};

int main() {
    Array ar(6);

    for (int i = 0; i < 6; i++) {
        ar.insert((i + 1) * 10);
    }

    ar.display();

    ar.remove();
    ar.display();

    ar.insert(100);
    ar.display();

    return 0;
}
