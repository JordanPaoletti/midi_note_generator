#include "midivlq.h"
#include <stdio.h>
#include <stdint.h>

#define CONTINUE_BIT_MASK 0x80
#define VALUE_BITS_MASK 0x7f
/**
 * returns how many bytes the vlq is (stops at max bytes by midi standard)
 * -1 if the vlq is invalid
 */
int32_t vlqLength(char *start) {
    int32_t length = 1;
    while (*start & CONTINUE_BIT_MASK && length < MIDI_VLQ_MAX_BYTES) {
        length++;
        start++;
    }
    if (length == 4 && *start & CONTINUE_BIT_MASK) {
        fprintf(stderr, "vlqLength - last byte does not have continue bit cleared\n");
        length = -1;
    }
    return length;
}


/*
 * converts an int32_t value to char array
 * returns 0 if value is greater than max vlq value
 * otherwise returns length
 * ary must be at least 4 bytes
 */ 
int32_t int32ToVlq(int32_t value, char *ary) {
    int32_t length = 0;
    if (value > MIDI_VLQ_MAX_VAL) {
        fprintf(stderr, "int32ToVlq - passed value is greater than max vlq value");
        return length;
    }

    while (value) {
        *ary = (char) value & VALUE_BITS_MASK;
        value >>= 7;
        *ary |= CONTINUE_BIT_MASK;
        ary++;
        length++;
    }
    *(ary-1) &= (char)~CONTINUE_BIT_MASK; //clear continue bit on last byte

    return length;
}

/*
 * Takes a point to the start of a vlq and
 * returns the int32_t represented by the vlq.
 * returns -1 if error
 */
int32_t vlqToint32(char *start) {
    int32_t retval = 0;

    while (*start & CONTINUE_BIT_MASK) {
        retval |= *start & VALUE_BITS_MASK;
        retval <<= 7;
        start++;
    }
    retval |= *start & VALUE_BITS_MASK;

    if (*start & CONTINUE_BIT_MASK) {
        retval = -1;
    }

    return retval;
}
