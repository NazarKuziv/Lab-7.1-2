// Lab_7_1-2.cpp
// < Кузів Назар >
// Лабораторна робота № 7.1-2
// Впорядкування рядків / стовпчиків матриці.
// Варіант 6

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Change(int** R, const int row1, const int row2, const int colCount);

void Create(int** R, const int rowCount, const int colCount,
	const int Low, const int High, int i, int j)
{
	R[i][j] = Low + rand() % (High - Low + 1);

	if (j < colCount - 1)
		Create(R, rowCount, colCount, Low, High, i, j + 1);
	else
		if (i < rowCount - 1)
			Create(R, rowCount, colCount, Low, High, i + 1, 0);
}

void Print(int** R, const int rowCount, const int colCount, int i, int j)
{
	cout << setw(4) << R[i][j];
	if (j < colCount - 1)
		Print(R, rowCount, colCount, i, j + 1);
	else
		if (i < rowCount - 1)
		{
			cout << endl;
			Print(R, rowCount, colCount, i + 1, 0);
		}
		else
			cout << endl << endl;
}
void Sort(int** R, const int rowCount, const int colCount)
{
	for (int i0 = 0; i0 < rowCount - 1; i0++)
		for (int i1 = 0; i1 < rowCount - i0 - 1; i1++)
			if ((R[i1][0] < R[i1 + 1][0])
				||
				(R[i1][0] == R[i1 + 1][0] &&
					R[i1][1] > R[i1 + 1][1])
				||
				(R[i1][0] == R[i1 + 1][0] &&
					R[i1][1] == R[i1 + 1][1] &&
					R[i1][3] < R[i1 + 1][3]))
				Change(R, i1, i1 + 1, colCount);
}

void Change(int** R, const int row1, const int row2, const int colCount)
{
	int tmp =0 ;
	for (int j = 0; j < colCount; j++)
	{
		tmp = R[row1][j];
		R[row1][j] = R[row2][j];
		R[row2][j] = tmp;
	}
}
int main()
{
	srand((unsigned)time(NULL));

	//Діапазон значень елементів матриці
	int Low = 16;
	int High = 97;

	int rowCount = 8; // Кількість рядків
	int colCount = 6; // Кількість стовпців

	int** R = new int* [rowCount];

	for (int i = 0; i < rowCount; i++)
		R[i] = new int[colCount];

	Create(R, rowCount, colCount, Low, High, 0, 0);
	cout << endl;
	Print(R, rowCount, colCount, 0, 0);

	Sort(R, rowCount, colCount);
	cout << endl;
	Print(R, rowCount, colCount, 0, 0);

	for (int i = 0; i < rowCount; i++)
		delete[] R[i];
	delete[] R;

	return 0;
}