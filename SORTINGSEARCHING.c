             I      BUBBLE SORT
                    SOURCE CODE:
#include <stdio.h>
void bubbleSort(int array[], int size) {
  for (int step = 0; step < size - 1; ++step) {
    for (int i = 0; i < size - step - 1; ++i) {
      if (array[i] > array[i + 1]) {
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
      }
    }
  }
}
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}
int main() {
  int data[] = {-2, 45, 0, 11, -9};
  int size = sizeof(data) / sizeof(data[0]);
  bubbleSort(data, size);
  printf("Sorted Array in Ascending Order:\n");
  printArray(data, size);
}
OUTPUT:
Sorted Array in Ascending Order:
-9  -2  0  11  45


                  SELECTION SORT
                    SOURCE CODE:
#include <stdio.h>
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
void selectionSort(int array[], int size) {
  for (int step = 0; step < size - 1; step++) {
    int min_idx = step;
    for (int i = step + 1; i < size; i++) {
      if (array[i] < array[min_idx])
        min_idx = i;
    }
    swap(&array[min_idx], &array[step]);
  }
}
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

int main() {
  int data[] = {20, 12, 10, 15, 2};
  int size = sizeof(data) / sizeof(data[0]);
  selectionSort(data, size);
  printf("Sorted array in Acsending Order:\n");
  printArray(data, size);
}

OUPUT:
Sorted array in Acsending Order:
2  10  12  15  20  


INSERTION SORT

SOURCE CODE:

#include <stdio.h>
void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}
void insertionSort(int array[], int size) {
  for (int step = 1; step < size; step++) {
    int key = array[step];
    int j = step - 1;
    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
}
int main() {
  int data[] = {9, 5, 1, 4, 3};
  int size = sizeof(data) / sizeof(data[0]);
  insertionSort(data, size);
  printf("Sorted array in ascending order:\n");
  printArray(data, size);
}

OUTPUT:
Sorted array in ascending order:
1 3 4 5 9














QUICK SORT

SOURCE CODE:
#include <stdio.h>
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}
int partition(int array[], int low, int high) {
  int pivot = array[high];
  int i = (low - 1);
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}
void quickSort(int array[], int low, int high) {
  if (low < high) {
    int pi = partition(array, low, high);
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}
int main() {
  int data[] = {8, 7, 2, 1, 0, 9, 6};
  int n = sizeof(data) / sizeof(data[0]);
  printf("Unsorted Array\n");
  printArray(data, n);
  quickSort(data, 0, n - 1);
  printf("Sorted array in ascending order: \n");
  printArray(data, n);
}

OUTPUT:
Unsorted Array
8  7  2  1  0  9  6  
Sorted array in ascending order: 
0  1  2  6  7  8  9  











MERGE SORT

SOURCE CODE:

#include <stdio.h>
void merge(int arr[], int p, int q, int r) {

  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r) {
  if (l < r) {

    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Merge the sorted subarrays
    merge(arr, l, m, r);
  }
}

// Print the array
void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

// Driver program
int main() {
  int arr[] = {6, 5, 12, 10, 9, 1};
  int size = sizeof(arr) / sizeof(arr[0]);

  mergeSort(arr, 0, size - 1);

  printf("Sorted array: \n");
  printArray(arr, size);
}

OUTPUT:
Sorted array: 
1 5 6 9 10 12

Implement a linear search algorithm to find the position of a given element in an array. If the
element is present multiple times, the function should return the positions of all occurrences.
#include <stdio.h>

// Function to find all occurrences of a given element in an array
void linearSearch(int arr[], int size, int key) {
    int found = 0;

    printf("Positions of element %d in the array: ", key);
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            printf("%d ", i + 1);
            found = 1;
        }
    }

    if (!found) {
        printf("Element not found in the array.\n");
    } else {
        printf("\n");
    }
}

