/***************************************************************************/
/*
 *   Author:  Gary Williams
 *   Made safe for uclibc
 *
 */
#include "defs.h"

char *newTestFileData(char *basefile, char *oldfile)
{
FILE *localfp, *bfp;
char *newFileName;
int testCount;

   testCount = 0;
   newFileName = newTestListFile(oldfile);

   if (newFileName == NULL) {
      return(NULL);
   }

   localfp = fopen(newFileName, "a+");
   bfp = fopen(basefile, "r");
   if (bfp == NULL) {
      printf("ERROR:  Could not open file %s\n", basefile);
      fflush(stdout);
      exit(0);
   }

   if (testCount <= 0) {
      testCount = doTestCount(bfp);
   }

   makeLineUseTrack(testCount);
   randomize(testCount);

   fillNewFile(bfp, localfp);

   clearLineUseTrack(testCount);
   fclose(bfp);
   fclose(localfp);

   return(newFileName);
}
