#include<iostream>
#include<fstream>
#include"linkedList.h"
#include"doublyLinkedList.h"

using namespace std;

void loadList(ifstream &inFile, linkedList &list1, doublyLinkedList &list2);
void printList(doublyLinkedList &list2);

int main() {
	ifstream inFile;
	linkedList list1;
	doublyLinkedList list2;

	loadList(inFile, list1, list2);
	list2.copyList(list1);
	printList(list2);

	cin.get();
	return 0;
}

void loadList(ifstream &inFile, linkedList &list1, doublyLinkedList &list2) {
	int data;
	
	inFile.open("p2datafile.txt");

	while (!inFile.eof()) {
		inFile >> data;
		list1.addNode(data);
	}
}

void printList(doublyLinkedList &list2) {
	list2.traverseHead();
}