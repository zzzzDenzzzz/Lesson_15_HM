#include<iostream>

void createArray(int **array, const int &rows, int &cols)
{
	for (int i = 0; i < rows; i++)
	{
		array[i] = new int[cols];
	}
}

void initArray(int **array, const int &rows, int &cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			array[i][j] = i + j;
		}
	}
}

void printArray(int **array, const int &rows, int &cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << array[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void copy(int &a, int &b)
{
	a = b;
}

void deleteArray(int **array, const int &rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[]array[i];
	}
	delete[]array;
}

int **deleteCol(int **array, const int &rows, int &cols, const int &number_col)
{
	int **array_new = new int *[rows];
	cols--;
	createArray(array_new, rows, cols);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (j < number_col)
			{
				copy(array_new[i][j], array[i][j]);

			}
			else
			{
				copy(array_new[i][j], array[i][j + 1]);
			}
		}
	}

	return array_new;
}

int main()
{
	int rows = 5;
	int **arr = new int *[rows];
	int cols = 5;

	createArray(arr, rows, cols);
	initArray(arr, rows, cols);
	printArray(arr, rows, cols);
	int number_col;
	std::cout << "Enter position: ";
	std::cin >> number_col;
	std::cout << std::endl;
	int **a = deleteCol(arr, rows, cols, number_col);
	printArray(a, rows, cols);

	deleteArray(arr, rows);
	deleteArray(a, rows);

	return 0;
}