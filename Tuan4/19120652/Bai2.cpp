#include<iostream>
using namespace std;
#include<string>

class SinhVien {
private:
	string name;
	string id;
	float Marks[3];
public:
	SinhVien() {
		name = "";
		id = "";
		Marks[0] = Marks[1] = Marks[2] = 0;
	}
	SinhVien(string a, string b, float* c) {
		name = a;
		id = b;
		Marks[0] = c[0];
		Marks[1] = c[1];
		Marks[2] = c[2];
	}
	void Nhap();
	void Xuat();
	float DiemTB();
};
void SinhVien::Nhap() {
	cout << "Nhap name:";
	cin.ignore();
	getline(cin, name);
	cout << "Nhap id:";
	cin >> id;
	cout << "Nhap diem bai tap:";
	cin >> Marks[0];
	cout << "Nhap diem giua ki:";
	cin >> Marks[1];
	cout << "Nhap diem cuoi ki:";
	cin >> Marks[2];
}
void SinhVien::Xuat() {
	cout << "name:" << name << endl;
	cout << "id:" << id << endl;
	cout << "DBT:" << Marks[0] << endl;
	cout << "DGK:" << Marks[1] << endl;
	cout << "DCK:" << Marks[2] << endl;
	cout << endl;
}
float SinhVien::DiemTB() 
{
	float a= (Marks[0] * 0.25 + Marks[1] * 0.25 + Marks[2] * 0.5);
	return a;
}
class DSSV {
private:
	SinhVien a[100];
	int size;
public:
	void NhapDSSV() {
		cout << "Nhap size:";
		cin >> size;
		for (int i = 0; i < size; i++)
		{
			cout << "Nhap sinh vien thu " << i << endl;
			a[i].Nhap();
		}
	}
	void XuatXepHang(int a);// 1="DSHS yeu", 2="TB",3="Kha",4="gioi"
};
void DSSV::XuatXepHang(int b) {
	if (b < 1 || b>4)
		return;
	float gh_tren = 0;
	float gh_duoi = 0;
	if (b == 1) {
		gh_tren = 5;
		gh_duoi = 0;
	}
	else if (b == 2) {
		gh_tren = 5;
		gh_duoi = 6.5;
	}
	else if (b == 3) {
		gh_tren = 6.5;
		gh_duoi = 8;
	}
	else if (b == 4) {
		gh_duoi = 8;
		gh_tren = 10;
	}
	else return;
	for (int i = 0; i < size; i++)
	{
		if (a[i].DiemTB() >= gh_duoi && a[i].DiemTB() < gh_tren)
			a[i].Xuat();
		if (a[i].DiemTB() == gh_tren && gh_tren == float(10))
			a[i].Xuat();
	}
}
int main()
{
	DSSV dssv;
	dssv.NhapDSSV();
	dssv.XuatXepHang(4);
	system("pause");
	return 0;
}
