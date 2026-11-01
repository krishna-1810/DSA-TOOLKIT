#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

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

    // Piche se add karo
    void enqueue(int value) {
        QueueNode* newNode = new QueueNode(value);
        if (rearNode == nullptr) {
            frontNode = rearNode = newNode;
            return;
        }
        rearNode->next = newNode;
        rearNode = newNode;
    }

    // Aage se nikalo
    bool dequeue(int& value) {
        if (isEmpty()) return false;
        QueueNode* temp = frontNode;
        value = temp->data;
        frontNode = frontNode->next;
        if (frontNode == nullptr) rearNode = nullptr;
        delete temp;
        return true;
    }

    // Sabse aage wala element dekhna (hatana nahi)
    bool front(int& value) const {
        if (isEmpty()) return false;
        value = frontNode->data;
        return true;
    }

    void display() const {
        if (isEmpty()) {
            std::cout << "Queue is empty" << std::endl;
            return;
        }
        std::cout << "Front -> ";
        QueueNode* current = frontNode;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << "<- Rear" << std::endl;
    }
};

#endif