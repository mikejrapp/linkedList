/*
	CS240, Section 003
	Class: LinkedList
	Author: Michael Rapp
	Date: 9/17/2016
	Description: This class creates a single linked list capable of storing integer data.
*/

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
	//Constructor for linkedList. Create first list object. Set members to null.
	isStart = true;
	newNode = new node;
	newNode->data = 0;
	newNode->next = nullptr;
	current = newNode;
	head = newNode;
}

void linkedList::addNode(int newData) {
	//The method takes an integer argument to store in the node "data" variable.
	//If list has only one node, stores data in "head". Else adds new node, stores
	//data and adds to list.
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
	//This function starts at the head of the list and traverse each node to the end.
	current = head;
	while (current != nullptr) {
		printNode();
		current = current->next;
	}
}

void linkedList::printNode() {
	//This function prints a single node.
	//Designed for use with the traverse function.
	cout << current->data << endl;
}

int linkedList::getFirst() {
	//This function returns the data from the head of the list.
	//Resets the isStart boolean.
	isStart = true;
	current = head;
	return head->data;	
}

int linkedList::getNext() {
	//This function moves the the next object in the list and returns the data.
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
	//This function checks if the current object is the end of the list
	//returns true if on last object.
	if (current->next == nullptr) {
		return true;
	}
	else {
		return false;
	}
}
#endif