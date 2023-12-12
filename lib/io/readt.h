#ifndef _READT_H
#define _READT_H

/* void flush ();
 *
 * Read
 * https://faq.cprogramming.com/cgi-bin/smartfaq.cgi?answer=1044873249&id=1043284392
 *
 */

extern const unsigned int DEFAULT_BUFFER_LENGTH;

void fill (char *, char **);

void readStr (char *, int);

void readInt (int *, int);
void readUInt (unsigned int *, int);

void readFloat (float *, int);
void readDouble (double *, int);

#endif // _READT_H
