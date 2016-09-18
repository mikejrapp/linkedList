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
private:
	node *tail;
};

doublyLinkedList::doublyLinkedList() {
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
	current = head;
	while (current != nullptr) {
		cout << current->data << " ";
		current = current->next;
	}
}

void doublyLinkedList::traverseTail() {
	current = tail;
	while (current != nullptr) {
		printNode();
		current = current->previous;
	}
}

void doublyLinkedList::traverseAdd(int newData) {
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
	newNode = new node;
	newNode->data = newData;
	newNode->next = head;
	newNode->previous = nullptr;
	head->previous = newNode;
	head = newNode;
}

void doublyLinkedList::insertAtTail(int newData){
	newNode = new node;
	newNode->data = newData;
	newNode->previous = tail;
	newNode->next = nullptr;
	tail = newNode;
	current->next = tail;
}

void doublyLinkedList::insertBetween(int newData) {
	newNode = new node;
	newNode->data = newData;
	newNode->next = current;
	newNode->previous = current->previous;
	current->previous->next = newNode;
	current->previous = newNode;
}

void doublyLinkedList::copyList(linkedList list) {
	if (this->isEmpty()) {
		head->data = list.getFirst();
		current = head;
	}
	while(!list.isEnd()){
		this->traverseAdd(list.getNext());
	}
}

bool doublyLinkedList::isEmpty() {
	if (head->next == nullptr && isStart) {
		return true;
	}
	else {
		return false;
	}
}
#endif
