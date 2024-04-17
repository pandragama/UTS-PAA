#include <stdio.h>
#include <stdlib.h>

#include "penjadwalan.h"

// create function bruteForce to exchange coins
// Brute Force Algorithm
void bruteForce(int coin[], int manyCoins, int coinExchange)
{
	// Initialize variables to keep track of minimum coins and the combination
	int minCoins = coinExchange;
	int bestCombination[manyCoins];

	// Iterate through all possible combinations
	for (int i = 0; i <= coinExchange; i++)
	{
		int currentCoins = 0;
		int currentCombination[manyCoins];

		// Try all possible combinations for current amount
		for (int j = 0; j < manyCoins; j++)
		{
			int count = 0;
			while (currentCoins + coin[j] <= coinExchange && count < manyCoins)
			{
				currentCombination[j]++;
				currentCoins += coin[j];
				count++;
			}
		}

		// If current combination uses fewer coins, update the best combination
		if (currentCoins == coinExchange && currentCoins < minCoins)
		{
			minCoins = currentCoins;
			for (int j = 0; j < manyCoins; j++)
			{
				bestCombination[j] = currentCombination[j];
			}
		}
	}

	// Output the best combination
	printf("Best combination using brute force: ");
	for (int i = 0; i < manyCoins; i++)
	{
		printf("%d ", bestCombination[i]);
	}
	printf("\n");
}

// Greedy Algorithm
void greedyAlgorithm(int coin[], int manyCoins, int coinExchange)
{
	// Initialize variables to keep track of used coins and remaining amount
	int usedCoins[manyCoins];
	int remainingAmount = coinExchange;

	// Initialize usedCoins array with zeros
	for (int i = 0; i < manyCoins; i++)
	{
		usedCoins[i] = 0;
	}

	// Iterate through coins starting from the highest denomination
	for (int i = manyCoins - 1; i >= 0; i--)
	{
		// Calculate how many of this coin can be used
		usedCoins[i] = remainingAmount / coin[i];
		// Update the remaining amount
		remainingAmount %= coin[i];
	}

	// Output the used coins
	printf("Coins used using greedy algorithm: ");
	for (int i = 0; i < manyCoins; i++)
	{
		printf("%d ", usedCoins[i]);
	}
	printf("\n");
}

// precedure base exchange coins
void exchangeCoins()
{

	int manyCoins, coinExchange, selectAlgorithm;
	printf("Masukkan jumlah coin: ");
	scanf("%d", &manyCoins);

	int coin[manyCoins];

	printf("Masukkan coin: ");
	for (int i = 0; i < manyCoins; i++)
	{
		scanf("%d", &coin[i]);
	}

	printf("Masukkan jumlah uang yang akan ditukar: ");
	scanf("%d", &coinExchange);

	printf("Pilih menu:\n");
	printf("1. Brute Force \n");
	printf("2. Greedy Algorithm \n");
	printf("Choise Algorithm : \n");
	scanf("%d", &selectAlgorithm);

	if (selectAlgorithm == 1)
	{
		bruteForce(coin, manyCoins, coinExchange);
	}
	else if (selectAlgorithm == 2)
	{
		greedyAlgorithm(coin, manyCoins, coinExchange);
	}
	else
	{
		printf("Algorithm tidak ditemukan\n");
	}
}

int main()
{
	int pilihanProgram;
	printf("Pilih program: \n");
	printf("1. Exchange Coins \n");
	printf("2. Task Scheduling \n");
	printf("3. Knapsack Problem \n");
	printf("4. Exit \n");
	printf("Pilih program: ");
	scanf("%d", &pilihanProgram);

	switch (pilihanProgram)
	{
	case 1:
		exchangeCoins();
		break;
	case 2:
		taskScheduling();
		break;
	case 3:
		// knapsackProblem();
		break;
	case 4:
		exit(0);
		break;
	default:
		printf("Program tidak ditemukan\n");
		break;
	}
	return 0;
}