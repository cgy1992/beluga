/*
 *  diagnostic messages
 */

/* E: error (warning if not set)
   N: note (warning if not set)
   P: prints locus
   O: issued once for file (works only with warnings)
   U: issued once for func (works only with warnings; must be defined as yy())
   T: issued once for tree (works only with warnings; must be defined as yy())
   F: fatal errors (not set with warnings)
   W: issued if -W given or in standard mode
   A: issued if in C90 mode
   B: issued if in C99 mode
   C: issued if in C1X mode

   ASSUMPTION: (HAVE_ICONV) UTF-8 used as internal pivot encoding */

xx(INPUT_ERROR,       E    |F    , 0, "failed to read input"                                       )
xx(INPUT_EMPTYFILE,         A|B|C, 0, "ISO C forbids an empty source file"                         )
xx(INPUT_NOTENDNL,          W    , 0, "input does not end in newline"                              )
xx(INPUT_BSNLEOF,           W    , 0, "backslash-newline followed by end-of-file"                  )
xx(INPUT_LINESPLICE,  E|P        , 0, "line splicing is not supported"                             )
xx(INPUT_LONGLINE,      P        , 1, "logical source line is too long"                            )
xx(INPUT_LONGLINESTD, N    |A|B|C, 1, "ISO C guarantees at most %u characters"                     )
xx(INPUT_CONVFAIL,    E|P  |F    , 0, "conversion failed while reading input"                      )

