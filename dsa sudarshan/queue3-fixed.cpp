#include <iostream>
#define MAX 4
using namespace std;
class List {
int avail;
struct nodeType {
int info;
int next;
};
struct nodeType node[MAX];
public:
// Constructor to initialize the list
List() {
avail = 0;
for (int i = 0; i < MAX; i++) {
node[i].next = i + 1;
node[i].info = 0;
}

node[MAX - 1].next = -1;
}
// Function to get a new node
int getnode() {
if (avail == -1) {
cout << "############# Overflow #############" << endl;
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
if (ptr == 0) {
node[ptr].info = num;
node[ptr].next = -1;
} else {
node[ptr].info = num;
node[ptr].next = -1;
bool test = true;
int temp = 0;
while (test) {
if (node[temp].next == -1) {
test = false;
node[temp].next = ptr;
}

temp = node[temp].next;
}
}
}
// Function to insert after a given position
void insafter() {
int num, ptr, pos;
cout << "\nEnter n-1 position: ";
cin >> pos;
cout << "Enter the number: ";
cin >> num;
ptr = getnode();
if (ptr == -1 || ptr > MAX - 1) {
cout << "######### Invalid ############" << endl;
return;
}
node[ptr].info = num;
node[ptr].next = node[pos].next;
node[pos].next = ptr;
}
// Function to delete a node
void del() {
int pos;
cout << "Enter n position: ";
cin >> pos;
if (pos == -1 || pos > MAX - 1) {
cout << "##### Can't REMOVE #####" << endl;
return;
}
node[pos].info = 0;
bool test = true;
int temp = 0;
while (test) {
if (node[temp].next == pos) {
test = false;
node[temp].next = node[pos].next;
}
temp = node[temp].next;
}

freenode(pos);
}
// Function to delete after a given position
void delafter() {
int pos;
cout << "Enter n-1 position: ";
cin >> pos;
if (pos == -1 || pos > MAX - 1) {
cout << "####### Can't remove ##########" << endl;
return;
}
int delptr = node[pos].next;
node[delptr].info = 0;
node[pos].next = node[delptr].next;
freenode(delptr);
}
// Function to display the list
void display() {
cout << "--------------------------------------" << endl;
cout << "--------------------------------------" << endl;
cout << "avail = " << avail << endl;
cout << "Node\t\tInfo\t\tNext" << endl;
for (int i = 0; i < MAX; i++) {
cout << i << "\t\t" << node[i].info << "\t\t" << node[i].next << endl;
}
cout << "--------------------------------------" << endl;
cout << "--------------------------------------" << endl;
}
};
int main() {
int option;
List l;
do {
cout << "Choose:\n1. Insert\n2. Delete\n3. Insert After\n4. Delete After\n5. Exit" << endl;
cin >> option;
switch (option) {
case 1:
l.ins();
break;

case 2:
l.del();
break;
case 3:
l.insafter();
break;
case 4:
l.delafter();
break;
case 5:
cout << "************** Exiting ************" << endl;
break;
default:
cout << "Invalid option, try again." << endl;
}
l.display();
} while (option != 5);
return 0;
}
