#include <iostream>

#define MAX 5

using namespace std;

// Define a Queue //
template <class T>
class Queue {
private:
    int front, rear, counter;
    T arr[MAX];

public:
    // Constructor to initialize front, rear, and other members
    Queue() {
        front = -1;
        rear = -1;
        counter = 0;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return (counter == 0);
    }

    // Check if the queue is full
    bool isFullQ() {
        return (counter == MAX);
    }

    // Enqueue into the queue
    void enq(T data) {
        if (!isFullQ()) {
            if (front == -1) // If queue is empty, set front to 0
                front = 0;
            rear = (rear + 1) % MAX; // Circular increment for rear index
            arr[rear] = data;
            counter++;
        } else {
            cout << "Overflow" << endl;
        }
    }

    // Dequeue from the queue
    void deq() {
        if (!isEmpty()) {
            cout << "Dequeued: " << arr[front] << endl;
            front = (front + 1) % MAX; // Circular increment for front index
            counter--;
        } else {
            cout << "Underflow" << endl;
        }
    }

    // Display the queue
    void display() {
        if (isEmpty()) {
            cout << "The queue is empty!" << endl;
            return;
        }
        cout << "\nQueue Contents: ";
        for (int i = 0; i < counter; i++) {
            int idx = (front + i) % MAX;
            cout << arr[idx] << "\t";
        }
        cout << "\nFront Index: " << front
             << " | Rear Index: " << rear
             << " | Length: " << counter << endl;
    }
};

// Driver main function
int main() {
    Queue<int> que; // Creating a queue for integers
    int choice;
    int val;

    cout << "What do you want to do?\n"
         << "1 - Enqueue\n"
         << "2 - Dequeue\n"
         << "3 - Display\n"
         << "4 - Exit\n";

    do {
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> val;
                que.enq(val);
                break;

            case 2:
                que.deq();
                break;

            case 3:
                que.display();
                break;

            case 4:
                cout << "Thank you!" << endl;
                break;

            default:
                cout << "Invalid choice, try again." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}