xx(PP_UNCLOSESTR,     E|P        , 0, "missing closing %c"                                         )
xx(PP_UNCLOSEHDR,     E|P        , 0, "missing closing %c"                                         )
xx(PP_UNCLOSECMT,     E|P        , 0, "unclosed comment"                                           )
xx(PP_C99CMT,           P|O|A    , 0, "C90 does not support //-comments"                           )
xx(PP_CMTINCMT,         P  |W    , 0, "`/*' within comment"                                        )
xx(PP_UNKNOWNDIR,     E|P        , 0, "unrecognized directive"                                     )
xx(PP_UNKNOWNDIRW,      P        , 0, "unrecognized directive"                                     )
xx(PP_SPHTDIREC,        P  |W    , 0, "only space and horizontal tab allowed in directives"        )
xx(PP_EXTRATOKEN,       P        , 0, "extraneous tokens ignored"                                  )
xx(PP_EXTRATOKENCL,     P        , 0, "extraneous tokens after `%s' ignored"                       )
xx(PP_INCBROKEN,                0, 0, "tracking nested #include files failed"                      )
xx(PP_INCNOTENTER,              0, 0, "file `%s' left but not entered"                             )
xx(PP_INCNOTLEAVE,              0, 0, "file `%s' entered but not left"                             )
xx(PP_NOUNIQUELINE,             0, 0, "different lines have the same locus"                        )
xx(PP_NOHEADER,       E|P        , 0, "`#include' expects a header name (\"header\" or <header>)"  )
xx(PP_NOINCFILE,      E|P  |F    , 0, "cannot open #include file `%s'"                             )
xx(PP_MANYINC1,       E|P  |F    , 0, "too many nesting levels of `#include'"                      )
xx(PP_MANYINC2,         P  |W    , 0, "too many nesting levels of `#include'"                      )
xx(PP_MANYINCSTD,     N    |A|B|C, 0, "ISO C guarantees only %d nesting levels"                    )
xx(PP_COMBINEHDR,       P  |A|B|C, 1, "combining header name from tokens is not portable"          )
xx(PP_NOMCRID,        E|P        , 0, "missing identifier for macro name"                          )
xx(PP_MCRREDEF,       E|P        , 0, "redefinition of macro `%s' previously defined at %p"        )
xx(PP_PMCRREDEF,      E|P        , 0, "redefinition of built-in macro `%s'"                        )
xx(PP_PMCRUNDEF,      E|P        , 0, "undefining built-in macro `%s'"                             )
xx(PP_UNDEFMCR,         P        , 1, "#undefining undefined macro `%s'"                           )
xx(PP_NOPNAME,        E|P        , 0, "missing identifier for macro parameter name"                )
xx(PP_NOPRPAREN,      E|P        , 0, "missing `)' in macro parameter list"                        )
xx(PP_NOSPACE,          P        , 0, "missing space between macro `%s' and replacement list"      )
xx(PP_NOEQCL,           P        , 0, "missing `=' between %s-like macro `%s' and replacement list")
xx(PP_DUPNAME,        E|P        , 0, "duplicate macro parameter `%s'"                             )
xx(PP_MANYPARAM,        P  |W    , 0, "too many parameters"                                        )
xx(PP_MANYPSTD,       N    |A|B|C, 0, "ISO C guarantees only %d parameters"                        )
xx(PP_MANYPPID,         P  |W    , 0, "too many macros simultaneously defined"                     )
xx(PP_MANYPPIDSTD,    N    |A|B|C, 0, "ISO C guarantees only %d macros"                            )
xx(PP_LONGID,           P  |W    , 0, "identifier is too long; see `%s' declared at %p"            )
xx(PP_LONGIDSTD,      N    |A|B|C, 0, "ISO C guarantees only %d significant characters"            )
xx(PP_DSHARPPOS,      E|P        , 0, "`##' cannot appear at the boundaries of macro expansion"    )
xx(PP_TWODSHARP,      E|P        , 0, "`##' cannot be an operand of `##'"                          )
xx(PP_NEEDPARAM,      E|P        , 0, "`#' must be followed by a macro parameter"                  )
xx(PP_EMPTYARG,         P  |A    , 0, "C90 does not support empty macro argument to macro `%s'"    )
xx(PP_DIRECINARG,       P        , 0, "directive-like line given as macro argument"                )
xx(PP_UNTERMARG,      E|P        , 0, "unterminated argument list to macro `%s'"                   )
xx(PP_MANYARG1,       E|P        , 0, "too many arguments to macro `%s'"                           )
xx(PP_MANYARG2,         P  |W    , 0, "too many arguments to macro `%s'"                           )
xx(PP_MANYARGSTD,     N    |A|B|C, 0, "ISO C guarantees only %d arguments"                         )
xx(PP_INSUFFARG,      E|P        , 0, "insufficient number of arguments to macro `%s'"             )
xx(PP_INVTOKMADE,     E|P        , 0, "`##' generated multiple tokens from `%s'"                   )
xx(PP_EMPTYTOKMADE,     P  |A    , 0, "`##' generated an empty token"                              )
xx(PP_INVSTRMADE,     E|P        , 0, "`#' generated an invalid string `%s'"                       )
xx(PP_ORDERSDS,         P  |W    , 0, "evaluation order of `#' and `##' operators is unspecified"  )
xx(PP_ORDERDS,          P        , 1, "evaluation order of `##' operators is unspecified"          )
xx(PP_ORDERDSEX,      N          , 1, "no valid token can be generated from `%s'"                  )
xx(PP_UNSPCRECUR,       P  |W    , 0, "unspecified whether call to `%s' is considered recursive"   )
xx(PP_MANYCOND,         P  |W    , 0, "too many nesting levels of conditional inclusion"           )
xx(PP_MANYCONDSTD,    N    |A|B|C, 0, "ISO C guarantees only %d nesting levels"                    )
xx(PP_UNTERMCOND,     E|P        , 0, "unterminated `%C' started at %p"                            )
xx(PP_NOMATCHIF,      E|P        , 0, "missing matching `#if' for `%s'"                            )
xx(PP_ELIFAFTRELSE,   E|P        , 0, "`#elif' after `#else' at %p"                                )
xx(PP_DUPELSE,        E|P        , 0, "`#else' already seen at %p"                                 )
xx(PP_NOIFEXPR,       E|P        , 0, "missing controlling expression for `%s'"                    )
xx(PP_NOIFID,         E|P        , 0, "missing identifier for `%C'"                                )
xx(PP_ILLOP,          E|P        , 0, "`%s' is not allowed in preprocessing expression"            )
xx(PP_ILLOPW,           P  |W    , 0, "`%s' is not allowed in preprocessing expression"            )
xx(PP_DEFFROMMCR,       P        , 0, "`defined' generated from macro expansion"                   )
xx(PP_MCRDEF,         E|P        , 0, "`defined' cannot be #defined"                               )
xx(PP_NODEFID,        E|P        , 0, "missing identifier for `defined'"                           )
xx(PP_NODEFRPAREN,    E|P        , 0, "missing `)' for `defined'"                                  )
xx(PP_ILLEXPR,        E|P        , 0, "invalid preprocessing expression"                           )
xx(PP_NOEXPRLPAREN,   E|P        , 0, "missing `(' in preprocessing expression"                    )
xx(PP_EXPRERR,        E|P        , 0, "%s expected before `%s'"                                    )
xx(PP_PPNUMBER,       E|P        , 0, "invalid pp-number `%s'"                                     )
xx(PP_OVFCONST,         P        , 0, "overflow in preprocessing expression"                       )
xx(PP_DIVBYZERO,        P        , 0, "divide by zero"                                             )
xx(PP_NEGTOUNSIGN,      P  |W    , 0, "negative value converted to unsigned type"                  )
xx(PP_OVERSHIFTS,       P        , 0, "shift by %d is undefined"                                   )
xx(PP_OVERSHIFTU,       P        , 0, "shift by %u is undefined"                                   )
xx(PP_RSHIFTNEG,        P  |W    , 0, "right shift of negative value is not portable"              )
xx(PP_LSHIFTNEG,        P  |W    , 0, "left shift of negative value is undefined"                  )
xx(PP_NEGUNSIGNED,      P        , 1, "unsigned operand of unary -"                                )
xx(PP_LARGEHEX,       E|P        , 0, "the value of hexadecimal escape sequence is too large"      )
xx(PP_ESCOCT89,         P  |W    , 0, "8 and 9 are not allowed in octal escape sequence"           )
xx(PP_ESCOCT3DIG,       P  |W    , 0, "octal escape sequence takes at most 3 digits"               )
xx(PP_LARGEOCT,       E|P        , 0, "the value of octal escape sequence is too large"            )
xx(PP_INVESC1,        E|P        , 0, "invalid escape sequence `%s' in %s"                         )
xx(PP_INVESC2,        E|P        , 0, "invalid escape sequence in %s"                              )
xx(PP_EMPTYCHAR,      E|P        , 0, "empty character constant is not allowed"                    )
xx(PP_LARGECHAR,      E|P        , 0, "excess characters in character constant"                    )
xx(PP_WIDENOTFIT,       P        , 0, "wide string/character does not fit to wchar_t"              )
xx(PP_CONVFAIL,       E|P  |F    , 0, "conversion failed while recognizing string/character"       )
xx(PP_MANYPE,           P  |W    , 0, "too many nesting levels of parenthesized expressions"       )
xx(PP_MANYPESTD,      N    |A|B|C, 0, "ISO C guarantees at most %d levels"                         )
xx(PP_EXPRUNDEFID,      P        , 1, "undefined identifier `%s' evaluated to 0"                   )
xx(PP_ERROR1,         E|P        , 0, "#error%s"                                                   )
xx(PP_ERROR2,         E|P  |F    , 0, "#error%s"                                                   )
xx(PP_UNKNOWNPRAGMA,    P        , 0, "unknown #pragma"                                            )
xx(PP_LARGELINE,        P        , 0, "line number is too large"                                   )
xx(PP_ZEROLINE,         P        , 0, "line number zero is not permitted"                          )
xx(PP_ESCINFNAME,       P        , 0, "escape sequence used in file name"                          )
xx(PP_NOLINENO,      E|P         , 0, "missing line number for #line"                              )
xx(PP_ILLLINENO,     E|P         , 0, "invalid line number `%s'"                                   )
xx(PP_ILLFNAME,      E|P         , 0, "invalid file name `%s'"                                     )

