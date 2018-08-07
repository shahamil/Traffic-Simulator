#ifndef FUNCTIONS_H
#define FUNCTIONS_H
//prints charcters on the screen screen with a given color (Eg: 2 is green)
void coutc(int color, char* output);

//prints number on the screen with a given color
void coutc(int color, int output);

//prints character based on ASCII code 
void coutchar(int color, int output);

//move cursor to location(x, y)
void gotoxy(short x, short y);

#endif