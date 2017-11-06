#include "midival.h"
#include <ctype.h>

#define NUM_NOTES 7

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
 *  -& reduces pitch by half tone
 *  -# increases pitch by half tone
 *  -arbitrary number of theses can precede note
 * note: character that a - g
 * octave: octave val based on middle c octave
 *
 * returns -999 if invalid
 */
int midiValFromString(char *str) {
    int retVal, octaveMod, pitchMod, note;

    retVal = -999;

    //determine flats/sharps
    pitchMod = 0;
    while (*str == '#' || *str == '&') {
        if (*str == '#') {
            pitchMod++;
        }
        else { //must be '&'
            pitchMod--;
        }
        str++;
    }

    //determine note
    note = getNoteNumber(*str);
    str++;
    if (note != -1 && isdigit(*str)) {
        octaveMod = (*str - '0') - middleCOctave; //get octave offset from mid c
        retVal = MIDDLE_C + note; //get midi value in relation to mid c
        retVal += 12 * octaveMod + pitchMod; //apply offset
    }

    return retVal;
}

/*
 * returns the note number (c = 0, d = 2, ... b = 11)
 * for passed character. -1 if the character is invalid
 * note number represents midi # offset from c
 */
static int getNoteNumber(char note) {
    int retVal = -1;

    if (isupper(note)) {
       note = tolower(note);
    }

    switch (note) {
        case 'c':
            retVal = 0;
            break;
        case 'd':
            retVal = 2;
            break;
        case 'e':
            retVal = 4;
            break;
        case 'f':
            retVal = 5;
            break;
        case 'g':
            retVal = 7;
            break;
        case 'a':
            retVal = 9;
            break;
        case 'b':
            retVal = 11;
            break;
        default:
            break;
    }

    return retVal;
}
