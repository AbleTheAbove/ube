/*  Wide char wrapper for strtof
 *  Revision history:
 *  25 Aug 2006 Initial version.
 *
 *  Contributor:   Danny Smith <dannysmith@users.sourceforege.net>
 */

 /* This routine has been placed in the public domain.*/

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <locale.h>
#include <wchar.h>
#include <stdlib.h>
#include <string.h>
#include <mbstring.h>

#include "mb_wc_common.h"

float wcstof (const wchar_t * __restrict__ wcs, wchar_t ** __restrict__ wcse)
{
  char * cs;
  char * cse;
  unsigned int i;
  float ret;
  const unsigned int cp = ___lc_codepage_func();

  /* Allocate enough room for (possibly) mb chars */
  cs = (char *) malloc ((wcslen(wcs)+1) * MB_CUR_MAX);

  if (cp == 0) /* C locale */
    {
                   for (i = 0; (wcs[i] != 0) && wcs[i] <= 255; i++)
	cs[i] = (char) wcs[i];
                   cs[i]  = '\0';
    }
  else
    {
                   int nbytes = -1;
                   int mb_len = 0;
                   /* loop through till we hit null or invalid character */
                   for (i = 0; (wcs[i] != 0) && (nbytes != 0); i++)
	{
	  nbytes = WideCharToMultiByte(cp, WC_COMPOSITECHECK | WC_SEPCHARS,
				                    wcs + i, 1, cs + mb_len, MB_CUR_MAX,
				                    NULL, NULL);
	  mb_len += nbytes;
	}
                   cs[mb_len] = '\0';
    }

  ret =  strtof (cs, &cse);

  if (wcse)
    {
                   /* Make sure temp mbstring cs has 0 at cse.  */ 
                   *cse = '\0';
                   i = MultiByteToWideChar (cp, MB_ERR_INVALID_CHARS, cs, -1, NULL, 0);
                   if (i > 0)
                     i -= 1; /* Remove zero terminator from length.  */
                   *wcse = (wchar_t *) wcs + i;
    }
  free (cs);

  return ret;
}
