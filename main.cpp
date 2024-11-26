#include <iostream>
#include <iomanip>

using namespace std;

float Minor(int matrix[3][3], int line, int column) // Функція обчислення мінора.
{
	int detMinor[2][2];
	int det = NULL;
	int detApplication = 1;
	int i = 0, j, jNum = 0;

	for (int l = 0; l < 2; l++) // Викреслення рядків.
	{
		if (i != line)
		{
			for (int c = 0; c < 2; c++)
			{
				for (j = jNum; j < 3; j++)
				{
					if (j != column)
					{
						detMinor[l][c] = matrix[i][j];
						jNum++;
						break;
					}
					else jNum++;
				}
			}
		}
		else l--;

		jNum = 0;
		i++;
	}

	// Обчислення детермінанту другого порядка.
	for (i = 0, j = 0; i < 2; i++, j++)
	{
		detApplication *= detMinor[i][j];
	}
	det += detApplication;
	detApplication = 1;
	for (i = 0, j = 1; i < 2; i++, j--)
	{
		detApplication *= detMinor[i][j];
	}
	det -= detApplication;

	if ((line + column) % 2 != 0) det *= -1;

	return det;
}

static void InverseMatrix()
{
	int i = 0;
	int j = 0;
	int l;

	const int height = 3;
	const int width = 3;
	int matrix[width][height];
	float matrixA[width][height];

	int det = NULL;
	int detApplication = 1;


	cout << "Введіть елементи матриці третього порядку: " << endl;
	for (i = 0; i < width; i++)
	{
		for (j = 0; j < height; j++)
		{
			cin >> matrix[i][j];
		}
	}
	cout << endl;

	// Обчислення детермінанта третього порядку.
	for (int l = 0; l < 3; l++)
	{
		for (i = 0, j = l; i < 3; i++, j++)
		{
			detApplication *= matrix[i][j];
			if (j == 2) j -= 3;
		}
		det += detApplication;
		detApplication = 1;
	}

	for (int l = 0; l < 3; l++)
	{
		for (i = 0, j = l; i < 3; i++, j--)
		{
			detApplication *= matrix[i][j];
			if (j == 0) j += 3;
		}
		det -= detApplication;
		detApplication = 1;
	}

	if (det == 0)
	{
		  cout << "розв'зку не існує";
	}
	else
	{
		for (i = 0; i < width; i++) // Вираховування матриці А.
		{
			for (j = 0; j < height; j++)
			{
				matrixA[j][i] = Minor(matrix, i, j) / det;
			}
		}

		cout << "обернена матриця:" << endl;

		for (i = 0; i < width; i++)
		{
			for (j = 0; j < height; j++)
			{
				if (matrixA[i][j] == (int)matrixA[i][j])
				{
					cout << fixed << setprecision(0) << matrixA[i][j] << " ";
				}
				else
				{
					cout << fixed << setprecision(2) << matrixA[i][j] << " ";
				}
			}

			cout << endl;
		}
	}
}

int main()
{
	InverseMatrix();

	return 0;
}