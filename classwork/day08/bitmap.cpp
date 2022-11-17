#include "bitmap.hpp"
#include <fstream>			// write to file
#include <random>			// use random numbers
//#include <webp/decode.h> 	// still need to download, would use "-lwebp" when compiling
//#include <webp/encode.h>  	// still need to download


	bitmap(const char filename[]);
	~bitmap();

bitmap::bitmap(uint32_t w, uint32_t h, uint32_t color) : w(w), h(h){
	// you can initialize the object's variables using these two methods. the uncommented way is the more accepted way
	// this->w = w; OR use w(w)
	// this->h = h; OR use h(h)
	rgb = new uint32_t[w * h];
	for (int i = 0; i < w * h; i++) 
		rgb[i] = color;
}

bitmap::~bitmap() {
	delete [] rgb;
}

bitmap::clear() {
	for (int i = 0; i < w * h; i ++) {
		rgb[i] = color;
	}
}

// always have w, h, rgb
// we are treating pixels as one long array
void bitmap::horiz_line(uint32_t x1, uint32_t x2, uint32_t y, uint32_t color) {
	// x1 = 2, y - 1
	uint32_t pos1 = y * w + x1;
	uint32_t pos2 = y * w + x2;
	for (uint32_t i = pos1; i <= pos2; i++) {
		rgb[i] = color;
	}
}
void bitmap::vert_line(uint32_t y1, uint32_t y2, uint32_t x, uint32_t color);

// makes shape at the (x,y) coordinate that has width = w and height = h with random colors inside
void bitmap::random(uint32_t x, uint32_t y, uint32_t w, uint32_t h);

// create rectangle at (x,y) of width = w and height = h and put squares in side 
void bitmap::grid(uint32_t x, uint32_t y, uint32_t w , uint32_t h, uint32_t gridx, uint32_t gridy, uint32_t color);

void bitmap::save(const char filename[]) {
	uint8_t*out;
	size_t s = WebPEncodeRGBA((uint8_t*) rgb, w, h, 4*w, 100, &out);
	ofstream f(filename, ios::binary);
	f.write((char*) out, s);
	WebPFree(out);
}