#ifndef SEA_CANARY
xx(CONST_LONGSTR,       P  |W    , 0, "string literal is too long"                                 )
xx(CONST_LONGSTRSTD,  N    |A|B|C, 0, "ISO C guarantees only %u characters"                        )
xx(CONST_LARGECHAR,   E|P        , 0, "excess characters in character constant"                    )
xx(CONST_EMPTYCHAR,   E|P        , 0, "empty character constant is not allowed"                    )
xx(CONST_MBWIDE,        P  |A    , 0, "adjacent multibyte and wide strings result in wide string"  )
xx(CONST_MBWIDESTD,   N    |A    , 0, "the concatenation is not portable in C90"                   )
xx(CONST_WIDENOTFIT,    P        , 0, "wide string/character does not fit to wchar_t"              )
xx(CONST_LARGEOCT,    E|P        , 0, "the value of octal escape sequence is too large"            )
xx(CONST_LARGEHEX,    E|P        , 0, "the value of hexadecimal escape sequence is too large"      )
xx(CONST_ILLHEXESC,   E|P        , 0, "invalid hexadecimal escape sequence"                        )
xx(CONST_UNKNOWNESC,  E|P        , 0, "unknown escape sequence"                                    )
xx(CONST_PPNUMBER,    E|P        , 0, "pp-number that is not a valid %t"                           )
xx(CONST_ILLFPCNST,   E|P        , 0, "invalid floating constant"                                  )
xx(CONST_LARGEFP,     E|P        , 0, "the value of floating constant is too large"                )
xx(CONST_LONGFP,      E|P        , 0, "floating constant is too long"                              )
xx(CONST_TRUNCFP,       P        , 0, "floating constant truncated to 0"                           )
xx(CONST_ILLINTCNST,  E|P        , 0, "invalid integer constant"                                   )
xx(CONST_LARGEINT,    E|P        , 0, "the value of integer constant is too large"                 )
xx(CONST_ILLOCTESC,   E|P        , 0, "8 and 9 are not allowed in octal constant"                  )
xx(CONST_CONVFAIL,    E|P  |F    , 0, "conversion failed while recognizing string/character"       )
xx(CONST_ESCOCT89,      P  |W    , 0, "8 and 9 are not allowed in octal escape sequence"           )
xx(CONST_ESCOCT3DIG,    P  |W    , 0, "octal escape sequence takes at most 3 digits"               )

