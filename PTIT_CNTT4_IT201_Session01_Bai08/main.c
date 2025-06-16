#include <stdio.h>
//do phuc tap la O(n) ,bi gioi han ve bo nho
int findMostNumber(int arr[], int n) {
    int count[1000] = {0};  
    int maxFreq = 0;
    int mostFreqVal = arr[0];

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
        if (count[arr[i]] > maxFreq) {
            maxFreq = count[arr[i]];
            mostFreqVal = arr[i];
        }
    }

    return mostFreqVal;
}

int main() {
    int arr[] = {1, 2, 3, 2, 4, 2, 5, 6, 2, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = findMostFrequent(arr, n);
    printf("Phần tử xuất hiện nhiều nhất là: %d\n", result);

    return 0;
}
