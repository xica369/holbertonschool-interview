#ifndef _SLIDE_LINE_
#define _SLIDE_LINE_

#include <stdio.h>

#define SLIDE_LEFT 1
#define SLIDE_RIGHT 2


int slide_line(int *line, size_t size, int direction);
int validate(int *line, size_t size, int direction);

#endif
