#ifndef MISC_H
#define MISC_H

void flush ();
/*
 * Read
 * https://faq.cprogramming.com/cgi-bin/smartfaq.cgi?answer=1044873249&id=1043284392
 */

void hr (char c, unsigned int length);
/*
 * print a horizontal rule on stdout
 * use the character c for the horizontal rule
 * set newline to a positive integer to append a \n after the horizontal rule
 */

void readInt (int *, int);
void readUInt (unsigned int *, int);
void readStr (char *, int);
void fill (char *, char **);
#endif // MISC_H
