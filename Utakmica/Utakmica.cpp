#include <ctime>
#include "Utakmica.h"
using namespace std;

int Utakmica::brKosevaDomaci = 0;
int Utakmica::brKosevaGosti = 0;

void Utakmica::setDatum() {
	cout << "Unesite datum utakmice: ";
	cin.getline(this->datum, 15);
}

void Utakmica::setDomaci() {
	cout << "Unesite domacina:\n";
	cin >> domaci;
}

void Utakmica::setGosti() {
	cout << "Unesite gosta:\n";
	cin >> gosti;
}

char* Utakmica::getDatum() {
	return this->datum;
}

Klub& Utakmica::getDomaci() {
	return this->domaci;
}

Klub& Utakmica::getGosti() {
	return this->gosti;
}

void Utakmica::operator++() {
	srand(time(NULL));
	rand();
	int x = rand() % 4;
	if (x == 0) {
		cout << "---------------------\n";
		cout << this->getDomaci().getNaziv() << " " << Utakmica::brKosevaDomaci << " : " << Utakmica::brKosevaGosti << " " << this->getGosti().getNaziv() << endl;
		cout << "Izgubljena lopta " << this->getDomaci().getNaziv();
		cout << "---------------------\n";
	}
	else {
		Utakmica::brKosevaDomaci += x;
		cout << "---------------------\n";
		cout << this->getDomaci().getNaziv() << " " << Utakmica::brKosevaDomaci << " : " << Utakmica::brKosevaGosti << " " << this->getGosti().getNaziv() << endl;
		int y = rand() % 5;
		this->getDomaci().getIgraci()[y].setBrKoseva(x);
		cout << this->getDomaci().getIgraci()[y].getIme() << " " << this->getDomaci().getIgraci()[y].getPrezime() << " " << x << "p\n";
		cout << "---------------------\n";
	}
}

void Utakmica::operator++(int) {
	srand(time(NULL));
	rand();
	int x = rand() % 4
		;
	if (x == 0) {
		cout << "---------------------\n";
		cout << this->getDomaci().getNaziv() << " " << Utakmica::brKosevaDomaci << " : " << Utakmica::brKosevaGosti << " " << this->getGosti().getNaziv() << endl;
		cout << "Izgubljena lopta " << this->getGosti().getNaziv();
		cout << "---------------------\n";
	}
	else {
		Utakmica::brKosevaGosti += x;
		cout << "---------------------\n";
		cout << this->getDomaci().getNaziv() << " " << Utakmica::brKosevaDomaci << " : " << Utakmica::brKosevaGosti << " " << this->getGosti().getNaziv() << endl;
		int y = rand() % 5;
		this->getGosti().getIgraci()[y].setBrKoseva(x);
		cout << this->getGosti().getIgraci()[y].getIme() << " " << this->getGosti().getIgraci()[y].getPrezime() << " " << x << "p\n";
		cout << "---------------------\n";
	}
}

void Utakmica::operator!() {
	int max1 = INT_MIN, max2 = INT_MIN, indeks1, indeks2;
	for (int i = 0; i < this->getDomaci().getIgraci().size(); i++) {
		if (this->getDomaci().getIgraci()[i].getBrKoseva > max1) {
			max1 = this->getDomaci().getIgraci()[i].getBrKoseva();
			indeks1 = i;
		}
	}
	for (int i = 0; i < this->getGosti().getIgraci().size(); i++) {
		if (this->getDomaci().getGosti()[i].getBrKoseva > max2) {
			max1 = this->getGosti().getIgraci()[i].getBrKoseva();
			indeks2 = i;
		}
	}
	if (max1 > max2) {
		cout << "MVP utakmice je " << this->getDomaci().getIgraci()[indeks1] << " poena\n";
	}
	else if (max1 < max2) {
		cout << "MVP utakmice je " << this->getGosti().getIgraci()[indeks2] << " poena\n";
	}
	else {
		if (Utakmica::brKosevaDomaci > Utakmica::brKosevaGosti) {
			std::cout << "MVP utakmice je "
				<< this->getDomaci().getIgraci()[indeks1] << " poena\n";
		}
		else {
			std::cout << "MVP utakmice je "
				<< this->getGosti().getIgraci()[indeks2] << " poena\n";
		}
	}
}


istream& operator>>(istream &stream, Utakmica &u) {
	u.setDatum();
	u.setDomaci();
	u.setGosti();
	return stream;
}

ostream& operator<<(ostream& stream, Utakmica& u) {
	stream << "--------------------------------------\n";
	stream << u.getDomaci().getNaziv() << " " << Utakmica::brKosevaDomaci << " : "
		<< Utakmica::brKosevaGosti << " " << u.getGosti().getNaziv()
		<< "-----------------------------------------\n";
	for (int i = 0; i < u.getDomaci().getIgraci().size(); i++) {
		stream << u.getDomaci().getIgraci()[i] << "\t"
			<< u.getGosti().getIgraci()[i] << endl;
	}
	return stream;
}