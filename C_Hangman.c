#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLENGTH 80
#define MAX_TRIES 5

int alpha_insert (char, char[], char[]);
void init_unknown (char[], char[]);

int main()
{
	int num_of_wrong_guess = 0;

	char alphabet;
	char unknown[MAXLENGTH];
	char word[MAXLENGTH];
	char words[5][MAXLENGTH] = {
		"struct",
		"extern",
		"typedef",
		"sizeof",
		"volatile"
							  };

	int n = rand () / 5 * 5;
	strcpy (word, words[n]);

	init_unknown (word, unknown);

	printf ("\n\nLet's Play C Hangman....Guess a C keyword");
	printf ("\n\nEach letter is represented by a underscore.");
	printf ("\n\nYou have to type only one letter in a single try");
	printf ("\n\nYou have %d tries to try and guess the keyword", MAX_TRIES);
	printf ("\n---------------------------------------------------");

	while (num_of_wrong_guess < MAX_TRIES)
	{
		printf ("\n\n %s", unknown);
		printf ("\n\nGuess a alphabet: ");
		scanf ("%c", &alphabet);

		if (alpha_insert (alphabet, word, unknown) == 0)
		{
			printf ("\nWoops! That letter isn't in there\n");
			++num_of_wrong_guess;
		}
		else
		{
			printf ("\nYou found a letter! Awesome :D\n");
		}

		printf ("You have %d guesses left\n", MAX_TRIES - num_of_wrong_guess);

		if (strcmp (word, unknown) == 0)
		{
			printf ("%s\n", word);
			printf ("Awesome! You got it!");
			break;
		}

		if (num_of_wrong_guess == MAX_TRIES)
		{
			printf ("\nOops! You Lose! Hanged!\n");
			printf ("The word was : %s\n", word);
		}

	}
	return 0;
}

int alpha_insert (char guess, char hidden_word[], char guess_word[])
{
	int i;
	int matches = 0;
	for (i = 0; hidden_word[i] != '\0'; ++i)
	{
		if (guess == guess_word[i])
		{
			return 0;
		}

		if (guess == hidden_word[i])
		{
			guess_word[i] = guess;
			++matches;
		}
	}
	return matches;
}

void init_unknown (char word[], char unknown[])
{
	int i;
	int length = strlen (word);
	for (i = 0; i < length; ++i)
	{
		unknown[i] = '-';
	}
	unknown[i] = '\0';
}
