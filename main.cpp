#include <iostream>
#include "include/LinkedList.h"
#include "include/Stack.h"
#include "include/Queue.h"
#include "include/PriorityQueue.h"
#include "include/HashTable.h"
#include "include/Sorting.h"
#include "include/Searching.h"
using namespace std;

int readInt(const char* prompt) {
    int x;
    cout << prompt;
    while (!(cin >> x)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input. Enter a number: ";
    }
    return x;
}

int* readArray(int& n) {
    n = readInt("Number of elements: ");
    if (n <= 0) {
        cout << "Size must be at least 1." << endl;
        return nullptr;
    }
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = readInt("  Element: ");
    }
    return arr;
}

void linkedListMenu() {
    LinkedList list;
    int choice;
    do {
        cout << "\n--- Linked List ---\n"
             << "1. Insert at beginning\n2. Insert at end\n3. Delete value\n"
             << "4. Search\n5. Display\n0. Back\n";
        choice = readInt("Choice: ");

        if (choice == 1) list.insertAtBeginning(readInt("Value: "));
        else if (choice == 2) list.insertAtEnd(readInt("Value: "));
        else if (choice == 3) {
            if (list.deleteValue(readInt("Value to delete: "))) cout << "Deleted." << endl;
            else cout << "Value not found." << endl;
        }
        else if (choice == 4) {
            if (list.search(readInt("Value to search: "))) cout << "Found!" << endl;
            else cout << "Not found." << endl;
        }
        else if (choice == 5) list.display();
        else if (choice != 0) cout << "Invalid choice." << endl;
    } while (choice != 0);
}

void stackMenu() {
    Stack s;
    int choice, val;
    do {
        cout << "\n--- Stack ---\n"
             << "1. Push\n2. Pop\n3. Peek\n4. Display\n0. Back\n";
        choice = readInt("Choice: ");

        if (choice == 1) s.push(readInt("Value: "));
        else if (choice == 2) {
            if (s.pop(val)) cout << "Popped: " << val << endl;
            else cout << "Stack is empty." << endl;
        }
        else if (choice == 3) {
            if (s.peek(val)) cout << "Top: " << val << endl;
            else cout << "Stack is empty." << endl;
        }
        else if (choice == 4) s.display();
        else if (choice != 0) cout << "Invalid choice." << endl;
    } while (choice != 0);
}

void queueMenu() {
    Queue q;
    int choice, val;
    do {
        cout << "\n--- Queue ---\n"
             << "1. Enqueue\n2. Dequeue\n3. Front\n4. Display\n0. Back\n";
        choice = readInt("Choice: ");

        if (choice == 1) q.enqueue(readInt("Value: "));
        else if (choice == 2) {
            if (q.dequeue(val)) cout << "Dequeued: " << val << endl;
            else cout << "Queue is empty." << endl;
        }
        else if (choice == 3) {
            if (q.front(val)) cout << "Front: " << val << endl;
            else cout << "Queue is empty." << endl;
        }
        else if (choice == 4) q.display();
        else if (choice != 0) cout << "Invalid choice." << endl;
    } while (choice != 0);
}

void priorityQueueMenu() {
    PriorityQueue pq;
    int choice, val;
    do {
        cout << "\n--- Priority Queue (larger number = higher priority) ---\n"
             << "1. Insert\n2. Extract highest\n3. Peek\n4. Display\n0. Back\n";
        choice = readInt("Choice: ");

        if (choice == 1) pq.insert(readInt("Value: "));
        else if (choice == 2) {
            if (pq.extractMax(val)) cout << "Extracted: " << val << endl;
            else cout << "Priority Queue is empty." << endl;
        }
        else if (choice == 3) {
            if (pq.peek(val)) cout << "Highest priority: " << val << endl;
            else cout << "Priority Queue is empty." << endl;
        }
        else if (choice == 4) pq.display();
        else if (choice != 0) cout << "Invalid choice." << endl;
    } while (choice != 0);
}

void hashTableMenu() {
    HashTable ht(7);
    int choice, key, val;
    do {
        cout << "\n--- Hash Table ---\n"
             << "1. Insert (key, value)\n2. Search by key\n3. Delete by key\n"
             << "4. Display\n0. Back\n";
        choice = readInt("Choice: ");

        if (choice == 1) {
            key = readInt("Key: ");
            val = readInt("Value: ");
            ht.insert(key, val);
        }
        else if (choice == 2) {
            key = readInt("Key: ");
            if (ht.search(key, val)) cout << "Value = " << val << endl;
            else cout << "Key not found." << endl;
        }
        else if (choice == 3) {
            if (ht.remove(readInt("Key: "))) cout << "Deleted." << endl;
            else cout << "Key not found." << endl;
        }
        else if (choice == 4) ht.display();
        else if (choice != 0) cout << "Invalid choice." << endl;
    } while (choice != 0);
}

void sortingMenu() {
    cout << "\n--- Sorting ---" << endl;
    int n;
    int* arr = readArray(n);
    if (arr == nullptr) return;

    cout << "1. Bubble Sort\n2. Selection Sort\n3. Merge Sort\n4. Quick Sort\n";
    int choice = readInt("Choice: ");

    if (choice == 1) bubbleSort(arr, n);
    else if (choice == 2) selectionSort(arr, n);
    else if (choice == 3) mergeSort(arr, 0, n - 1);
    else if (choice == 4) quickSort(arr, 0, n - 1);
    else {
        cout << "Invalid choice." << endl;
        delete[] arr;
        return;
    }

    cout << "Sorted array: ";
    printArray(arr, n);
    delete[] arr;
}

void searchingMenu() {
    cout << "\n--- Searching ---" << endl;
    int n;
    int* arr = readArray(n);
    if (arr == nullptr) return;

    cout << "1. Linear Search\n2. Binary Search\n";
    int choice = readInt("Choice: ");
    int target, index;

    if (choice == 1) {
        target = readInt("Element to search: ");
        index = linearSearch(arr, n, target);
    }
    else if (choice == 2) {
        mergeSort(arr, 0, n - 1);
        cout << "Array sorted: ";
        printArray(arr, n);
        target = readInt("Element to search: ");
        index = binarySearch(arr, n, target);
    }
    else {
        cout << "Invalid choice." << endl;
        delete[] arr;
        return;
    }

    if (index == -1) cout << "Element not found." << endl;
    else cout << "Element found at index " << index << "." << endl;
    delete[] arr;
}

int main() {
    int choice;
    do {
        cout << "\n=========== DSA TOOLKIT ===========\n"
             << "1. Linked List\n2. Stack\n3. Queue\n4. Priority Queue\n"
             << "5. Hash Table\n6. Sorting\n7. Searching\n0. Exit\n";
        choice = readInt("Choice: ");

        switch (choice) {
            case 1: linkedListMenu(); break;
            case 2: stackMenu(); break;
            case 3: queueMenu(); break;
            case 4: priorityQueueMenu(); break;
            case 5: hashTableMenu(); break;
            case 6: sortingMenu(); break;
            case 7: searchingMenu(); break;
            case 0: cout << "Bye!" << endl; break;
            default: cout << "Invalid choice." << endl;
        }
    } while (choice != 0);

    return 0;
}
