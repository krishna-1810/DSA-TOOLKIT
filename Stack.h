#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;
struct StackNode {
    int data;
    StackNode* next;
    StackNode(int value) : data(value), next(nullptr) {}
};

class Stack {
private:
    StackNode* top;

public:
    Stack() : top(nullptr) {}

    Stack(const Stack&) = delete;
    Stack& operator=(const Stack&) = delete;

    ~Stack() {
        while (top != nullptr) {
            StackNode* temp = top;
            top = top->next;
            delete temp;
        }
    }

    bool isEmpty() const {
        return top == nullptr;
    }

    void push(int value) {
        StackNode* newNode = new StackNode(value);
        newNode->next = top;
        top = newNode;
    }

    bool pop(int& value) {
        if (isEmpty()) return false;
        StackNode* temp = top;
        value = temp->data;
        top = top->next;
        delete temp;
        return true;
    }
    bool peek(int& value) const {
        if (isEmpty()) return false;
        value = top->data;
        return true;
    }

    void display() const {
        if (isEmpty()) {
           cout << "Stack is empty" << endl;
            return;
        }
        cout << "Top -> ";
        StackNode* current = top;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
       cout << endl;
    }
};

#endif
