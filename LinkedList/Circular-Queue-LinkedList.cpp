#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

Node* front = NULL;
Node* rear = NULL;

void enqueue(int value) {
    Node* newNode = new Node(value);
    if (front == NULL) {
        front = rear = newNode;
        rear->next = front;  
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;  
    }
}

int dequeue() {
    if (front == NULL) {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    int value;
    if (front == rear) {
        value = front->data;
        delete front;
        front = rear = NULL;
    } else {
        Node* temp = front;
        value = temp->data;
        front = front->next;
        rear->next = front;  
        delete temp;
    }
    cout << value << " dequeued from queue." << endl;
    return value;
}

void display() {
    if (front == NULL) {
        cout << "Queue is empty!" << endl;
        return;
    }
    Node* temp = front;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != front);
    cout << endl;
}

bool isEmpty() {
    return (front == NULL);
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    display();

    dequeue();
    display();

    enqueue(50);
    display();

    dequeue();
    display();

    return 0;
}
