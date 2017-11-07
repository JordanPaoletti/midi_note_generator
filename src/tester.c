#include <stdio.h>
#include "midivlq.h"
/*
 * Tests the entire git repo.
 * or a bunch of small crappy tests, only time will tell
 */

void printTest(int passed, const char *name);


void testVLQs();

int main(void) {
    testVLQs();
}

/*
 * File testing
 */

/*
 * midivlq.h
 */
void testVLQs() {
    //varibles
    char vlqLength_1[] = {0x00};
    char vlqLength_2[] = {0x80, 0x00};
    char vlqLength_3[] = {0x80,0x80,0x00};
    char vlqLength_4[] = {0x80,0x80,0x80,0x00};
    char vlqLength_5[] = {0x80,0x80,0x80,0x80,0x00};

    /*
     * vlqLength tests
     */
    printTest(vlqLength(vlqLength_1) == 1,
            "vlqLength - length 1");
    printTest(vlqLength(vlqLength_2) == 2,
            "vlqLength - length 2");
    printTest(vlqLength(vlqLength_3) == 3,
            "vlqLength - length 3");
    printTest(vlqLength(vlqLength_4) == 4,
            "vlqLength - length 4");
    vlqLength(vlqLength_5); //should print to stderr

}

/*
 * Helper functions
 */
void printTest(int passed, const char *name) {
    if (passed) {
        printf("%s: passed\n", name);
    }
    else {
        printf("%s: failed\n", name);
    }
}
