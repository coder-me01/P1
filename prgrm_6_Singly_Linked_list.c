#include <stdio.h>
#include <stdlib.h>

// Define a node structure
struct Node {
    int data;
    struct Node *next;
};

// Function to display the linked list
void displayList(struct Node *head) {
    struct Node *temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to insert a node at the beginning of the list
struct Node* insertAtBeginning(struct Node *head, int value) {
    struct Node newNode = (struct Node)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    return newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node *head, int value) {
    struct Node newNode = (struct Node)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    struct Node *temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete the first node from the list
struct Node* deleteFromBeginning(struct Node *head) {
    if(head == NULL) {
        printf("List is empty. No node to delete.\n");
        return NULL;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Function to delete the last node from the list
void deleteFromEnd(struct Node *head) {
    if(head == NULL) {
        printf("List is empty. No node to delete.\n");
        return;
    }
    struct Node *prev = NULL;
    struct Node *temp = head;
    while(temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
}

// Function to delete a given element from the list
void deleteElement(struct Node *head, int key) {
    struct Node *prev = NULL;
    struct Node *temp = head;

    // If key is found at the beginning
    if(temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        return;
    }

    // Find the node to be deleted
    while(temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in the list
    if(temp == NULL) {
        printf("Element %d not found in the list.\n", key);
        return;
    }

    // Unlink the node from the list
    prev->next = temp->next;
    free(temp);
}

int main() {
    struct Node *head = NULL;

    // Insert elements at the beginning
    head = insertAtBeginning(head, 3);
    head = insertAtBeginning(head, 2);
    head = insertAtBeginning(head, 1);

    printf("List after insertion at beginning: ");
    displayList(head);

    // Insert element at the end
    insertAtEnd(head, 4);
    printf("List after insertion at end: ");
    displayList(head);

    // Delete from beginning
    head = deleteFromBeginning(head);
    printf("List after deleting from beginning: ");
    displayList(head);

    // Delete from end
    deleteFromEnd(head);
    printf("List after deleting from end: ");
    displayList(head);

    // Delete a given element
    deleteElement(head, 2);
    printf("List after deleting element 2: ");
    displayList(head);

    return 0;
}
