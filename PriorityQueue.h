#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>

class PriorityQueue {
private:
    int* arr;
    int size;
    int capacity;

    void resize() {
        capacity *= 2;
        int* newArr = new int[capacity];
        for (int i = 0; i < size; i++) newArr[i] = arr[i];
        delete[] arr;
        arr = newArr;
    }

    void swapValues(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
    void heapifyUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (arr[i] > arr[parent]) {
                swapValues(arr[i], arr[parent]);
                i = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int i) {
        while (true) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int largest = i;

            if (left < size && arr[left] > arr[largest]) largest = left;
            if (right < size && arr[right] > arr[largest]) largest = right;

            if (largest == i) break;
            swapValues(arr[i], arr[largest]);
            i = largest;
        }
    }

public:
    PriorityQueue() : size(0), capacity(4) {
        arr = new int[capacity];
    }

    PriorityQueue(const PriorityQueue&) = delete;
    PriorityQueue& operator=(const PriorityQueue&) = delete;

    ~PriorityQueue() {
        delete[] arr;
    }

    bool isEmpty() const {
        return size == 0;
    }

    void insert(int value) {
        if (size == capacity) resize();
        arr[size] = value;
        heapifyUp(size);
        size++;
    }

    bool peek(int& value) const {
        if (isEmpty()) return false;
        value = arr[0];
        return true;
    }

    bool extractMax(int& value) {
        if (isEmpty()) return false;
        value = arr[0];
        arr[0] = arr[size - 1];
        size--;
        heapifyDown(0);
        return true;
    }

    void display() const {
        if (isEmpty()) {
            cout << "Priority Queue is empty" << endl;
            return;
        }
        cout << "Heap array: ";
        for (int i = 0; i < size; i++) {
           cout << arr[i] << " ";
        }
    cout << endl;
    }
};

#endif
