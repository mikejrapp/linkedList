#pragma once
#ifndef H_DOUBLYLINKEDLIST
#define H_DOUBLYLINKEDLIST

#include "linkedList.h"
#include<iostream>

using namespace std;

class doublyLinkedList : public linkedList {
public:
	doublyLinkedList();
	void traverseHead();
	void traverseTail();
	void traverseAdd(int newData);
	void insertAtHead(int newData);
	void insertAtTail(int newData);
	void insertBetween(int newData);
	void copyList(linkedList list);
	bool isEmpty();
	//add deleteList for use with copyList
private:
	node *tail;
};

doublyLinkedList::doublyLinkedList() {
	//Constructor for doublyLinkedList
	//creates head and tail node and sets members to null.
	isStart = true;
	newNode = new node;
	newNode->data = 0;
	newNode->next = nullptr;
	newNode->previous = nullptr;
	current = newNode;
	head = newNode;
	tail = current;
}

void doublyLinkedList::traverseHead() {
	//This function will traveres the list from the head pointer.
	current = head;
	while (current != nullptr) {
		cout << current->data << endl;
		current = current->next;
	}
}

void doublyLinkedList::traverseTail() {
	//This function will traverse the list from the tail pointer.
	current = tail;
	while (current != nullptr) {
		printNode();
		current = current->previous;
	}
}

void doublyLinkedList::traverseAdd(int newData) {
	//This function is designed for use with the copy function.
	//Traverses the list and determines where to set a node in ascending order
	current = head;
	while (current != nullptr) {
		if (newData > current->data && current == tail) {
			this->insertAtTail(newData);
		}
		if (newData < current->data && current == head) {
			this->insertAtHead(newData);
		}
		if (newData < current->data && newData > current->previous->data) {
			this->insertBetween(newData);
		}
		current = current->next;
	}
}

void doublyLinkedList::insertAtHead(int newData) {
	//This function is designed for use with traverseAdd
	//Will insert a new node at the head of the list.
	newNode = new node;
	newNode->data = newData;
	newNode->next = head;
	newNode->previous = nullptr;
	head->previous = newNode;
	head = newNode;
}

void doublyLinkedList::insertAtTail(int newData){
	//This function is designed for use with traverseAdd
	//Will insert a new node at the tail of the list
	newNode = new node;
	newNode->data = newData;
	newNode->previous = tail;
	newNode->next = nullptr;
	tail = newNode;
	current->next = tail;
}

void doublyLinkedList::insertBetween(int newData) {
	//This function is designed for use with traverseAdd
	//Will insert a new node in ascending order between two existing nodes
	newNode = new node;
	newNode->data = newData;
	newNode->next = current;
	newNode->previous = current->previous;
	current->previous->next = newNode;
	current->previous = newNode;
}

void doublyLinkedList::copyList(linkedList list) {
	//This function will take a single linked list, copy and insert 
	//it's data in a doubly linked list in ascending order.
	if (this->isEmpty()) {
		head->data = list.getFirst();
		current = head;
		while (!list.isEnd()) {
			this->traverseAdd(list.getNext());
		}
	}
}

bool doublyLinkedList::isEmpty() {
	//This function checks if the doubly linked list is empty.
	if (head->next == nullptr && isStart) {
		return true;
	}
	else {
		return false;
	}
}
#endif
