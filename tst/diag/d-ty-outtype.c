void f1(void) { int *a; const int *b; a = b; }
void f2(void) { int *a; volatile int *b; a = b; }
void f3(void) { int *a; volatile const int *b; a = b; }
void f4(void) { int *a; struct tag *x; a = x; }
void f5(void) { int *a; struct { int x; } *x; a = x; }
typedef struct t6 t6; void f6(void) { int *a; t6 *b; a = b; }
void f7(void) { int a; void *b; a = b; }
void f8(void) { int *a; float *b; a = b; }
void f9(void) { int *a; double *b; a = b; }
void f10(void) { int *a; char *b; a = b; }
void f11(void) { int *a; signed char *b; a = b; }
void f12(void) { int *a; unsigned char *b; a = b; }
void f13(void) { int *a; short *b; a = b; }
void f14(void) { int *a; signed short *b; a = b; }
void f15(void) { int *a; unsigned short *b; a = b; }
void f16(void) { char *a; signed int *b; a = b; }
void f17(void) { char *a; unsigned int *b; a = b; }
void f18(void) { int *a; long *b; a = b; }
void f19(void) { int *a; signed long *b; a = b; }
void f20(void) { int *a; unsigned long *b; a = b; }
void f21(void) { int *a; long double *b; a = b; }
void f22(void) { int **a; int * const *b; a = b; }
void f23(void) { int (*a)(int x, int *y); int *(*b)(void); a = b; }
void f24(void) { int (*a)(); int (*b)(int, ...); a = b; }
void f25(void) { int (*a)[2][3]; int (*b)[2][3][4]; a = b; }
void f26(void) { int (*a)[]; double (*b)[][]; a = b; }
void f27(void) { int *a; enum tag { X } *x; a = x; }
void f28(void) { int *a; enum { X } *x; a = x; }
typedef enum t29 { X } t29; void f29(void) { int *a; t29 *b; a = b; }