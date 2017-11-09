#include <stdio.h>
#include "../src/midivlq.h"
#include "citytester.h"
/*
 * Tests the entire git repo.
 * or a bunch of small crappy tests, only time will tell
 */

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
    startTest("midivlq.h");

    //varibles
    char vlqLength_1[] = {0x00};
    char vlqLength_2[] = {0x80, 0x00};
    char vlqLength_3[] = {0x80,0x80,0x00};
    char vlqLength_4[] = {0x80,0x80,0x80,0x00};
    char vlqLength_5[] = {0x80,0x80,0x80,0x80,0x00};

    /*
     * vlqLength tests
     */
    startSubSection("vlqLength tests");

    testInt("vlqLength 1", vlqLength(vlqLength_1), 1);
    testInt("vlqLength 2", vlqLength(vlqLength_2), 2);
    testInt("vlqLength 3", vlqLength(vlqLength_3), 3);
    testInt("vlqLength 4", vlqLength(vlqLength_4), 4);
    testInt("vlqLength err", vlqLength(vlqLength_5), -1);

    finishSubSection();
    finishTest();


}

