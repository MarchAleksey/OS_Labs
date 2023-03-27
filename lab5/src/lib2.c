#include <stdio.h>
#include <stdlib.h>

void quickSort(int *array, int low, int high) {
    int i = low;
    int j = high;
    int pivot = array[(i + j) / 2];
    int temp;

    while (i <= j) {
        while (array[i] < pivot) i++;
        while (array[j] > pivot) j--;
        if (i <= j) {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            ++i;
            --j;
        }
    }
    if (j > low) quickSort(array, low, j);
    if (i < high) quickSort(array, i, high);
}

int * Sort(int * array, int size)
{
    quickSort(array, 0, size - 1);
    return array;
}

float binPow(float x, int y)
{
    float z = 1.0;
    while (y > 0) {
        if (y % 2 != 0) {
            z *= x;
        }
        x *= x;
        y /= 2;
    }
    return z;
}

float Sin(float x) {
    float result = 0.0;
    int n = 0;
    while (n <= 10) {
        float numerator = binPow(-1, n) * binPow(x, 2 * n + 1);
        float denominator = 1.0;
        for (int i = 1; i <= 2 * n + 1; i++) {
            denominator *= i;
        }
        result += numerator / denominator;
        n++;
    }
    return result;
}

float SinIntegral(float A, float B, float e) {
    float sum = (Sin(A) + Sin(B)) / 2.0;
    float x = A + e;
    while (x < B) {
        sum += Sin(x);
        x += e;
    }
    return sum * e;
}
