#include <iostream>
using namespace std;

void quicksort(int arr[], int low, int high) {
    int i, j, pivot, temp;
    if (low < high) {
        pivot = low;
        i = low + 1;
        j = high;
        while (i < j) {
            while (arr[i] <= arr[pivot] && i < high)
                i++;
            while (arr[j] > arr[pivot] && j > low)
                j--;
            if (i < j) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        temp = arr[pivot];
        arr[pivot] = arr[j];
        arr[j] = temp;
        quicksort(arr, low, j - 1);
        quicksort(arr, j + 1, high);
    }
}

int main() {
    int i, count, arr[25];
    cout << "Number of elements in the array: ";
    cin >> count;

    cout << "Enter " << count << " elements: ";
    for (i = 0; i < count; i++) {
        cin >> arr[i];
    }

    quicksort(arr, 0, count - 1);

    cout << "Order of Sorted elements: ";
    for (i = 0; i < count; i++) {
        cout << " " << arr[i];
    }

    return 0;
}

