#ifndef SEARCHING_H
#define SEARCHING_H

// Linear Search: shuru se end tak ek-ek check karta hai.
// Mila to index return karta hai, nahi mila to -1.
inline int linearSearch(const int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

// Binary Search: array SORTED hona zaroori hai.
// Har baar beech wala element dekhta hai aur aadha hissa chhod deta hai.
inline int binarySearch(const int arr[], int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

#endif