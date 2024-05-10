#include <stdio.h>  
int binary_search(int arr[], int l, int r, int ele) {  
while (l <= r) {  
int mid = l + (r - l) / 2;  
if (arr[mid] == ele) {  
return mid;  
} else if (arr[mid] < ele) {  
l = mid + 1;  
}  
else 
{  
r = mid - 1;  
} } 
return -1;  
}  
int main() {  
int arr[] = {2,4,6,8,10};  
int n= sizeof(arr) / sizeof(arr[0]);  
int ele = 8;  
int index = binary_search(arr, 0, n - 1, ele);  
if (index == -1) {  
printf("element not found\n");  
} else 
{  
printf("element found at index %d\n", index);  
}  
return 0; } 
