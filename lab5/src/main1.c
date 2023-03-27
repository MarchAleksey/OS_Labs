#include "lib.h"
#include <stdio.h>
#include <stdlib.h>

#ifdef SYSTEM
    #define PRINT_OS printf("Operation system: %s\n", SYSTEM)
#else
    #define PRINT_OS
#endif

int main()
{
    while (1) {
        int target;
        scanf("%d", &target);

        if (target == 1) {
            int n;
            scanf("%d", &n);
            int *array = (int *) malloc(n * sizeof(int));
            for (int i = 0; i < n; i++) {
                scanf("%d", &array[i]);
            }
            array = Sort(array, n);
            PRINT_OS;
            printf("Sorted\n");
            for (int i = 0; i < n; i++) {
                printf("%d ", array[i]);
            }
            printf("\n");
        } else if (target == 2) {
            float a, b, e;
            scanf("%f %f %f", &a, &b, &e);
            PRINT_OS;
            printf("SinIntegral: %f\n", SinIntegral(a, b, e));
        } else if (target == -1)
            break;
    }
    
    return 0;
}