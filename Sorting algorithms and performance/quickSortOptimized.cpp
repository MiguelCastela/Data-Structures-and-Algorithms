#pragma once
#include <iostream>
#include <vector>
using namespace std; 

// Insertion sort function
void insertionSort(vector<int>& arr, int low, int high) {
    for (int i = low + 1; i <= high; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= low && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}




int median (vector<int> &arr, int l, int r){
    int m = (l + r) / 2;
    if (arr[l] > arr[m]) swap(arr[l], arr[m]);
    if (arr[l] > arr[r]) swap(arr[l], arr[r]);
    if (arr[m] > arr[r]) swap(arr[m], arr[r]);
    return m;
}
// Partition function to rearrange the elements
int partitionopt(vector<int>& arr, int low, int high) {
    int pivot = median(arr, low, high);
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
// Quicksort function
void quicksortopt(vector<int>& arr, int low, int high) {
    if (low < high) {
        if (high - low <= 30) {
            insertionSort(arr, low, high);
        } else {
            int pivotIndex = partitionopt(arr, low, high);
            quicksortopt(arr, low, pivotIndex - 1);
            quicksortopt(arr, pivotIndex + 1, high);
        }
    }
}