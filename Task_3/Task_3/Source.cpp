#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>

int main()
{
	const int row = 4;
	const int col = 7;

	int **arr = new int *[row];
	for (int i = 0; i < row; i++)
	{
		arr[i] = new int [col];
	}

	srand(time(NULL));
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			arr[i][j] = 0 + rand() % 10;
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}

	SetConsoleOutputCP(1251);

	int numbers_shift;
	while (true)
	{
		std::cout << "Укажите количество сдвигов: ";
		std::cin >> numbers_shift;
		if (numbers_shift > 0)
		{
			std::cin.ignore(32767, '\n');
			std::cout << "OK\n";
			break;
		}
		else if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Что-то пошло не так. Попробуйте еще раз.\n";
		}
		else
		{
			std::cin.ignore(32767, '\n');
			std::cout << "Что-то пошло не так. Попробуйте еще раз.\n";
		}
	}

	char shift;
	while (true)
	{
		std::cout << "Укажите направление сдвига(влево - l, вправо - r, вверх - u, вниз - d): ";
		std::cin >> shift;
		if (shift == 'l' || shift == 'r' || shift == 'u' || shift == 'd')
		{
			std::cin.ignore(32767, '\n');
			std::cout << "OK\n";
			break;
		}
		else if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Что-то пошло не так. Попробуйте еще раз.\n";
		}
		else
		{
			std::cin.ignore(32767, '\n');
			std::cout << "Что-то пошло не так. Попробуйте еще раз.\n";
		}
	}
	std::cout << std::endl;

	std::cout << "Количество сдвигов: " << numbers_shift << '\n';
	switch (shift)
	{
	case 'l':
		std::cout << "Направление сдвига: влево\n";
		if (numbers_shift >= col)
		{
			numbers_shift %= col;
		}
		while (numbers_shift > 0)
		{
			int variable;
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col - 1; j++)
				{
					variable = arr[i][j];
					arr[i][j] = arr[i][j + 1];
					arr[i][j + 1] = variable;
				}
			}
			numbers_shift--;
		}
		break;
	case 'r':
		std::cout << "Направление сдвига: вправо\n";
		if (numbers_shift >= col)
		{
			numbers_shift %= col;
		}
		while (numbers_shift > 0)
		{
			int variable;
			for (int i = 0; i < row; i++)
			{
				for (int j = col - 1; j > 0; j--)
				{
					variable = arr[i][j];
					arr[i][j] = arr[i][j - 1];
					arr[i][j - 1] = variable;
				}
			}
			numbers_shift--;
		}
		break;
	case 'u':
		std::cout << "Направление сдвига: вверх\n";
		if (numbers_shift >= row)
		{
			numbers_shift %= row;
		}
		while (numbers_shift > 0)
		{
			int variable;
			for (int i = 0; i < row - 1; i++)
			{
				for (int j = 0; j < col; j++)
				{
					variable = arr[i][j];
					arr[i][j] = arr[i + 1][j];
					arr[i + 1][j] = variable;
				}
			}
			numbers_shift--;
		}
		break;
	case 'd':
		std::cout << "Направление сдвига: вниз\n";
		if (numbers_shift >= row)
		{
			numbers_shift %= row;
		}
		while (numbers_shift > 0)
		{
			int variable;
			for (int i = row - 1; i > 0; i--)
			{
				for (int j = 0; j < col; j++)
				{
					variable = arr[i][j];
					arr[i][j] = arr[i - 1][j];
					arr[i - 1][j] = variable;
				}
			}
			numbers_shift--;
		}
		break;
	default:
		break;
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}

	for (int i = 0; i < row; i++)
	{
		delete[]arr[i];
	}
	delete[]arr;

	return 0;
}