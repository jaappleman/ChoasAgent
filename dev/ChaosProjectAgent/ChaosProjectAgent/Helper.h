#pragma once
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <random>

namespace Helper
{
	// defining const display color values for strings
	const std::string PINK = "\033[95m";
	const std::string LIGHT_PINK = "\033[38;5;218m";
	const std::string HOT_PINK = "\033[38;5;205m";
	const std::string SOFT_PINK = "\033[38;5;213m";
	const std::string CYAN = "\033[36m";
	const std::string YELLOW = "\033[33m";
	const std::string RED = "\033[31m";
	const std::string GREEN = "\033[32m";
	const std::string ORANGE = "\033[38;5;208m";
	const std::string PURPLE = "\033[35m";
	const std::string GOLD = "\033[38;5;220m";
	const std::string RESET = "\033[0m";
	// In your Helper namespace Add the following static method
	// CoinFlip
	// This method is static
	static bool CoinFlip()
	{
		/// this seeds a different random number generator that will cause problems so I need to change it
		// static std::random_device rd; // obtain a random seed
		// static std::mt19937 gen(rd()); // creates a random number generator and seeds the device
		// Think about coinflips as one or the other type number and how that may be reflected in code
		// static std::uniform_int_distribution<> distrib(0, 1); // return a value of either 1 or 0
		// This method returns a bool
		// return distrib(gen) == 1; // will return true for heads (1) or false for tails (0)
		/// simplifying to use the same seed from main
		return rand() % 2 == 1; // % 2 will = either 1 or 0 and return true for heads (1) or false for tails (0)
	}
	// creating a multicolor banner for the RPG title screen
	static void BannerRPG()
	{
		std::cout << PURPLE
			<< "\n============================================\n";
		std::cout << RED
			<< "     EVERYTHING ";
		std::cout << ORANGE
			<< "EVERYWHERE ";
		std::cout << GREEN
			<< "ALL AT ONCE!\n";
		std::cout << CYAN
			<< "           A MULTIVERSE BATTLE\n";
		std::cout << GOLD
			<< "============================================\n";
		std::cout << RESET << "\n";
	}

	static bool IntegerValidation(char* input)
	{
		bool isValid = false; /// set bool to false
		int intValue; /// intiate an int
		/// using sscanf_s to convert the input from a char array to an int by assigning it to the memory address of the uninitialized int intValue
		if (sscanf_s(input, "%d", &intValue) > NULL && *input != '\n') /// if statement to check if something has been entered by the user and that the input was converted to an int that is more than 0
		{
			printf("\nValid integer followed by ENTER key.\n"); /// print the result of the check of the user successfully entering an int value and pressing ENTER
			printf("User input: %d", intValue); /// print the user input valiue converted successfully to an int value of intValue
			isValid = true; /// set bool to true
		} 
		else
		{
			printf("\nUser entry not valid.\n"); /// output error message that a valid integer was not entered
			isValid = false; /// set bool to false
		}
		
		return isValid; /// return bool result
	}			
	//  Description: Validates that the parameter is a valid integer. It should accept a char* as input, converting the input into an integer and ensuring the input is valid. If the input is not a valid integer, it will return false.
	//  Example parameters: char* (the input char[] to validate)
	//  Return type: bool (true if valid, false if invalid)
	//  Good Test case is to use user input to use this as a validation.
	//  Hint: You will need to do independent research for determining if the data entered in the char* is a valid integer value.

	static void PrintIntegerBinary(int* num)
	{
		if (num == NULL) /// if statement to check for a NULL pointer
		{
			printf("Error: NULL pointer passed.\n"); /// print error message for a NULL pointer
			return; /// return to main
		}

		unsigned int value = (unsigned int)(*num); /// Handle negative numbers via unsigned cast
		int totalBits = sizeof(int) * 8;           /// Number of bits in an int

		for (int i = totalBits - 1; i >= 0; i--) /// iterate through the bits from left to right
		{
			unsigned int mask = 1u << i; /// set mask for collecting the bits
			printf("%c", (value & mask) ? '1' : '0'); /// print bits from most significant to least significant
		}
	}
	//  Description: Prints the binary representation of an integer passed as a pointer
	//  Example parameters: int* num (point to the integer to convert)
	//  Return type: void
	//  Bitset is NOT allowed in this function
	//  This function must print all 32 bits of the passed integer

