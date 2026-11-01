#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>

struct Entry {
    int key;
    int value;
    Entry* next;
    Entry(int k, int v) : key(k), value(v), next(nullptr) {}
};

class HashTable {
private:
    Entry** table;      // Har index pe ek linked list ka head
    int tableSize;

    // Key ko index mein badalta hai (negative key ko bhi handle karta hai)
    int hashFunction(int key) const {
        int index = key % tableSize;
        if (index < 0) index += tableSize;
        return index;
    }

public:
    HashTable(int size = 10) : tableSize(size) {
        table = new Entry*[tableSize];
        for (int i = 0; i < tableSize; i++) table[i] = nullptr;
    }

    HashTable(const HashTable&) = delete;
    HashTable& operator=(const HashTable&) = delete;

    ~HashTable() {
        for (int i = 0; i < tableSize; i++) {
            Entry* current = table[i];
            while (current != nullptr) {
                Entry* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    // Key pehle se hai to value update hoti hai, warna naya entry judta hai
    void insert(int key, int value) {
        int index = hashFunction(key);
        Entry* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                current->value = value;
                return;
            }
            current = current->next;
        }
        Entry* newEntry = new Entry(key, value);
        newEntry->next = table[index];
        table[index] = newEntry;
    }

    // Key mili to true, aur value "value" mein aa jaati hai
    bool search(int key, int& value) const {
        Entry* current = table[hashFunction(key)];
        while (current != nullptr) {
            if (current->key == key) {
                value = current->value;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    bool remove(int key) {
        int index = hashFunction(key);
        Entry* current = table[index];
        Entry* prev = nullptr;

        while (current != nullptr) {
            if (current->key == key) {
                if (prev == nullptr) table[index] = current->next;
                else prev->next = current->next;
                delete current;
                return true;
            }
            prev = current;
            current = current->next;
        }
        return false;
    }

    void display() const {
        for (int i = 0; i < tableSize; i++) {
            std::cout << "Bucket " << i << ": ";
            Entry* current = table[i];
            if (current == nullptr) {
                std::cout << "empty";
            }
            while (current != nullptr) {
                std::cout << "[" << current->key << ":" << current->value << "]";
                if (current->next != nullptr) std::cout << " -> ";
                current = current->next;
            }
            std::cout << std::endl;
        }
    }
};

#endif