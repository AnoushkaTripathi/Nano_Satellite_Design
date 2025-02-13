#include <stdio.h>
#include <stdint.h>  // For int8_t and int16_t types

// Matrix dimensions
#define INPUT_ROWS 8
#define INPUT_COLS 8
#define KERNEL_ROWS 3
#define KERNEL_COLS 3
#define OUTPUT_ROWS (INPUT_ROWS - KERNEL_ROWS + 1)
#define OUTPUT_COLS (INPUT_COLS - KERNEL_COLS + 1)

// Function to perform 2D convolution
void Convolution2D(int8_t input[INPUT_ROWS][INPUT_COLS], int8_t kernel[KERNEL_ROWS][KERNEL_COLS], int8_t result[OUTPUT_ROWS][OUTPUT_COLS]) {
    for (int i = 0; i < OUTPUT_ROWS; ++i) {
        for (int j = 0; j < OUTPUT_COLS; ++j) {
            int16_t sum = 0;  // Use int16_t to prevent overflow
            // Element-wise multiplication and summation over the kernel
            for (int m = 0; m < KERNEL_ROWS; ++m) {
                for (int n = 0; n < KERNEL_COLS; ++n) {
                    sum += (int16_t)input[i + m][j + n] * (int16_t)kernel[m][n];
                }
            }
            // Cast back to int8_t and store result
            result[i][j] = (int8_t)sum;
        }
    }
}

// Function to print a matrix
void printMatrix(int8_t matrix[OUTPUT_ROWS][OUTPUT_COLS]) {
    for (int i = 0; i < OUTPUT_ROWS; ++i) {
        for (int j = 0; j < OUTPUT_COLS; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Define a 3x3 kernel
    int8_t kernel[KERNEL_ROWS][KERNEL_COLS] = {
        {-1, 0, 1},
        {-1, 0, 1},
        {-1, 0, 1}
    };

    // Define an 8x8 input matrix
    int8_t input[INPUT_ROWS][INPUT_COLS] = {
        {2, 1, 0, 2, 5, 6, 1, 3},
        {4, 4, 1, 1, 4, 7, 0, 5},
        {5, 4, 0, 4, 1, 2, 8, 1},
        {1, 2, 2, 1, 3, 4, 7, 2},
        {6, 3, 1, 0, 5, 2, 4, 3},
        {3, 1, 0, 1, 3, 3, 1, 0},
        {1, 4, 7, 3, 2, 3, 5, 2},
        {5, 2, 3, 6, 1, 4, 3, 1}
    };

    // Result matrix for 2D convolution
    int8_t result[OUTPUT_ROWS][OUTPUT_COLS];

    // Perform the convolution
    Convolution2D(input, kernel, result);

    // Display the result
    printf("Convolution Result:\n");
    printMatrix(result);

    return 0;
}

