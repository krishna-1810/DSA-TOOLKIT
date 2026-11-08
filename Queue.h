#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;
struct QueueNode {
    int data;
    QueueNode* next;
    QueueNode(int value) : data(value), next(nullptr) {}
};

class Queue {
private:
    QueueNode* frontNode;
    QueueNode* rearNode;

public:
    Queue() : frontNode(nullptr), rearNode(nullptr) {}

    Queue(const Queue&) = delete;
    Queue& operator=(const Queue&) = delete;

    ~Queue() {
        while (frontNode != nullptr) {
            QueueNode* temp = frontNode;
            frontNode = frontNode->next;
            delete temp;
        }
    }

    bool isEmpty() const {
        return frontNode == nullptr;
    }

    void enqueue(int value) {
        QueueNode* newNode = new QueueNode(value);
        if (rearNode == nullptr) {
            frontNode = rearNode = newNode;
            return;
        }
        rearNode->next = newNode;
        rearNode = newNode;
    }

    bool dequeue(int& value) {
        if (isEmpty()) return false;
        QueueNode* temp = frontNode;
        value = temp->data;
        frontNode = frontNode->next;
        if (frontNode == nullptr) rearNode = nullptr;
        delete temp;
        return true;
    }

    bool front(int& value) const {
        if (isEmpty()) return false;
        value = frontNode->data;
        return true;
    }

    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Front -> ";
        QueueNode* current = frontNode;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << "<- Rear" <<endl;
    }
};

#endif
