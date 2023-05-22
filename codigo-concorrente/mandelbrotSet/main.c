#include <stdio.h>
#include <omp.h>

// int mandelbrot(int real, int img) {
//     int iterations = 100;
//     int i;
// 	double zReal = real;
// 	double zImg = img;

// 	for (i = 0; i < iterations; i++) {
// 		double r2 = zReal * zReal;
// 		double i2 = zImg * zImg;
//         double dist2 = r2 + i2;
		
// 		if (dist2 > 4.0) return i;

// 		zImg = 2 * zReal * zImg + img;
// 		zReal = r2 - i2 + real;
// 	}

// 	return iterations;
// }

int main() {
    int width = 1920;
    int height = 1080;
    int value;
    int x, y;
    int i, j;

    double xStart = -2;
    double xEnd = 1;
    double yStart = -1;
    double yEnd = 1;

    double dx = (xEnd - xStart) / (width - 1);
    double dy = (yEnd - yStart) / (height - 1);

    int iterations = 100;
    int k;
    double zReal, zImg;
    double r2, i2, dist2;
    
    #pragma omp parallel for private(i, j)
    for(i = 0; i < width; i++) {
        for(j = 0; j < height; j++) {
            x = xStart + i * dx;
            y = yEnd - j * dy;

            zReal = x;
            zImg = y;
            value = iterations;

            #pragma omp parallel for private(k)
            for (k = 0; k < iterations; k++) {
                r2 = zReal * zReal;
                i2 = zImg * zImg;
                dist2 = r2 + i2;
                
                if (dist2 > 4.0) value = i;

                zImg = 2 * zReal * zImg + y;
                zReal = r2 - i2 + x;
            }
        }
    }

    return 0;
}