xx(LEX_INVCHAR,       E|P        , 0, "invalid character `%s' ignored"                             )
xx(LEX_INVCHARCV,     E|P        , 0, "invalid character `%s' ignored (after conversion to UTF-8)" )
xx(LEX_STRAYWS,         P        , 0, "stray whitespace character `%s'"                            )
xx(LEX_STRAYBS,       E|P        , 0, "stray backslash character"                                  )
xx(LEX_SHARP,         E|P        , 0, "# or ## is supported only in preprocessing"                 )
xx(LEX_EXTRATOKEN,      P|O|W    , 0, "extraneous tokens ignored"                                  )
xx(LEX_LONGIDOV,      E|P        , 0, "identifier truncated; %P ignored"                           )
xx(LEX_LONGID,          P  |W    , 0, "identifier is too long; see `%s' declared at %p"            )
xx(LEX_LONGEID,         P  |W    , 0, "external identifier is too long; see `%s' declared at %p"   )
xx(LEX_LONGIDSTD,     N    |A|B|C, 0, "ISO C guarantees only %d significant characters"            )
xx(LEX_EXTRACOMMA,    E|P        , 0, "extra comma or missing %s"                                  )

xx(PARSE_ERROR,       E|P        , 0, "syntax error; expected `%t' before `%t'"                    )
xx(PARSE_SKIPTOK,     N|P        , 0, "%P skipped including one here"                              )
xx(PARSE_MANYBID,       P  |W    , 0, "too many identifiers in a block"                            )
xx(PARSE_MANYBIDSTD,  N    |A|B|C, 0, "ISO C guarantees only %d local identifiers"                 )
xx(PARSE_CLSFIRST,      P  |A|B|C, 0, "ISO C recommends `%t' come first in declaration"            )
xx(PARSE_CLS,         E|P        , 0, "storage-class specifier is not allowed"                     )
xx(PARSE_INVUSE,      E|P        , 0, "invalid use of `%t' in declaration"                         )
xx(PARSE_DEFINT,        P  |W    , 0, "type defaults to `int'"                                     )
xx(PARSE_DEFINTSTD,   N      |B|C, 0, "ISO C forbids implicit `int' since C99"                     )
xx(PARSE_INVCLS,      E|P        , 0, "invalid storage class `%t'"                                 )
xx(PARSE_INVCLSID,    E|P        , 0, "invalid storage class `%t' for %C%i"                        )
xx(PARSE_REDECL1,     E|P        , 0, "redeclaration of%I declared at %p"                          )
xx(PARSE_REDECL2,       P        , 0, "declaration of%I does not match one at %p"                  )
xx(PARSE_HIDEID,        P        , 1, "declaration of%I hides one declared at %p"                  )
xx(PARSE_NOINIT,      E|P        , 0, "initializer is not allowed for %s"                          )
xx(PARSE_VOIDID,      E|P        , 0, "invalid parameter type `void'"                              )
xx(PARSE_VOIDALONE,   E|P        , 0, "`void' must be the only parameter"                          )
xx(PARSE_ELLSEEN,     E|P        , 0, "`...' must be the last in parameters"                       )
xx(PARSE_ELLALONE,    E|P        , 0, "missing named parameter before `...'"                       )
xx(PARSE_QUALVOID,    E|P        , 0, "`void' as only parameter must not be qualified"             )
xx(PARSE_NOPTYPE,     E|P        , 0, "missing parameter type"                                     )
xx(PARSE_PARAMID,     E|P        , 0, "expecting a parameter identifier"                           )
xx(PARSE_EXTRAID,     E|P        , 0, "extraneous identifier%i"                                    )
xx(PARSE_INVARRSIZE,  E|P        , 0, "array size must be greater than 0; adjusted to 1"           )
xx(PARSE_REDEF,       E|P        , 0, "redefinition of%I defined at %p"                            )
xx(PARSE_INVLINK,     E|P        , 0, "inconsistent linkage with%I declared at %p"                 )
xx(PARSE_INVLINKW,      P        , 0, "inconsistent linkage with%I declared at %p"                 )
xx(PARSE_MANYEID,       P  |W    , 0, "too many external-linkage identifiers"                      )
xx(PARSE_MANYEIDSTD,  N    |A|B|C, 0, "ISO C guarantees at most %d external identifiers"           )
xx(PARSE_INCOMPTYPE,  E|P        , 0, "size must be known to define%I"                             )
xx(PARSE_NODECLSPEC,    P  |W    , 0, "missing declaration specifier"                              )
xx(PARSE_EMPTYDECL,   E|P        , 0, "empty declaration"                                          )
xx(PARSE_DECLPARAM,     P        , 0, "declaration must include declarator for parameter"          )
xx(PARSE_NOUSECLS,      P  |W    , 0, "useless storage-class specifier `%t'"                       )
xx(PARSE_INVDECL,     E|P        , 0, "invalid declaration"                                        )
xx(PARSE_INVDCLSTMT,  E|P        , 0, "invalid declaration or statement"                           )
xx(PARSE_INVTYPE,     E|P        , 0, "invalid type specifier (`%t' and `%t')"                     )
xx(PARSE_TYPEDEFF,    E|P        , 0, "function definition declared `typedef'"                     )
xx(PARSE_EXTRAPARAM,  E|P        , 0, "extraneous old-style parameter list"                        )
xx(PARSE_NOPROTO,       P        , 1, "missing prototype"                                          )
xx(PARSE_NOID,        E|P        , 0, "missing identifier"                                         )
xx(PARSE_MANYPARAM,     P  |W    , 0, "too many parameters"                                        )
xx(PARSE_MANYPSTD,    N    |A|B|C, 0, "ISO C guarantees at most %d parameters"                     )
xx(PARSE_INCOMPRET,   E|P        , 0, "size must be known for return type"                         )
xx(PARSE_NOPARAM,     E|P        , 0, "declared parameter%I is missing from the identifier list"   )
xx(PARSE_PARAMMATCH,  E|P        , 0, "parameter mismatch to prototype declared at %p"             )
xx(PARSE_NOPARAMID,   E|P        , 0, "missing name for %o parameter"                              )
xx(PARSE_INCOMPARAM,  E|P        , 0, "size must be known for parameter%I"                         )
xx(PARSE_ENUMID,      E|P        , 0, "expecting an enumerator identifier"                         )
xx(PARSE_ENUMOVER,    E|P        , 0, "overflow in value for enum constant%i"                      )
xx(PARSE_MANYEC,        P  |W    , 0, "too many enum constants in an enum type"                    )
xx(PARSE_MANYECSTD,   N    |A|B|C, 0, "ISO C guarantees at most %d enum constants"                 )
xx(PARSE_ENUMCOMMA,     P  |A    , 0, "C90 disallows extraneous comma at enumerator list"          )
xx(PARSE_ENUMSEMIC,   E|P        , 0, "enumerator definitions must not end with `;'"               )
xx(PARSE_INVENUM,     E|P        , 0, "unknown enum type"                                          )
xx(PARSE_INVBITTYPE,  E|P        , 0, "bit-fields must have `(signed/unsigned) int' type"          )
xx(PARSE_INVBITSIZE,  E|P        , 0, "illegal bit-field size (that must be [0, %d])"              )
xx(PARSE_NOFNAME,     E|P        , 0, "missing member name"                                        )
xx(PARSE_INCOMPMEM,   E|P        , 0, "size must be known for member"                              )
xx(PARSE_INVFTYPE,    E|P        , 0, "function cannot be a member"                                )
xx(PARSE_MANYMBR,       P  |W    , 0, "too many struct/union members"                              )
xx(PARSE_MANYMBRSTD,  N    |A|B|C, 0, "ISO C guarantees at most %d members"                        )
xx(PARSE_ANONYTAG,      P      |C, 0, "anonymous struct/union must have no tag"                    )
xx(PARSE_INVFIELD,    E|P        , 0, "invalid %t member declaration"                              )
xx(PARSE_NOFIELD,     E|P        , 0, "missing %t member declaration"                              )
xx(PARSE_NOTAG,       E|P        , 0, "missing %t tag"                                             )
xx(PARSE_REFSTATIC,     P  |W    , 0, "static%I defined but not referenced"                        )
xx(PARSE_REFPARAM,      P  |W    , 0, "parameter%I defined but not referenced"                     )
xx(PARSE_REFLOCAL,      P  |W    , 0, "local%I defined but not referenced"                         )
xx(PARSE_SETNOREFS,     P  |W    , 0, "static%I set but not meaningfully used"                     )
xx(PARSE_SETNOREFP,     P  |W    , 0, "parameter%I set but not meaningfully used"                  )
xx(PARSE_SETNOREFL,     P  |W    , 0, "local%I set but not meaningfully used"                      )
xx(PARSE_UNDSTATIC,   E|P        , 0, "static%I used but not defined in this translation unit"     )
xx(PARSE_ENUMINT,       P  |W    , 0, "`enum' may not be compatible with `int' (see %p)"           )
xx(PARSE_INITCONST,   E|P        , 0, "initializer must be constant"                               )
xx(PARSE_INVINIT,     E|P        , 0, "invalid initializer; %y given for %y"                       )
xx(PARSE_BIGFLDINIT,    P        , 0, "initializer exceeds bit-field"                              )
xx(PARSE_INCOMINIT,   E|P        , 0, "incomplete type %y cannot be initialized"                   )
xx(PARSE_NOBRACE,     E|P        , 0, "missing `{' for initializer of %y"                          )
xx(PARSE_EXTRABRACE,    P        , 1, "extra brace for scalar initializer"                         )
xx(PARSE_MANYINIT,    E|P        , 0, "too many initializer for %y"                                )
xx(PARSE_INVMBINIT,   E|P        , 0, "character array initialized from wide string"               )
xx(PARSE_INVWINIT,    E|P        , 0, "wide character array initialized from non-wide string"      )
xx(PARSE_MANYPD,        P  |W    , 0, "too many nesting levels of parenthesized declarators"       )
xx(PARSE_MANYPDSTD,   N    |A|B|C, 0, "ISO C guarantees at most %d levels"                         )
xx(PARSE_MANYPE,        P  |W    , 0, "too many nesting levels of parenthesized expressions"       )
xx(PARSE_MANYPESTD,   N    |A|B|C, 0, "ISO C guarantees at most %d levels"                         )
xx(PARSE_MANYSTR,       P  |W    , 0, "too many nesting levels of struct/union definitions"        )
xx(PARSE_MANYSTRSTD,  N    |A|B|C, 0, "ISO C guarantees at most %d levels"                         )
xx(PARSE_MIXDCLSTMT,  E|P        , 0, "mixing declarations and statements is not allowed in C90"   )
xx(PARSE_UNUSEDINIT,  E|P        , 0, "useless initializer; nothing to initialize"                 )
xx(PARSE_ATAGPARAM,     P  |W    , 0, "anonymous %t declared in parameter list"                    )
xx(PARSE_PINTFLD,       P        , 1, "signedness of plain bit-field is implementation-defined"    )
xx(PARSE_MIXPROTO,    E|P        , 0, "mixed prototype; former parameters ignored"                 )
xx(PARSE_QUALFRET,      P  |W    , 0, "type qualifier is useless on function return type"          )
xx(PARSE_VOIDOBJ,       P        , 0, "object%I referenced but cannot be defined"                  )
xx(PARSE_MANYDECL,      P  |W    , 0, "too many type derivations in a declarator"                  )
xx(PARSE_MANYDECLSTD, N    |A|B|C, 0, "ISO C guarantees at most %d derivations"                    )