	static void BubbleSort(int* arr, int size)
	{
		for (int i = 0; i < size - 1; i++) /// iterates through each position in the array, ititiating a second for loop to iterate through the array from that position, moving right after the inner loop completes
		{
			for (int j = 0; j < size - i - 1; j++) /// interates through each position in the array for each interation of i until the next element is larger than the current element, returning to move to the next position in the array and start again
			{
				if (arr[j] > arr[j + 1]) /// if statement to compare the value of the index with the value of the element that comes next in the array, completeing the code if the index is greater of the two
				{
					std::swap(arr[j], arr[j + 1]); /// switch the position (values) of the two elements if the index is greater than the element that follows in the array
				}
			}
		}
	}
	//  Description : Implements the bubble sort algorithm to sort an array of integers.
	//  It should take an array and its size as parameters and sort the array in ascending order.
	//  Example parameters : int* arr, int size(pointer to the array and its size).
	//  Return type: void

	static void ClearInputBuffer()
	{
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
	}
	//   Description: Clears any residual input from the buffer that may have been left over from previous cin operations, ensuring no invalid data is left to affect future user input.
	//   Example parameters : None required.
	//   Return type : void

	static void ClearConsoleWindow()
	{
		system("cls");
	}
	//   Description : Clears the entire console window to provide a clean slate for the user interface.This can be used when the program needs to reset its output or prompt the user for new input without clutter.
	//   Example parameters : None required.

