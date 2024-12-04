#include <iostream>
#define MAX 4

using namespace std;

class List {
    int avail;
    struct nodeType {
        int info;
        int next;
    } node[MAX];

public:
    // Constructor to initialize the list
    List() {
        avail = 0;
        for (int i = 0; i < MAX - 1; i++) {
            node[i].next = i + 1;
            node[i].info = 0;
        }
        node[MAX - 1].next = -1;
    }

    // Function to get a new node
    int getnode() {
        if (avail == -1) {
            cout << "List Overflow!" << endl;
            return -1;
        } else {
            int ptr = avail;
            avail = node[ptr].next;
            return ptr;
        }
    }

    // Function to free a node
    void freenode(int ptr) {
        node[ptr].next = avail;
        avail = ptr;
    }

    // Function to insert a value
    void ins() {
        int num, ptr;
        cout << "Enter the number: ";
        cin >> num;

        ptr = getnode();

        if (ptr == -1) {
            return;
        }

        node[ptr].info = num;
        node[ptr].next = -1;

        if (avail == 0) { // If it's the first element
            node[ptr].next = -1;
        } else {
            int temp = 0;
            while (node[temp].next != -1) {
                temp = node[temp].next;
            }
            node[temp].next = ptr;
        }
    }

    // Function to insert after a given position
    void insafter() {
        int num, ptr, pos;
        cout << "Enter the position to insert after: ";
        cin >> pos;
        cout << "Enter the number: ";
        cin >> num;

        if (pos >= MAX || pos == -1) {
            cout << "Invalid position!" << endl;
            return;
        }

        ptr = getnode();

        if (ptr == -1) {
            return;
        }

        node[ptr].info = num;
        node[ptr].next = node[pos].next;
        node[pos].next = ptr;
    }

    // Function to delete a node
    void del() {
        int pos;
        cout << "Enter the position to delete: ";
        cin >> pos;

        if (pos == -1 || pos >= MAX) {
            cout << "Invalid position!" << endl;
            return;
        }

        int temp = 0;
        while (node[temp].next != pos) {
            temp = node[temp].next;
        }

        node[temp].next = node[pos].next;
        node[pos].info = 0;
        freenode(pos);
    }

    // Function to delete after a given position
    void delafter() {
        int pos;
        cout << "Enter the position to delete after: ";
        cin >> pos;

        if (pos == -1 || pos >= MAX) {
            cout << "Invalid position!" << endl;
            return;
        }

        int delptr = node[pos].next;
        if (delptr == -1) {
            cout << "No node after the given position!" << endl;
            return;
        }

        node[pos].next = node[delptr].next;
        node[delptr].info = 0;
        freenode(delptr);
    }

    // Function to display the list
    void display() {
        cout << "Node\t\tInfo\t\tNext" << endl;
        for (int i = 0; i < MAX; i++) {
            cout << i << "\t\t" << node[i].info << "\t\t" << node[i].next << endl;
        }
    }
};

int main() {
    int option;
    List list;

    do {
        cout << "\nChoose an option:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Insert After\n";
        cout << "4. Delete After\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
            case 1:
                list.ins();
                break;
            case 2:
                list.del();
                break;
            case 3:
                list.insafter();
                break;
            case 4:
                list.delafter();
                break;
            case 5:
                list.display();
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid option, try again." << endl;
        }
    } while (option != 6);

    return 0;
}

