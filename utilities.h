#ifndef _UTILITIES_H_
#define _UTILITIES_H_

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 30

#define ASCI_DIFF(x,y) (((x) > (y)) ? ((x) - (y)) : ((y) - (x))) 
#define UPPER(c) ((((c) >= 'a') && (c <= 'z'))?((c) - ASCI_DIFF('a','A')) : c)
#define LOWER(c) ((((c) >= 'A') && (c <= 'Z'))?((c) + ('a' - 'A')) : c)

extern int asci_to_int (char *);
extern char to_upper (char);
extern char to_lower (char);
extern void string_to_upper (char *);
extern void string_to_lower (char *);
extern void mem_copy (char *, char *, int);
extern void print_memory (char *, int );
extern char *string_cat (char *, char *);
extern void string_copy (char *, char *);
extern char *mem_set (char *, char, int);
extern int string_length (char *);
extern char * string_reverse (char *);
extern int utilities_main ();
extern char * trim_simple (char *);

#endif //_UTILITIES_H_
