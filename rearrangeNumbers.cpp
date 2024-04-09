#include <bits/stdc++.h>
using namespace std;

void rearrangePositiveEvenNegativeOdd(int arr[], int size);
void swapIntegers(int *a, int *b);
void printArray(int arr[], int size);

void rearrangePositiveEvenNegativeOdd(int arr[], int size) {
    int negativePartitionIndex = -1;
    for (int index = 0; index < size; ++index) {
        if (arr[index] < 0) {
            negativePartitionIndex++;
            swapIntegers(&arr[negativePartitionIndex], &arr[index]);
        }
    }
    
    int positiveStartIndex = negativePartitionIndex + 1;
    int negativeIndex = 0;
    while (positiveStartIndex < size && negativeIndex < positiveStartIndex && arr[negativeIndex] < 0) {
        swapIntegers(&arr[negativeIndex], &arr[positiveStartIndex]);
        positiveStartIndex++;
        negativeIndex += 2;
    }
}

void swapIntegers(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int size) {
    for (int index = 0; index < size; ++index) {
        std::cout << arr[index] << " ";
    }
}

int main() {
   	int n;
   	cin>>n;
   	int arr[n];
    for(int i = 0;i<n;i++){
    	cin>>arr[i];
    }
    rearrangePositiveEvenNegativeOdd(arr, n);
    printArray(arr, n);
    return 0;
}


//time complexity of the code is O(n)
//space complexity of the code is O(1)

//possible test case
//input : [3 1 2 4 6 8 8 1]
//output: [3 1 2 4 6 8 8 1 ]

//possible test case
//input : [-1 2 -3 4 5 6 -7 8 9]
//output : [4 -3 5 -1 6 -7 2 8 9 ]
