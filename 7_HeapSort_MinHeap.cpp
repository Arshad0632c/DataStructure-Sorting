#include <iostream>
#include <vector>
using namespace std;

void printArray(const vector<int>& hT);
void minHeapify(vector<int> &hT, int heapSize, int i);
void minHeapSort(vector<int> &hT);
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

    minHeapSort(heapTree);

    cout << "Sorted array (Min Heap - Descending): ";
    printArray(heapTree);

    return 0;
}

// Heapify a subtree rooted at index i to maintain Min Heap property
void minHeapify(vector<int> &hT, int heapSize, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < heapSize && hT[l] < hT[smallest])
        smallest = l;

    if (r < heapSize && hT[r] < hT[smallest])
        smallest = r;

    if (smallest != i) {
        swap(hT[i], hT[smallest]);
        minHeapify(hT, heapSize, smallest);
    }
}

// Perform Min Heap Sort (results in descending order)
void minHeapSort(vector<int> &hT) {
    int n = hT.size();

    // Build min heap
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(hT, n, i);

    // Extract elements from heap
    for (int i = n - 1; i > 0; i--) {
        swap(hT[0], hT[i]);      // Move smallest to the end
        minHeapify(hT, i, 0);    // Heapify the reduced heap
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
