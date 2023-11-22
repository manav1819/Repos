#include <stdio.h>

int Afunc(int x, int y, int z, int v) {
    int c, d;
    c = x * z + y * z;
    d = c * x + v;
    printf("Inside Afunc:\n");
    printf("x: %d, y: %d, z: %d, v: %d\n", x, y, z, v);
    printf("c: %d, d: %d\n", c, d);
    printf("Stack addresses: &x=%p, &y=%p, &z=%p, &v=%p, &c=%p, &d=%p\n", (void*)&x, (void*)&y, (void*)&z, (void*)&v, (void*)&c, (void*)&d);
    return d;
}

int Cfunc(int g) {
    printf("Inside Cfunc:\n");
    printf("g: %d\n", g);
    printf("Stack addresses: &g=%p\n", (void*)&g);
    return (g * g * g + 5);
}

int Bfunc(int x1, int y1) {
    int c, d, result;
    c = x1 * y1 + x1;
    d = Afunc(x1, y1, c, 0);
    result = Cfunc(d);
    printf("Inside Bfunc:\n");
    printf("x1: %d, y1: %d\n", x1, y1);
    printf("c: %d, d: %d, result: %d\n", c, d, result);
    printf("Stack addresses: &x1=%p, &y1=%p, &c=%p, &d=%p, &result=%p\n", (void*)&x1, (void*)&y1, (void*)&c, (void*)&d, (void*)&result);
    return result;
}

int main() {
    int a, b, c, d, e;
    c = 3;
    d = 4;
    e = 5;
    b = 6;
    a = 20;
    printf("Inside main before Afunc:\n");
    printf("a: %d, b: %d, c: %d, d: %d, e: %d\n", a, b, c, d, e);
    printf("Stack addresses: &a=%p, &b=%p, &c=%p, &d=%p, &e=%p\n", (void*)&a, (void*)&b, (void*)&c, (void*)&d, (void*)&e);
    d = Afunc(b, c, e, a);
    b = Bfunc(a, c);
    return 0;
}
