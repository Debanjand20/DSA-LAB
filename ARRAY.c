1.	You are given two sorted arrays, arr1 and arr2, each of size m and n, respectively. Design a
function to merge these two arrays into a single sorted array without using extra space.
#include <stdio.h>

void mergeSortedArrays(int arr1[], int m, int arr2[], int n) {
    int i = m - 1;
    int j = n - 1;
    int mergedIndex = m + n - 1;
    
    while (i >= 0 && j >= 0) {
        if (arr1[i] >= arr2[j]) {
            arr1[mergedIndex] = arr1[i];
            i--;
        } else {
            arr1[mergedIndex] = arr2[j];
            j--;
        }
        mergedIndex--;
    }
    
    // If there are remaining elements in arr2, copy them to arr1
    while (j >= 0) {
        arr1[mergedIndex] = arr2[j];
        j--;
        mergedIndex--;
    }
}

int main() {
    int arr1[8] = {1, 3, 5, 7};
    int arr2[4] = {2, 4, 6, 8};
    
    mergeSortedArrays(arr1, 4, arr2, 4);
    
    printf("Merged Array: ");
    for (int i = 0; i < 8; i++) {
        printf("%d ", arr1[i]);
    }
    
    return 0;
}

2.	You are given an array containing n-1 unique integers in the range of 1 to n. One integer is
missing from the array. Design a function to find the missing number.

#include <stdio.h>

int findMissingNumber(int arr[], int n) {
    int expectedSum = n * (n + 1) / 2;
    int actualSum = 0;
    
    for (int i = 0; i < n - 1; i++) {
        actualSum += arr[i];
    }
    
    return expectedSum - actualSum;
}

int main() {
    int arr[] = {1, 2, 4, 5, 6}; // One number missing in the range 1 to 6
    int n = sizeof(arr) / sizeof(arr[0]) + 1; // n is one more than the array size
    
    int missingNumber = findMissingNumber(arr, n);
    printf("Missing Number: %d\n", missingNumber);
    
    return 0;
}

3.	Implement a program that allows the user to perform various operations on an array:
a. Create an array of size n and populate it with elements.
b. Insert an element at a specified position in the array.
c. Delete an element from a specified position in the array.
d. Search for an element in the array and return its index.
e. Find the maximum and minimum elements in the array.
f. Display the array.

#include <stdio.h>

// Function to create an array and populate it with elements
void createArray(int arr[], int n) {
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

// Function to insert an element at a specified position in the array
void insertElement(int arr[], int *n, int position, int value) {
    if (position < 0 || position > *n) {
        printf("Invalid position for insertion.\n");
        return;
    }
    for (int i = *n; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = value;
    (*n)++;
}

// Function to delete an element from a specified position in the array
void deleteElement(int arr[], int *n, int position) {
    if (position < 0 || position >= *n) {
        printf("Invalid position for deletion.\n");
        return;
    }
    for (int i = position; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

// Function to search for an element in the array and return its index
int searchElement(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1; // Not found
}

// Function to find the maximum element in the array
int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to find the minimum element in the array
int findMin(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// Function to display the array
void displayArray(int arr[], int n) {
    printf("Array Elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100]; // Assuming maximum array size of 100
    int n = 0;    // Initial array size
    
    int choice;
    do {
        printf("\nArray Operations:\n");
        printf("1. Create array\n");
        printf("2. Insert element\n");
        printf("3. Delete element\n");
        printf("4. Search element\n");
        printf("5. Find max element\n");
        printf("6. Find min element\n");
        printf("7. Display array\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter array size: ");
                scanf("%d", &n);
                createArray(arr, n);
                break;
            case 2:
                if (n == 0) {
                    printf("Create array first.\n");
                } else {
                    int position, value;
                    printf("Enter position and value to insert: ");
                    scanf("%d %d", &position, &value);
                    insertElement(arr, &n, position, value);
                }
                break;
            case 3:
                if (n == 0) {
                    printf("Create array first.\n");
                } else {
                    int position;
                    printf("Enter position to delete: ");
                    scanf("%d", &position);
                    deleteElement(arr, &n, position);
                }
                break;
            case 4:
                if (n == 0) {
                    printf("Create array first.\n");
                } else {
                    int target;
                    printf("Enter element to search: ");
                    scanf("%d", &target);
                    int index = searchElement(arr, n, target);
                    if (index != -1) {
                        printf("Element found at index %d.\n", index);
                    } else {
                        printf("Element not found.\n");
                    }
                }
                break;
            case 5:
                if (n == 0) {
                    printf("Create array first.\n");
                } else {
                    int max = findMax(arr, n);
                    printf("Maximum element: %d\n", max);
                }
                break;
            case 6:
                if (n == 0) {
                    printf("Create array first.\n");
                } else {
                    int min = findMin(arr, n);
                    printf("Minimum element: %d\n", min);
                }
                break;
            case 7:
                if (n == 0) {
                    printf("Create array first.\n");
                } else {
                    displayArray(arr, n);
                }
                break;
            case 0:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 0);
    
    return 0;
}

4.	Given an array of integers, design a program to find if there exists a subarray with a given sum.
If such a subarray exists, print the starting and ending indices of the subarray. If multiple
subarrays with the same sum exist, display any one of them.
#include <stdio.h>

void findSubarrayWithSum(int arr[], int n, int targetSum) {
    int start = 0;
    int end = 0;
    int currentSum = arr[0];
    
    while (end < n) {
        if (currentSum == targetSum) {
            printf("Subarray with sum %d found between indices %d and %d.\n", targetSum, start, end);
            return;
        }
        if (currentSum < targetSum) {
            end++;
            if (end < n) {
                currentSum += arr[end];
            }
        } else {
            currentSum -= arr[start];
            start++;
        }
    }
    
    printf("No subarray found with sum %d.\n", targetSum);
}

int main() {
    int arr[] = {1, 4, 20, 3, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int targetSum = 33;
    
    findSubarrayWithSum(arr, n, targetSum);
    
    return 0;
}

5.	Given an array of integers, write a program to rearrange the elements such that all positive
numbers come before negative numbers while maintaining the relative order of positive and
negative numbers in the original array.
#include <stdio.h>

void rearrangePositiveNegative(int arr[], int n) {
    int pos = 0;
    int neg = 1;
    
    while (pos < n && neg < n) {
        if (arr[pos] < 0 && arr[neg] >= 0) {
            int temp = arr[pos];
            arr[pos] = arr[neg];
            arr[neg] = temp;
            pos += 2;
            neg += 2;
        }
        if (arr[pos] >= 0) {
            pos += 2;
        }
        if (arr[neg] < 0) {
            neg += 2;
        }
    }
}

int main() {
    int arr[] = {-1, 2, -3, 4, 5, 6, -7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    rearrangePositiveNegative(arr, n);
    
    printf("Rearranged Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
