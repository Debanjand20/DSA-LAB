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

6.	Inventory Management System
ALGORITHM:
•	Initialization:
1.	Initialize a global array inventory of structures to store product information.
2.	Initialize a global variable numProducts to keep track of the number of products in the inventory.
•	Main Menu Loop:
1.	Enter a loop that displays the main menu for the inventory management system:
2.	Display the menu options: Add a product, Update product quantity, Find a product by ID, Calculate total inventory value, and Exit.
3.	Prompt the user to enter their choice.
•	Adding a Product:
1.	If the user chooses to "Add a product":
2.	Prompt the user to enter the product ID, name, price, and quantity.
3.	Create a new product structure with the entered information.
4.	Check if the inventory is not full (i.e., numProducts < MAX_PRODUCTS).
5.	If there's space in the inventory, add the new product to the inventory array and increment numProducts by 1.
6.	Display a success message if the product is added successfully, or an error message if the inventory is full.
•	Updating Product Quantity:
1.	If the user chooses to "Update product quantity":
2.	Prompt the user to enter the product ID they want to update and the new quantity.
3.	Iterate through the inventory array to find the product with the matching ID.
4.	If found, update the quantity of the product with the new quantity and display a success message.
5.	If not found, display an error message.
•	Finding a Product by ID:
1.	If the user chooses to "Find a product by ID":
2.	Prompt the user to enter the product ID they want to find.
3.	Iterate through the inventory array to find the product with the matching ID.
4.	If found, display the product details (ID, name, price, and quantity).
5.	If not found, display an error message.
•	Calculating Total Inventory Value:
1.	If the user chooses to "Calculate total inventory value":
2.	Iterate through the inventory array, calculating the total value as the sum of (price * quantity) for all products.
3.	Display the total inventory value.
•	Exiting the Program:
If the user chooses to "Exit," exit the program.
•	Error Handling:
Handle invalid user input by displaying an error message and asking the user to try again.
•	Repeat Menu:
After each operation (add, update, find, calculate, or error), display the menu options again, and repeat the loop until the user chooses to exit.
•	This algorithm outlines the logic and flow of the inventory management system code, covering adding, updating, finding, and calculating inventory value while providing error handling and a menu-driven interface.

SOURCE CODE:
#include <stdio.h>
#include <stdlib.h>
#define MAX_PRODUCTS 100
struct Product {
    int id;
    char name[100];
    float price;
    int quantity;
};
struct Product inventory[MAX_PRODUCTS];
int numProducts = 0;
void addProduct(int id, const char* name, float price, int quantity) {
    if (numProducts < MAX_PRODUCTS) {
        struct Product newProduct;
        newProduct.id = id;
        snprintf(newProduct.name, sizeof(newProduct.name), "%s", name);
        newProduct.price = price;
        newProduct.quantity = quantity;
        inventory[numProducts] = newProduct;
        numProducts++;
        printf("Product added successfully!\n");
    } else {
        printf("Inventory is full. Cannot add more products.\n");
    }
}
void updateProductQuantity(int id, int newQuantity) {
    for (int i = 0; i < numProducts; i++) {
        if (inventory[i].id == id) {
            inventory[i].quantity = newQuantity;
            printf("Quantity updated successfully!\n");
            return;
        }
    }
    printf("Product with ID %d not found in the inventory.\n", id);
}
struct Product findProductById(int id) {
    struct Product notFound;
    notFound.id = -1;

    for (int i = 0; i < numProducts; i++) {
        if (inventory[i].id == id) {
            return inventory[i];
        }
    }

    return notFound;
}
float calculateTotalValue() {
    float totalValue = 0;
    for (int i = 0; i < numProducts; i++) {
        totalValue += (inventory[i].price * inventory[i].quantity);
    }
    return totalValue;
}

