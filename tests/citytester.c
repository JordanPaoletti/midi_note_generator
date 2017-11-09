#include "citytester.h"
#include <stdio.h>
#include <string.h>

//file variables
static char *testName;
static int inTest;
static char *subName;
static int inSub;

static int MainTestPasses;
static int MainTestFails;
static int subTestPasses;
static int subTestFails;


static int isInTest(void);
static void failTest(void);
static void passTest(void);
static int isInSub(void);

#define BOOL(X) ((X ? "true" : "false"))

/*
 * Starts a new test to be tracked by the tester
 * returns 1 if successfully started
 * returns 0 if failed
 */
int startTest(char *name) {
    if (!inTest) {
        MainTestPasses = 0;
        MainTestFails = 0;
        testName = name;
        inTest = 1;
        printf("\n**************************************************\n");
        printf(  "*  %s\n", testName);
        printf(  "**************************************************\n");
        return 1;
    }
    else {
        fprintf(stderr, "Can't create test, test already in progress\n");
        return 0;
    }
}

/**
 * ends the current test and print stats
 * returns 1 if successful
 * returns 0 otherwise
 */
int finishTest(void) {
    if (isInTest()) {
        double passPercent = 100 * ((double)MainTestPasses / (MainTestPasses + MainTestFails));
        if (inSub) {
            finishSubSection();
        }

        inTest = 0;
        printf("\n**************************************************\n");
        printf(  "* passed: %d, failed: %d, passed %.2f\n", MainTestPasses,
                MainTestFails, passPercent);
        printf(  "*  %s\n", testName);
        printf(  "**************************************************\n");
        return 1;

    }
    return 0;
}


/*
 * Starts a subsection of tests
 * returns 1 if successful
 * return 0 if failed
 */
int startSubSection(char *name) {
    if (!inSub) {
        subTestFails = 0;
        subTestPasses = 0;
        subName = name;
        inSub = 1;
        printf("\n--------------------------------------------------\n");
        printf(  "-  %s\n", subName);
        printf(  "--------------------------------------------------\n");
        return 1;
    }
    else {
        fprintf(stderr, "Can't create subsection, already in a subsection");
        return 0;
    }
}

/*
 * ends a subsection
 * returns 1 if successful
 * returns 0 if failed
 */
int finishSubSection(void) {
    if (isInSub()) {
        double passPercent = 100 * ((double)subTestPasses / (subTestPasses + subTestFails));

        inSub = 0;
        printf("\n--------------------------------------------------\n");
        printf(  "- passed: %d, failed: %d, passed %.2f\n", subTestPasses, 
                subTestFails, passPercent);
        printf(  "-  %s\n", subName);
        printf(  "--------------------------------------------------\n");
        inSub = 0;
        return 1;
    }
    return 0;
}

int testBool(char *name, int actual, int expected) {
   if (actual == expected) {
       printf("%s - PASSED\n", name);
       passTest();
       return TEST_PASSED;
   }
   else {
       printf("%s - FAILED\n", name);
       printf("    Expected: %s, Actual: %s\n", BOOL(expected), BOOL(actual));
       failTest();
       return TEST_FAILED;
   }
}

int testInt(char *name, long long actual, long long expected) {
   if (actual == expected) {
       printf("%s - PASSED\n", name);
       passTest();
       return TEST_PASSED;
   }
   else {
       printf("%s - FAILED\n", name);
       printf("    Expected: %lld, Actual: %lld\n", expected, actual);
       failTest();
       return TEST_FAILED;
   }
}

int testChar(char *name, int actual, int expected) {
   if (actual == expected) {
       printf("%s - PASSED\n", name);
       passTest();
       return TEST_PASSED;
   }
   else {
       printf("%s - FAILED\n", name);
       printf("    Expected: %c, Actual: %c\n", (char)expected, (char)actual);
       failTest();
       return TEST_FAILED;
   }
}

int testString(char *name, char *actual, char *expected) {
   if (strcmp(actual, expected)) {
       printf("%s - PASSED\n", name);
       passTest();
       return TEST_PASSED;
   }
   else {
       printf("%s - FAILED\n", name);
       printf("    Expected: %s, Actual: %s\n", expected, actual);
       failTest();
       return TEST_FAILED;
   }
}

int testFloat(char *name, double actual, double expected, double delta) {
   if (actual > expected - delta && actual < expected + delta) {
       printf("%s - PASSED\n", name);
       passTest();
       return TEST_PASSED;
   }
   else {
       printf("%s - FAILED\n", name);
       printf("    Expected: %f, Actual: %f\n", expected, actual);
       failTest();
       return TEST_FAILED;
   }
}


static void passTest(void) {
    MainTestPasses++;
    if (inSub) {
        subTestPasses++;
    }
}

static void failTest(void) {
    MainTestFails++;
    if (inSub) {
        subTestFails++;
    }
}

static int isInTest(void) {
    if (!inTest) {
        fprintf(stderr, "City Tester is not currently in a Main Test\n");
        return 0;
    }
    else
        return 1;
}

static int isInSub(void) {
    if (!inSub) {
        fprintf(stderr, "City Tester is not currently in a sub section\n");
        return 0;
    }
    else 
        return 1;
}
        
