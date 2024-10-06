#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};
class LinkedList {
public:
	LinkedList() { // constructor
		head = NULL;
	}
	~LinkedList() {}; // destructor
	void addFirst(int key);
	void addLast(int key);
	Node* findPreNode(int key);
	void addMidList(int key, int newKey);
	void reverseList();
	void display() {

	};// Don't understand
	void deleteAll();
	void print();
private:
	Node* head;
};void LinkedList::addFirst(int key) {	Node* temp = new Node{ key,NULL };	if (head == NULL)	{		head = temp;		return;	}	temp->next = head;	head = temp;}void LinkedList::addLast(int key) {	Node* add = new Node{ key,NULL };	if (head == NULL)	{		head = add;		return;	}	Node* temp = head;	while (temp->next != NULL)	{		temp = temp->next;	}	temp->next = add;}Node* LinkedList::findPreNode(int key) {	Node* temp = head;	if (temp == NULL)		return NULL;	while (temp != NULL)	{		if (temp->data == key) {			return temp;		}		temp = temp->next;	}	return NULL;}void LinkedList::addMidList(int key, int newKey) {	Node* find = findPreNode(key);	if (find == NULL)	{		cout<< "preNode khong ton tai\n";		return;	}	Node* add = new Node{ newKey,NULL };	Node* temp = find->next;	find->next = add;	add->next = temp;}void LinkedList::deleteAll() {	if (head == NULL)		return;	Node* temp = head->next;	while (head != NULL&&temp!=NULL)	{		delete head;		head = NULL;		head = temp;		temp = temp->next;	}}void LinkedList::reverseList() { 
	Node* current = head;
	Node* prev = NULL, * next = NULL;

	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
}void LinkedList::print() {	if (head == NULL)		return;	cout << "Link list\n";	Node* temp = head;	while (temp != NULL)	{		cout << temp->data << "   ";		temp = temp->next;	}}int main(){	LinkedList a;	a.addFirst(3);	a.addFirst(4);	a.addFirst(5);	a.addLast(6);	a.addLast(7);	Node* b = a.findPreNode(7);	cout << b << "  " << b->data << endl;	a.addMidList(8,8);	a.addMidList(4, 8);	a.print();	cout << endl;	a.reverseList();	a.print();	system("pause");	return 0;}