	static void PauseConsoleWindow(bool silent = false)
	{
		ClearInputBuffer();
		if (!silent) std::cout << "Press ENTER to continue..."; /// "Press ENTER to continue..."
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); /// ignore all input other than ENTER, completing the function and returning to main when ENTER is pressed
	}
	//   Description : Pauses the execution of the program, preventing it from continuing until the user presses the "Enter" key.It is commonly used to allow users to read output or messages before closing the console.
	//   Example parameters : None required.
	//   Return type : void

	static bool isPositiveInteger(char* input)
	{
		int convertedInt; /// creating unititialized variable int
		sscanf_s(input, "%d", &convertedInt); /// converting the value passed by pointer into an int
		bool isPosInt = false; /// initializing bool IsPosInt as false
		if (sscanf_s(input, "%d", &convertedInt) > NULL && *input != '\n') /// if statement to check if something has been entered by the user and that the input was converted to an int that is more than 0
		{
			printf("\nValid integer followed by ENTER key.\n"); /// print the result of the validation check of the user successfully entering an int value and pressing ENTER
			printf("User input: %d", convertedInt); /// print the user input value converted successfully to an int value of convertedInt
			
			if (convertedInt > 0) /// if statement to check if value of int convertedInt is more than 0, so positive
			{
				isPosInt = true; /// set bool to true
			}
		}
		else
		{
			printf("\nUser entry not valid integer.\n"); /// output error message to the user that a valid integer was not entered
			isPosInt = false; /// set bool to false
		}
		return isPosInt; /// return bool result
	}
	//   Description : Validates that the parameter is a positive integer.If the input is not a valid positive integer(0 should be rejected as well), it will return false.
	//   Example parameters : char\ * input(a pointer to the char \[\] value).
	//   Return type : bool(true if valid, false if invalid)
	//   Good Test case is to use user input to use this as a validation.

	static int RandomNumberGenerator(int min, int max)
	{
		int randomInt = rand() % (max + 1); /// assign a random value between the min and max values, default is 1-100, to the int variable randomInt
		return randomInt; /// return result
	}
	//  Description: Generates a random number within a given range, with a default range specified by the method.
	//	It can optionally allow for the specification of different ranges for flexibility.
	//  Example parameters : int min = 1, int max = 100 (the min and max values for the random number).
	//  Return type : int(the generated random number)

	// PrintIntegerHex
	//  Description : Prints the hexadecimal representation of an integer passed as a pointer.
	//  Example parameters : int\ * num(pointer to the integer to convert).
	//  Return type : void

	// PrintIntegerOct
	//  Description : Prints the octal representation of an integer passed as a pointer.
	//  Example parameters : int\ * num(pointer to the integer to convert).
	//  Return type : void

	// UserInputBool
	//  Description : Prompts the user to input a boolean value(true or false).The method should handle invalid inputs(such as non - boolean values) and ensure a valid boolean is returned.
	//  Example parameters : bool\ * input(pointer to the boolean variable to store the input).
	//  Return type : void

	static void IntegerSwap(int* a, int* b)
	{
		printf("Before: a: %d b: %d \n", *a, *b); /// print the starting values of the int variables
		int tempInt = *b; /// assign the value on int b to int tempInt
		b = a; /// assign the value of int a to int b
		a = &tempInt; /// assign the value of tempInt (original value of int b) to int a
		printf("\nAfter: a: %d b: %d \n", *a, *b); /// print the new values of the int variables
	}
	//  Description : Swaps two integer values.The method should take the integers by reference so that their values are swapped in place.
	//  Example parameters : int\ * a, int\* b(pointers to the integers to swap).
	//  Return type : void

	static bool IsEven(int* num)
	{
		bool isEven = false; /// set bool to false
		if (*num % 2 == 0) isEven = true; /// if statement checking if the number is divisable by two with no remainder, making it even, sets bool to true
		return isEven; /// return bool result
	}
	//  Description : Checks if the number passed in is even.The method should return a boolean(true if the number is even, false otherwise).
	//  Example parameters : int\ * num(pointer to the integer to check).
	//  Return type : bool(true if even, false if not)

	// GetMaxValue
	//  Description : Compares two integers and returns the larger value.The method should dereference the two integer pointers to access the values they point to and return the maximum of the two.
	//  Example parameters : int\ * num1, int\* num2(pointers to the integers).
	//  Return type : int(the maximum value)

	// GetMinValue
	//  Description : Compares two integers and returns the smaller value.Similar to GetMaxValue, but returns the minimum of the two values.
	//  Example parameters : int\ * num1, int\* num2(pointers to the integers).
	//  Return type : int(the minimum value)

	// ClampInteger
	//  Description : Clamps a given integer between a specified minimum and maximum value.If the integer is less than the minimum, it is set to the minimum.If it's greater than the maximum, it is set to the maximum.
	//  Example parameters : int\ * value, int min, int max(pointer to the value, and the min and max range).
	//  Return type : void

	static bool IsPrime(int num)
	{
		int i = 3; /// initiating an int i with a value of 3, as prime numbers are odd, this will be the start of my interator once I complete the conditions checks for the exceptions, incrementing by 2 to only check odd numbers and reduce the amount of loops to complete to check the int value against the conditions
		bool isPrime = true; /// the default value will be true, that the number is prime
		if (num < 2) /// if statement to exclude all negative values, 0, and 1 as not being prime
		{
			isPrime = false; /// set bool to false for the exceptions
		}
		else if (num == 2) /// else if to include 2 as a special case for true, is the only even prime number (making it a special case allows me to check the rest in my loop condition without overly complicating the interation. And it is proper practice to set the strictest conditions first when using a if, else if, else statement)
		{
			isPrime = true; /// set bool to true (it is already) for the special case inclusion of 2
		}
		else if (num >= i) /// evaluating all remaining values
		{
			for (i; i <= (int)sqrt(num); i += 2) /// setting the limit to the square root of my number as it is not possible to have a factor greater than this without a factor lower than this
				/// also setting the interval to skip all positive values to remove redundancy evaluations as I will exclude all positive numbers first
			{
				if (num % 2 == 0) /// excluding all positive values for number
				{
					isPrime = false;  /// set bool value to false for all even numbers
				}
				else if (num % i == 0) /// checking for any factors of the number up to the sqrt(number) and removing any values that are divisible by those factors
				{
					isPrime = false; /// setting bool to false for all odd numbers that can be divided by numbers other than just themselves and 1
				}
			}

		}
		return isPrime; /// return bool result
	}
	//  Description : Checks if the number passed in is a prime number.The method should return a boolean value(true if the number is prime, false otherwise).
	//  Example parameters : int num(the integer to check).
	//  Return type : bool(true if prime, false otherwise)

	// UserInputChar
	//  Description : Prompts the user to input a single character.The method should validate the input to ensure only a single character is entered.
	//  Example parameters : char\ * input(pointer to the character to store the input).
	//  Return type : void

	static bool ValidateRange(int value, int min, int max)
	{
		bool isInRange = false; /// set bool to false
		if (value >= min && value <= max) isInRange = true; /// if statement to check if int value is in the range of min-max, set bool to true
		return isInRange; /// return bool result
	}
	//  Description : Verifies that a given value lies within a specified range(inclusive).If the value is out of range, it should either prompt the user again or return an error message.
	//  Example parameters : int value, int min, int max(the value to check, and the min and max range).
	//  Return type : bool(true if within range, false if out of range)

	static int SafeDivide(int numerator, int denominator)
	{
		if (denominator == 0) return 0;
		int dividedInt = numerator / denominator;
		return dividedInt;
	}
	//  Description : Divides two numbers, but checks if the denominator is zero before performing the division.If the denominator is zero, it returns 0 to avoid division by zero errors.
	//  Example parameters : int numerator, int denominator(the numbers to divide).
	//  Return type : int(the result of the division, or 0 if denominator is zero)

	// VectorSum
	//  Description : Computes the sum of all elements in a vector and returns the total sum.
	//  Example parameters : std::vector\ * vec(pointer to the vector of integers).
	//  Return type : int(the sum of the vector elements)

}

