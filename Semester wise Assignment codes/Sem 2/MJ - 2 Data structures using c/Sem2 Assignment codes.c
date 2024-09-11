// Semester 1 Programs

// 1. Program to implement stack using arrays:

#include <stdio.h>

#define MAX_SIZE 100

int top = -1;
int stack[MAX_SIZE];

void push(int element) {
    if (top == MAX_SIZE - 1) {
        printf("Stack is full. Cannot push %d.\n", element);
        return;
    }
    stack[++top] = element;
}

int pop() {
    if (top == -1) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
    return stack[top--];
}

void display() {
    int i;
    for (i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    display(); // Output: 10 20 30
    printf("Popped element: %d\n", pop()); // Output: 30
    display(); // Output: 10 20
    return 0;
}


// 2. Program to convert infix notation to postfix notation using stacks:

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char element) {
    stack[++top] = element;
}

char pop() {
    return stack[top--];
}

int precedence(char operator) {
    if (operator == '+' || operator == '-')
        return 1;
    else if (operator == '*' || operator == '/')
        return 2;
    else
        return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    for (i = 0; i < strlen(infix); i++) {
        if (infix[i] == ' ') continue;
        else if (infix[i] == '(') push(infix[i]);
        else if (infix[i] == ')') {
            while (stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop(); // Remove '('
        } else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/') {
            while (top != -1 && stack[top] != '(' && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i]);
        } else {
            postfix[j++] = infix[i];
        }
    }
    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int main() {
    char infix[] = "A+B*C";
    char postfix[MAX_SIZE];
    infixToPostfix(infix, postfix);
    printf("Postfix notation: %s\n", postfix); // Output: ABC*+
    return 0;
}


// 3. Program to implement queue using arrays:

#include <stdio.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(int element) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue is full. Cannot enqueue %d.\n", element);
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = element;
}

int dequeue() {
    if (front == -1) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int element = queue[front++];
    if (front > rear) front = rear = -1;
    return element;
}

