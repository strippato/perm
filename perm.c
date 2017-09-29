//  
//	strippato@gmail.com
//
//	gcc -O2 -Wall perm.c -o perm 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long int
perm (char *data, char *base)
{
	unsigned long int nperm = 0;

	size_t lenData = strlen (data);
	size_t lenBase = strlen (base);

	if (lenData == 1) {
		// done!
		printf ("%s%s\n", base, data);
		
		return 1;

	} else {
		
		for (int i = 0; i < lenData; ++i) {
			
			// copy
			char *tmpstr = malloc (lenData + 1);
			strcpy (tmpstr, data);
			
			// swap (0,i)
			char firstchr;
			firstchr   = tmpstr [0];
			tmpstr [0] = tmpstr[i];
			tmpstr [i] = firstchr;

			// build nextbase
			char *nextbase = malloc (lenBase + 1 + 1);
			strcpy (nextbase, base);
			nextbase [lenBase] = tmpstr [0];
			nextbase [lenBase + 1] = '\0';

			nperm += perm (&tmpstr [1], nextbase);

			// avoid memleak 
			free (nextbase);
			free (tmpstr);
		}

		return nperm;

	}

}

int
main (int argc, char *argv[])
{
	if (argc > 1) printf ("Total: %li\n", perm (argv[1], ""));

	return EXIT_SUCCESS;
}

