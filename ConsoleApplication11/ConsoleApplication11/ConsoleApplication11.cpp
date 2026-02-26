#include"ConsoleApplication11.h"

void List::initList(Node*& head)
{
	head = nullptr;
}

bool List::isEmpty(Node* head) 
{
	return head == nullptr;
}

void List::addToHead(Node*& head, int elem)
{
	Node* p = new Node;
	p->data = elem;
	p->next = head;
	head = p;
}

void List::addAfterNode(Node*& pNode, int elem)
{
	Node* p = new Node;
	p->data = elem;
	p->next = pNode->next;
	pNode->next = p;
}

void List::deleteFromHead(Node*& head)
{
	Node* p = head;
	head = head->next;
	p->next = nullptr;
	delete p;
	p = nullptr;
}

void List::deleteAfterNode(Node* pNode, int elem)
{
	Node* p = pNode->next;
	pNode->next = p->next;
	p->next = nullptr;
	delete p;
	p = nullptr;
}

List::Node* List::createStraight(ifstream& in)
{
	Node* head;
	initList(head);
	int elem;
	in >> elem;
	addToHead(head, elem);
	Node* cur = head;
	while (in >> elem) {
		addAfterNode(cur, elem);
		cur = cur->next;
	}
	return head;
}

List::Node* List::createReverse(ifstream& in)
{
	Node* head;
	initList(head);
	int elem;
	while (in >> elem) {
		addToHead(head, elem);
	}
	return head;
}

List::Node* List::createInOrder(ifstream& in)
{
	Node* head;
	initList(head);
	int elem;
	in >> elem;
	addToHead(head, elem);
	Node* cur = head;
	while (in >> elem) {
		if (elem < head->data)
			addToHead(head, elem);
		else {
			Node* pNode = findPlace(head, elem);
			addAfterNode(pNode, elem);
		}
	}
	return head;
}

List::Node* List::findPlace(Node* head, int elem) {
	Node* cur = head;
	while (cur->next && cur->next->data < elem) {
		cur = cur->next;
	}
	return cur;
}

void List::print(Node* head, ostream&out)
{
	Node* cur = head;
	while (cur) {
		out << cur->data;
		cur = cur->next;
	}
}

void List::clear(Node*& head)
{
	while (!isEmpty(head)) {
		deleteFromHead(head);
	}
}












