#include <stdlib.h>
#include "midiheader.h"

MidiHeaderChunk *createMidiHeaderChunk(
        MidiHeaderChunk *chunk,
        MidiHeaderFormat format,
        uint16_t ntrks,
        uint16_t timeDiv 
        ) {

    chunk->mthd = MTHD;
    chunk->length = HEADER_LENGTH;
    chunk->format = format;
    chunk->ntrks = ntrks;
    chunk->timeDivision = timeDiv;

    return chunk;
}
