#include <string.h>
#include <stdio.h>

size_t	strlcat(char *dst, const char *src, size_t size);

int main(void)
{
	char *dst = "Hello";
	char *src = " world!";

	printf("%zu", strlcat(dst, src, 12));
	printf("%s", dst);
}
