#include "Igrac.h"
#include <iomanip>
using namespace std;

Igrac::Igrac() {
	strcpy(this->ime, "Niko");
	strcpy(this->prezime, "Nikic");
	this->brKoseva = 0;
	this->pozicija = PG;
}

Igrac::Igrac(const Igrac& i) {
	strcpy(this->ime, i.ime);
	strcpy(this->prezime, i.prezime);
	this->brKoseva = i.brKoseva;
	this->pozicija = i.pozicija;
}

void Igrac::setIme() {
	cout << "Unesite ime: ";
	cin.getline(this->ime, 30);
}

void Igrac::setPrezime() {
	cout << "Unesite prezime: ";
	cin.getline(this->prezime, 30);
}

void Igrac::setPozicija() {
	int x;
	do {
		cout << "Unesite poziciju igraca: ";
		cin >> x;
	} while (x < 1 || x>5);
	cin.ignore();
	this->pozicija = static_cast<Pozicija>(x);
}

void Igrac::setBrKoseva(int a) {
	this->brKoseva += a;
}

char *Igrac::getIme() {
	return this->ime;
}

char* Igrac::getPrezime() {
	return this->prezime;
}

int Igrac::getBrKoseva() {
	return this->brKoseva;
}

Pozicija Igrac::getPozicija() {
	return this->pozicija;
}

istream& operator>>(istream& stream, Igrac& i) {
	i.setIme();
	i.setPrezime();
	i.setPozicija();
	return stream;
}

ostream& operator<<(ostream& stream, Igrac& i) {
	switch (i.getPozicija()) {
	case PG:
		stream << setw(2) << setfill(' ') << right << "PG";
		break;
	case SG:
		stream << setw(2) << setfill(' ') << right << "SG";
		break;
	case SF:
		stream << setw(2) << setfill(' ') << right << "SF";
		break;
	case F:
		stream << setw(2) << setfill(' ') << right << "F";
		break;
	case C:
		stream << setw(2) << setfill(' ') << right << "C";
		break;
	default:
		break;
	}

	stream << " " << i.getIme() << " " << i.getPrezime() << "\t" << i.getBrKoseva();
	return stream;
	

}