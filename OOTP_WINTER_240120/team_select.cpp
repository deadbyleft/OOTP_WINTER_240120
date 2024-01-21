/*

#include <iostream>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip> 

using namespace std;


int main()
{
	int map[10][10] = { 0, };
	int value = 0;
	bool pass = true;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			while (1)
			{
				pass = true;
				value = rand() % 10 + 1;

				if (i == j)
				{
					map[i][j] = i + 1;
					break;
				}
					

				else
				{
					for (int k = 0; k < 9; k++)
					{
						if (map[i][k] == value) pass = false;
						if (map[k][j] == value) pass = false;
					}

					if (pass)
					{
						map[i][j] = value;
						map[j][i] = value;
						break;
					}

					
				}

				
				
			}
			

			
		}
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << left << setw(3) << map[i][j] << " ";
		}
		cout << '\n';
	}
		
	

}

*/