#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* addSpaces(const char* s, const int* spaces, int spacesSize) {
    int len = strlen(s);
    int newLen = len + spacesSize; 
    char* result = (char*)malloc((newLen + 1) * sizeof(char));
    int resIndex = 0, start = 0;

    for (int i = 0; i < spacesSize; i++) {
        int space = spaces[i];
        
        strncpy(result + resIndex, s + start, space - start);
        resIndex += space - start;
        result[resIndex++] = ' '; 
        start = space;
    }
    strcpy(result + resIndex, s + start); 
    return result; 
}