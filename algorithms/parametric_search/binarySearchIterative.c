#include <stdio.h>
#define MAX 100000

int binarySearch(int arr[], int low, int high, int value) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == value) 
            return mid;
        else if (arr[mid] > value) 
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[MAX];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d", binarySearch(arr, 0, n - 1, k));

    return 0;
}