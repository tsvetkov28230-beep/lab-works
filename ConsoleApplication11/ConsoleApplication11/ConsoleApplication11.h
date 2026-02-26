#pragma once
#include<iostream>
#include<fstream>
using std::ostream;
using std::ifstream;
class List {
	struct Node {
		int data;
		Node* next;
	};
	Node* head;
public:
	void initList(Node*& head);
	bool isEmpty(Node* head);
	void addToHead(Node*& head, int elem);
	void addAfterNode(Node*& pNode, int elem);
	void deleteFromHead(Node*& head);
	void deleteAfterNode(Node* pNode, int elem);
	Node* createStraight(ifstream& in);
	Node* createReverse(ifstream& in);
	Node* createInOrder(ifstream& in);
	Node* findPlace(Node* head, int elem);
	void print(Node* head, ostream& out);
	void clear(Node*& head);
};