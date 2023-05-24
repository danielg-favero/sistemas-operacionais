#include <stdio.h>
#include <stdlib.h>
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
    int i, j;

    int iterations = 100;
    int k;

    unsigned char *image = (unsigned char *)malloc(width * height * sizeof(unsigned char));

    #pragma omp parallel for private(i, j) shared(image)
    for(i = 0; i < height; i++) {
        for(j = 0; j < width; j++) {
            double x = (j - width / 2.0) * 4.0 / width;
            double y = (i - height / 2.0) * 4.0 / width;

            double zReal = 0;
            double zImg = 0;
            
            int value = iterations;

            for (k = 0; k < iterations; k++) {
                double r2 = zReal * zReal;
                double i2 = zImg * zImg;
                double dist2 = r2 + i2;
                
                if (dist2 >= 4.0) {
                    value = k;
                    k = iterations;
                }

                zImg = 2 * zReal * zImg + y;
                zReal = r2 - i2 + x;
            }
            
            unsigned char color = (unsigned char)(255 * (value / (double)iterations));
            image[i * width + j] = color;
        }
    }

    FILE *file = fopen("mandelbrot.pgm", "wb");
    fprintf(file, "P5\n%d %d\n255\n", width, height);
    fwrite(image, sizeof(unsigned char), width * height, file);
    fclose(file);
    
    free(image);

    return 0;
}