int main() {
    int arr[] = {3, 7, 2, 8, 3, 6, 3, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 3;

    printf("Original Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    linearSearch(arr, size, key);

    return 0;
}
Implement a binary search algorithm to find the position of a given element in a sorted array. If
the element is present multiple times, the function should return the position of any occurrence.
#include <stdio.h>

// Function to perform binary search in a sorted array
int binarySearch(int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid + 1; // Return position of any occurrence
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // Element not found
}

int main() {
    int arr[] = {2, 4, 6, 8, 8, 10, 12};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 8;

    printf("Sorted Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int position = binarySearch(arr, size, key);

    if (position != -1) {
        printf("Position of element %d in the array: %d\n", key, position);
    } else {
        printf("Element %d not found in the array.\n", key);
    }

    return 0;
}






You are given a 2D matrix sorted row-wise and column-wise. Implement a function to search for
a given element in the 2D array efficiently.
#include <stdio.h>

// Function to search for an element in a sorted row-wise and column-wise 2D matrix
int searchInMatrix(int matrix[3][3], int rows, int cols, int target) {
    int row = 0;
    int col = cols - 1; // Starting from the top-right corner

    while (row < rows && col >= 0) {
        if (matrix[row][col] == target) {
            return 1; // Element found
        } else if (matrix[row][col] > target) {
            col--; // Move left in the current row
        } else {
            row++; // Move down to the next row
        }
    }

    return 0; // Element not found
}

int main() {
    int matrix[3][3] = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}
    };
    int rows = 3;
    int cols = 3;
    int target = 5;

    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    if (searchInMatrix(matrix, rows, cols, target)) {
        printf("Element %d is present in the matrix.\n", target);
    } else {
        printf("Element %d is not present in the matrix.\n", target);
    }

    return 0;
}



Implement one or more other sorting algorithms, such as Bubble Sort, Insertion Sort, Merge
Sort, Selection Sort, Quick Sort and Radix sort. Write functions for each of these sorting
algorithms and measure their execution time using the same set of input arrays. Generate arrays
of random integers with varying lengths, starting from small arrays (e.g., 100 elements) up to
reasonably large arrays (e.g., 10,000 elements or more). Use a suitable method to record the
execution time for each input size.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Utility function to swap two elements in an array
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort algorithm
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Insertion Sort algorithm
void insertionSort(int arr[], int size) {
    int i, key, j;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Merge Sort algorithm
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

// Selection Sort algorithm
void selectionSort(int arr[], int size) {
    int i, j, min_idx;
    for (i = 0; i < size - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
    }
}

// Quick Sort algorithm
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Radix Sort algorithm
int getMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void countSort(int arr[], int size, int exp) {
    int output[size];
    int i, count[10] = {0};

    for (i = 0; i < size; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (i = size - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < size; i++) {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int size) {
    int m = getMax(arr, size);

    for (int exp = 1; m / exp > 0; exp *= 10) {
        countSort(arr, size, exp);
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL)); // Seed for random numbers
    clock_t start, end;
    double timeTaken;

    // Varying input array sizes
    for (int n = 100; n <= 10000; n *= 10) {
        int arr[n];

        // Generating random integers for the array
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 1000; // Random numbers between 0 to 999
        }

        printf("Array size: %d\n", n);

        // Bubble Sort
        int bubbleArr[n];
        for (int i = 0; i < n; i++) {
            bubbleArr[i] = arr[i];
        }
        start = clock();
        bubbleSort(bubbleArr, n);
        end = clock();
        timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Bubble Sort time taken: %f seconds\n", timeTaken);

        // Insertion Sort
        int insertionArr[n];
        for (int i = 0; i < n; i++) {
            insertionArr[i] = arr[i];
        }
        start = clock();
        insertionSort(insertionArr, n);
        end = clock();
        timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Insertion Sort time taken: %f seconds\n", timeTaken);

        // Merge Sort
        int mergeArr[n];
        for (int i = 0; i < n; i++) {
            mergeArr[i] = arr[i];
        }
        start = clock();
        mergeSort(mergeArr, 0, n - 1);
        end = clock();
        timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Merge Sort time taken: %f seconds\n", timeTaken);

        // Selection Sort
        int selectionArr[n];
        for (int i = 0; i < n; i++) {
            selectionArr[i] = arr[i];
        }
        start = clock();
        selectionSort(selectionArr, n);
        end = clock();
        timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Selection Sort time taken: %f seconds\n", timeTaken);

        // Quick Sort
        int quickArr[n];
        for (int i = 0; i < n; i++) {
            quickArr[i] = arr[i];
        }
        start = clock();
        quickSort(quickArr, 0, n - 1);
        end = clock();
        timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Quick Sort time taken: %f seconds\n", timeTaken);

        // Radix Sort
        int radixArr[n];
        for (int i = 0; i < n; i++) {
            radixArr[i] = arr[i];
        }
        start = clock();
        radixSort(radixArr, n);
        end = clock();
        timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Radix Sort time taken: %f seconds\n", timeTaken);

        printf("\n");
    }

    return 0;
}

Create a class representing a custom object (e.g., a Person with attributes like name, age, and
address). Implement a sorting algorithm that can sort a list of these custom objects based on
different attributes (e.g., sorting by name, age, or address). Test the sorting algorithm with a list
of objects and verify that the objects are sorted correctly.
#include <stdio.h>
#include <string.h>

// Person structure representing a custom object
typedef struct {
    char name[50];
    int age;
    char address[100];
} Person;

// Function to swap two Person objects
void swap(Person *a, Person *b) {
    Person temp = *a;
    *a = *b;
    *b = temp;
}

// Selection sort based on name
void sortByname(Person arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[j].name, arr[min_idx].name) < 0) {
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
    }
}