int main() {
    int choice;
    int id, quantity;
    char name[100];
    float price;
    while (1) {
        printf("\nInventory Management System Menu:\n");
        printf("1. Add a product\n");
        printf("2. Update product quantity\n");
        printf("3. Find a product by ID\n");
        printf("4. Calculate total inventory value\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter product ID: ");
                scanf("%d", &id);
                printf("Enter product name: ");
                scanf("%s", name);
                printf("Enter product price: ");
                scanf("%f", &price);
                printf("Enter product quantity: ");
                scanf("%d", &quantity);
                addProduct(id, name, price, quantity);
                break;
            case 2:
                printf("Enter product ID to update quantity: ");
                scanf("%d", &id);
                printf("Enter new quantity: ");
                scanf("%d", &quantity);
                updateProductQuantity(id, quantity);
                break;
            case 3:
                printf("Enter product ID to find: ");
                scanf("%d", &id);
                struct Product foundProduct = findProductById(id);
                if (foundProduct.id != -1) {
                    printf("Product ID: %d\n", foundProduct.id);
                    printf("Product Name: %s\n", foundProduct.name);
                    printf("Product Price: %.2f\n", foundProduct.price);
                    printf("Product Quantity: %d\n", foundProduct.quantity);
                } else {
                    printf("Product not found in the inventory.\n");
                }
                break;
            case 4:
                printf("Total inventory value: $%.2f\n", calculateTotalValue());
                break;
            case 5:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

7.	wap in c to concatenate two arrays

#include <stdio.h>

// Function to concatenate two arrays
void concatenateArrays(int arr1[], int size1, int arr2[], int size2, int result[]) {
    int i, j;

    // Copy elements from the first array
    for (i = 0; i < size1; i++) {
        result[i] = arr1[i];
    }

    // Copy elements from the second array
    for (j = 0; j < size2; j++) {
        result[size1 + j] = arr2[j];
    }
}

// Function to display an array
void displayArray(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i != size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main() {
    int arr1[] = {1, 2, 3, 4};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {5, 6, 7};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    int resultSize = size1 + size2;
    int result[resultSize];

    concatenateArrays(arr1, size1, arr2, size2, result);

    printf("Array 1: ");
    displayArray(arr1, size1);

    printf("Array 2: ");
    displayArray(arr2, size2);

    printf("Concatenated Array: ");
    displayArray(result, resultSize);

    return 0;
}

8.	wap in c to find duplicate elements in an array
#include <stdio.h>

// Function to find duplicate elements in an array
void findDuplicates(int arr[], int size) {
    printf("Duplicate elements in the array: ");

    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                printf("%d ", arr[i]);
                break; // Break to avoid printing the same duplicate multiple times
            }
        }
    }
    printf("\n");
}

int main() {
    int arr[] = {2, 4, 6, 8, 2, 4, 7, 9, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    findDuplicates(arr, size);

    return 0;
}

9.	wap in c to print only unique elements in an array
#include <stdio.h>

// Function to check if an element is unique in the array
int isUnique(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            if (i != size - 1) {
                return 0; // Not unique
            }
        }
    }
    return 1; // Unique
}

// Function to print unique elements in the array
void printUniqueElements(int arr[], int size) {
    printf("Unique elements in the array: ");

    for (int i = 0; i < size; i++) {
        if (isUnique(arr, size, arr[i])) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

int main() {
    int arr[] = {2, 4, 6, 8, 2, 4, 7, 9, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printUniqueElements(arr, size);

    return 0;
}

10.	merge two arrays
#include <stdio.h>

// Function to merge two arrays
void mergeArrays(int arr1[], int size1, int arr2[], int size2, int result[]) {
    int i, j;

    // Copy elements from the first array
    for (i = 0; i < size1; i++) {
        result[i] = arr1[i];
    }

    // Copy elements from the second array
    for (j = 0; j < size2; j++) {
        result[size1 + j] = arr2[j];
    }
}

// Function to display an array
void displayArray(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i != size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main() {
    int arr1[] = {1, 2, 3, 4};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {5, 6, 7};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    int resultSize = size1 + size2;
    int result[resultSize];

    mergeArrays(arr1, size1, arr2, size2, result);

    printf("Array 1: ");
    displayArray(arr1, size1);

    printf("Array 2: ");
    displayArray(arr2, size2);

    printf("Merged Array: ");
    displayArray(result, resultSize);

    return 0;
}

11.	calculate the frequency of each element in an array
#include <stdio.h>

// Function to calculate frequency of each element in the array
void calculateFrequency(int arr[], int size) {
    int freq[size];
    int visited = -1;

    for (int i = 0; i < size; i++) {
        int count = 1;
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
                freq[j] = visited;
            }
        }
        if (freq[i] != visited) {
            freq[i] = count;
        }
    }

    printf("Element\tFrequency\n");
    for (int i = 0; i < size; i++) {
        if (freq[i] != -1) {
            printf("%d\t%d\n", arr[i], freq[i]);
        }
    }
}

int main() {
    int arr[] = {2, 4, 6, 8, 2, 4, 7, 9, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    calculateFrequency(arr, size);

    return 0;
}


