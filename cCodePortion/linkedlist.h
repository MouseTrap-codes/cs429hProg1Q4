#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct llNode{
	int val;
	struct llNode* next;
};

//Create a new llNode
struct llNode* createllNode(int value);

struct LinkedList{
	int size;
	struct llNode* head;
	struct llNode* tail;
};

//Return a pointer to a heap allocated LinkedList struct
struct LinkedList* createLinkedList();

//Insert an element ot the front of the linked list
void llAppendFront(struct LinkedList* llist, int value);

//Insert an element to the back of the linked list
void llAppendBack(struct LinkedList* llist, int value);

//Insert an element at the specified index in the linked list
//All values in the linked list with an index greater than or equal to
//the passed in index prior to this call should follow this new value
//in the linked list
//Return -1 if the given index does not exist in the linked list
int llInsert(struct LinkedList* llist, int index, int value);

//Returns the value at the given index in the linked list
int llGet(struct LinkedList* llist, int index);

//Returns the index of the given value in the linked list
//Return -1 if the given value does not exist in the linked list
int llGetIndex(struct LinkedList* llist, int value);

//Removes the node at the specified index in the linked list
//Return -1 if the index does not exist in the linked list, and zero otherwise
int llRemove(struct LinkedList*, int index);

//Sets the node at the specified index in the linked ist to the new value
//Return -1 if the index does not exist in the linked list, and zero otherwise
int llSet(struct LinkedList* llist, int index, int nVal);

//Destroy the linked list object and free all of its memory
void destroyLinkedList(struct LinkedList* llist);

//Return the number of elements currently in the linked list
int llGetSize(struct LinkedList* llist);

#endif // LINKEDLIST_H