xx(EXPR_SKIPREF,        P        , 0, "reference to incomplete type elided"                        )
xx(EXPR_SKIPVOLREF,     P        , 0, "reference to volatile elided"                               )
xx(EXPR_SIZEOFINV,    E|P        , 0, "invalid operand given to sizeof"                            )
xx(EXPR_SIZEOFBIT,    E|P        , 0, "bit-field given to sizeof"                                  )
xx(EXPR_PTRINT,         P  |A|B|C, 0, "conversion between pointer and integer is not portable"     )
xx(EXPR_FPTROPTR,       P  |W    , 0, "conversion between function/object pointers is not portable")
xx(EXPR_INVCAST,      E|P        , 0, "conversion from %y to %y is not allowed"                    )
xx(EXPR_NOID,         E|P        , 0, "undeclared identifier%I"                                    )
xx(EXPR_IMPLDECL,       P  |W    , 0, "implicit declaration of a function"                         )
xx(EXPR_IMPLDECLSTD,  N      |B|C, 0, "ISO C forbids implicit declaration since C99"               )
xx(EXPR_ILLTYPEDEF,   E|P        , 0, "illegal use of type name%I"                                 )
xx(EXPR_ILLEXPR,      E|P        , 0, "expression required"                                        )
xx(EXPR_NEEDLVALUE,   E|P        , 0, "lvalue required"                                            )
xx(EXPR_VOIDLVALUE,     P        , 0, "`%s' used as an lvalue"                                     )
xx(EXPR_ADDRREG,      E|P        , 0, "taking address of register is not allowed"                  )
xx(EXPR_ATOPREG,      E|P        , 0, "conversion to pointer of register array is not allowed"     )
yy(EXPR_NLVALARR,       P|T|A    , 0, "non-lvalue array does not decay to pointer in C90"          )
xx(EXPR_NEGUNSIGNED,    P  |W    , 1, "unsigned operand of unary -"                                )
xx(EXPR_ASGNCONST,    E|P        , 0, "assigning to const%I is not allowed"                        )
xx(EXPR_CONDTYPE,     E|P        , 0, "%s%s has illegal type %y; assumed true"                     )
xx(EXPR_NOFUNC,       E|P        , 0, "function or function pointer required"                      )
xx(EXPR_NOMEMBER,     E|P        , 0, "member name expected"                                       )
xx(EXPR_NOSTRUCT1,    E|P        , 0, "struct or union required but `%C' given"                    )
xx(EXPR_NOSTRUCT2,    E|P        , 0, "struct or union pointer required but `%C' given"            )
xx(EXPR_UNKNOWNMEM,   E|P        , 0, "unknown member name%i"                                      )
xx(EXPR_RETINCOMP,    E|P        , 0, "function returns an incomplete type, %y"                    )
xx(EXPR_ARGNOTMATCH,  E|P        , 0, "type error in %o argument to %f; %y given for %y"           )
xx(EXPR_INCOMPARG,    E|P        , 0, "type error in %o argument to %f; %y is an incomplete type"  )
xx(EXPR_POINTER,      E|P        , 0, "pointer required but `%C' given"                            )
xx(EXPR_EXTRAARG,     E|P        , 0, "extra arguments to %f"                                      )
xx(EXPR_MANYARG,        P  |W    , 0, "too many arguments to %f"                                   )
xx(EXPR_MANYARGSTD,   N    |A|B|C, 0, "ISO C guarantees at most %d arguments"                      )
xx(EXPR_INSUFFARG,    E|P        , 0, "insufficient number of arguments to %f"                     )
xx(EXPR_UNKNOWNSIZE,  E|P        , 0, "unknown size for type %y"                                   )
xx(EXPR_ASGNENUMPTR,    P  |W    , 0, "assignment between %y and %y is not portable"               )
xx(EXPR_ASGNINCOMP,   E|P        , 0, "assignment of incomplete type is not allowed"               )
xx(EXPR_NEEDOBJ,      E|P        , 0, "addressable object required"                                )
xx(EXPR_BINOPERR,     E|P        , 0, "operands of %s have illegal types %y and %y"                )
xx(EXPR_UNIOPERR,     E|P        , 0, "operand of unary %s has illegal type %y"                    )
xx(EXPR_OVFCONSTFP,     P        , 0, "overflow in floating constant expression; not folded"       )
xx(EXPR_OVFCONST,       P        , 0, "overflow in constant expression"                            )
xx(EXPR_OVFCONV,        P        , 0, "overflow in converting constant expression from %y to %y"   )
xx(EXPR_NOINTCONST,   E|P        , 0, "integer constant expression reqruied for %s"                )
xx(EXPR_NOINTCONSTW,    P  |W    , 0, "integer constant expression reqruied for %s"                )
xx(EXPR_INVINITCE,      P  |A|B|C, 0, "non-portable constant expression for initializer"           )
xx(EXPR_LARGEVAL,     E|P        , 0, "too large value for %s; adjusted to %d"                     )
xx(EXPR_OVERSHIFT,      P  |W    , 0, "shift results in undefined behavior"                        )
xx(EXPR_OVERSHIFTS,     P  |W    , 0, "shift by %d is undefined"                                   )
xx(EXPR_OVERSHIFTU,     P  |W    , 0, "shift by %u is undefined"                                   )
xx(EXPR_LSHIFTNEG,      P  |W    , 0, "left shift of negative value is undefined"                  )
xx(EXPR_RSHIFTNEG,      P  |W    , 0, "right shift of negative value is not portable"              )
xx(EXPR_DIVBYZERO,      P        , 0, "divide by zero"                                             )
xx(EXPR_UNSIGNEDCMP,    P  |W    , 0, "comparison always results in %s"                            )
yy(EXPR_SYMBOLTRUE,     P  |W    , 0, "address of%I always results in true"                        )
xx(EXPR_NOEFFECT,       P  |W    , 0, "expression always results in %d"                            )
xx(EXPR_VOIDLVALUE1,    P  |A    , 0, "lvalue required but `void' is not an lvalue"                )
xx(EXPR_VOIDLVALUE2,    P        , 0, "lvalue required but `void' is not an lvalue"                )
xx(EXPR_BIGFLD,         P        , 0, "value exceeds bit-field"                                    )
xx(EXPR_VALNOTUSED,     P        , 0, "expression result not used"                                 )
xx(EXPR_CHARSUBSCR,     P  |W    , 0, "array subscript has `char' type that might be signed"       )

