#include <iostream>
#include "constants.h"

double calculateHeight(double initialHeight, int seconds)
{
	double distanceFallen{ myConstants::gravity * seconds * seconds / 2 }; // math for gravity
	double heightNow{ initialHeight - distanceFallen }; // distance in the air MATH

	// Check whether we've gone under the ground
	// If so, set the height to ground-level

	if (heightNow < 0.0) // if height is less than 0 set it to 0
		return 0.0;
	else
		return heightNow; // otherwise return what the current height is
}

bool calculateAndPrintHeight(double initialHeight, int time) // Set function to a boolean so the program knows if its true or false
{
	double solution{ calculateHeight(initialHeight,time) }; // calculates time & height together
	std::cout << "At " << time << " seconds, the ball is at height: " << solution << '\n'; // bullshit

	return (solution == 0); // returns our solution value 
}

int main()
{
	std::cout << "Enter the initial height of the tower in meters: ";
	double initialHeight{}; 
	std::cin >> initialHeight; // intake user height

	int seconds{ 0 }; // used for a for loop
	
	while (!calculateAndPrintHeight(initialHeight, seconds))
	{
		++seconds;
	}
	
	

	return 0;
}