// Selection sort based on age
void sortByAge(Person arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].age < arr[min_idx].age) {
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
    }
}

// Selection sort based on address
void sortByAddress(Person arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[j].address, arr[min_idx].address) < 0) {
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
    }
}

// Function to print an array of Person objects
void printPeople(Person arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Name: %s, Age: %d, Address: %s\n", arr[i].name, arr[i].age, arr[i].address);
    }
}

int main() {
    // Creating a list of Person objects
    Person people[] = {
        {"Alice", 25, "123 Main St"},
        {"Bob", 30, "456 Elm St"},
        {"Charlie", 22, "789 Oak St"}
    };
    int n = sizeof(people) / sizeof(people[0]);

    printf("Original List:\n");
    printPeople(people, n);

    // Sort by name
    sortByname(people, n);
    printf("\nSorted List (by name):\n");
    printPeople(people, n);

    // Sort by age
    sortByAge(people, n);
    printf("\nSorted List (by age):\n");
    printPeople(people, n);

    // Sort by address
    sortByAddress(people, n);
    printf("\nSorted List (by address):\n");
    printPeople(people, n);

    return 0;
}
             I      BUBBLE SORT
                    SOURCE CODE:
#include <stdio.h>
void bubbleSort(int array[], int size) {
  for (int step = 0; step < size - 1; ++step) {
    for (int i = 0; i < size - step - 1; ++i) {
      if (array[i] > array[i + 1]) {
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
      }
    }
  }
}
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}
int main() {
  int data[] = {-2, 45, 0, 11, -9};
  int size = sizeof(data) / sizeof(data[0]);
  bubbleSort(data, size);
  printf("Sorted Array in Ascending Order:\n");
  printArray(data, size);
}
OUTPUT:
Sorted Array in Ascending Order:
-9  -2  0  11  45


                  SELECTION SORT
                    SOURCE CODE:
#include <stdio.h>
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
void selectionSort(int array[], int size) {
  for (int step = 0; step < size - 1; step++) {
    int min_idx = step;
    for (int i = step + 1; i < size; i++) {
      if (array[i] < array[min_idx])
        min_idx = i;
    }
    swap(&array[min_idx], &array[step]);
  }
}
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

int main() {
  int data[] = {20, 12, 10, 15, 2};
  int size = sizeof(data) / sizeof(data[0]);
  selectionSort(data, size);
  printf("Sorted array in Acsending Order:\n");
  printArray(data, size);
}

OUPUT:
Sorted array in Acsending Order:
2  10  12  15  20  


INSERTION SORT

SOURCE CODE:

