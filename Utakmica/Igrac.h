#pragma once
enum Pozicija{PG=1, SG, SF, F, C};
using namespace std;

class Igrac {
private:
	char ime[30], prezime[30];
	int brKoseva;
	Pozicija pozicija;
public:
	Igrac();
	Igrac(const Igrac& i);
	void setIme();
	void setPrezime();
	void setPozicija();
	void setBrKoseva(int a);
	char* getIme();
	char* getPrezime();
	int getBrKoseva();
	Pozicija getPozicija();
	friend istream& operator>>(istream& stream, Igrac& i);
	friend ostream& operator<<(ostream& stream, Igrac& i);
	~Igrac() = default;
};
