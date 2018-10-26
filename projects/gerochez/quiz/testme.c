#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
	int index = (rand() % 94) + 32;
	char returnVal = index;
	return returnVal;
}

char *inputString()
{
	char newstr[6];
	memset(newstr, '\0', sizeof(newstr));
	for (int i = 0; i < 5; i++)
	{
		int index = (rand() % 26) + 97;
		char putMe = index;
		newstr[i] = putMe;
	}
	return newstr;
}

void testme()
{
	int tcCount = 0;
	char s[6];
	memset(s, '\0', sizeof(s));
	char c;
	int state = 0;
	while (1)
	{
		tcCount++;
		c = inputChar();
		strcpy(s, inputString());
		printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

		if (c == '[' && state == 0) state = 1;
		if (c == '(' && state == 1) state = 2;
		if (c == '{' && state == 2) state = 3;
		if (c == ' ' && state == 3) state = 4;
		if (c == 'a' && state == 4) state = 5;
		if (c == 'x' && state == 5) state = 6;
		if (c == '}' && state == 6) state = 7;
		if (c == ')' && state == 7) state = 8;
		if (c == ']' && state == 8) state = 9;
		if (s[0] == 'r' && s[1] == 'e'
			&& s[2] == 's' && s[3] == 'e'
			&& s[4] == 't' && s[5] == '\0'
			&& state == 9)
		{
			printf("error ");
			break;
			//exit(200);
		}
	}
}


int main(int argc, char *argv[])
{
	srand(time(NULL));
	testme();
	return 0;
}
