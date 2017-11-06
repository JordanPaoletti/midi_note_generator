#ifndef MIDI_HEADER_CHUNK_HEADER
#define MIDI_HEADER_CHUNK_HEADER

#define MTHD 0x4d546864
#define HEADER_LENGTH 6

#include <stdint.h>

/*
 * Header chunk consists of
 * "MThd" + <header_length> + <format> + <ntrks> + <division>
 *
 * where "MThd" is the literal ascii string (no null terminator) -4 bytes on file
 * header length is the length of the header in bytes (always 6 bytes) - 4 bytes on file
 * format: 2 bytes on file
 *      -0 = single track file format
 *      -1 = multiple track format
 *      -2 = mutliple song file format
 *  ntrks is the number of track chunks that follow the header - 2 bytes on file
 *  division is the unit of time for delta timing - 2 bytes on file
 */

typedef struct MidiHeaderChunk {
    uint32_t mthd;
    uint32_t length;
    uint16_t format;
    uint16_t ntrks;
    uint16_t timeDivision;
} MidiHeaderChunk;

typedef enum MidiHeaderFormat {
    Single_Track = 0,
    Multiple_Track,
    Multiple_Song
} MidiHeaderFormat;

MidiHeaderChunk *createMidiHeaderChunk(MidiHeaderFormat format,
        uint16_t ntrks, uint16_t timeDiv);

#endif
