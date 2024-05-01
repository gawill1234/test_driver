/***************************************************************************/
/*
 *   Author:  Gary Williams
 *   Made safe for uclibc
 *
 */
#include "defs.h"

/*********************************************************/
/*   Takes the read line dealing with the test and saves
 *   it to the test data area.  At the end of this function,
 *   each test is completely self-contained, at least as far
 *   as associated data is concerned.
 */
int dohickey(char *input)
{
char **myargs, *mycopy1, *mycopy2;
int slotid;

   envvarreplace(input);

   /***************************************************/
   /*   To copies of the read line.  One is to be kept
    *   intact so it can be returned to the user if
    *   necessary.  The other is manipulated to become
    *   the container for the arguments to execvp.
    *   Stored in running_test[].cmdline and
    *             running_test[].modline
    */
   mycopy1 = copyline(input);
   mycopy2 = copyline(input);

   /**************************************************/
   /*   Manipulate one of the lines and have the execvp
    *   args point to it.
    *             running_test[].args
    */
   myargs = domyargs(mycopy1);

   /**************************************************/
   /*   Stash all of the test data in one of the available
    *   test structures.
    */
   slotid = useslot(-1, mycopy2, myargs, mycopy1);

   return(slotid);
}
