#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef SYSTEM
    #define PRINT_OS printf("Operation system: %s\n", SYSTEM)
#else
    #define PRINT_OS
#endif

#define CHECK_ERROR(expr, message) \
    do {                           \
        void* res = (expr);        \
        if (res == NULL) {         \
            perror(message);       \
            return -1;             \
        }                          \
    } while (0)

const int N = 2;
const char* names[] = {"./liblib1.so", "./liblib2.so"};

int main()
{
    int n = 0;
    void* handle;
    float (*SinIntegral)(float, float, float);
    int *(*Sort)(int *, int);
    CHECK_ERROR(handle = dlopen(names[n], RTLD_LAZY), "dlopen error");
    CHECK_ERROR(SinIntegral = dlsym(handle, "SinIntegral"), "dlsym error (SinIntegral)");
    CHECK_ERROR(Sort = dlsym(handle, "Sort"), "dlsym error (Sort)");
    while (1) {
        int t;
        scanf("%d", &t);

        if (t == 0) {
            n = (n + 1) % N;

            if (dlclose(handle) != 0) {
                perror("dlclose error");
                return -1;
            };

            CHECK_ERROR(handle = dlopen(names[n], RTLD_LAZY), "dlopen error");
            CHECK_ERROR(SinIntegral = dlsym(handle, "SinIntegral"), "dlsym error (SinIntegral)");
            CHECK_ERROR(Sort = dlsym(handle, "Sort"), "dlsym error (Sort)");
        }

        if (t == 1) {
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
        }

        if (t == 2) {
            int a, b, e;
            scanf("%d %d %d", &a, &b, &e);
            PRINT_OS;
            printf("SinIntegral: %f\n", (*SinIntegral)(a, b, e));
        }

        if (t == -1)
            break;
    }

    return 0;
}