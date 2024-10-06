#pragma once
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



class Singleton {//khai báo l?p
private:
	static Singleton* _instance;//??i t??ng duy nh?t c?a l?p
	Singleton() {};//ph??ng th?c t?o l?p
public:
	//ph??ng th?c l?y ??i t??ng c?a l?p
	static Singleton* getInstance();
};
Singleton* Singleton::_instance = NULL;
Singleton* Singleton::getInstance(){
	if (_instance == NULL)
		_instance = new Singleton();
	return _instance;
}