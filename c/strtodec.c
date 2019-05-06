#include <stdio.h>
#include <string.h>

float todec(char *str)
{
	int i, len;
	int dec = 0;
	float num = 0;

	len = strlen(str);
	for (i=0; i < len;i++) {
		if (str[i] == '.') {
			dec = 1;
			continue;
		}

		num = num*10 + (str[i]-'0');

		if (dec) {
			dec *= 10;
		}
	}
	return num/dec;
}

int main()
{
	char str[]="1234.56";
	printf("%f", todec(str));
}
