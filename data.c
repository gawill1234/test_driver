/***************************************************************************/
/*
 *   Author:  Gary Williams
 *   Made safe for uclibc
 *
 */
#include "defs.h"

struct limitations test_limits;

struct thing **mymess;

/****************************************************/
/*  This is the running test table.  It contains all
 *  of the data for up to MAXTESTS tests (default, 32).
 *  This defines the maximum level of concurrency 
 *  allowed by the drive.
 */
struct tdata running_tests[MAXTESTS];

char *newenv, *thome, *optDir;
char *driveCommand;
char *infile;
int myuid;

FILE *outfp, *fp, *failfp, *runfp;

char *tmpdirname;
int runcount, newsession;

int MAXCONCUR;
int TIMEOUT_TIME;
int SLEEPTIME;
int REPEAT_COUNT;
int RUN_TIME;

int GL_keepall, GL_dorandom, GL_time_over;
int GL_ig_ig, GL_totalmem, GL_wantmem;

time_t GL_start_time, GL_end_time;
