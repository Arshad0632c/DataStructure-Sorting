#include <iostream>
#include <vector>
using namespace std;

void InsertionSort(vector<int>& arr) {
    int size = arr.size(),  j;
    for (int i = 1; i < size; ++i) {
        int temp = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > temp; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = temp;
    }
}

void display(const vector<int>& arr) {
    for (int i=0; i<arr.size();i++)
        cout << arr[i] << " ";
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

    InsertionSort(arr);
    cout << "Sorted array: \n";
    display(arr);

    return 0;
}

