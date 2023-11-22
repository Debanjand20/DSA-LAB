In order traversal of binary tree 
ALGORITHM:
1. Start at the root node of the binary tree.
2. If the current node is not NULL, do the following:
   - Recursively traverse the left subtree by calling the in-order traversal algorithm on the left child (current node->left).
   - Visit the current node by performing the desired operation (e.g., print its value).
   - Recursively traverse the right subtree by calling the in-order traversal algorithm on the right child (current node->right).
3. If the current node is NULL (reached a leaf or an empty subtree), return to the previous level of the recursion.
4. Continue the process until all nodes in the binary tree have been visited.

SOURCE CODE:
#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void inOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        // Traverse the left subtree
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        // Traverse the right subtree
        inOrderTraversal(root->right);
    }
}
int main() {
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    printf("In-order traversal of the binary tree: ");
    inOrderTraversal(root);    
    return 0;
}
OUTPUT:
In-order traversal of the binary tree: 4 2 5 1 3















PRE ORDER TRAVERSAL OF BINARY TREE

ALGORITHM:
•	Start at the root node of the binary tree.
•	If the current node is not NULL, do the following:
•	Visit the current node by performing the desired operation (e.g., print its value).
•	Recursively traverse the left subtree by calling the pre-order traversal algorithm on the left child (current_node->left).
•	Recursively traverse the right subtree by calling the pre-order traversal algorithm on the right child (current_node->right).
•	If the current node is NULL (reached a leaf or an empty subtree), return to the previous level of the recursion.
•	Continue the process until all nodes in the binary tree have been visited.

SOURCE CODE:
#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void preOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        // Visit the current node
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}
int main() {
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    printf("Pre-order traversal of the binary tree: ");
    preOrderTraversal(root);
    return 0;
}

OUTPUT:
Pre-order traversal of the binary tree: 1 2 4 5 3











POST ORDER TRAVERSAL OF BINARY TREE

ALGORITHM:
•	Start at the root node of the binary tree.
•	If the current node is not NULL, do the following:
•	Recursively traverse the left subtree by calling the post-order traversal algorithm on the left child (current_node->left).
•	Recursively traverse the right subtree by calling the post-order traversal algorithm on the right child (current_node->right).
•	Visit the current node by performing the desired operation (e.g., print its value).
•	If the current node is NULL (reached a leaf or an empty subtree), return to the previous level of the recursion.
•	Continue the process until all nodes in the binary tree have been visited.

SOURCE CODE:
#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void postOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}
int main() {
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);  
    printf("Post-order traversal of the binary tree: ");
    postOrderTraversal(root);
    return 0;
}

OUTPUT:
Post-order traversal of the binary tree: 4 5 2 3 1








1.	Implement a Binary Tree data structure in c that supports the following operations: a. Insertion of a new node. b. Deletion of a node. c. Search for a key in the tree. d. Finding the minimum and maximum elements in the tree.
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the Binary Search Tree
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node with a given key
struct Node *createNode(int key) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node with a given key into the BST
struct Node *insertNode(struct Node *root, int key) {
    if (root == NULL) {
        return createNode(key);
    }

    if (key < root->data) {
        root->left = insertNode(root->left, key);
    } else if (key > root->data) {
        root->right = insertNode(root->right, key);
    }

    return root;
}

// Function to find the minimum value node in the BST
struct Node *findMin(struct Node *node) {
    struct Node *current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a node with a given key from the BST
struct Node *deleteNode(struct Node *root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        struct Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to search for a key in the BST
struct Node *search(struct Node *root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }

    if (key < root->data) {
        return search(root->left, key);
    }
    return search(root->right, key);
}

// Function to find the minimum value in the BST
struct Node *findMinimum(struct Node *root) {
    if (root == NULL) {
        return NULL;
    }
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to find the maximum value in the BST
struct Node *findMaximum(struct Node *root) {
    if (root == NULL) {
        return NULL;
    }
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

// Function to free the memory allocated to the BST nodes
void freeTree(struct Node *root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    struct Node *root = NULL;

    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    printf("Binary Search Tree operations:\n");
    printf("Insertion completed.\n");

    struct Node *searchResult = search(root, 40);
    if (searchResult != NULL) {
        printf("Key 40 found in the tree.\n");
    } else {
        printf("Key 40 not found in the tree.\n");
    }

    struct Node *minNode = findMinimum(root);
    printf("Minimum element in the tree: %d\n", minNode->data);

    struct Node *maxNode = findMaximum(root);
    printf("Maximum element in the tree: %d\n", maxNode->data);

    root = deleteNode(root, 30);
    printf("Node with key 30 deleted.\n");

    freeTree(root); // Free memory allocated for the tree nodes

    return 0;
}

2.	Given two binary trees, check if they are structurally identical:
#include <stdio.h>
#include <stdbool.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

bool isIdentical(struct TreeNode* root1, struct TreeNode* root2) {
    if (root1 == NULL && root2 == NULL) {
        return true;
    }
    if (root1 == NULL || root2 == NULL) {
        return false;
    }
    return (root1->data == root2->data) &&
           isIdentical(root1->left, root2->left) &&
           isIdentical(root1->right, root2->right);
}

int main() {
    struct TreeNode* root1 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root1->data = 4;
    root1->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root1->left->data = 2;
    root1->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root1->right->data = 6;

    struct TreeNode* root2 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root2->data = 4;
    root2->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root2->left->data = 2;
    root2->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root2->right->data = 6;

    printf("Are the trees structurally identical? %s\n",
           isIdentical(root1, root2) ? "Yes" : "No");

    return 0;
}

3.	Given a sorted array, construct a Balanced Binary Search Tree (BST) from it:

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* sortedArrayToBST(int arr[], int start, int end) {
    if (start > end) {
        return NULL;
    }

    int mid = (start + end) / 2;
    struct TreeNode* root = createNode(arr[mid]);

    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);

