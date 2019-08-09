#include<stdio.h>

void getstr(char str[], int arrlen)
{
	int i;
	char * strend = NULL;

	fgets(str, arrlen, stdin);
	for (i = 0; i < arrlen - 1; i++)
	{
		if (str[i] == '\n')
		{
			str[i] = '\0';
			strend = &str[i];
			break;
		}
	}
	if (strend == NULL)
	{
		str[arrlen - 1] = '\0';
		while (getchar() != '\n')
			continue;
	}
}
