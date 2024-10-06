#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct Student {
	int id;
	char name[10];
	int score;
	char grade; // 'A', 'B', 'C', 'D', 'F'
};
class ListStudent {
private:
	Student st[10];
	int size;
public:
	void Inp(string i);
	void Out();
};
void stringToChar(string s, char a[10]) {
	for (int i = 0; i < s.size(); i++)
	{
		a[i] = s[i];
	}
}
void ListStudent::Inp(string i) {
	fstream f;                    
	f.open("input.txt", ios::in);
	string b;
	while (!f.eof()) {
		size++;
		f << st[size - 1].id;
		getline(f, b, ' ');
		stringToChar(b, st[size - 1].name);
		f << st[size - 1].score;
		if (st[size - 1].score < 5)
			st[size - 1].grade = 'F';
		else if (st[size - 1].score >= 5 && st[size - 1].score < 6)
			st[size - 1].grade = 'D';
		else if (st[size - 1].score >= 6 && st[size - 1].score < 7)
			st[size - 1].grade = 'C';
		else if (st[size - 1].score >= 7 && st[size - 1].score < 8)
			st[size - 1].grade = 'B';
		else st[size - 1].grade = 'A';
	}
}
void ListStudent::Out() {
	cout << "id name score grade\n";
	for (int i = 0; i < size; i++)
		cout << st[size - 1].id << " " << st[size - 1].name << " " << st[size - 1].score 
		<< " " << st[size - 1].grade << endl;
}
int main()
{
	ListStudent test;
	test.Inp("Input.txt");
	test.Out();
	system("pause");
	return 0;
}