#ifndef CITYTESTER_HEADER
#define CITYTESTER_HEADER

#define TEST_PASSED 1
#define TEST_FAILED 0

int startTest(char *name);
int finishTest(void);

int startSubSection(char *name);
int finishSubSection(void);

int testBool(char *name, int actual, int expected);
int testInt(char *name, long long actual, long long expected);
int testChar(char *name, int actual, int expected);
int testString(char *name, char *actual, char *expected);
int testFloat(char *name, double actual, double expected, double delta);

#endif

