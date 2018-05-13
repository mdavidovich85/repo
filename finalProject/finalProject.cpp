// finalProject.cpp
// by Mike Davidovich (davidovm@csp.edu) and Brant Sarazin (sarazinb@csp.edu)
// Created Spring Semester 2017
 
#include "stdafx.h"
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	char input[256];

	do
	{
		// START USER INPUT
		cout << "Enter an expression: ";
		cin.getline(input, 256);

		if (input[0] == '\0')
		{
			break;
		}
		// REMOVE SPACES FROM INPUT EQUATION
		int a;
		int b;
		for (a = 0; input[a] != 0; a++)
		{
			if (isspace(input[a]))
			{
				for (b = a; input[b] != 0; b++)
				{
					input[b] = input[b + 1];
				}
			}
		}

		// END USER INPUT

		// START PARSING OPERATORS
		int countOfOps = 0;
		for (int index = 0; index < strlen(input); index++)
		{
			if (input[index] == '+' || input[index] == '-' || input[index] == '*' || input[index] == '/')
				countOfOps++;
		}

		char * ops = new char[countOfOps + 1];

		int opIndex = 0;
		for (int index = 0; index < strlen(input); index++)
		{
			if (input[index] == '+' || input[index] == '-' || input[index] == '*' || input[index] == '/')
			{
				ops[opIndex] = input[index];
				opIndex++;
			}
			ops[countOfOps] = '\0';
		}

		// DEBUG - CHECK OPS ARRAY
		// USE THIS IF YOU WANT TO SEE WHICH OPERATORS ARE IN THE OPS ARRAY
		//cout << "YOUR OPERATORS ARE: " << ops << endl;

		// END PARSING OPERATORS

		// START PARSING TERMS
		double * terms = new double[countOfOps + 1];
		terms[0] = atof(input);

		int termIndex = 1;
		for (int index = 0; index < strlen(input); index++)
		{
			if (input[index] == '+' || input[index] == '-' || input[index] == '*' || input[index] == '/')
			{
				terms[termIndex] = atof(input + index + 1);
				termIndex++;
			}
		}

		// USE THIS WHEN YOU NEED TO LOOP THROUGH THE TERMS ARRAY
		// YOU CAN'T USE SIZE() WITH A DYNAMIC ARRAY
		// COMMENT OUT WHEN DONE
		/*
		cout << "YOUR TERMS ARE: ";
		for (int i = 0; i < countOfOps + 1; i++)
		cout << terms[i] << " ";
		cout << endl << endl;
		*/

		// END PARSING TERMS
		double total;
		int i = 0;

		// DISPLAY THE EQUATION
		cout << endl;
		for (int a = 0; a < countOfOps + 1; a++)
		{
			cout << " " << terms[a] << " " << ops[a];
		}
		int newCount = countOfOps;
		// PERFORM MULTIPLICATION AND DIVISION OPERATIONS FIRST
		do
		{
			if ((ops[i] == '*') || (ops[i] == '/'))
			{
				switch (ops[i])
				{
				case ('*') :
				{
					total = terms[i] * terms[i + 1];
					terms[i] = total;

					// SHIFT ALL TERMS AND OPERATORS ONE POSITION TO THE LEFT
					for (int j = i; j < countOfOps; j++)
					{
						terms[j + 1] = terms[j + 2];
						ops[j] = ops[j + 1];
					}
					break;
				}
				case ('/') :
				{
					total = terms[i] / terms[i + 1];
					terms[i] = total;

					// SHIFT ALL TERMS AND OPERATORS ONE POSITION TO THE LEFT
					for (int j = i; j < countOfOps; j++)
					{
						terms[j + 1] = terms[j + 2];
						ops[j] = ops[j + 1];
					}
					break;
				}

				}
			}
			else
			{
				i++;
			}
		} while (newCount-- > 0);

		int c = 0;
		newCount = countOfOps;

		// PERFORM ANY ADDITION AND SUBTRACTION 
		do
		{
			switch (ops[c])
			{
			case ('+') :
			{
				total = terms[c] + terms[c + 1];
				terms[c] = total;

				// SHIFT ALL TERMS AND OPERATORS ONE POSITION TO THE LEFT
				for (int j = c; j < countOfOps; j++)
				{
					terms[j + 1] = terms[j + 2];
					ops[c] = ops[c + 1];
				}
				break;
			}
			case ('-') :
			{
				total = terms[c] - terms[c + 1];
				terms[c] = total;

				// SHIFT ALL TERMS AND OPERATORS ONE POSITION TO THE LEFT
				for (int j = c; j < countOfOps; j++)
				{
					terms[j + 1] = terms[j + 2];
					ops[c] = ops[c + 1];
				}
				break;
			}
			}
			//cout << "NOW IS: " << newCount << endl;
		} while (newCount-- >= 0);

		// DISPLAY THE TOTAL
		cout << "= " << total << endl << endl;
	} while (!(input[0] == '\0'));

	cout << endl << "BYE!" << endl << endl;
	cin.get();
	return 0;
}