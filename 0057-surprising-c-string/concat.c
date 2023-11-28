#include <stdio.h>
#include <string.h>

int main(void) {
	char s1[] = "foo";
	char s2[] = "bar";
	char s3[10];

	strcpy(s3, s1);
	strcat(s3, s2);
	printf("%s\n", s3);
}	
