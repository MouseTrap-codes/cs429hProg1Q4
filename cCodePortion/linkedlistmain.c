#include "linkedlist.h"
#include <stdio.h>
#include <stdbool.h>

const int NUM_ELEMS = 100;

int main(int argc, char** argv){
	struct LinkedList* testLinkedList = createLinkedList();

	if(testLinkedList == NULL){
		printf("Error: testLinkedList is a null pointer!\n");
		//return 1;
	}

	int testCasesPassed = 12;
	bool removePt = false;

	for(int i = 0; i < NUM_ELEMS; ++i){
		llAppendFront(testLinkedList, i);
		llAppendBack(testLinkedList, i);
	}

	unsigned int size = llGetSize(testLinkedList);
	if(size != 200){
		printf("Error: Linked list has incorrect size. Expected 200, got %d\n", size);
	}

	printf("Verifying correctness of first 100 elements\n");

	int expectedVal = 99;
	for(int i = 0; i < 100; ++i){
		int val = llGet(testLinkedList, i);
		if(val != expectedVal){
			removePt = true;
			printf("Error: incorrect value at index %d\n", i);
		}
		--expectedVal;
	}

	if(removePt){
		removePt = false;
		--testCasesPassed;
	}

	printf("Verifying correctness of last 100 elements\n");

	expectedVal = 0;
	for(int i = 100; i < 200; ++i){
		int val = llGet(testLinkedList, i);
		if(val != expectedVal){
			removePt = true;
			printf("Error: incorrect value at index %d\n", i);
		}
		++expectedVal;
	}

	if(removePt){
		removePt = false;
		--testCasesPassed;
	}

	printf("Starting first removal test\n");
	
	for(int i = 0; i < 50; ++i){
		llRemove(testLinkedList, 50);
	}

	if(llGetSize(testLinkedList) != 150){
		printf("Error: Linked list has incorrect size. Expected 150, got %d\n", llGetSize(testLinkedList));
		--testCasesPassed;
	}

	expectedVal = 99;
	for(int i = 0; i < 50; ++i){
		if(llGet(testLinkedList, i) != expectedVal){
			removePt = true;
			printf("Error: incorrect value at index %d\n", i);
		}
		--expectedVal;
	}

	expectedVal = 0;
	for(int i = 0; i < 100; ++i){
		if(llGet(testLinkedList, i + 50) != expectedVal){
			removePt = true;
			printf("Error: incorrect value at index %d\n", (i + 50));
		}
		++expectedVal;
	}

	if(removePt){
		removePt = false;
		--testCasesPassed;
	}

	printf("Starting second removal test\n");

	for(int i = 0; i < 50; ++i){
		llRemove(testLinkedList, 0);
	}

	if(llGetSize(testLinkedList) != 100){
		printf("Error: Linked list has incorrect size. Expected 100, got %d\n", llGetSize(testLinkedList));
		--testCasesPassed;
	}
	
	for(int i = 0; i < 100; ++i){
		if(llGet(testLinkedList, i) != i){
			removePt = true;
			printf("Error: incorrect value at index %d. Expected %d, got %d\n", i, i, llGet(testLinkedList, i));
		}
	}

	if(removePt){
		removePt = false;
		--testCasesPassed;
	}

	printf("Testing set method\n");
	
	for(int i = 0; i < 100; ++i){
		llSet(testLinkedList, i, i * 2);;
	}

	if(llGetSize(testLinkedList) != 100){
		printf("Error: Linked list has incorrect size. Expected 100, got %d\n", llGetSize(testLinkedList));
		--testCasesPassed;
	}

	for(int i = 0; i < 100; ++i){
		if(llGet(testLinkedList, i) != (i * 2)){
			removePt = true;
			printf("Error: incorrect value at index %d\n", i);
		}
	}

	if(removePt){
		removePt = false;
		--testCasesPassed;
	}

	for(int i = 99; i >= 0; --i){
		if(llGetIndex(testLinkedList, i * 2) != i){
			removePt = true;
			printf("Error: value %d is at the wrong index!\n", (i * 2));
		}
	}

	if(removePt){
		removePt = false;
		--testCasesPassed;
	}
	
	printf("Testing insertion into the middle of the linked list\n");
	
	for(int i = 49; i >= 0; --i){
		llInsert(testLinkedList, 50, i);
	}

	if(llGetSize(testLinkedList) != 150){	
		printf("Error: Linked list has incorrect size. Expected 100, got %d\n", llGetSize(testLinkedList));
		--testCasesPassed;
	}

	for(int i = 0; i < 50; ++i){
		if(llGet(testLinkedList, i) != (i * 2)){
			removePt = true;
			printf("Error: incorrect value at index %d\n", i);
		}
	}

	for(int i = 0; i < 50; ++i){
		if(llGet(testLinkedList, i + 50) != i){
			removePt = true;
			printf("Error: incorrect value at index %d. Expected %d, got %d\n", (i + 50), i, llGet(testLinkedList, i + 50));
		}
	}
	
	for(int i = 50; i < 100; ++i){
		if(llGet(testLinkedList, i + 50) != (i * 2)){
			removePt = true;
			printf("Error: incorrect value at index %d. Expected %d, got %d\n", (i + 100), i, llGet(testLinkedList, i + 50));
		}
	}

	if(removePt){
		removePt = false;
		--testCasesPassed;
	}
	
	destroyLinkedList(testLinkedList);

	printf("Passed %d out of 12 test cases\n", testCasesPassed);

	return 0;
}