void display() {
    int i;
    for (i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display(); // Output: 10 20 30
    printf("Dequeued element: %d\n", dequeue()); // Output: 10
    display(); // Output: 20 30
    return 0;
}


// 4. Program to implement circular queue using arrays:

#include <stdio.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = 0, rear = 0;

void enqueue(int element) {
    if ((rear + 1) % MAX_SIZE == front) {
        printf("Queue is full. Cannot enqueue %d.\n", element);
        return;
    }
    queue[rear] = element;
    rear = (rear + 1) % MAX_SIZE;


int dequeue() {
    if (front == rear) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int element = queue[front];
    front = (front + 1) % MAX_SIZE;
    return element;
}

void display() {
    int i;
    if (front <= rear) {
        for (i = front; i < rear; i++) {
            printf("%d ", queue[i]);
        }
    } else {
        for (i = front; i < MAX_SIZE; i++) {
            printf("%d ", queue[i]);
        }
        for (i = 0; i < rear; i++) {
            printf("%d ", queue[i]);
        }
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display(); // Output: 10 20 30
    printf("Dequeued element: %d\n", dequeue()); // Output: 10
    display(); // Output: 20 30
    return 0;
}


// 5. Program to create, add, remove & display element from single linked list:

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

void createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void display() {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void addNode(int data) {
    createNode(data);
}

void removeNode(int data) {
    if (head == NULL) return;
    if (head->data == data) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        if (temp->next->data == data) {
            Node* nodeToRemove = temp->next;
            temp->next = temp->next->next;
            free(nodeToRemove);
            return;
        }
        temp = temp->next;
    }
}

int main() {
    addNode(10);
    addNode(20);
    addNode(30);
    display(); // Output: 10 20 30
    removeNode(20);
    display(); // Output: 10 30
    return 0;
}


// 6. Program to count number of nodes in linear linked list:

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

void createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int countNodes() {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    createNode(10);
    createNode(20);
    createNode(30);
    printf("Number of nodes: %d\n", countNodes()); // Output: 3
    return 0;
}



// 7. Program to accept a singly linked list of integers & sort the list in ascending order:

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

void createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void sortList() {
    Node* temp = head;
    while (temp != NULL) {
        Node* innerTemp = temp->next;
        
        while (innerTemp != NULL) {
            if (temp->data > innerTemp->data) {
                int tempData = temp->data;
                temp->data = innerTemp->data;
                innerTemp->data = tempData;
            }
            innerTemp = innerTemp->next;
        }
        temp = temp->next;
    }
}

void display() {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    createNode(30);
    createNode(10);
    createNode(20);
    printf("Before sorting: ");
    display(); // Output: 30 10 20
    sortList();
    printf("After sorting: ");
    display(); // Output: 10 20 30
    return 0;
}


// 8. Program to represent polynomial using linked list:

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
} Node;

Node* head = NULL;

void createNode(int coefficient, int exponent) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void display() {
    Node* temp = head;
    while (temp != NULL) {
        printf("%dx^%d + ", temp->coefficient, temp->exponent);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    createNode(3, 2);
    createNode(2, 1);
    createNode(1, 0);
    display(); // Output: 3x^2 + 2x^1 + 1x^0 +
    return 0;
}


// 9. Program for the creation of binary tree, provide insertion & deletion in c:

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* root = NULL;

void createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    if (root == NULL) {
        root = newNode;
    } else {
        Node* temp = root;
        while (1) {
            if (data < temp->data) {
                if (temp->left == NULL) {
                    temp->left = newNode;
                    break;
                }
                temp = temp->left;
            } else {
                if (temp->right == NULL) {
                    temp->right = newNode;
                    break;
                }
                temp = temp->right;
            }
        }
    }
}

void inorderTraversal(Node* node) {
    if (node != NULL) {
        inorderTraversal(node->left);
        printf("%d ", node->data);
        inorderTraversal(node->right);
    }
}

void deleteNode(int data) {
    Node* temp = root;
    Node* parent = NULL;
    while (temp != NULL) {
        if (temp->data == data) {
            if (temp->left == NULL && temp->right == NULL) {
                if (parent == NULL) {
                    root = NULL;
                } else {
                    if (parent->left == temp) {
                        parent->left = NULL;
                    } else {
                        parent->right = NULL;
                    }
                }
            } else if (temp->left == NULL) {
                if (parent == NULL) {
                    root = temp->right;
                } else {
                    if (parent->left == temp) {
                        parent->left = temp->right;
                    } else {
                        parent->right = temp->right;
                    }
                }
            } else if (temp->right == NULL) {
                if (parent == NULL) {
                    root = temp->left;
                } else {
                    if (parent->left == temp) {
                        parent->left = temp->left;
                    } else {
                        parent->right = temp->left;
                    }
                }
            } else {
                Node* successor = temp->right;
                while (successor->left != NULL) {
                    successor = successor->left;
                }
                temp->data = successor->data;
                deleteNode(successor->data);
            }
            free(temp);
            return;
        }
        if (data < temp->data) {
            parent = temp;
            temp = temp->left;
        } else {
            parent = temp;
            temp = temp->right;
        }
    }
}

int main() {
    createNode(50);
    createNode(30);
    createNode(20);
    createNode(40);
    createNode(70);
    createNode(60);
    createNode(80);
    printf("Inorder traversal: ");
    inorderTraversal(root); // Output: 20 30 40 50 60 70 80
    deleteNode(20);
    printf("Inorder traversal after deletion: ");
    inorderTraversal(root); // Output: 30 40 50 60 70 80
    return 0;
}



// 10. Program to implement a stack using linked list:

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* top = NULL;

void push(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

int pop() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    int data = top->data;
    Node* temp = top;
    top = top->next;
    free(temp);
    return data;
}

void display() {
    Node* temp = top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    display(); // Output: 30 20 10
    printf("Popped element: %d\n", pop()); // Output: 30
    display(); // Output: 20 10
    return 0;
}


// 11. Program to implement a queue using linked list:

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;

void enqueue(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (front == NULL) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

int dequeue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    int data = front->data;
    Node* temp = front;
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }
    free(temp);
    return data;
}

void display() {
    Node* temp = front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display(); // Output: 10 20 30
    printf("Dequeued element: %d\n", dequeue()); // Output: 10
    display(); // Output: 20 30
    return 0;
}


// 12. Program to implement a graph using adjacency list:

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node** adjList;
} Graph;

Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjList = (Node**) malloc(numVertices * sizeof(Node*));
    for (int i = 0; i < numVertices; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = dest;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = (Node*) malloc(sizeof(Node));
    newNode->data = src;
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

void displayGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjList[i];
        printf("Adjacency list of vertex %d: ", i);
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    Graph* graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    displayGraph(graph);
    return 0;
}


// 13. Program to implement a hash table:

#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

Node* table[TABLE_SIZE];

void initTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = NULL;
    }
}

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insert(int key, int value) {
    int index = hashFunction(key);
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = table[index];
    table[index] = newNode;
}

