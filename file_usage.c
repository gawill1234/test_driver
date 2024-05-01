/***************************************************************************/
/*
 *   Author:  Gary Williams
 *   Made safe for uclibc
 *
 */
#include "defs.h"

void validateInFile()
{
char *dot, *newfile, *tmpdir;
int len;

   if (infile != NULL) {
      dot = rindex(infile, (int)'.');
      if (dot != NULL) {
         if (strcmp(dot, ".gtd") == 0) {
            if (infile[0] != '/') {
               tmpdir = (char *)calloc(DIRLEN, 1);
               getcwd(tmpdir, DIRLEN);
               len = strlen(tmpdir) + strlen(infile) + 2;
               newfile = (char *)calloc(len, 1);
               sprintf(newfile, "%s/%s", tmpdir, infile);
               infile = newfile;
               free(tmpdir);
            }
            return;
         }
      }
   } else {
      printf("gtd error:   Not input file specified (-i option)\n\n");
      commandLineError();
   }

   printf("gtd error:     file %s is not a valid test list\n", infile);
   printf("               If it is valid, please rename so that the file\n");
   printf("               name ends in .gtd\n\n");
   printf("WARNING:       This utility can not tell the difference between\n");
   printf("               a test and any other executable.  Be aware\n");
   printf("               that any executable that can be found will\n");
   printf("               be executed.  Even if it is shutdown, or\n");
   printf("               rm -rf /.  Be careful how you name your tests.\n");

   exit(-1);
}
