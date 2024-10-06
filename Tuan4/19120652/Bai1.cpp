#include<iostream>
using namespace std;
// class vector
class vector {
	int sz; // number of elements
	double* elem; // address of first element
	int space; // for new elements ("the current allocation")
public:
	// methods
	vector();
	// Construct Copy
	vector(const vector& src);
	// Destructor
	~vector() { delete[] elem; }
	// access: return reference
	double& operator[](int idx) { return elem[idx]; }
	// the current size
	int size() const { return sz; }
	int capacity() const { return space; }
		// Assignment Contructor
	vector& operator=(const vector& a);
	// Thêm không gian cho phần tử mới
	void reserve(int newalloc);
	// resize: Cập nhật lại kích thước vector
	void resize(int newsize);
	// Thêm 1 phan tu vao cuoi vector - push_back
	void push_back(double d);
};vector::vector() {	sz = 0;	space = 10;	elem = new double[space];}vector::vector(const vector& src) {	sz = src.sz;	elem = new double[src.space];	for (int i = 0; i < sz; i++) {		elem[i] = src.elem[i];	}	space = src.space;}vector& vector::operator=(const vector& a) {	sz = a.sz;	elem = a.elem;	space = a.space;	return *this;}// Thêm không gian cho phần tử mới
void vector::reserve(int newalloc) {	double* temp = elem;	delete[] elem;	space += newalloc;	elem = new double[space];	for (int i = 0; i < sz; i++)	{		elem[i] = temp[i];	}}// resize: Cập nhật lại kích thước vector
void vector::resize(int newsize) {	if (newsize <= space)		return;	space = newsize;	sz = newsize;	this->reserve(newsize-space);}// Thêm 1 phan tu vao cuoi vector - push_back
void vector::push_back(double d) {	sz++;	if (sz <= space)	{		elem[sz - 1] = d;	}	else{		this->resize(sz);		elem[sz - 1] = d;	}}int main(){	vector a;	a.push_back(4);	a.push_back(5);	cout << a[1];}