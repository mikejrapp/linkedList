/*
	CS240, Section ...
	Program 2 "Linked Lists"
	Author: Michael Rapp
	Date: 9/18/2016
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

void loadList(ifstream &inFile, linkedList &list1, doublyLinkedList &list2);
void printList(linkedList list1);
void printDoubleList(doublyLinkedList list2);
void greet();

int main() {
	ifstream inFile;
	linkedList list1;
	doublyLinkedList list2;

	greet();
	loadList(inFile, list1, list2);
	list2.copyList(list1);
	printList(list1);
	printDoubleList(list2);

	cin.ignore();
	cin.get();
	return 0;
}

void loadList(ifstream &inFile, linkedList &list1, doublyLinkedList &list2) {
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
	cout << "\nSingle linked list contents:" << endl;
	list1.traverse();
	cout << endl;
}

void printDoubleList(doublyLinkedList list2) {
	cout << "\nDouble linked list contents:" << endl;
	list2.traverseHead();
	cout << endl;
}

void greet() {
	cout << "CS240, Section ...\nProgram 2 'Linked Lists'" << endl;
}