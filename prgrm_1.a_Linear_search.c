#include <stdio.h> 
int linearSearch(int a[], int size, int key) { 
  for (int i=0; i < size; i++) { 
    if (a[i] == key) { 
      return i; 
   } 
  } 
  return -1; 
} 
int main()  
{ 
  int a[] = {2,4,6,9,21,89}; 
  int size = sizeof(a) / sizeof(a[0]); 
  int key = 21; 
 
  int result = linearSearch(a, size, key); 
  if (result == -1) { 
     printf("Element not found.\n"); 
  }  
else 
 { 
     printf("Element found at index %d.\n", result); 
  } 
  return 0; 
}
