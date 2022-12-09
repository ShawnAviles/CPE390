// Lab 06 
// Shawn Aviles and Thomas Byrnes

#pragma once

#include "shape.hh"

class pyramid : public shape { // a pyramid is_a shape
private:
	double w; // layer width
	double H; // height of total pyramid
	double t; // layer thickness

public:
	pyramid(double w) : 
		w(w), H(w) {
	}
	void draw_layer(std::ostream& gc,double x, double y, double layer_thickness, double z) const override;	
	double height() const override;
};
