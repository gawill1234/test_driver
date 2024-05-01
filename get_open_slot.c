/***************************************************************************/
/*
 *   Author:  Gary Williams
 *   Made safe for uclibc
 *
 */
#include "defs.h"

/***********************************************************/
/*   Find any unused slot.
 */
int getopenslot()
{
   return(findslotbypid(0));
}
