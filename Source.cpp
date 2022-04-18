#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

struct date {
	int day;
	int month;
	int year;
};
struct person {
	string name;
	date birthday;
	string position = "�����������";
	int salary = 50000;
	//int salary = rand() % (55000 + 1 - 45000) + 45000; // ����� ������ ��������� �����
};

void printperson(person &P) {
	cout << P.name << " - " << P.position << endl;
	cout << "���� ��������: " << P.birthday.day << "." << P.birthday.month <<
		"." << P.birthday.year << endl;
	cout << "��������: " << P.salary << endl;
}

person inputperson() {
	person newP;
	cout << "������� ���: ";
	getline(cin, newP.name);
	cout << "������� ����: ";
	cin >> newP.birthday.day;
	cout << "������� �����: ";
	cin >> newP.birthday.month;
	cout << "������� ���: ";
	cin >> newP.birthday.year;
	cin.ignore();
	cout << "������� ���������: ";
	getline(cin, newP.position);
	cout << "������� �/�: ";
	cin >> newP.salary;
	cin.ignore();
	return newP;
}

void fillperson(person &P) {
	cout << "������� ���: ";
	getline(cin, P.name);
	cout << "������� ����: ";
	cin >> P.birthday.day;
	cout << "������� �����: ";
	cin >> P.birthday.month;
	cout << "������� ���: ";
	cin >> P.birthday.year;
	cin.ignore(); // ����� ������ ������ ����� cin, ����� ��������������� getline, ������ cin.ingnore()
	cout << "������� ���������: ";
	getline(cin, P.position);
	cout << "������� �/�: ";
	cin >> P.salary;
	cin.ignore(); // � ����� ����� ��� ����, ����� ����� ����� ���� ������������ ��� ������� getline
}

int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	// ��������� date � 4 ������
	struct date { // ������ ��������� date � 4 ������
		int day; // ����, �������� ����
		int month; // ����, �������� �����
		int year; // ����, �������� ���
		string note; // ���� � ������� �������
	} birthday, saleDay = { 18, 4, 2022, "���� ������" }; // ���������� � �������������� �������� ���������
	// ������ ������������ �������� ����� ������� birthday
	birthday.day = 1;
	birthday.month = 5;
	birthday.year = 1970;
	birthday.note = "���� �������� ����� ����";
	birthday = { 1, 5, 1970, "���� �������� ����� ����" }; // ����������� ���������� ����� ������� birthday
	//saleDay = birthday; // ������������ ����� ������� saleDay �������� ����� ������� birthday

	// ����� ����� birthday
	cout << birthday.day << "." << birthday.month << "." << 
		birthday.year << " - " << birthday.note << endl;
	// ����� ����� saleDay
	cout << saleDay.day << "." << saleDay.month << "." <<
		saleDay.year << " - " << saleDay.note << endl;

	date yesterday = { 17, 4, 2022, "��������� ����" }; // �������������� ������ �������� ������� ���������.
														// ����� ������� � ����� ����� ���������.
	// ����� ����� yesterday
	cout << yesterday.day << "." << yesterday.month << "." <<
		yesterday.year << " - " << yesterday.note << endl;

	
	person tom = { "��� ����" };
	//tom.birthday.day = 1;
	//tom.birthday.month = 4;
	//tom.birthday.year = 1985;
	tom.birthday = { 1, 4, 1985};
	person bob = { "��� �������", { 15, 12, 1970 } , "��������", 1200000 };

	printperson(tom);
	printperson(bob);

	// ����� ����� � ���� � ����
	cout << tom.name << " - " << tom.position << endl;
	cout << "���� ��������: " << tom.birthday.day << "." << tom.birthday.month << 
		"." << tom.birthday.year << endl;
	cout << "��������: " << tom.salary << endl;

	cout << bob.name << " - " << bob.position << endl;
	cout << "���� ��������: " << bob.birthday.day << "." << bob.birthday.month <<
		"." << bob.birthday.year << endl;
	cout << "��������: " << bob.salary << endl;

	person *ptom = &tom;
	cout << "���: " << ptom->name << endl;
	cout << "��� ��������: " << ptom->birthday.year << endl;
	ptom->salary += 10000;
	cout << "����� �/�: " << ptom->salary << endl;

	cout << "\n----------------------\n\n";
	person myPerson = inputperson();
	printperson(myPerson);

	cout << "\n----------------------\n\n";
	person badGuy;
	fillperson(badGuy);
	printperson(badGuy);

	struct point {
		int arr[5]; // ���� �� �������� ����� �������, ����� ����� �������������
	};
	point A = { { 1, 5, 2, 6, 9 } };


	return 0;
}