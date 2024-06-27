#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

#define load_symbol(handle, container, fname) \
	*(void**)(container) = dlsym(handle, fname); \
	if (dlerror() != NULL) { \
		(void)dlclose(handle); \
		return NULL; \
	}

static struct
{
    int (*add)(int, int);
    int (*minus)(int, int);
} libsum;

int main() {
	// while(1){}

    void *handle = dlopen("./libsum.so", RTLD_NOW | RTLD_GLOBAL);
	if (!handle) {
		return 1;
	}

    (void)dlerror();
	load_symbol(handle, &libsum.add, "add");
	load_symbol(handle, &libsum.minus, "minus");

    printf("symbol add succeed\n");

    int a = libsum.add(2, 3);
    printf("%d\n", a);
    int b = libsum.minus(2, 3);
    printf("%d\n", b);

}