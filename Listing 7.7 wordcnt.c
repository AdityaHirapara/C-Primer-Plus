/*
	Name: 赵子豪(ZiHao Zhao)
	Date: 2017年10月20日
*/
//	wordcnt.c -- counts characters, word, line
#include <stdio.h>
#include <ctype.h>			//	for isspace()
#include <stdbool.h>			//	for bool, true, false
#define STOP '|'
int main(void)
{
	char c;			//	read in character
	char prev;			//	previous character read
	long n_chars = 0L;			//	number of characters
	int n_lines = 0;			//	number of lines;
	int n_words = 0;			//	number of words;
	int p_lines = 0;			//	number of partial lines
	bool inword = false;			//	== true if c is in a word

	printf("Enter tet to be analyzed (| to terminate):\n");
	prev = '\n';			//	used to identify complete lines
	while ((c = getchar()) != STOP)
	{
		n_chars++;			//	count characters
		if (c == '\n')
			n_lines++;
		if (!isspace(c) && !inword)
		{
			inword = true;			//	starting a new word
			n_words++;			//	count word
		}
		if (isspace(c) && inword)
			inword = false;			//	reached end of word
		prev = c;			//	save character value
	}

	if(prev != '\n')
		p_lines = 1;
	printf("characters = %ld, words = %d, lines = %d,", n_chars, n_words, n_lines);
	printf("partial lines = %d\n", p_lines);

	return 0;
}
