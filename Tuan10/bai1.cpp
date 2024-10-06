#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <cassert>
using namespace std;
template<typename T>
class Stack {
private:
	T* ptr;
	int capacity;
	int size;
public:
	Stack(int capacity);
	~Stack();
	void push(const T& element);
	T pop();
	bool isEmpty();
};
#endif
template<class T>
Stack<T>::Stack(int capac) {
	if (capac > 0 && capac < 1000)
		size = capac;
	else
		size = 10;
	capacity = -1;
	ptr = new T[size];
}
template<class T>
Stack<T> ::~Stack() {
	delete[] ptr;
	ptr = NULL;
	cout << "destructor";
}
template<class T>
bool Stack<T>::isEmpty(){
	if (capacity == -1)
		return true;
	return false;
}
template<class T>
void Stack<T>::push(const T& element) {
	if (capacity<=size) {
		capacity++;
		ptr[capacity] = element;
		return;
	}
}
template<class T>
T Stack<T> ::pop() {
	T temp=NULL;
	if (!isEmpty()) {
		temp = ptr[capacity];
		capacity--;
	}
	return temp;
}
int main() {
	Stack<int> a(100);
	a.push(3);
	a.push(6);
	a.pop();
	return 0;
}