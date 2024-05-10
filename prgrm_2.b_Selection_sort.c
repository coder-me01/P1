#include <stdio.h> 
void selectionSort(int arr[], int n) { 
  int i, j, maxIndex; 
  for (i = 0; i < n - 1; i++) { 
    maxIndex = i; 
    for (j = i + 1; j < n; j++) { 
      if (arr[j] > arr[maxIndex]) { 
        maxIndex = j; 
      } 
    } 
 
    int temp = arr[i]; 
    arr[i] = arr[maxIndex]; 
    arr[maxIndex] = temp; 
  } 
} 
 
void printArray(int arr[], int n) { 
  for (int i = 0; i < n; i++) { 
    printf("%d ", arr[i]); 
  } 
  printf("\n"); 
} 
 
int main() { 
  int arr[] = {45,89,44,11,1,2,4}; 
int n = sizeof(arr) / sizeof(arr[0]); 
selectionSort(arr, n); 
printf("Sorted array in descending order: "); 
printArray(arr, n); 
return 0; 
} 