xx(TYPE_ARRFUNC,      E|P        , 0, "`array of functions' is not allowed"                        )
xx(TYPE_ARRINCOMP,    E|P        , 0, "`array of incomplete type' is not allowed"                  )
xx(TYPE_ARRVOID,      E|P        , 0, "`array of void' is not allowed"                             )
xx(TYPE_BIGARR,       E|P        , 0, "array is too big; size adjusted to %d"                      )
xx(TYPE_BIGARRSTD,    N    |A|B|C, 0, "ISO C guarantees at most %u-byte object"                    )
xx(TYPE_QUALFUNC,       P        , 0, "applying `%t' to function is not allowed; ignored"          )
xx(TYPE_DUPQUAL,        P  |A    , 0, "duplicate qualifier `%t'"                                   )
xx(TYPE_DUPQUALDCLR,    P  |A    , 0, "pointer declarator has duplicate qualifier `%t'"            )
xx(TYPE_FUNCARR,      E|P        , 0, "`function returning array' is not allowed"                  )
xx(TYPE_FUNCFUNC,     E|P        , 0, "`function returning function' is not allowed"               )
xx(TYPE_STRREDEF,     E|P        , 0, "redefinition of%I previously defined at %p"                 )
xx(TYPE_DIFFTAG,      E|P        , 0, "different kind of%I declared at %p"                         )
xx(TYPE_STRDUPMEM,    E|P        , 0, "duplicate member name%i with one at %p"                     )
xx(TYPE_STRAMBMEM,    E|P        , 0, "ambiguous member%i with one at %p in %y"                    )
xx(TYPE_INVENUM,      E|P        , 0, "unknown enum type"                                          )
xx(TYPE_ERRPROTO,       P        , 0, "erroneous prototype generated for%I due to unnamed tag"     )
xx(TYPE_BIGOBJ,         P        , 0, "size of a type is too big"                                  )
xx(TYPE_BIGOBJADJ,    E|P        , 0, "size of a type is too big; size adjusted to %d"             )

