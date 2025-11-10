#include <iostream>
#include <vector>
using namespace std;

void display(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

void SelectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < n; ++j)
            if (arr[j] < arr[min])
                min = j;

        cout << "Min = " << arr[min] << endl;
        display(arr);

        swap(arr[i], arr[min]);
    }
}

int main() {
    int size;
    cout << "Enter the size of array: ";
    cin >> size;

    vector<int> arr(size);
    cout << "Enter the array elements: ";
    for (int i = 0; i < size; ++i)
        cin >> arr[i];

    SelectionSort(arr);

    cout << "Sorted array: \n";
    display(arr);

    return 0;
}
