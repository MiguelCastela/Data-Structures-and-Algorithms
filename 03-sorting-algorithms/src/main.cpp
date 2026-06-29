#include "heapSort.cpp"
#include "quickSort.cpp"
#include "insertionSort.cpp"
#include "testCases.cpp"
#include <chrono>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include "quickSortOptimized.cpp"

using namespace std;
int main(){
    //TESTES

    // Test quickSort
    vector<int> arrqs = {9, 5, 2, 7, 1, 8, 3};
    int size_qs = arrqs.size();

    quicksort(arrqs, 0, size_qs - 1);

    cout << "Sorted array using quickSort: ";
    for (int num : arrqs) {
        cout << num << " ";
    }
    cout << endl;

    //test heapSort
    std::vector<int> arrhs = { 12, 11, 13, 5, 6, 7 };
    heapSort(arrhs);

    std::cout << "Sorted array using heapSort: ";
    for (int num : arrhs)
        std::cout << num << " ";
    std::cout << std::endl;

    //test insertionSort
    std::vector<int> arris = {5, 2, 8, 1, 3};
    insertionSort(arris);
    std::cout << "Sorted array using insertionSort: ";
    for (int num : arris) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    //TESTES RELATORIO
    vector<int> inputs;
    auto start = chrono::high_resolution_clock::now();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed;
    int n = 10000;
    for(int i =0; i<10; i++){

    // Test quickSort
    inputs = increasingOrderInputs(n);
    start = chrono::high_resolution_clock::now();
    quicksort(inputs, 0, n - 1);
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    cout << "Time taken by quickSort on increasing order inputs for " << n << " cases: " << elapsed.count() << "s" << endl;

    inputs = decreasingOrderInputs(n);
    start = chrono::high_resolution_clock::now();
    quicksort(inputs, 0, n - 1);
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    cout << "Time taken by quickSort on decreasing order inputs for " << n << " cases:" << elapsed.count() << "s" << endl;

    inputs = randomOrderInputs(n);
    start = chrono::high_resolution_clock::now();
    quicksort(inputs, 0, n - 1);
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    cout << "Time taken by quickSort on random order inputs for " << n << " cases:" << elapsed.count() << "s" << endl;

    //test quickSortOptimized
    inputs = increasingOrderInputs(n);
    start = chrono::high_resolution_clock::now();
    quicksortopt(inputs, 0, n - 1);
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    cout << "Time taken by quickSortOptimized on increasing order inputs for " << n << " cases: " << elapsed.count() << "s" << endl;

    inputs = decreasingOrderInputs(n);
    start = chrono::high_resolution_clock::now();
    quicksortopt(inputs, 0, n - 1);
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    cout << "Time taken by quickSortOptimized on decreasing order inputs for " << n << " cases:" << elapsed.count() << "s" << endl;

    inputs = randomOrderInputs(n);
    start = chrono::high_resolution_clock::now();
    quicksortopt(inputs, 0, n - 1);
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    cout << "Time taken by quickSortOptimized on random order inputs for " << n << " cases:" << elapsed.count() << "s" << endl;

    // Test heapSort
    inputs = increasingOrderInputs(n);
    start = chrono::high_resolution_clock::now();
    heapSort(inputs);
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    cout << "Time taken by heapSort on increasing order inputs for " << n << " cases:" << elapsed.count() << "s" << endl;

    inputs = decreasingOrderInputs(n);
    start = chrono::high_resolution_clock::now();
    heapSort(inputs);
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    cout << "Time taken by heapSort on decreasing order inputs for " << n << " cases:" << elapsed.count() << "s" << endl;

    inputs = randomOrderInputs(n);
    start = chrono::high_resolution_clock::now();
    heapSort(inputs);
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    cout << "Time taken by heapSort on random order inputs for " << n << " cases:" << elapsed.count() << "s" << endl;

    // Test insertionSort
    inputs = increasingOrderInputs(n);
    start = chrono::high_resolution_clock::now();
    insertionSort(inputs);
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    cout << "Time taken by insertionSort on increasing order inputs for " << n << " cases:" << elapsed.count() << "s" << endl;

    inputs = decreasingOrderInputs(n);
    start = chrono::high_resolution_clock::now();
    insertionSort(inputs);
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    cout << "Time taken by insertionSort on decreasing order inputsfor " << n << " cases:" << elapsed.count() << "s" << endl;

    inputs = randomOrderInputs(n);
    start = chrono::high_resolution_clock::now();
    insertionSort(inputs);
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    cout << "Time taken by insertionSort on random order inputs for " << n << " cases:" << elapsed.count() << "s" << endl;
    n = n + 10000;
    }
    return 0;
}
