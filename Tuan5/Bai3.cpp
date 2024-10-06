#include<iostream>
using namespace std;
#include<string>
struct Sach {
	string sMaso; // mã số của sách
	string sTenSach; // tên của sách
	int iSoLuong; // số lượng hiên có của đầu sách này
	float fGiaTien; // giá tiền của 1 cuốn
	Sach* pNext;
};
class NhaSach {
private:
	Sach* pHead; //con trỏ đến cuốn sách đầu tiên
public:
	// Constructors
	//default cons
	NhaSach();
	NhaSach(string MaSo, string TenSach, int SoLuong, float Gia, Sach* pnext);
	//copy constuctor
	NhaSach(const Sach a);
	// Các hàm thành phần xử lý
	int DemSach(); // số lượng sách hiện có
	~NhaSach();
	void deleteAll();
	bool isEmpty();
	void ThemSach(Sach* pSachMoi);
	void nhap_Sach();
	void xuat_Sach();
	// others...
};NhaSach::NhaSach() {	pHead = nullptr;}bool NhaSach::isEmpty() {	if (pHead == nullptr)		return true;	return false;}NhaSach::NhaSach(string MaSo, string TenSach, int SoLuong, float Gia, Sach* pnext) {	pHead = new Sach;	pHead->sMaso = MaSo;	pHead->fGiaTien = Gia;	pHead->iSoLuong = SoLuong;	pHead->sTenSach = TenSach;	pHead->pNext = pnext;}NhaSach::NhaSach(const Sach a){	pHead = new Sach;	pHead->sMaso = a.sMaso;	pHead->fGiaTien = a.fGiaTien;	pHead->iSoLuong = a.iSoLuong;	pHead->sTenSach = a.sTenSach;	pHead->pNext = a.pNext;}void NhaSach::deleteAll() {	if (isEmpty())		return;	if (pHead->pNext == nullptr) {		delete pHead;		pHead = nullptr;		return;	}	Sach* temp = pHead->pNext;	while (pHead != nullptr) {		delete pHead;		pHead = nullptr;		pHead = temp;		if (isEmpty())			return;		temp = pHead->pNext;	}}NhaSach::~NhaSach() {	if (isEmpty())		return;	deleteAll();	cout << "destructor";}int NhaSach::DemSach() {	int count = 0;	if (isEmpty())		return count;	Sach* temp = pHead;	while (temp != nullptr) {		count += temp->iSoLuong;		temp = temp->pNext;	}	return count;}void NhaSach::ThemSach(Sach* pSachMoi) {	if (isEmpty()) {		pHead = pSachMoi;	}	Sach* temp_SM = pSachMoi;	while (temp_SM->pNext != nullptr) {		temp_SM = temp_SM->pNext;	}	Sach* temp = pHead;	if (pHead->sMaso < pSachMoi->sMaso) {		pHead = pSachMoi;		temp_SM->pNext = temp;		cout << "A";		return;	}	while (temp->pNext != nullptr) {		if (temp->pNext->sMaso < pSachMoi->sMaso) {			Sach* temp1 = temp->pNext;			temp->pNext = pSachMoi;			temp_SM->pNext = temp1;			return;		}		temp = temp->pNext;	}	temp->pNext = pSachMoi;	temp->pNext->pNext = nullptr;}void NhaSach::nhap_Sach() {	int soLuong = 0;	cout << "Nhap so luong sach muon nhap:";	cin >> soLuong;	for (int i = 1; i <= soLuong; i++) {		cout << "Nhap sach thu " << i << endl;		Sach* add = new Sach{ "","",0,0,nullptr };		cout << "Nhap ma so sach:";		cin.ignore();		getline(cin, add->sMaso);		cout << "Nhap ten sach:";		getline(cin, add->sTenSach);		cout << "Nhap so luong:";		cin >> add->iSoLuong;		cout << "Nhap gia tien moi quyen sach:";		cin >> add->fGiaTien;		add->pNext = nullptr;		ThemSach(add);	}}void NhaSach::xuat_Sach() {	Sach* temp = pHead;	if (isEmpty())		cout << "Nha sach rong\n";	if (temp->pNext == nullptr) {		cout << "Loai sach thu " << "1" << endl;		cout << "Ma sach:" << temp->sMaso << endl;		cout << "Ten sach:" << temp->sTenSach << endl;		cout << "So luong:" << temp->iSoLuong << endl;		cout << "Gia moi quyen sach:" << temp->fGiaTien << endl;		return;	}	int i = 1;	while (temp->pNext != nullptr) {		i++;		temp = temp->pNext;	}	cout << "Loai sach thu " << i << endl;	cout << "Ma sach:" << temp->sMaso << endl;	cout << "Ten sach:" << temp->sTenSach << endl;	cout << "So luong:" << temp->iSoLuong << endl;	cout << "Gia moi quyen sach:" << temp->fGiaTien << endl;	Sach* temp1 = pHead;	while (temp != pHead) {		while (temp1->pNext != temp) {			temp1 = temp1->pNext;		}		i--;		cout << "Loai sach thu " << i << endl;		cout << "Ma sach:" << temp1->sMaso << endl;		cout << "Ten sach:" << temp1->sTenSach << endl;		cout << "So luong:" << temp1->iSoLuong << endl;		cout << "Gia moi quyen sach:" << temp1->fGiaTien << endl;		temp = temp1;	}	i--;	cout << "Loai sach thu " << i << endl;	cout << "Ma sach:" << temp->sMaso << endl;	cout << "Ten sach:" << temp->sTenSach << endl;	cout << "So luong:" << temp->iSoLuong << endl;	cout << "Gia moi quyen sach:" << temp->fGiaTien << endl;}int main() {	NhaSach a;	a.nhap_Sach();	cout << "So sach trong nha sach:"<<a.DemSach() << endl;	a.xuat_Sach();	system("pause");	return 0;}