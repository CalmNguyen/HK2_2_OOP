#include<iostream>
using namespace std;
#include<string>
class student {
private:
	int maso;
	char* hoten;
	char* diachi;
public:
	// Constructors
	student();
	~student();
	// cai dat toan tu gan bang
	student& operator=(const student& src);
	// io
	void Nhap();
	void Xuat();
};
class dssv {
private:
	int n;
	student* S;
public:
	dssv();
	~dssv();
	// io
	void ds_nhap();
	void ds_xuat();
};
student::student() {
	maso = 0;
	hoten = new char[30]{ "empty" };
	diachi = new char[200]{"empty"};
}
student::~student() {
	delete[] hoten;
	hoten = nullptr;
	delete[] diachi;
	diachi = nullptr;
}
student& student::operator=(const student& src) {
	maso = src.maso;
	for(int i=0;i<30;i++)
		hoten[i] = src.hoten[i];
	for (int i = 0; i < 200; i++)
		diachi[i] = src.diachi[i];
	return *this;
}
void student::Nhap(){
	do {
		cout << "Nhap Ma So:";
		cin >> maso;
	} 	while (maso < 0);
	cin.ignore();
	cout << "Nhap ho ten:";
	cin.getline(hoten, 30);
	cout << "Nhap dia chi:";
	cin.getline(diachi, 200);
}
void student::Xuat() {
	cout << "Ma so:" << maso << endl;
	cout << "Ho ten:" << hoten << endl;
	cout << "Dia chi:" << diachi << endl;
}
dssv::dssv() {
	n = 0;
	S = nullptr;
}
dssv::~dssv() {
	delete[] S;
	S = nullptr;
}
void dssv::ds_nhap() {
	do {
		cout << "Enter size:";
		cin >> n;
	} while (n < 0);
	S = new student[n];
	for (int i = 0; i < n; i++) {
		cout << "Enter student " << i << ":\n";
		S[i].Nhap();
	}
}
void dssv::ds_xuat() {
	for (int i = 0; i < n; i++) {
		cout << "Export student " << i << ":\n";
		S[i].Xuat();
	}
}
int main()
{
	student a;
	a.Nhap();
	a.Xuat();
	student b;
	b=a;
	b.Xuat();
	dssv tm;
	tm.ds_nhap();
	tm.ds_xuat();
	return 0;
}