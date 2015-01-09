#include <stdio.h>
#include <time.h>

void rules ();
void draw (int, char);

int main()
{
	char player_name[100];
	int amt, bett_amt, guess, dice;
	char choice[1];

	srand (time(0));

	draw(60, '_');

	printf ("\n\n\n\t\t CASINO GAME \n\n\n\n");

	draw(60, '_');

	printf ("\n\nEnter Your Name : ");
	scanf ("%s", player_name);

	printf ("Hi %s!", player_name);
	printf("\n\nEnter amount to start the game : Rs. ");
	scanf ("%d", &amt);

	do
	{
		rules();

		printf ("\n\nYour current balance is Rs. %d\n", amt);

		do
		{
			printf ("%s Enter money to bet : Rs. ", player_name);
			scanf ("%d", &bett_amt);
			if (bett_amt > amt)
				printf ("You cannot bet more then what you have common!\n Renter the amount");
		}while (bett_amt > amt);

		do
		{
			printf ("Guess the number between 1 to 29 to bet on : ");
			scanf ("%d", &guess);
			if (guess <= 0 || guess > 29)
				printf ("Oh, the range is 1 to 29 included \n Renter the number to bet on : ");
		}while (guess <= 0 || guess > 29);

		dice = rand () % 29 + 1;

		if (dice == guess)
		{
			printf ("Cool, You won. You get Rs. %d more", bett_amt * 5);
			amt = amt + bett_amt * 5;
		}
		else
		{
			printf ("woops, You loose. You lost Rs. %d", bett_amt);
			amt = amt - bett_amt;
		}

		if (amt <= 0)
		{
			printf ("You have no money :(");
			break;
		}

		printf ("\n\nDo you want to play again (y/n)?");
		scanf ("%s", choice);
	}while (choice[0] == 'Y' || choice[0] == 'y');

	printf ("\n\n\n");

	draw (70, '=');

	printf ("\n\n Thanks for palying. :) Your balance amount is Rs. %d\n\n", amt);
	draw (70,'=');
	return 0;
}

void rules ()
{
	printf ("\n\n");
	draw (80, '-');
	printf ("\n");
	printf ("\t\tRules of the game\n");
	draw (80, '-');

	printf ("\t1. Choose any number between 1 to 29 \n");
	printf ("\t2. If you win you will get 5 times of money you bet\n");
	printf ("\t3. If you vet on wrong number you will loose your betting amount \n\n");

	draw (80, '-');
}

void draw (int n, char sym)
{
	int i;

	for (i = 0; i < n; ++i)
	{
		printf ("%c", sym);
	}

	printf ("\n");
}
