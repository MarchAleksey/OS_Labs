#include <stdio.h>
#include <stdlib.h>

void Swap(int * a, int * b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int * Sort(int * array, int size)
{
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j+1]) {
                Swap(&array[j], &array[j+1]);
            }
        }
    }
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
    float sum = 0.0;
    float x = A;
    while (x <= B) {
        sum += Sin(x) * e;
        x += e;
    }
    return sum;
}
