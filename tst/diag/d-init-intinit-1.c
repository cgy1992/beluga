char a1[] = { { 1 }, { 2 }, { 3 }, 4 };
char a2[] = { { { 1 }, { 2 }, }, { 3 }, { { 4 } } };
char a3[] = { 1, a1 };
char a4[] = { 1, a2[0] };
struct t { const int x:32, :6, y:4; };
struct t t6 = { -2147483647-1, -9 };
struct t t7 = { 2147483647, 8 };
struct s { unsigned x:32, :6, y:4; };
struct s t9 = { { { 4294967295 } }, 16 };
struct s t10 = { { -2147483647-1, }, -16 };
