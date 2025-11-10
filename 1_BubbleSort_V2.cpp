#include <iostream>
#include <vector>
using namespace std;

void BubbleSort(vector<int>& arr) {
    int size = arr.size();
    for (int i = 0; i < size - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; // Exit early if no swaps were made
    }
}

void display(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

int main() {
    int size;
    cout << "Enter the size of array: ";
    cin >> size;

    vector<int> arr(size);
    cout << "Enter the array elements: ";
    for (int i = 0; i < size; ++i)
        cin >> arr[i];

    BubbleSort(arr);
    cout << "Sorted array: \n";
    display(arr);

    return 0;
}

