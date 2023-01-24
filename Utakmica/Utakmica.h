#pragma once
#include "Klub.h"
using namespace std;

class Utakmica {
private:
	char datum[15];
	Klub domaci, gosti;

public:
	static int brKosevaDomaci, brKosevaGosti;
	Utakmica() {};
	void setDatum();
	void setDomaci();
	void setGosti();
	char* getDatum();
	Klub& getDomaci();
	Klub& getGosti();
	friend istream& operator>>(istream& stream, Utakmica& u);
	friend ostream& operator<<(ostream& stream, Utakmica& u);
	void operator++();
	void operator++(int);
	void operator!();
	~Utakmica() = default;
};