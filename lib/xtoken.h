/*
 *  token definitions;
 *  ASSUMPTION: 7-bit ASCII or its superset for the source character set
 */


/* ASCII         enum  code prec     op     tree-func    token-set       string    need-sp */
/* NUL */  yy(0,          0,  0, 0,       0,           0,            0,                    0)
/* (TY_FLOAT == LEX_FLOAT) must come first; see ty.h and sym.c */
/* SOH */  xx(FLOAT,      1,  0, 0,       0,           LEX_CHAR,     "float",              0)
/* STX */  xx(DOUBLE,     2,  0, 0,       0,           LEX_CHAR,     "double",             0)
/* ETX */  xx(LDOUBLE,    3,  0, 0,       0,           0,            0,                    0)
/* EQT */  xx(CHAR,       4,  0, 0,       0,           LEX_CHAR,     "char",               0)
/* ENQ */  xx(SHORT,      5,  0, 0,       0,           LEX_CHAR,     "short",              0)
/* ACK */  xx(INT,        6,  0, 0,       0,           LEX_CHAR,     "int",                0)
/* BEL */  xx(ENUM,       7,  0, 0,       0,           LEX_CHAR,     "enum",               0)
/* BS  */  xx(UNSIGNED,   8,  0, 0,       0,           LEX_CHAR,     "unsigned",           0)
/* HT  */  xx(LONG,       9,  0, 0,       0,           LEX_CHAR,     "long",               0)
/* NL  */  xx(ULONG,     10,  0, 0,       0,           0,            0,                    0)
/* VT  */  xx(POINTER,   11,  0, 0,       0,           0,            0,                    0)
/* FF  */  xx(VOID,      12,  0, 0,       0,           LEX_CHAR,     "void",               0)
/* CR  */  xx(STRUCT,    13,  0, 0,       0,           LEX_CHAR,     "struct",             0)
/* (LEX_FLOAT ~ LEX_STRUCT) must be sequential and below 16; see ty.h and op.h */
/* SO  */  xx(UNION,     14,  0, 0,       0,           LEX_CHAR,     "union",              0)
/* SI  */  xx(FUNCTION,  15,  0, 0,       0,           0,            0,                    0)
/* DLE */  xx(ARRAY,     16,  0, 0,       0,           0,            0,                    0)
/* (TY_ARRAY == LEX_ARRAY) must be the last and < (TY_CONST == LEX_CONST); see ty.h and sym.c */
/* DC1 */  yy(0,         17,  0, 0,       0,           0,            0,                    0)
/* DC2 */  yy(0,         18,  0, 0,       0,           0,            0,                    0)
/* DC3 */  yy(0,         19,  0, 0,       0,           0,            0,                    0)
/* DC4 */  xx(CREM,      20,  2, 0,       0,           0,            "%=",                 2)
/* NAK */  xx(CBAND,     21,  2, 0,       0,           0,            "&=",                 2)
/* SYN */  xx(CMUL,      22,  2, 0,       0,           0,            "*=",                 2)
/* ETB */  xx(CADD,      23,  2, 0,       0,           0,            "+=",                 2)
/* CAN */  xx(CSUB,      24,  2, 0,       0,           0,            "-=",                 2)
/* EN  */  xx(CDIV,      25,  2, 0,       0,           0,            "/=",                 2)
/* SUB */  xx(CRSHFT,    26,  2, 0,       0,           0,            ">>=",                2)
/* ESC */  xx(CLSHFT,    27,  2, 0,       0,           0,            "<<=",                2)
/* FS  */  xx(CBXOR,     28,  2, 0,       0,           0,            "^=",                 0)
/* GS  */  xx(CBOR,      29,  2, 0,       0,           0,            "|=",                 2)
/* RS  */  xx(ID,        30,  0, 0,       0,           LEX_ID,       "identifier",         3)
/* US  */  xx(CCON,      31,  0, 0,       0,           LEX_ID,       "character constant", 2)
/* (TY_CONST == LEX_CONST) must be a power of 2 and > (TY_ARRAY == LEX_ARRAY) */
/* SP  */  xx(CONST,     32,  0, 0,       0,           LEX_CHAR,     "const",              0)
/*  !  */  yy(0,         33,  0, 0,       0,           LEX_ID,       "!",                  1)
/*  "  */  xx(FCON,      34,  0, 0,       0,           LEX_ID,       "floating constant",  3)
/*  #  */  xx(ICON,      35,  0, 0,       0,           LEX_ID,       "integer constant",   3)
/*  $  */  xx(SCON,      36,  0, 0,       0,           LEX_ID,       "string literal",     2)
/*  %  */  yy(0,         37, 13, OP_MOD,  tree_bit_s,  '%',          "%",                  3)
/*  &  */  yy(0,         38,  8, OP_BAND, tree_bit_s,  LEX_ID,       "&",                  3)
/*  '  */  xx(INCR,      39,  0, OP_INCR, tree_add_s,  LEX_ID,       "++",                 2)
/*  (  */  yy(0,         40,  0, 0,       0,           LEX_ID,       "(",                  0)
/*  )  */  yy(0,         41,  0, 0,       0,           ')',          ")",                  0)
/*  *  */  yy(0,         42, 13, OP_MUL,  tree_mul_s,  LEX_ID,       "*",                  3)
/*  +  */  yy(0,         43, 12, OP_ADD,  tree_add_s,  LEX_ID,       "+",                  3)
/*  ,  */  yy(0,         44,  1, 0,       0,           ',',          ",",                  0)
/*  -  */  yy(3,         45, 12, OP_SUB,  tree_sub_s,  LEX_ID,       "-",                  3)
/*  .  */  yy(0,         46,  0, 0,       0,           '.',          ".",                  3)
/*  /  */  yy(0,         47, 13, OP_DIV,  tree_mul_s,  '/',          "/",                  3)
/*  0  */  xx(DECR,      48,  0, OP_DECR, tree_sub_s,  LEX_ID,       "--",                 2)
/*  1  */  xx(DEREF,     49,  0, 0,       0,           LEX_DEREF,    "->",                 2)
/*  2  */  xx(ANDAND,    50,  5, OP_AND,  tree_and_s,  LEX_ANDAND,   "&&",                 2)
/*  3  */  xx(OROR,      51,  4, OP_OR,   tree_and_s,  LEX_OROR,     "||",                 2)
/*  4  */  xx(LEQ,       52, 10, OP_LE,   tree_cmp_s,  LEX_LEQ,      "<=",                 2)
/*  5  */  xx(EQEQ,      53,  9, OP_EQ,   tree_cmp_s,  LEX_EQEQ,     "==",                 2)
/*  6  */  xx(NEQ,       54,  9, OP_NE,   tree_cmp_s,  LEX_NEQ,      "!=",                 0)
/*  7  */  xx(GEQ,       55, 10, OP_GE,   tree_cmp_s,  LEX_GEQ,      ">=",                 2)
/*  8  */  xx(RSHFT,     56, 11, OP_RSH,  tree_sh_s,   LEX_RSHFT,    ">>",                 2)
/*  9  */  xx(LSHFT,     57, 11, OP_LSH,  tree_sh_s,   LEX_LSHFT,    "<<",                 2)
/*  :  */  yy(0,         58,  0, 0,       0,           ':',          ":",                  3)
/*  ;  */  yy(0,         59,  0, 0,       0,           LEX_IF,       ";",                  0)
/*  <  */  yy(0,         60, 10, OP_LT,   tree_cmp_s,  '<',          "<",                  3)
/*  =  */  yy(0,         61,  2, OP_ASGN, tree_asgn_s, '=',          "=",                  3)
/*  >  */  yy(0,         62, 10, OP_GT,   tree_cmp_s,  '>',          ">",                  3)
/*  ?  */  yy(0,         63,  0, 0,       0,           '?',          "?",                  0)
/* (TY_VOLATILE == LEX_VOLATILE) must be a power of 2 and > (TY_CONST == LEX_CONST) */
/*  @  */  xx(VOLATILE,  64,  0, 0,       0,           LEX_CHAR,     "volatile",           0)
/*  A  */  xx(ELLIPSIS,  65,  0, 0,       0,           LEX_ELLIPSIS, "...",                2)
/*  B  */  xx(SIZEOF,    66,  0, 0,       0,           LEX_ID,       "sizeof",             0)
/*  C  */  yy(0,         67,  0, 0,       0,           0,            0,                    0)
/* LEX_AUTO must come first */
/*  D  */  xx(AUTO,      68,  0, 0,       0,           LEX_STATIC,   "auto",               0)
/*  E  */  xx(EXTERN,    69,  0, 0,       0,           LEX_STATIC,   "extern",             0)
/*  F  */  xx(REGISTER,  70,  0, 0,       0,           LEX_STATIC,   "register",           0)
/*  G  */  xx(STATIC,    71,  0, 0,       0,           LEX_STATIC,   "static",             0)
/*  H  */  xx(TYPEDEF,   72,  0, 0,       0,           LEX_STATIC,   "typedef",            0)
/* LEX_TYPEDEF must be the last */
/*  I  */  yy(0,         73,  0, 0,       0,           0,            0,                    0)
/*  J  */  xx(BREAK,     74,  0, 0,       0,           LEX_IF,       "break",              0)
/*  K  */  xx(CASE,      75,  0, 0,       0,           LEX_IF,       "case",               0)
/*  L  */  xx(CONTINUE,  76,  0, 0,       0,           LEX_IF,       "continue",           0)
/*  M  */  xx(DEFAULT,   77,  0, 0,       0,           LEX_IF,       "default",            0)
/*  N  */  xx(DO,        78,  0, 0,       0,           LEX_IF,       "do",                 0)
/*  O  */  xx(ELSE,      79,  0, 0,       0,           LEX_IF,       "else",               0)
/*  P  */  xx(FOR,       80,  0, 0,       0,           LEX_IF,       "for",                0)
/*  Q  */  xx(GOTO,      81,  0, 0,       0,           LEX_IF,       "goto",               0)
/*  R  */  xx(IF,        82,  0, 0,       0,           LEX_IF,       "if",                 0)
/*  S  */  xx(RETURN,    83,  0, 0,       0,           LEX_IF,       "return",             0)
/*  T  */  xx(SWITCH,    84,  0, 0,       0,           LEX_IF,       "switch",             0)
/*  U  */  xx(WHILE,     85,  0, 0,       0,           LEX_IF,       "while",              0)
/*  V  */  xx(SIGNED,    86,  0, 0,       0,           LEX_CHAR,     "signed",             0)
/*  W  */  yy(0,         87,  0, 0,       0,           0,            0,                    0)
/*  X  */  yy(0,         88,  0, 0,       0,           0,            0,                    0)
/*  Y  */  yy(0,         89,  0, 0,       0,           0,            0,                    0)
/*  Z  */  yy(0,         90,  0, 0,       0,           0,            0,                    0)
/*  [  */  yy(0,         91,  0, 0,       0,           '[',          "[",                  0)
/*  \  */  yy(0,         92,  0, 0,       0,           0,            0,                    0)
/*  ]  */  yy(0,         93,  0, 0,       0,           ']',          "]",                  0)
/*  ^  */  yy(0,         94,  7, OP_BXOR, tree_bit_s,  '^',          "^",                  1)
/*  _  */  yy(0,         95,  0, 0,       0,           0,            0,                    0)
/*  `  */  yy(0,         96,  0, 0,       0,           0,            0,                    0)
/*  a  */  xx(SHARP,     97,  0, 0,       0,           0,            "#",                  3)
/*  b  */  xx(DSHARP,    98,  0, 0,       0,           0,            "##",                 2)
/*  c  */  xx(STROP,     99,  0, 0,       0,           0,            "#",                  0)
/*  d  */  xx(PASTEOP,  100,  0, 0,       0,           0,            "##",                 0)
/*  e  */  xx(PPNUM,    101,  0, 0,       0,           0,            "pp-number",          3)
/*  f  */  xx(HEADER,   102,  0, 0,       0,           0,            "header name",        0)
/*  g  */  yy(0,        103,  0, 0,       0,           0,            0,                    0)
/*  h  */  yy(0,        104,  0, 0,       0,           0,            0,                    0)
/*  i  */  yy(0,        105,  0, 0,       0,           0,            0,                    0)
/*  j  */  yy(0,        106,  0, 0,       0,           0,            0,                    0)
/*  k  */  yy(0,        107,  0, 0,       0,           0,            0,                    0)
/*  l  */  yy(0,        108,  0, 0,       0,           0,            0,                    0)
/*  m  */  yy(0,        109,  0, 0,       0,           0,            0,                    0)
/*  n  */  yy(0,        110,  0, 0,       0,           0,            0,                    0)
/*  o  */  yy(0,        111,  0, 0,       0,           0,            0,                    0)
/*  p  */  yy(0,        112,  0, 0,       0,           0,            0,                    0)
/*  q  */  yy(0,        113,  0, 0,       0,           0,            0,                    0)
/*  r  */  yy(0,        114,  0, 0,       0,           0,            0,                    0)
/*  s  */  yy(0,        115,  0, 0,       0,           0,            0,                    0)
/*  t  */  yy(0,        116,  0, 0,       0,           0,            0,                    0)
/*  u  */  yy(0,        117,  0, 0,       0,           0,            0,                    0)
/*  v  */  yy(0,        118,  0, 0,       0,           0,            0,                    0)
/*  w  */  yy(0,        119,  0, 0,       0,           0,            0,                    0)
/*  x  */  yy(0,        120,  0, 0,       0,           0,            0,                    0)
/*  y  */  yy(0,        121,  0, 0,       0,           0,            0,                    0)
/*  z  */  yy(0,        122,  0, 0,       0,           0,            0,                    0)
/*  {  */  yy(0,        123,  0, 0,       0,           LEX_IF,       "{",                  0)
/*  |  */  yy(0,        124,  6, OP_BOR,  tree_bit_s,  '|',          "|",                  3)
/*  }  */  yy(0,        125,  0, 0,       0,           '}',          "}",                  0)
/*  ~  */  yy(0,        126,  0, OP_BCOM, 0,           LEX_ID,       "~",                  0)
/* DEL */  xx(EOI,      127,  0, 0,       0,           LEX_EOI,      "end of input",       0)
/* 128 */  xx(SPACE,    128,  0, 0,       0,           0,            "whitespace",         0)
/* 129 */  xx(NEWLINE,  129,  0, 0,       0,           0,            "end of line",        0)
/* 130 */  xx(UNKNOWN,  130,  0, 0,       0,           0,            "unknown token",      3)
/* 131 */  xx(MCR,      131,  0, 0,       0,           0,            "macro expansion",    0)

#undef xx
#undef yy

/* end of xtoken.h */
