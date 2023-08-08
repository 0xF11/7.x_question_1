#include <iostream>
#include <random>
#include <limits>
#include <cmath>
#include <string>
void errorhandling()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
#include <Windows.h> // declared after since it messes with streamsize>::max(), declared for sleep

void errorhandler() // i dont want to type this out every time.
{
	if (!std::cin)
	{
		if (std::cin.eof())
		{
			exit(0);
		}

		std::cin.clear();
		errorhandling();
		std::cout << "You're wasting attempts inputting invalid variables!\n\n";
	}
}

int main()
{
	int restart;
	restart:
	std::random_device rd{};
	std::seed_seq seeder{ rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() }; // seeding

	std::mt19937 rng{ seeder };

	std::uniform_int_distribution HiLow100{ 1,100 };

	int x{ HiLow100(rng) }; // Assigns HiLow variable to X (for the user to be able to properly guess)
	int userinput{}; // Used for user to input whatever number they think the game is
	int attempts{ 0 }; // assigned to 0 so user can only try 3 times

	std::cout << "Hello! Lets play a game of High - Low, The range of numbers is 1 - 100! You have 6 guesses to win! \n";
	std::cout << "Please input your first number!\n";
	std::cout << x << std::endl;
	

	while (attempts <= 5)
	{
		
		errorhandler();


		std::cin >> userinput;
		if (userinput != x)
		{
			std::cout << "Incorrect number! Sorry! Try again!\n";

		}
		else if (userinput == x)
		{
			std::cout << "Great job! You won!\n";
			break;
		}
		

		if (attempts == 5)
		{
			std::cout << "This is your last chance!! Make it count!\n";
		}

		++attempts;

	} //end of actual program
	errorhandler();
	char invalid;
	invalid:
	char playagain;
	std::cout << "\nWould you like to play again? Y/N\n";
	std::cin >> playagain;
	switch (playagain)
	{
	case 'y':
		std::cout << "-------------------------------\n";
		std::cout << "\n\n\n\n\nResetting the game....\n\n\n\n";
		std::cout << "-------------------------------\n";
		Sleep(500);
		goto restart;
	case 'n':
		std::cout << "Maybe next time then i guess :( \n\n";
		Sleep(1000);
		break;
	default:
		std::cout << "Please enter a valid character.\n\n";
		std::cout << "-----------------------------------\n";
		goto invalid;
	}
	
	return 0;
}
