#include <iostream>
#include <vector>
using namespace std;

void printArray(const vector<int>& hT);
void heapify(vector<int> &hT, int heapSize, int i);
void heapSort(vector<int> &hT);
void swap(int &a, int &b);

int main() {
    vector<int> heapTree;
    int n, ele;
    cout << "Enter the count of elements: ";
    cin >> n;
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> ele;
        heapTree.push_back(ele);
    }
    cout << "Original array: ";
    printArray(heapTree);
    heapSort(heapTree);
    cout << "Sorted array (Heap Sort): ";
    printArray(heapTree);
    return 0;
}

// Heapify a subtree rooted at index i in a heap of size heapSize
void heapify(vector<int> &hT, int heapSize, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < heapSize && hT[l] > hT[largest])
        largest = l;

    if (r < heapSize && hT[r] > hT[largest])
        largest = r;

    if (largest != i) {
        swap(hT[i], hT[largest]);
        heapify(hT, heapSize, largest);
    }
}

// Perform Heap Sort
void heapSort(vector<int> &hT) {
    int n = hT.size();
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(hT, n, i);
    // Extract elements one by one from the heap
    for (int i = n - 1; i > 0; i--) {
        swap(hT[0], hT[i]); // Move current root to end
        heapify(hT, i, 0);  // Heapify reduced heap
    }
}

// Swap two integers
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Print elements of the array
void printArray(const vector<int>& hT) {
    for (int i=0; i<hT.size();i++)
        cout << hT[i] << " ";
    cout << "\n";
}

