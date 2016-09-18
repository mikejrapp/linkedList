#pragma once
#ifndef H_LINKEDLIST
#define H_LINKEDLIST

#include<iostream>

using namespace std;

struct node {
	int data;
	node *next;
	node *previous;
};

class linkedList {
public:
	linkedList();
	void addNode(int newData);
	void traverse();
	void printNode();
	int getFirst();
	int getNext();
	bool isEnd();
protected:
	node *head;
	node *current;
	node *newNode;
	bool isStart;
};

linkedList::linkedList() {
	isStart = true;
	newNode = new node;
	newNode->data = 0;
	newNode->next = nullptr;
	current = newNode;
	head = newNode;
}

void linkedList::addNode(int newData) {
	if (isStart) {
		head->data = newData;
		isStart = false;
	}
	else {
		newNode = new node;
		newNode->data = newData;
		newNode->next = nullptr;
		current->next = newNode;
		current = newNode;
	}
}

void linkedList::traverse() {
	current = head;
	while (current != nullptr) {
		printNode();
		current = current->next;
	}
}

void linkedList::printNode() {
	cout << current->data << endl;
}

int linkedList::getFirst() {
	isStart = true;
	current = head;
	return head->data;	
}

int linkedList::getNext() {
	if (isStart) {
		current = head->next;
		isStart = false;
		return current->data;
	}
	else {
		current = current->next;
		if (current != nullptr) {
			return current->data;
		}
	}
}

bool linkedList::isEnd() {
	if (current->next == nullptr) {
		return true;
	}
	else {
		return false;
	}
}
#endif