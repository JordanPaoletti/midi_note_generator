#include "midival.h"
#include <ctype.h>

static int getNoteNumber(char note);

static signed char middleCOctave = 5;

/*
 * Sets the octave value for middle c
 * in order to calibrate midi values
 * returned from string parsing
 */
void setMiddleCOctave(int octave) {
    middleCOctave = octave;
}

/*
 * Returns the midi value from passed
 * string. String is of format
 * [flat/sharp mods][note][octave]
 * 
 * flat/sharp mods: change pitch of note
 *  -b reduces pitch by half tone
 *  -# increases pitch by half tone
 *  -arbitrary number of theses can precede note
 * note: character that a - g
 * octave: octave val based on middle c octave
 */
int midiValFromString(char *str) {
}

/*
 * returns the note number (c = 0, d = 1, ... a = 11)
 * for passed character. -1 if the character is invalid
 */
static int getNoteNumber(char note) {
    int retVal = -1;

    if (isupper(note)) {
       note = tolower(note);
    }

    if (note >= 'a' || note <= 'g') {
        retVal = note - 'c';
        retVal = (retVal < 0) ? retVal + 'g'-'a' : retVal;
    }

    return retVal;
}
