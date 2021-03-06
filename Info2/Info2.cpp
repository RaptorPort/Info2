// Info2.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//


#include "stdafx.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include <iostream>

using namespace std;

void swap(int*a, int*b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int add(int a, int b, int c = 0, int d = 0)
{
	return a + b + c + d;
}



class computer {
	friend  ostream& operator<< ( ostream &o, const computer& c) {
		o << "Marke: " << c.marke << "Ram: " << c.ram;
		return o;
	};
private:
	char *marke;
	int ram;
public:
	computer(char *m, int r);
	computer() {
		marke = (char*)malloc(1); *marke = 0; ram = 0;
	}
	~computer() { free(marke); }

	computer(computer&cmp)
	{
		ram = cmp.ram;

		marke = (char*)malloc(sizeof(strlen(cmp.marke) + 1));

		strcpy(marke, cmp.marke);
	}

	computer& operator=(const computer& cmp)
	{
		char *tmp;
		tmp = (char*)malloc(sizeof(strlen(cmp.marke) + 1));
		strcpy(tmp, cmp.marke);

		free(marke);

		marke = tmp;

		ram = cmp.ram;
		return *this;
	}

};
computer::computer(char *m, int r) {
	if (m != 0) {
		marke = (char*)malloc(sizeof(strlen(m) + 1));
		strcpy(marke, m);
	}
	else
		marke = 0;
	if (r  > 1000)
		ram = r;
	else
		ram = 1000;
}

class person
{
private:
	char *name;
	int alter;
	int vermoegen;
	computer bf;

public:
	person(char *n, int a, int v, char *m, int r);
	void print() {  cout << "Ausgabe von " << name << " Alter " << alter << " Vermoegen " << vermoegen << bf; }
	~person() {  cout << "~person" <<  endl; free(name); }
	person(const person& p);

};

person::person(char *n, int a, int v, char *m, int r) : bf(m, r)
{
	if (n != 0)
	{
		name = (char*)malloc(sizeof(strlen(n) + 1));
		strcpy(name, n);
	}
	else
		name = 0;
	if (a > 0 && a < 100)
		alter = a;
	else
		alter = 1;
	if (v > 1000)
		vermoegen = v;
	else
		vermoegen = 1000;
};

person::person(const person& p) {
	alter = p.alter;
	bf = p.bf;
	name = (char*)malloc(strlen(p.name) + 1);
	strcpy(name, p.name);
	vermoegen = p.vermoegen;
}

void f(person p) {
	 
}

int main()
{
	int weiter = 0;
	int x;
	char niconame[5] = "Nico";
	char pcname[6] = "Jesus";
	person* nico = new person(niconame, 69, 1111, pcname, 4269);
	nico->print();
	f(*nico);

	delete nico;


	 cout << "Weiter? 1 Ja, 0 Nein.";
	 cin >> weiter;

	if (weiter > 1)
	{
		int x = 1, y = 2;
		int z;

		 cout << "x,y = " << x << ',' << y << '\n';

		swap(&x, &y);

		 cout << "x,y(swap) = " << x << ',' << y << '\n';

		 cout << "1. Zahl: ";
		 cin >> x;
		 cout << "2.Zahl: ";
		 cin >> y;
		 cout << "3.Zahl: ";
		 cin >> z;

		 cout << "Ergebnis: " << add(x, y, z) << '\n';
		 cout << "Ergebnis2: " << add(x, y, z, 2) << '\n';
	}




	 cin >> x;

	return 0;
}