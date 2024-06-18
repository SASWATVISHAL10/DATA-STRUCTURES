//OPEN ADDRESSING
#include <stdio.h> 
#include <stdlib.h>  
void merge(int arr[], int l, int m, int r) 
{ 
	int i, j, k; 
	int n1 = m - l + 1; 
	int n2 = r - m;  
	int L[n1], R[n2]; 
	for (i = 0; i < n1; i++) 
		L[i] = arr[l + i]; 
	for (j = 0; j < n2; j++) 
		R[j] = arr[m + 1 + j]; 
	i = 0; 
  j = 0; 
  k = l; 
	while (i < n1 && j < n2) { 
		if (L[i] <= R[j]) { 
			arr[k] = L[i]; 
			i++; 
		} 
		else { 
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
void mergeSort(int arr[], int l, int r) 
{ 
	if (l < r) {  
		int m = l + (r - l) / 2;  
		mergeSort(arr, l, m); 
		mergeSort(arr, m + 1, r); 

		merge(arr, l, m, r); 
	} 
} 
void printArray(int A[], int size) 
{ 
	int i; 
	for (i = 0; i < size; i++) 
		printf("%d ", A[i]); 
	printf("\n"); 
}  
int main() 
{ 
	int arr[] = { 12, 11, 13, 5, 6, 7 }; 
	int arr_size = sizeof(arr) / sizeof(arr[0]); 
  printf("Given array is \n"); 
	printArray(arr, arr_size); 
  mergeSort(arr, 0, arr_size - 1); 
  printf("\nSorted array is \n"); 
	printArray(arr, arr_size); 
	return 0; 
}

//REHASHING

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

typedef struct HashTable {
    int size;
    int count; 
    Node** table;
} HashTable;
  Node* createNode(int key, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}
  HashTable* createTable(int size) {
    HashTable* newTable = (HashTable*)malloc(sizeof(HashTable));
    newTable->size = size;
    newTable->count = 0;
    newTable->table = (Node**)malloc(sizeof(Node*) * size);
    for (int i = 0; i < size; i++) {
        newTable->table[i] = NULL;
    }
    return newTable;
}
  int hashFunction(int key, int size) {
    return key % size;
}
    void insert(HashTable* hashTable, int key, int value);
    void rehash(HashTable* hashTable) {
    int oldSize = hashTable->size;
    Node** oldTable = hashTable->table;
    int newSize = oldSize * 2;
    hashTable->table = (Node**)malloc(sizeof(Node*) * newSize);
    hashTable->size = newSize;
    hashTable->count = 0;
    for (int i = 0; i < newSize; i++) {
        hashTable->table[i] = NULL;
    }
    for (int i = 0; i < oldSize; i++) {
        Node* current = oldTable[i];
        while (current != NULL) {
            insert(hashTable, current->key, current->value);
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
  free(oldTable);
}

void insert(HashTable* hashTable, int key, int value) {
    if ((float)hashTable->count / hashTable->size >= 0.75) {
        rehash(hashTable);
    }

    int hashIndex = hashFunction(key, hashTable->size);
    Node* newNode = createNode(key, value);
    newNode->next = hashTable->table[hashIndex];
    hashTable->table[hashIndex] = newNode;
    hashTable->count++;
}
  int search(HashTable* hashTable, int key) {
    int hashIndex = hashFunction(key, hashTable->size);
    Node* current = hashTable->table[hashIndex];
    while (current != NULL) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }
    return -1;
}
  void delete(HashTable* hashTable, int key) {
    int hashIndex = hashFunction(key, hashTable->size);
    Node* current = hashTable->table[hashIndex];
    Node* prev = NULL;
    while (current != NULL && current->key != key) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        return;
    }
    if (prev == NULL) {
        hashTable->table[hashIndex] = current->next;
    } else {
        prev->next = current->next;
    }
    free(current);
    hashTable->count--;
}
  void freeTable(HashTable* hashTable) {
    for (int i = 0; i < hashTable->size; i++) {
        Node* current = hashTable->table[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(hashTable->table);
    free(hashTable);
}
    int main() {
    HashTable* hashTable = createTable(5);
    insert(hashTable, 1, 10);
    insert(hashTable, 2, 20);
    insert(hashTable, 3, 30);
    insert(hashTable, 4, 40);
    insert(hashTable, 5, 50);
    insert(hashTable, 6, 60); 
    printf("Value for key 1: %d\n", search(hashTable, 1));
    printf("Value for key 2: %d\n", search(hashTable, 2));
    printf("Value for key 3: %d\n", search(hashTable, 3));
    printf("Value for key 4: %d\n", search(hashTable, 4));
    printf("Value for key 5: %d\n", search(hashTable, 5));
    printf("Value for key 6: %d\n", search(hashTable, 6));

    delete(hashTable, 3);
    printf("Value for key 3 after deletion: %d\n", search(hashTable, 3));

    freeTable(hashTable);
    return 0;
}

//CLOSED ADDRESSING

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;
typedef struct HashTable {
    int size;
    Node** table;
} HashTable;
Node* createNode(int key, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}
HashTable* createTable(int size) {
    HashTable* newTable = (HashTable*)malloc(sizeof(HashTable));
    newTable->size = size;
    newTable->table = (Node**)malloc(sizeof(Node*) * size);
    for (int i = 0; i < size; i++) {
        newTable->table[i] = NULL;
    }
    return newTable;
}
int hashFunction(int key, int size) {
    return key % size;
}
void insert(HashTable* hashTable, int key, int value) {
    int hashIndex = hashFunction(key, hashTable->size);
    Node* newNode = createNode(key, value);
    newNode->next = hashTable->table[hashIndex];
    hashTable->table[hashIndex] = newNode;
}
int search(HashTable* hashTable, int key) {
    int hashIndex = hashFunction(key, hashTable->size);
    Node* current = hashTable->table[hashIndex];
    while (current != NULL) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }
    return -1; 
}
void delete(HashTable* hashTable, int key) {
    int hashIndex = hashFunction(key, hashTable->size);
    Node* current = hashTable->table[hashIndex];
    Node* prev = NULL;
    while (current != NULL && current->key != key) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        return;
    }
    if (prev == NULL) {
        hashTable->table[hashIndex] = current->next;
    } else {
        prev->next = current->next;
    }
    free(current);
}
void freeTable(HashTable* hashTable) {
    for (int i = 0; i < hashTable->size; i++) {
        Node* current = hashTable->table[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(hashTable->table);
    free(hashTable);
}
int main() {
    HashTable* hashTable = createTable(10);

    insert(hashTable, 1, 10);
    insert(hashTable, 2, 20);
    insert(hashTable, 12, 30);

    printf("Value for key 1: %d\n", search(hashTable, 1));
    printf("Value for key 2: %d\n", search(hashTable, 2));
    printf("Value for key 12: %d\n", search(hashTable, 12));
    printf("Value for key 3: %d\n", search(hashTable, 3)); 

    delete(hashTable, 2);
    printf("Value for key 2 after deletion: %d\n", search(hashTable, 2));

    freeTable(hashTable);
    return 0;
}