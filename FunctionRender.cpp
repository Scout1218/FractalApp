#include <iostream>
#include <string>
#include <fstream>
#include <stdint.h>
#include <tuple>
#include <stdexcept>
using namespace std;
double xmin, xmax, ymin, ymax, xres, yres;
uint16_t maxiter;
double mapToReal(int y), mapToImaginary(int x);
int findPoint(double cReal, double cImaginary, int maxIterations);
void findColor(int n, uint16_t maxiter);
int colorArray[3];
//tuple<int, int, int> colors(int n, uint16_t maxiter);
int main() {

	string filename;
	cout << "Enter options for the program.\nUsage is xmin, xmax, ymin, ymax, max iterations, x resolution, y resolution, and filename\nPress enter after every value" << endl;
	cin >> xmin >> xmax >> ymin >> ymax >> maxiter >> xres >> yres >> filename;
	filename += ".ppm";
	ofstream file(filename);
	if (file.is_open()) {
		file << "P3 \n" << xres << " " << yres << "\n255\n";
	}
	else {
		cout << "failed to open file" << endl;
		system("pause");
		return(0);
	}

	for (int y = 0; y < yres; y++) {
		for (int x = 0; x < xres; x++) {
			double cReal = mapToReal(x);
			double cImaginary = mapToImaginary(y);
			int pointVal = findPoint(cReal, cImaginary, maxiter);

			//tuple<int, int, int> colors(pointVal, maxiter); test tuples
			//file << get<0>(colors) << " " << get<1>(colors) << " " << get<2>(colors) << endl;
			findColor(pointVal, maxiter);
			file << colorArray[0] << " " << colorArray[1] << " " << colorArray[2] << endl;
		}
	}
	cout << "Calculations complete, check your files!" << endl;
	system("pause");
	return 0;
}
double mapToImaginary(int y) {
	double range = (ymax - ymin);
	return y * (range / yres) + ymin;
}
double mapToReal(int x) {
	double range = (ymax - ymin);
	return x * (range / xres) + xmin;
}
int findPoint(double cReal, double cImaginary, int maxIterations) {
	int i = 0;
	double zReal = 0.0, zImaginary = 0.0;
	while (i < maxIterations && zReal * zReal + zImaginary * zImaginary < 4.0)
	{
		double temp = zReal * zReal - zImaginary * zImaginary + cReal;
		zImaginary = 2.0 * zReal * zImaginary + cImaginary;
		zReal = temp;
		i++;
	}
	return i;
}
void findColor(int n, uint16_t maxiter) {
	double t = (double)n / (double)maxiter;
	colorArray[0] = (int)(9 * (1 - t)*t*t*t * 255);
	colorArray[1] = (int)(15 * (1 - t)*(1 - t)*t*t * 255);
	colorArray[2] = (int)(8.5*(1 - t)*(1 - t)*(1 - t)*t * 255);
}
/*tuple<int, int, int> colors(int n, uint16_t maxiter) {
	double t = (double)n / (double)maxiter;
	int r = (int)(9 * (1 - t)*t*t*t * 255);
	int g = (int)(15 * (1 - t)*(1 - t)*t*t * 255);
	int b = (int)(8.5*(1 - t)*(1 - t)*(1 - t)*t * 255);
	return make_tuple(r, g, b);
}*/


