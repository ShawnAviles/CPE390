#include <fstream>
#include "bitmap.hh"
#include <webp/decode.h>
#include <webp/encode.h>
#include <random>

using namespace std;
/*

	AUTHOR: your name goes here
	CITE: cite any sources you used other than the ones given
	PLEDGE
*/

/*
	In order to compile you will need to install libwebp, a new graphics
	standard from google. Most image programs won't yet work with webp,
	which is better compression than jpeg in general.

	In order to install under msys2: 
	https://packages.msys2.org/package/mingw-w64-x86_64-libwebp

	Using Multipass Linux Shell Run Command:
	sudo apt-get install -y libwebp-dev

	In order to access a particular element of thi bitmap (x,y) use the
	following equation point(x,y) does this

	y*w + x

	this works because the first point is 0*w+0 = 0, the second would be 0*w+1

	one row down would be 1*w + 0

	Run File (after installing libwebp):
	make
	./testbitmap
 */ 


bitmap::bitmap(uint32_t w, uint32_t h, uint32_t color) : w(w), h(h), rgb(new uint32_t[w*h]) {
	for (uint32_t i = 0; i < w*h; i++)
		rgb[i] = color;
}

bitmap::~bitmap() {
	delete [] rgb;
}

void bitmap::clear(uint32_t color) {
	for (uint32_t i = 0; i < w*h; i++)
		rgb[i] = color;
}

void bitmap::horiz_line(uint32_t x1, uint32_t x2, uint32_t y, uint32_t color) {
	for (uint32_t i = y * w + x1; i <= y * w + x2; i++) rgb[i] = color;
}

void bitmap::vert_line(uint32_t y1, uint32_t y2, uint32_t x, uint32_t color) {
	for (uint32_t i = y1 * w + x; i <= y2 * w; i += w) {
		rgb[i] = color;
	}
}

void bitmap::fill_rect(uint32_t x0, uint32_t y0, uint32_t w, uint32_t h, uint32_t color) {
	for (uint32_t y = y0; y <= y0 + h; y++) {
		horiz_line(x0, x0 + w, y, color);
	}
	// First Attempt:
	// for (uint32_t i = (y0 * this->w + x0); i <= ((y0 + h) * this->w); i += this->w) { // vertical
	// 	horiz_line(x0, x0 + w, (i - x0) / this->w, color);
	// }
}

void bitmap::rect(uint32_t x0, uint32_t y0, uint32_t w, uint32_t h, uint32_t color) {
	horiz_line(x0, x0 + w, y0, color);
	horiz_line(x0, x0 + w, y0 + h, color);
	vert_line(y0, y0 + h, x0, color);
	vert_line(y0, y0 + h, x0 + w, color);
}

// divx = cols, divy = rows 
void bitmap::grid(uint32_t x0, uint32_t y0, uint32_t w, uint32_t h, uint32_t divx, uint32_t divy, uint32_t color) {
	uint32_t deltaX = w / divx;
	uint32_t deltaY = h / divy;

	for (uint32_t x = x0; x < x0 + w - deltaX; x+= deltaX) {
		for (uint32_t y = y0; y <= y0 + h - deltaY; y+= deltaY) {
			rect(x, y, deltaX, deltaY, color);
		}
	}
}

std::default_random_engine gen;


//https://stackoverflow.com/questions/22853349/how-to-generate-random-32bit-integers-in-c
void bitmap::random(uint32_t x0, uint32_t y0, uint32_t rw, uint32_t rh) {
	// used for random number
	default_random_engine generator;
	uniform_int_distribution<uint32_t> distribution(0, 0xFFFFFFFF);

	for (uint32_t y = y0; y <= y0 + rh; y++) {
		for (uint32_t i = y * this->w + x0; i <= y * this->w + (x0 + rw); i++) {
			uint32_t randomColor = distribution(generator);
			rgb[i] = randomColor;
		}
	}
}


void bitmap::circle(uint32_t x, uint32_t y, uint32_t d, uint32_t color) {
	uint32_t tempX = d/2;
	uint32_t tempY = 0;

	// input handling
	if (d/2 <= 0) rgb[y * w + x] = color;

	rgb[(y - tempY) * w + (x + tempX)] = color;
	rgb[(y + tempX) * w + (x + tempY)] = color;
	rgb[(y + tempY) * w + (x - tempX)] = color;
	rgb[(y - tempX) * w + (x - tempY)] = color;

	// P has to be an integer, using uint64_t and uint32_t creates a diamond instead of a circle
	int P = 1 - d/2;
	while (tempX > tempY) {
		tempY++;

		// check midpoint inside of the perimeter
		if (P <= 0) {
			P += 2*tempY + 1;
		}
		else {
			tempX--;
			P += 2*tempY - 2*tempX + 1;
		}

		if (tempX < tempY) break;

		rgb[(y + tempY) * w + (x + tempX)] = color;
		rgb[(y - tempY) * w + (x + tempX)] = color;
		rgb[(y + tempY) * w + (x - tempX)] = color;
		rgb[(y - tempY) * w + (x - tempX)] = color;

		if (tempX != tempY) {
			rgb[(y + tempX) * w + (x + tempY)] = color;
			rgb[(y - tempX) * w + (x + tempY)] = color;
			rgb[(y + tempX) * w + (x - tempY)] = color;
			rgb[(y - tempX) * w + (x - tempY)] = color;
		}
	}
}

//https://stackoverflow.com/questions/1201200/fast-algorithm-for-drawing-filled-circles
void bitmap::fill_circle(uint32_t x0, uint32_t y0, uint32_t d, uint32_t color) {
	for (uint32_t r = d/2; r > 0; r--) {
		circle(x0, y0, 2*r, color);
	}
}


void bitmap::save(const char filename[]) {
	uint8_t*out;
	size_t s = WebPEncodeRGBA((uint8_t*)rgb, w, h, 4*w, 100, &out);
	ofstream f(filename, ios::binary);
	f.write((char*)out, s);
	WebPFree(out);
}


// Optional: Bonus points
// Approach: Recursive BFS
void bitmap::flood_fill_allcolor(uint32_t x, uint32_t y,uint32_t findcolor, uint32_t replace_color) {
	// Base Case - make sure its in bounds and the right color before changing it
	// Check for valid x and y positions
	if (x < 0 || x > w - 1 && y < 0 || y > h - 1) {
		return;
	}
	// Stop if we hit a color thats not the original or the color is already changed
	if (rgb[y * w + x] != findcolor && rgb[y * w + x] == replace_color) {
		return;
	}

	// replace current pixel with new color, since its a valid point
	rgb[y * w + x] = replace_color;

	// Recursive Step - Apply to all neighboring pixels
	flood_fill_allcolor(x+1, y, findcolor, replace_color);
	flood_fill_allcolor(x-1, y, findcolor, replace_color);
	flood_fill_allcolor(x, y+1, findcolor, replace_color);
	flood_fill_allcolor(x, y-1, findcolor, replace_color);
}
