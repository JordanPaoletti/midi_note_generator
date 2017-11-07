#ifndef MIDI_VARIABLE_LENGTH_QUANTITY_HEADER
#define MIDI_VARIABLE_LENGTH_QUANTITY_HEADER

#define MIDI_VLQ_MAX_VAL 0x0fffffff
#define MIDI_VLQ_MAX_BYTES 4

int vlqLength(char *start);
int intToVlq(int value, char *ary);
int vlqToInt(char *start);

#endif
