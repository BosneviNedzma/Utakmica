#include <iostream>
#include <ctime>
#include "Windows.h"
#include "Utakmica.h"
using namespace std;

int main() {
	Utakmica u;
	cin >> u;
	int x, prviNapad;
	srand(time(NULL));
	rand();
	prviNapad = rand() % 2;
	x = prviNapad;
	cout << "Prva cetvrtina: \n";
	for (int i = 0; i < 20; i++) {
		if (x == 0) {
			++u;
			x++;
			Sleep(1000);
		}
		else {
			u++;
			x--;
			Sleep(1000);
		}
	}
	cout << u;
	system('cls');
	x = (prviNapad + 1) % 2;
	cout << "Druga cetvrtina:\n";
	for (int i = 0; i < 20; i++) {
		if (x == 0) {
			++u;
			x++;
			Sleep(1000);
		}
		else {
			u++;
			x--;
			Sleep(1000);
		}
	}
	cout << u;
	system("cls");
	x = (prviNapad + 1) % 2;
	cout << "Treca cetvrtina: \n";
	for (int i = 0; i < 20; i++) {
		if (x == 0) {
			++u;
			x++;
			Sleep(1000);
		}
		else {
			u++;
			x--;
			Sleep(1000);
		}
	}
	cout << u;
	system("cls");
	x = prviNapad;
	cout << "Cetvrta cetvrtina: \n";
	for (int i = 0; i < 20; i++) {
		if (x == 0) {
			++u;
			x++;
			Sleep(1000);
		}
		else {
			u++;
			x--;
			Sleep(1000);
		}
	}
	cout << u;
	system("cls");
	int prod = 1;
	while (Utakmica::brKosevaDomaci == Utakmica::brKosevaGosti) {
		system("cls");
		cout << "Produzetak br. " << prod++ << ":\n";
		x = rand() % 2;
		for (int i = 0; i < 10; i++) {
			if (x == 0) {
				++u;
				x++;
				Sleep(1000);
			}
			else {
				u++;
				x--;
				Sleep(1000);
			}
		}
		cout << u;
	}
	if (prod == 1) {
		cout << u;
	}
	!u;
	return 0;
}