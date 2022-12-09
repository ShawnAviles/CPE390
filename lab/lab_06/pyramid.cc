// Lab 06 
// Shawn Aviles and Thomas Byrnes

#include "pyramid.hh"
#include <numbers>
#include <cmath>
using namespace std;
using namespace std::numbers;

void pyramid::draw_layer(ostream& gc, double x, double y, double layer_thickness, double z) const {
	// variables for pyramid
	double wi = w - z; 					// new width, updates width on each layer draw

	// variables for filling in pyramid
	double currX = x-wi/2;
	double currY = y-wi/2;
	
	goto_xyz(gc, currX, currY, z);		// start at bottom left

	// fill layer
	while (currY >= y - wi/2 && currY <= y + wi/2) {
		currX = -currX;

		squirt_toxy(gc, currX, currY);	// horizontal
		currY += layer_thickness;

		squirt_toxy(gc, currX, currY);  // vertical
	}
}

double pyramid::height() const {
	return H;
}
