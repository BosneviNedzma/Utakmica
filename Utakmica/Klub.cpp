#include "Klub.h"
using namespace std;

Klub::Klub() {

}

void Klub::setNaziv() {
	cout << "Unesite naziv kluba: ";
	cin.getline(this->naziv, 30);
}

void Klub::setIgrac() {
	Igrac temp;
	cin >> temp;
	this->igraci.push_back(temp);
}

char* Klub::getNaziv() {
	return this->naziv;
}

vector<Igrac>& Klub::getIgraci() {
	return this->igraci;
}

istream& operator>>(istream& stream, Klub& k) {
	k.setNaziv();
	for (int i = 0; i < 5; i++) {
		cout << "Unos igraca br. " << i + 1 << ":\n";
		k.setIgrac();
	}
	return stream;
}

ostream &operator<<(ostream &stream, Klub& k) {
	stream << k.getNaziv() << "\n";
	for (int i = 0; i < k.getIgraci().size(); i++) {
		stream << "\t" << k.getIgraci()[i] << endl;
	}
	return stream;
}