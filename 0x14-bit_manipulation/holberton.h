#ifndef thelib

#define thelib

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int _putchar(char c);

unsigned int binary_to_uint(const char *b);
void print_binary(unsigned long int n);
int get_bit(unsigned long int n, unsigned int index);

#endif