int search(int key) {
    int index = hashFunction(key);
    Node* temp = table[index];
    while (temp != NULL) {
        if (temp->key == key) {
            return temp->value;
        }
        temp = temp->next;
    }
    return -1;
}

void displayTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* temp = table[i];
        printf("Bucket %d: ", i);
        while (temp != NULL) {
            printf("(%d, %d) ", temp->key, temp->value);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    initTable();
    insert(5, 10);
    insert(15, 20);
    insert(25, 30);
    displayTable();
    printf("Value for key 15: %d\n", search(15));
    return 0;
}


// 14. Program to implement a sorting algorithm (Bubble Sort):

#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: ");
    printArray(arr, n);
    bubbleSort(arr, n);
    printf("Sorted array: ");
    printArray(arr, n);
    return 0;
}


// 15. Program to implement a sorting algorithm (Selection Sort):


#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: ");
    printArray(arr, n);
    selectionSort(arr, n);
    printf("Sorted array: ");
    printArray(arr, n);
    return 0;
}


// 16. Program to implement a sorting algorithm (Insertion Sort):

#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: ");
    printArray(arr, n);
    insertionSort(arr, n);
    printf("Sorted array: ");
    printArray(arr, n);
    return 0;
}



// 17. Program to implement a sorting algorithm (Merge Sort):


#include <stdio.h>

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArr[n1], rightArr[n2];

    for (i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: ");
    printArray(arr, n);
    mergeSort(arr, 0, n - 1);
    printf("Sorted array: ");
    printArray(arr, n);
    return 0;
}


// 18. Program to implement a sorting algorithm (Quick Sort):

#include <stdio.h>

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);

        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: ");
    printArray(arr, n);
    quickSort(arr, 0, n - 1);
    printf("Sorted array: ");
    printArray(arr, n);
    return 0;
}



// 19. Program to implement a sorting algorithm (Heap Sort):

#include <stdio.h>

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: ");
    printArray(arr, n);
    heapSort(arr, n);
    printf("Sorted array: ");
    printArray(arr, n);
    return 0;
}


// 20. Program to implement a searching algorithm (Linear Search):

#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 25;
    int result = linearSearch(arr, n, key);

    if (result != -1) {
        printf("Element %d found at index %d\n", key, result);
    } else {
        printf("Element %d not found in the array\n", key);
    }
    return 0;
}



// 21. Program to implement a searching algorithm (Binary Search):

#include <stdio.h>

int binarySearch(int arr[], int n, int key) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    int arr[] = {11, 12, 22, 25, 34, 64, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 25;
    int result = binarySearch(arr, n, key);

    if (result != -1) {
        printf("Element %d found at index %d\n", key, result);
    } else {
        printf("Element %d not found in the array\n", key);
    }
    return 0;
}


// 22. Program to implement a graph traversal algorithm (Breadth-First Search (BFS)):

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void BFS(int graph[][MAX], int vertices, int start) {
    int visited[vertices];
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
    }

    int queue[vertices];
    int front = 0, rear = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u);

        for (int v = 0; v < vertices; v++) {
            if (graph[u][v] == 1 && !visited[v]) {
                queue[rear++] = v;
                visited[v] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int vertices = 7;
    int graph[vertices][MAX] = {
        {0, 1, 1, 0, 0, 0, 0},
        {1, 0, 1, 1, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {0, 1, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 1, 1, 0}
    };

    int start = 0;
    printf("BFS traversal: ");
    BFS(graph, vertices, start);
    return 0;
}



// 23. Program to implement a graph traversal algorithm (Depth-First Search (DFS)):

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void DFS(int graph[][MAX], int vertices, int start, int visited[]) {
    printf("%d ", start);
    visited[start] = 1;

    for (int i = 0; i < vertices; i++) {
        if (graph[start][i] == 1 && !visited[i]) {
            DFS(graph, vertices, i, visited);
        }
    }
}

int main() {
    int vertices = 7;
    int graph[vertices][MAX] = {
        {0, 1, 1, 0, 0, 0, 0},
        {1, 0, 1, 1, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {0, 1, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 1, 1, 0}
    };

    int start = 0;
    int visited[vertices];
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
    }

    printf("DFS traversal: ");
    DFS(graph, vertices, start, visited);
    printf("\n");
    return 0;
}


// 24. Program to implement a dynamic programming algorithm (Fibonacci Series):

#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }

    int fib[n + 1];
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib[n];
}

int main() {
    int n = 10;
    printf("Fibonacci number at position %d: %d\n", n, fibonacci(n));
    return 0;
}