#include <stdio.h>
void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}
void insertionSort(int array[], int size) {
  for (int step = 1; step < size; step++) {
    int key = array[step];
    int j = step - 1;
    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
}
int main() {
  int data[] = {9, 5, 1, 4, 3};
  int size = sizeof(data) / sizeof(data[0]);
  insertionSort(data, size);
  printf("Sorted array in ascending order:\n");
  printArray(data, size);
}

OUTPUT:
Sorted array in ascending order:
1 3 4 5 9














QUICK SORT

SOURCE CODE:
#include <stdio.h>
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}
int partition(int array[], int low, int high) {
  int pivot = array[high];
  int i = (low - 1);
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}
void quickSort(int array[], int low, int high) {
  if (low < high) {
    int pi = partition(array, low, high);
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}
int main() {
  int data[] = {8, 7, 2, 1, 0, 9, 6};
  int n = sizeof(data) / sizeof(data[0]);
  printf("Unsorted Array\n");
  printArray(data, n);
  quickSort(data, 0, n - 1);
  printf("Sorted array in ascending order: \n");
  printArray(data, n);
}

OUTPUT:
Unsorted Array
8  7  2  1  0  9  6  
Sorted array in ascending order: 
0  1  2  6  7  8  9  











MERGE SORT

SOURCE CODE:

#include <stdio.h>
void merge(int arr[], int p, int q, int r) {

  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r) {
  if (l < r) {

    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Merge the sorted subarrays
    merge(arr, l, m, r);
  }
}

// Print the array
void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

// Driver program
int main() {
  int arr[] = {6, 5, 12, 10, 9, 1};
  int size = sizeof(arr) / sizeof(arr[0]);

  mergeSort(arr, 0, size - 1);

  printf("Sorted array: \n");
  printArray(arr, size);
}

OUTPUT:
Sorted array: 
1 5 6 9 10 12

Implement a linear search algorithm to find the position of a given element in an array. If the
element is present multiple times, the function should return the positions of all occurrences.
#include <stdio.h>

// Function to find all occurrences of a given element in an array
void linearSearch(int arr[], int size, int key) {
    int found = 0;

    printf("Positions of element %d in the array: ", key);
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            printf("%d ", i + 1);
            found = 1;
        }
    }

    if (!found) {
        printf("Element not found in the array.\n");
    } else {
        printf("\n");
    }
}

