#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

// create llNode
struct llNode* createllNode(int value){
	struct llNode* this = (struct llNode*)malloc(sizeof(struct llNode));

	if(this == NULL){
		printf("Error: malloc failed!\n");
		return NULL;
	}

	this->val = value;
	this->next = NULL;

	return this;
}

// return a pointer to a heap allocated LinkedList struct
struct LinkedList* createLinkedList(){
	struct LinkedList* this = (struct LinkedList*)malloc(sizeof(struct LinkedList));

	if(this == NULL){
		printf("Error: malloc failed!\n");
		return NULL;
	}

	this->size = 0;
	this->head = NULL;
	this->tail = NULL;

	return this;
}



//Insert an element to the front of the linked list
void llAppendFront(struct LinkedList* llist, int value){
	if (llist->head == NULL) {
        llist->head = createllNode(value);
        llist->tail = llist->head;
    } else {
        struct llNode* temp = llist->head;
        llist->head = createllNode(value);
        llist->head->next = temp;
    }
    llist->size++;
}

//Insert an element to the back of the linked list
void llAppendBack(struct LinkedList* llist, int value){
	if (llist->tail == NULL) {
        llist->tail = createllNode(value);
        llist->head = llist->tail;
    } else {
        llist->tail->next = createllNode(value);
        llist->tail = llist->tail->next;
    }

    llist->size++;
}

//Insert an element at the specified index in the linked list
//All values in the linked list with an index greater than or equal to
//the passed in index prior to this call should follow this new value
//in the linked list
//Return -1 if the given index does not exist in the linked list
int llInsert(struct LinkedList* llist, int index, int value){
	if (index < 0 || index > llist->size) return -1;

    if (index == 0) {
        llAppendFront(llist, value);
        return 0;
    }

    if (index == llist->size) {
        llAppendBack(llist, value);
        return 0;
    }

    struct llNode* current = llist->head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }

    struct llNode* newNode = createllNode(value);
    if (newNode == NULL) return -1; // Handle malloc failure

    newNode->next = current->next;
    current->next = newNode;
    llist->size++;
    return 0;
}

//Returns the value at the given index in the linked list
//Return -1 if the given value does not exist in the linked list
int llGet(struct LinkedList* llist, int index){
	if (index < 0 || index >= llist->size) {
        return -1;
    }

    struct llNode* current = llist->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

	return current->val;
}

//Returns the index of the given value in the linked list
//Return -1 if the given value does not exist in the linked list
int llGetIndex(struct LinkedList* llist, int value){
	struct llNode* current = llist->head;
    int index = 0;
    while (current != NULL) {
        if (current->val == value) {
            return index;
        }
        current = current->next;
        index++;
    }

    return -1;
}


//Removes the node at the specified index in the linked list
//Return -1 if the index does not exist in the linked list, and zero otherwise
int llRemove(struct LinkedList* llist, int index){
	if (index < 0 || index >= llist->size) {
        return -1;
    }

    // if we are trying to remove the head
    if (index == 0) {
        llist->head = llist->head->next;
        if (llist->head == NULL) { // list is empty
            llist->tail = NULL; 
        }
        llist->size--;
        return 0;
    }

    struct llNode* current = llist->head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }
    current->next = current->next->next;

    // if removing from the back of the list
    if (index + 1 == llist->size) {
        llist->tail = current;
    }
    llist->size--;
	return 0;
}

//Sets the node at the specified index in the linked ist to the new value
//Return -1 if the index does not exist in the linked list, and zero otherwise
int llSet(struct LinkedList* llist, int index, int nVal){
	if (index < 0 || index >= llist->size) {
        return -1;
    }
    struct llNode* current = llist->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    current->val = nVal;
	return 0;
}

void destroyLinkedList(struct LinkedList* llist){
    struct llNode* current = llist->head;
    struct llNode* nextNode = current;
    while(current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

//Return the number of elements currently in the linked list
int llGetSize(struct LinkedList* llist){	
	return llist->size;
}

char* toString(struct LinkedList* llist) {
    char* toReturn = (char*)malloc(sizeof(char) * llist->size + 1);

    if(toReturn == NULL){
		printf("Error: malloc failed!\n");
		return NULL;
	}

    struct llNode* current = llist->head;
    while (current != NULL) {
        toReturn += current->val;
        current = current->next;
    }
    return toReturn;
}

int contructFirstFiveFibonacciNumbers(struct LinkedList* llist) {
    int a = 1;
    int b = 1;
    for (int i = 1; i<=5; i++) {
        if (i == 1) {
            llAppendBack(llist, a);
            continue;
        }
        if (i == 2) {
            llAppendBack(llist, b);
            continue;
        }
        llAppendBack(llist, a + b);
        int temp = b;
        b = a + b;
        a = temp;
    }

    return 0;
}

