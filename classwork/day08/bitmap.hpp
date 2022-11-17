// 11/17/2022
// Preparation for this week's lab

// header file, since the extension is ".hh" or ".hpp"
#include <iostream>
#include <fstream>			// write to file
#include <random>			// use random numbers
#include <webp/decode.h> 	// still need to download, would use "-lwebp" when compiling
#include <webp/encode.h>  	// still need to download

using namespace std;

class bitmap {
private:
	uint32_t w, h;
	uint32_t* rgb; // pointer to the 
	void plotLineLow();
	void plotLineHigh();

public: 
	// constructors
	bitmap(uint32_t width, uint32_t height, uint32_t color);
	bitmap(const char filename[]); // not needed rn
	~bitmap(); 	// indicates that we can use a destructor

	// we are not implementing the copy funtions below
	bitmap(const bitmap& orig) = delete; 

	// functions

	// clear bitmap to certain color
	void clear(uint32_t color);

	void horiz_line(uint32_t x1, uint32_t x2, uint32_t y, uint32_t color);
	void vert_line(uint32_t y1, uint32_t y2, uint32_t x, uint32_t color);

	// makes shape at the (x,y) coordinate that has width = w and height = h with random colors inside
	void random(uint32_t x, uint32_t y, uint32_t w, uint32_t h);

	// create rectangle at (x,y) of width = w and height = h and put squares in side 
	void grid(uint32_t x, uint32_t y, uint32_t w , uint32_t h, uint32_t gridx, uint32_t gridy, uint32_t color);

	// https://www.google.com/search?client=safari&rls=en&q=bresenham%27s+line+algorithm&ie=UTF-8&oe=UTF-8
	void line();

	void rect(uint32_t x, uint32_t y, uint32_t w , uint32_t h);

	// extra functions
	void fill_rect(uint32_t x, uint32_t y, uint32_t w , uint32_t h);
	void round_rect(uint32_t x, uint32_t y, uint32_t w , uint32_t h);
	void circle();
	void fill_circle();
	void flood_fill_allcolor(uint32_t x, uint32_t y, uint32_t w , uint32_t h);
	void flood_fill_untilcolor(uint32_t x, uint32_t y, uint32_t w , uint32_t h);



	// Extra Credit 
	// https://en.wikipedia.org/wiki/Xiaolin_Wu%27s_line_algorithm
	void wuline();

	// essentiall a breadth first search that expands and changes the colors of pixels outwardly till hitting a barrier
	void flood_fill();
};