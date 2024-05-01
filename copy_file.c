/***************************************************************************/
/*
 *   Author:  Gary Williams
 *   Made safe for uclibc
 *
 */
#include "defs.h"

int copyfile(char *infile, char *outfile)
{
int fno, fno2, readnum, writenum;
char mychunk[BLOCK_SIZE];

#ifdef DEBUG
   printf("doCopy():  copying %s  to  %s\n", infile, outfile);
   fflush(stdout);
#endif

   /************************************/
   /*   Open infile for reading
   */ 
   if ((fno = open(infile, O_RDONLY, 00666)) == (-1)) {
      return(fno);
   }

   /************************************/
   /*   Open outfile for writing
   */ 
   if ((fno2 = open(outfile, O_RDWR|O_CREAT,00666)) == (-1)) {
      return(fno2);
   }

   /*************************************/
   /*  Read file a block a time and write
       to the output file.
   */
   readnum = read(fno, mychunk, BLOCK_SIZE);
   while (readnum == BLOCK_SIZE) {
      writenum = write(fno2, mychunk, BLOCK_SIZE);
      readnum = read(fno, mychunk, BLOCK_SIZE);
   }
   writenum = write(fno2, mychunk, readnum);

   /*************************************/
   /*   Close both files
   */
   close(fno);
   close(fno2);

   /*************************************/
   /*  return(success)
   */
   return(0);

}