xx(STMT_INFLOOP,        P  |W    , 0, "infinite loop detected"                                     )
xx(STMT_HUGETABLE,      P        , 0, "switch statement generates a huge jump table"               )
xx(STMT_SWTCHNOINT,   E|P        , 0, "integer required for switch statement"                      )
xx(STMT_SWTCHNOCASE,  E|P        , 0, "switch statement has no cases"                              )
xx(STMT_DUPCASES,     E|P        , 0, "duplicate case label `%d'"                                  )
xx(STMT_DUPCASEU,     E|P        , 0, "duplicate case label `%u'"                                  )
xx(STMT_MANYCASE,       P  |W    , 0, "too many cases in a switch statement"                       )
xx(STMT_MANYCASESTD,  N    |A|B|C, 0, "ISO C guarantees only %d cases"                             )
xx(STMT_DUPLABEL,     E|P        , 0, "redefinition of label%I defined at %p"                      )
xx(STMT_ILLRETTYPE,   E|P        , 0, "illegal return type; %y given for %y"                       )
xx(STMT_RETLOCAL,       P        , 0, "return value depends on address of %s%I"                    )
yy(STMT_UNREACHABLE,    P  |U    , 0, "unreachable code"                                           )
xx(STMT_MANYNEST,       P  |W    , 0, "too many levels of nested statements"                       )
xx(STMT_MANYNESTSTD,  N    |A|B|C, 0, "ISO C guarantees only %d levels"                            )
xx(STMT_ILLBREAK,     E|P        , 0, "illegal break statement"                                    )
xx(STMT_ILLCONTINUE,  E|P        , 0, "illegal continue statement"                                 )
xx(STMT_INVCASE,      E|P        , 0, "case label appears outside switch statement"                )
xx(STMT_INVDEFAULT,   E|P        , 0, "default label appears outside switch statement"             )
xx(STMT_DUPDEFAULT,   E|P        , 0, "extraneous default label in a switch statement"             )
xx(STMT_EXTRARETURN,  E|P        , 0, "extraneous return value"                                    )
xx(STMT_NORETURN,       P        , 0, "missing return value"                                       )
xx(STMT_GOTONOLAB,    E|P        , 0, "missing label in goto"                                      )
xx(STMT_ILLSTMT,      E|P        , 0, "unrecognized statement"                                     )
xx(STMT_STMTREQ,      E|P        , 0, "statement required before `%t'"                             )
xx(STMT_UNDEFLAB,     E|P        , 0, "undefined label%I"                                          )
xx(STMT_UNUSEDLAB,      P  |W    , 0, "label%I defined but not used"                               )
xx(STMT_LABELSTMT,    E|P        , 0, "label must have a statement follow it"                      )
xx(STMT_AMBELSE,        P  |W    , 0, "ambiguous `else' can be avoided with braces for `if'"       )
xx(STMT_EMPTYBODY,      P  |W    , 0, "empty body to %s `%s' statement can be misleading"          )

xx(X86_FPREGSPILL,    E|P        , 0, "too complex floating expression"                            )
#endif    /* !SEA_CANARY */

xx(XTRA_ERRLIMIT,     E    |F    , 0, "too many errors; compilation stopped"                       )
xx(XTRA_ONCEFILE,     N    |W    , 0, "this is reported only once per file"                        )
xx(XTRA_INVMAIN,        P  |A|B|C, 0, "%D is a non-standard definition"                            )
/* frozen by pre-v0.0.1 */

/* added for #34 */
xx(PARSE_NODCLR,      E|P        , 0, "missing declarator%s"                                       )

#undef xx
#undef yy

/* end of xerror.h */
