#include <iostream>
#include <vector>
#include <math.h>
#include "functions.h"

using namespace std;

class Screen {
    private:
        const int width = 120, height = 30;
        float aspect = (float)width / height;
        float pixelAspect = 11.0f / 24.0f;
        char* window = nullptr;
        char gradient[18] = " .:!/r(l1Z4H9W8$@";
        int gradientSize = size(gradient)-2;
    public:
        Screen() {
        	window = new char[width*height+1];
        	window[width*height] = '\0';
            for (int i = 0; i < width; i++)
            	for (int j = 0; j < height; j++)
            		window[i+j*width] = '@';
        }
        
        void circle (float r, float m) {
        	for (int i = 0; i < width; i++) {
	        	for (int j = 0; j < height; j++) {
	        		float x = (float)i / width * 2.0f - 1.0f;
	        		float y = (float)j / height * 2.0f - 1.0f;
	        		x *= aspect * pixelAspect;
	        		x += m;
	        		char pixel;
	        		float dist = sqrt(x*x+y*y);
	        		int color = clamp((int)(1.0f/dist), 0, gradientSize);
	        		pixel = gradient[color];
	        		window[i+j*width] = pixel;
	        	}
	        }
        }
        void display() const {
            cout << window;
        }
};

int main() {
    Screen scr = Screen();
    for (int t = 0; t < 10000; t++) {
    	scr.circle(0.5f, (float)sin(0.001*t));
    	scr.display();
	}
    return 0;
}