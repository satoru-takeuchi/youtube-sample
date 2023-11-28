#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
	char s1[] = "foo";
	char s2[5];
	strcpy(s2, s1);
	printf("%s\n", s2);

	char *s3;
	s3 = strdup(s1);
	printf("%s\n", s3);
	free(s3);
}	
