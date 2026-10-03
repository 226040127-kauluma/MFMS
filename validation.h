#ifndef VALIDATION_H
#define VALIDATION_H

/* Reads a whole number. Repeats until the input is valid. */
int readInt(void);

/* Reads a non-negative decimal number. Repeats until the input is valid. */
float readFloat(void);

/* Reads non-empty text into buffer (at most size-1 characters). */
void readString(char *buffer, int size);

/* Names used by the rest of the group */
int getValidInt(void);
int getMenuChoice(int min, int max);
double getValidDouble(void);
void getValidString(char *buffer, int size);

#endif