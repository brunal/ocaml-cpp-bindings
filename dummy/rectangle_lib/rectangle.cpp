#include <iostream>
#include "rectangle.hpp"

#define INTS(a,b) "(" << (a) << "," << (b) << ")"
using namespace std;

Rectangle::Rectangle(int x, int y,
					 int longueur, int hauteur) {
	this->x = x;
	this->y = y;
	this->longueur = longueur;
	this->hauteur = hauteur;

	cout << "Created a rectangle at " << this << endl;
}

Rectangle::~Rectangle() {
	cout << "Detroyed a rectangle at " << this << endl;
}

void Rectangle::print() {
//	cout << "(" << x << "," << (y + hauteur) << ") - (")
	cout << INTS(x, y + hauteur) << " - " << INTS(x + longueur, y + hauteur) << endl
		 << INTS(x, y) << " - " << INTS(x + longueur, y) << endl;
}

int Rectangle::perimetre() {
	return (longueur + hauteur)*2;
}

int Rectangle::surface() {
	return longueur*hauteur;
}


int main(int argc, char** argv) {
	Rectangle r(3,2,5,6);
	r.print();
	cout << "P = " << r.perimetre() << endl
		 << "A = " << r.surface() << endl;

	Rectangle* r2 = new Rectangle(0,0,1,1);
	r2->print();
	delete r2;

	return 0;
}