#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "midival.h"

int main(int argc, char **argv) {
    //testing code
    char input[100];
    int midiVal;
    char *inFile = "test.txt";
    char *outFile = "out.txt";
    FILE *rfp;
    FILE *wfp;

    rfp = fopen(inFile, "r");
    wfp = fopen(outFile, "w");

    while (fgets(input, 100, rfp)) {
        midiVal = midiValFromString(input);
        printf("%s: %d\n", input, midiVal);
        fprintf(wfp, "%d\n", midiVal);
    }

    fclose(rfp);
    fclose(wfp);

}