int main() {
    int arr[] = {3, 7, 2, 8, 3, 6, 3, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 3;

    printf("Original Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    linearSearch(arr, size, key);

    return 0;
}
Implement a binary search algorithm to find the position of a given element in a sorted array. If
the element is present multiple times, the function should return the position of any occurrence.
#include <stdio.h>

// Function to perform binary search in a sorted array
int binarySearch(int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid + 1; // Return position of any occurrence
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // Element not found
}

int main() {
    int arr[] = {2, 4, 6, 8, 8, 10, 12};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 8;

    printf("Sorted Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int position = binarySearch(arr, size, key);

    if (position != -1) {
        printf("Position of element %d in the array: %d\n", key, position);
    } else {
        printf("Element %d not found in the array.\n", key);
    }

    return 0;
}






You are given a 2D matrix sorted row-wise and column-wise. Implement a function to search for
a given element in the 2D array efficiently.
#include <stdio.h>

// Function to search for an element in a sorted row-wise and column-wise 2D matrix
int searchInMatrix(int matrix[3][3], int rows, int cols, int target) {
    int row = 0;
    int col = cols - 1; // Starting from the top-right corner

    while (row < rows && col >= 0) {
        if (matrix[row][col] == target) {
            return 1; // Element found
        } else if (matrix[row][col] > target) {
            col--; // Move left in the current row
        } else {
            row++; // Move down to the next row
        }
    }

    return 0; // Element not found
}

int main() {
    int matrix[3][3] = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}
    };
    int rows = 3;
    int cols = 3;
    int target = 5;

    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    if (searchInMatrix(matrix, rows, cols, target)) {
        printf("Element %d is present in the matrix.\n", target);
    } else {
        printf("Element %d is not present in the matrix.\n", target);
    }

    return 0;
}



Implement one or more other sorting algorithms, such as Bubble Sort, Insertion Sort, Merge
Sort, Selection Sort, Quick Sort and Radix sort. Write functions for each of these sorting
algorithms and measure their execution time using the same set of input arrays. Generate arrays
of random integers with varying lengths, starting from small arrays (e.g., 100 elements) up to
reasonably large arrays (e.g., 10,000 elements or more). Use a suitable method to record the
execution time for each input size.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Utility function to swap two elements in an array
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort algorithm
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Insertion Sort algorithm
void insertionSort(int arr[], int size) {
    int i, key, j;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Merge Sort algorithm
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

// Selection Sort algorithm
void selectionSort(int arr[], int size) {
    int i, j, min_idx;
    for (i = 0; i < size - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
    }
}

// Quick Sort algorithm
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Radix Sort algorithm
int getMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void countSort(int arr[], int size, int exp) {
    int output[size];
    int i, count[10] = {0};

    for (i = 0; i < size; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (i = size - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < size; i++) {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int size) {
    int m = getMax(arr, size);

    for (int exp = 1; m / exp > 0; exp *= 10) {
        countSort(arr, size, exp);
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL)); // Seed for random numbers
    clock_t start, end;
    double timeTaken;

    // Varying input array sizes
    for (int n = 100; n <= 10000; n *= 10) {
        int arr[n];

        // Generating random integers for the array
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 1000; // Random numbers between 0 to 999
        }

        printf("Array size: %d\n", n);

        // Bubble Sort
        int bubbleArr[n];
        for (int i = 0; i < n; i++) {
            bubbleArr[i] = arr[i];
        }
        start = clock();
        bubbleSort(bubbleArr, n);
        end = clock();
        timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Bubble Sort time taken: %f seconds\n", timeTaken);

        // Insertion Sort
        int insertionArr[n];
        for (int i = 0; i < n; i++) {
            insertionArr[i] = arr[i];
        }
        start = clock();
        insertionSort(insertionArr, n);
        end = clock();
        timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Insertion Sort time taken: %f seconds\n", timeTaken);

        // Merge Sort
        int mergeArr[n];
        for (int i = 0; i < n; i++) {
            mergeArr[i] = arr[i];
        }
        start = clock();
        mergeSort(mergeArr, 0, n - 1);
        end = clock();
        timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Merge Sort time taken: %f seconds\n", timeTaken);

        // Selection Sort
        int selectionArr[n];
        for (int i = 0; i < n; i++) {
            selectionArr[i] = arr[i];
        }
        start = clock();
        selectionSort(selectionArr, n);
        end = clock();
        timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Selection Sort time taken: %f seconds\n", timeTaken);

        // Quick Sort
        int quickArr[n];
        for (int i = 0; i < n; i++) {
            quickArr[i] = arr[i];
        }
        start = clock();
        quickSort(quickArr, 0, n - 1);
        end = clock();
        timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Quick Sort time taken: %f seconds\n", timeTaken);

        // Radix Sort
        int radixArr[n];
        for (int i = 0; i < n; i++) {
            radixArr[i] = arr[i];
        }
        start = clock();
        radixSort(radixArr, n);
        end = clock();
        timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Radix Sort time taken: %f seconds\n", timeTaken);

        printf("\n");
    }

    return 0;
}

Create a class representing a custom object (e.g., a Person with attributes like name, age, and
address). Implement a sorting algorithm that can sort a list of these custom objects based on
different attributes (e.g., sorting by name, age, or address). Test the sorting algorithm with a list
of objects and verify that the objects are sorted correctly.
#include <stdio.h>
#include <string.h>

// Person structure representing a custom object
typedef struct {
    char name[50];
    int age;
    char address[100];
} Person;

// Function to swap two Person objects
void swap(Person *a, Person *b) {
    Person temp = *a;
    *a = *b;
    *b = temp;
}

// Selection sort based on name
void sortByname(Person arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[j].name, arr[min_idx].name) < 0) {
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
    }
}

// Selection sort based on age
void sortByAge(Person arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].age < arr[min_idx].age) {
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
    }
}

// Selection sort based on address
void sortByAddress(Person arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[j].address, arr[min_idx].address) < 0) {
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
    }
}

// Function to print an array of Person objects
void printPeople(Person arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Name: %s, Age: %d, Address: %s\n", arr[i].name, arr[i].age, arr[i].address);
    }
}

int main() {
    // Creating a list of Person objects
    Person people[] = {
        {"Alice", 25, "123 Main St"},
        {"Bob", 30, "456 Elm St"},
        {"Charlie", 22, "789 Oak St"}
    };
    int n = sizeof(people) / sizeof(people[0]);

    printf("Original List:\n");
    printPeople(people, n);

    // Sort by name
    sortByname(people, n);
    printf("\nSorted List (by name):\n");
    printPeople(people, n);

    // Sort by age
    sortByAge(people, n);
    printf("\nSorted List (by age):\n");
    printPeople(people, n);

    // Sort by address
    sortByAddress(people, n);
    printf("\nSorted List (by address):\n");
    printPeople(people, n);

    return 0;
}