    return root;
}

void inorderTraversal(struct TreeNode* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

int main() {
    int sortedArray[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(sortedArray) / sizeof(sortedArray[0]);

    struct TreeNode* root = sortedArrayToBST(sortedArray, 0, n - 1);

    printf("Inorder Traversal of Balanced BST: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}

4.	Write functions to calculate the height of the AVL tree and the balance factor of each node in the tree:

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    int height;
    struct TreeNode* left;
    struct TreeNode* right;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct TreeNode* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

int getBalance(struct TreeNode* node) {
    if (node == NULL) {
        return 0;
    }
    return height(node->left) - height(node->right);
}

struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->height = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* insert(struct TreeNode* node, int data) {
    if (node == NULL) {
        return createNode(data);
    }

    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    } else {
        return node; // Duplicate keys not allowed
    }

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && data < node->left->data) {
        // Right rotate
        return node;
    }

    // Right Right Case
    if (balance < -1 && data > node->right->data) {
        // Left rotate
        return node;
    }

    // Left Right Case
    if (balance > 1 && data > node->left->data) {
        // Left rotate on left child, then right rotate on current node
        return node;
    }

    // Right Left Case
    if (balance < -1 && data < node->right->data) {
        // Right rotate on right child, then left rotate on current node
        return node;
    }

    return node;
}

void inorderTraversal(struct TreeNode* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

int main() {
    struct TreeNode* root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);

    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}




5.	Implement a threaded binary search tree (TBST) data structure in c that supports insertion, deletion, in-order traversal, and finding the in-order successor and predecessor of a given node. Ensure the TBST maintains the binary search tree property and the threaded connections.
#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the threaded binary search tree
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    int isThreaded; // Flag to indicate if the right pointer is a thread
};

// Function to create a new node
struct Node *createNode(int key) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->left = newNode->right = NULL;
    newNode->isThreaded = 0;
    return newNode;
}

// Function to insert a node into the threaded binary search tree
struct Node *insertNode(struct Node *root, int key) {
    if (root == NULL) {
        return createNode(key);
    }

    if (key < root->data) {
        if (root->left == NULL) {
            struct Node *newNode = createNode(key);
            root->left = newNode;
            newNode->right = root;
            newNode->isThreaded = 1;
        } else {
            root->left = insertNode(root->left, key);
        }
    } else if (key > root->data) {
        if (root->isThreaded || root->right == NULL) {
            struct Node *newNode = createNode(key);
            newNode->right = root->right;
            root->right = newNode;
            root->isThreaded = 0;
            newNode->isThreaded = 1;
        } else {
            root->right = insertNode(root->right, key);
        }
    }
    return root;
}

// Function to find the in-order successor of a given node
struct Node *inOrderSuccessor(struct Node *node) {
    if (node->isThreaded) {
        return node->right;
    }

    node = node->right;
    while (node != NULL && node->left != NULL) {
        node = node->left;
    }
    return node;
}

// Function to find the in-order predecessor of a given node
struct Node *inOrderPredecessor(struct Node *node) {
    if (node->isThreaded) {
        return node->left;
    }

    node = node->left;
    while (node != NULL && !node->isThreaded) {
        node = node->right;
    }
    return node;
}

// Function for in-order traversal of the threaded binary search tree
void inOrderTraversal(struct Node *root) {
    struct Node *current = root;
    while (current != NULL) {
        while (current->left != NULL) {
            current = current->left;
        }
        printf("%d ", current->data);

        if (current->isThreaded) {
            current = current->right;
        } else {
            current = inOrderSuccessor(current);
        }
    }
}

// Function to free the memory allocated to the TBST nodes
void freeTree(struct Node *root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    if (!root->isThreaded) {
        freeTree(root->right);
    }
    free(root);
}

int main() {
    struct Node *root = NULL;

    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    printf("In-order traversal of the TBST: ");
    inOrderTraversal(root);
    printf("\n");

    struct Node *successor = inOrderSuccessor(root->left->left); // Finding successor of 20
    if (successor) {
        printf("In-order successor of 20: %d\n", successor->data);
    } else {
        printf("No in-order successor found.\n");
    }

    struct Node *predecessor = inOrderPredecessor(root->right->right); // Finding predecessor of 80
    if (predecessor) {
        printf("In-order predecessor of 80: %d\n", predecessor->data);
    } else {
        printf("No in-order predecessor found.\n");
    }

    freeTree(root); // Free memory allocated for the TBST nodes

    return 0;
}
