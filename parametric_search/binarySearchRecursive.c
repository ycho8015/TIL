#include <stdio.h>
#define MAX 100000

int binarySearch(int arr[], int low, int high, int value) {
    if (low > high) 
        return -1;
    
    int mid = low + (high - low) / 2;
    if (arr[mid] == value)
        return mid;
    else if (arr[mid] > value)
        return binarySearch(arr, low, mid - 1, value);
    else
        return binarySearch(arr, mid + 1, high, value);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    int arr[MAX];
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int num;
    for (i = 0; i < k; i++) {
        scanf("%d", &num);
        printf("%d\n", binarySearch(arr, 0, n - 1, num));
    }
    
    return 0;
}