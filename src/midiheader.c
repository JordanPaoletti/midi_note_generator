#include <stdlib.h>
#include "midiheader.h"

MidiHeaderChunk *createMidiHeaderChunk(MidiHeaderFormat format,
        uint16_t ntrks, uint16_t timeDiv) {
    MidiHeaderChunk *retval = (MidiHeaderChunk *) malloc(sizeof(MidiHeaderChunk));

    retval->mthd = MTHD;
    retval->length = HEADER_LENGTH;
    retval->format = format;
    retval->ntrks = ntrks;
    retval->timeDivision = timeDiv;

    return retval;
}
