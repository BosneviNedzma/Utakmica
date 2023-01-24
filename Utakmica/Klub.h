#pragma once
#include "Igrac.h"
#include <vector>

class Klub {
private:
	char naziv[30];
	vector<Igrac> igraci;
public:
	Klub();
	void setNaziv();
	void setIgrac();
	char* getNaziv();
	vector<Igrac>& getIgraci();
	friend istream& operator>>(istream& stream, Klub& k);
	friend ostream& operator<<(ostream& stream, Klub& k);
	~Klub() = default;
};
