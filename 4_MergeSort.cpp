#include <iostream>
#include <cstdio>
using namespace std;

void merge(int a[], int low, int mid, int high) {
    int i, k, m, l, temp[50];
    l = low;
    i = low;
    m = mid + 1;
    
    while ((l <= mid) && (m <= high)) {
        if (a[l] <= a[m])
            temp[i++] = a[l++];
        else  // a[l] > a[m]
            temp[i++] = a[m++];
    }

    while (l <= mid)
        temp[i++] = a[l++];
    
    while (m <= high)
        temp[i++] = a[m++];

    for (k = low; k <= high; k++)
        a[k] = temp[k];
}

void partition(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        partition(arr, low, mid);
        partition(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void printArray(int A[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main() {
    int i, arr[20], n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    printf("Enter the array elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Given array is \n");
    printArray(arr, n);

    partition(arr, 0, n - 1);

    printf("\nSorted array is \n");
    printArray(arr, n);

    return 0;
}

