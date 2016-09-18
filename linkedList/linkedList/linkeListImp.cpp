/*
	CS240, Section 003
	Program 2 "Linked Lists"
	Author: Michael Rapp
	Date: 9/17/2016
	Description: This program reads a list of numbers from an ASCII file, imports them into a single linked list, copies the single
	linked list into a doubly linked list in ascedning order. Outputs the data from the single linked list, then the data from the doubly
	linked list.
*/

#include<iostream>
#include<fstream>
#include<string>
#include"linkedList.h"
#include"doublyLinkedList.h"

using namespace std;

void loadList(ifstream &inFile, linkedList &list1);
void printList(linkedList list1);
void printDoubleList(doublyLinkedList list2);
void title();

int main() {
	ifstream inFile;
	linkedList list1;
	doublyLinkedList list2;

	title();
	loadList(inFile, list1);
	list2.copyList(list1);
	printList(list1);
	printDoubleList(list2);

	cin.ignore();
	cin.get();
	return 0;
}

void loadList(ifstream &inFile, linkedList &list1) {
	//This function checks for the file, opens the file if found and loads the data into the single linked list
	int data;
	string fileName;

	cout << "\nPlease enter the file name: ";
	cin >> fileName;

	inFile.open(fileName);

	if (inFile) {
		while (!inFile.eof()) {
			inFile >> data;
			list1.addNode(data);
		}
	}
	else {
		cout << "\nFile not found. Program terminates." << endl;
	}
}

void printList(linkedList list1) {
	//This function prints the single linked list
	cout << "\nSingle linked list contents:" << endl;
	list1.traverse();
	cout << endl;
}

void printDoubleList(doublyLinkedList list2) {
	//this function prints the double linked list from the head of the list
	cout << "\nDouble linked list contents:" << endl;
	list2.traverseHead();
	cout << endl;
}

void title() {
	//this function prints the title
	cout << "CS240, Section 003\nProgram 2 'Linked Lists'" << endl;
}