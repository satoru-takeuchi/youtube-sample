#include <stdio.h>
#include <string.h>

int main(void) {
	char s1[] = "foo";
	char s2[] = "bar";

	printf("%d\n", strcmp(s1, s1) == 0);
	printf("%d\n", strcmp(s1, s2) == 0);
	printf("%d\n", strcmp(s2, s1) == 0);
}	
