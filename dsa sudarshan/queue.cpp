#include <iostream>

#include <cstdlib>

#define MAX 9

using namespace std;

template <class Q>
class Queue {
private:

Q data[MAX];

Q arr[MAX];

int front, rear;

bool IsEmpty() {
return (front > rear || front == -1);

}

bool IsFull() {
return (rear == (MAX - 1));
}

public:
Queue() : front(-1), rear(-1) {}

void enqueue(Q var) {
if (IsFull()) {
cout << "\nQueue overflow" << endl;
}else {
if (front == -1)
front = 0;
data[++rear] = var;
}
}

void dequeue() {
if (IsEmpty()) {
cout << "\nQueue underflow" << endl;
}else {
cout << "\nThe dequeued element is: " << data[front++] << endl;

}
}

void Front() {
if (IsEmpty()) {
cout << "\nQueue underflow" << endl;
}else {
cout << "\nThe front element of the queue is: " << data[front] << endl;
}
}
};

int main() {
Queue<int> q;
q.enqueue(10);
q.enqueue(20);

int choice;

while (1) {
cout << "1. Enqueue\n2. Dequeue\n3. View front element\n4. Exit\nEnter your choice: ";
cin >> choice;

switch (choice) {

case 1: {
cout << "Enter the value: ";
cin >> choice;
q.enqueue(choice);
break;

}

case 2:
q.dequeue();
break;

case 3:
q.Front();
break;

default:
exit(0);

}

cout << "\n\n";

}

return 0;

}
