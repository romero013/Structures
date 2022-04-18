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
	string position = "программист";
	int salary = 50000;
	//int salary = rand() % (55000 + 1 - 45000) + 45000; // Можно задать случайное число
};

void printperson(person &P) {
	cout << P.name << " - " << P.position << endl;
	cout << "Дата рождения: " << P.birthday.day << "." << P.birthday.month <<
		"." << P.birthday.year << endl;
	cout << "Зарплата: " << P.salary << endl;
}

person inputperson() {
	person newP;
	cout << "Введите имя: ";
	getline(cin, newP.name);
	cout << "Введите день: ";
	cin >> newP.birthday.day;
	cout << "Введите месяц: ";
	cin >> newP.birthday.month;
	cout << "Введите год: ";
	cin >> newP.birthday.year;
	cin.ignore();
	cout << "Введите должность: ";
	getline(cin, newP.position);
	cout << "Введите з/п: ";
	cin >> newP.salary;
	cin.ignore();
	return newP;
}

void fillperson(person &P) {
	cout << "Введите имя: ";
	getline(cin, P.name);
	cout << "Введите день: ";
	cin >> P.birthday.day;
	cout << "Введите месяц: ";
	cin >> P.birthday.month;
	cout << "Введите год: ";
	cin >> P.birthday.year;
	cin.ignore(); // после череды вводов через cin, перед использорванием getline, вводим cin.ingnore()
	cout << "Введите должность: ";
	getline(cin, P.position);
	cout << "Введите з/п: ";
	cin >> P.salary;
	cin.ignore(); // в конце пишем для того, чтобы потом можно было использовать без проблем getline
}

int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	// Структура date с 4 полями
	struct date { // создаём структуру date с 4 полями
		int day; // поле, хранящее день
		int month; // поле, хранящее месяц
		int year; // поле, хранящее год
		string note; // поле с записью события
	} birthday, saleDay = { 18, 4, 2022, "День продаж" }; // объявление и иинициализация объектов структуры
	// Прямое присваивание значений полям объекта birthday
	birthday.day = 1;
	birthday.month = 5;
	birthday.year = 1970;
	birthday.note = "День Рождения моего папы";
	birthday = { 1, 5, 1970, "День Рождения моего папы" }; // мнгновенное заполнение полей объекта birthday
	//saleDay = birthday; // Присваивание полям объекта saleDay значений полей объекта birthday

	// Вывод полей birthday
	cout << birthday.day << "." << birthday.month << "." << 
		birthday.year << " - " << birthday.note << endl;
	// Вывод полей saleDay
	cout << saleDay.day << "." << saleDay.month << "." <<
		saleDay.year << " - " << saleDay.note << endl;

	date yesterday = { 17, 4, 2022, "Вчерашняя дата" }; // альтернативный способ создания объекта структуры.
														// можно создать в любом месте программы.
	// вывод полей yesterday
	cout << yesterday.day << "." << yesterday.month << "." <<
		yesterday.year << " - " << yesterday.note << endl;

	
	person tom = { "Том Смит" };
	//tom.birthday.day = 1;
	//tom.birthday.month = 4;
	//tom.birthday.year = 1985;
	tom.birthday = { 1, 4, 1985};
	person bob = { "Боб Томпсон", { 15, 12, 1970 } , "директор", 1200000 };

	printperson(tom);
	printperson(bob);

	// Вывод полей о Томе и Бобе
	cout << tom.name << " - " << tom.position << endl;
	cout << "Дата рождения: " << tom.birthday.day << "." << tom.birthday.month << 
		"." << tom.birthday.year << endl;
	cout << "Зарплата: " << tom.salary << endl;

	cout << bob.name << " - " << bob.position << endl;
	cout << "Дата рождения: " << bob.birthday.day << "." << bob.birthday.month <<
		"." << bob.birthday.year << endl;
	cout << "Зарплата: " << bob.salary << endl;

	person *ptom = &tom;
	cout << "Имя: " << ptom->name << endl;
	cout << "Год рождения: " << ptom->birthday.year << endl;
	ptom->salary += 10000;
	cout << "Новая з/п: " << ptom->salary << endl;

	cout << "\n----------------------\n\n";
	person myPerson = inputperson();
	printperson(myPerson);

	cout << "\n----------------------\n\n";
	person badGuy;
	fillperson(badGuy);
	printperson(badGuy);

	struct point {
		int arr[5]; // если не передать длину массива, длина будет универсальной
	};
	point A = { { 1, 5, 2, 6, 9 } };


	return 0;
}