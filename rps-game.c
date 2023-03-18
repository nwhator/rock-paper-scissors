#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

int get_user_choice(void);
int get_comp_choice(void);
void play_game(int *user_wins, int *comp_win);
void print_taunt(int winner);
int prompt_again(void);

/**
 * main - Entry point
 * Description: Rock Paper Scissors | Random Number Generator | Score Keeper
 * Return: 0
 */

int main(void)
{
	int play_again = 1, user_wins = 0, comp_wins = 0;

	srand(time(NULL));
	/* random number generator with the current time */
	while (play_again)
	{
		play_game(&user_wins, &comp_wins);
		play_again = prompt_again();
	}
	printf("Final score: You - %d, Computer - %d\n", user_wins, comp_wins);
	return (0);
}

/**
 * get_user_choice - Main entry
 * Description: User choice on Rock Paper Scissors
 * a number representing the user's choice (1 = rock, 2 = paper, 3 = scissors)
 * Return: int
 */

int get_user_choice(void)
{
	char input[9]; /* 9 to leave space for enough input from user */
	int i;

	printf("Enter your choice - rock, paper or scissors: ");
	scanf("%s", input);

	/* Converts input to lowercase */
	for (i = 0; input[i]; i++)
	{
		input[i] = tolower(input[i]);
	}
	/* Check the input against the possible choices */
	if (strcmp(input, "rock") == 0)
	{
		return (1);
	}
	else if (strcmp(input, "paper") == 0)
	{
		return (2);
	}
	else if (strcmp(input, "scissors") == 0)
	{
		return (3);
	}
	else
	{
		printf("Please try again. Invalid choice!");
		return (get_user_choice());
	}
}

/**
 * get_comp_choice - Main entry
 * Description: Gets computer's input
 */

int get_comp_choice(void)
{
	return ((rand() % 3) + 1);
}

/**
 * play_game - Main entry
 * Description: Plays one round of Rock Paper Scissors
 * @user_wins: pointer to user's score
 * @comp_wins: pointer to computer's score
 */

void play_game(int *user_wins, int *comp_wins)
{
	int user_choice, comp_choice, winner;

	user_choice = get_user_choice();
	comp_choice = get_comp_choice();

	/* 1 = rock, 2 = paper, 3 = scissors */
	if (user_choice == comp_choice)
	{
		printf("It's a tie!\n");
		winner = 0;
	}
	else if ((user_choice == 1 && comp_choice == 3) ||
		(user_choice == 2 && comp_choice == 1) ||
		(user_choice == 3 && comp_choice == 2))
	{
		printf("You win!\n");
		*user_wins += 1;
		winner = 1;
	}
	else
	{
		printf("Computer wins!\n");
		*comp_wins += 1;
		winner = -1;
	}
	print_taunt(winner);
}

/**
 * print_taunt - Main entry
 * Description: Prints a taunt message if the user wins
 * @winner: indicates who won the game
 */

void print_taunt(int winner)
{
	if (!winner)
	{
		switch (rand() % 3)
		{
			case 0:
				printf("Ha! You lost to a computer.\n");
				break;
			case 1:
				printf("The computer is superior to humans.\n");
				break;
			case 2:
				printf("Looks like you need more practice!\n");
				break;
		}
	}
	else
	{
		switch (rand() % 3)
		{
			case 0:
				printf("I got lucky this time!\n");
				break;
			case 1:
				printf("Ha! I win again!\n");
				break;
			case 2:
				printf("I am unstoppable!\n");
				break;
		}
	}
}

/**
 * prompt_again - Main entry
 * Description: Ask if the user wants to play again
 * Return: int (0 if no, 1 if yes)
 */

int prompt_again(void)
{
	char input[4];

	printf("Do you want to play again? (yes/no): ");
	scanf("%s", input);

	if (strcmp(input, "yes") == 0)
	{
		return (1);
	}
	else if (strcmp(input, "no") == 0)
	{
		return (0);
	}
	else
	{
		printf("Please enter a valid input\n");
		return (prompt_again());
	}
}
