#include<iostream>
#include<array>
#include<stdexcept>
#include"pa1.h"
//Since I coded this project in Visual Studio, I might not have #include<stdfix.h>.
using namespace std;

int main() {
	int n = 0;
	cout << "Enter an odd number that is larger than 2 and smaller than 15:";

	do {

		cin >> n;
		//exception handling for when user enters even number and other unexpected input
		if ((n < 3) || (n % 2 == 0) || (n > 15)) {
			cout << "Be serious." << endl;
			cin.clear();
			cin.ignore(1024, '\n');
			n = 1;
		}

	} while ((n < 3) || (n % 2 == 0) || (n > 15));

	int** matrix;
	matrix = new int*[n];
	//allocates memory for each of of 2D array
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[n];
	}

	if (n == 3)
		TbtMagicSquare(matrix, n);
	else
		NormalMagicSquare(matrix, n);

	delete matrix;
	system("pause");
	return 0;
}

void MagicSquare(int **matrix, int n) {//This magic square only makes sure that the sum of each row and each collumn is the same
	int dms = n * n;                   //But the sum of the two diagonals is not guarranteed.
	int x = n / 2;
	int	y = 0;     //Matrix construction starts here

	for (int k = 1; k <= dms; ++k) {
		matrix[x][y] = k;

		x++;
		y--;//The numbers are filled in in the derection of bottomleft


		if (k % n != 0) { //This helps switch sides
			if (x == n)
				x -= n;
			if (y < 0)
				y += n;
		}
		else { //Immediate adjustments every n numbers are filled in
			x -= 1;
			y += 2;
			if (x < 0) {
				x += n;
			}
		}
	}
}
void MagicSquare2(int **matrix, int n) {//This function is only for 3+ order matrices
	int dms = n * n;                   //But the sum of the two diagonals is not guarranteed.
	int x = n - 1;
	int	y = n - 1;     //Matrix construction starts here

	for (int k = 1; k <= dms; ++k) {
		matrix[x][y] = k;

		x++;
		y--;//The numbers are filled in in the derection of bottomleft


		if (k % n != 0) { //This helps switch sides
			if (x == n)
				x -= n;
			if (y < 0)
				y += n;
		}
		else { //Immediate adjustments every n numbers are filled in
			x -= 1;
			y += 2;
			if (x < 0) {
				x += n;
			}
			if (y == n) {
				y -= n;
			}
		}
	}
}

void TbtMagicSquare(int **matrix, int n) {
	int counter = 1; //Counts how many times this function has run
	MagicSquare(matrix, n);//Constructs the matrix
	while (counter < 5) {

		cout << "Magic square #" << counter << " is: " << endl;
		cout << endl;

		PrintMagicSquare(matrix, n);
		cout << endl;

		CheckPerfection(matrix, n);

		counter++;

		cout << endl;
		Rotate90(matrix, n);
	}
	SwapMagicSquare2(matrix, n);//Switches the columns
	while (counter < 9) {
		cout << "Magic square #" << counter << " is: " << endl;
		cout << endl;

		PrintMagicSquare(matrix, n);
		cout << endl;

		CheckPerfection(matrix, n);

		counter++;

		cout << endl;
		Rotate90(matrix, n);
	}
	//rotates it 8 times

}

void NormalMagicSquare(int **matrix, int n) {
	int counter = 1; //Counts how many times this function has run
	MagicSquare(matrix, n);//Constructs the matrix
	while (counter < 5) {

		cout << "Magic squre #" << counter << " is: " << endl;
		cout << endl;

		PrintMagicSquare(matrix, n);
		cout << endl;

		CheckPerfection(matrix, n);

		counter++;

		cout << endl;
		Rotate90(matrix, n);
	}
	SwapMagicSquare2(matrix, n);//Switches the columns
	while (counter < 9) {
		cout << "Magic square #" << counter << " is: " << endl;
		cout << endl;

		PrintMagicSquare(matrix, n);
		cout << endl;

		CheckPerfection(matrix, n);

		counter++;

		cout << endl;
		Rotate90(matrix, n);
	}
	//rotates it 8 times
	//Since in other cases we need to construct the matrices 10 times, below is the function

	cout << "Magic Square #9 is:" << endl;
	cout << endl;
	SwapMagicSquare3(matrix, n);
	PrintMagicSquare(matrix, n);
	cout << endl;
	CheckPerfection(matrix, n);
	cout << endl;

	cout << "Magic square #10 is: " << endl;
	cout << endl;
	Rotate90(matrix, n);
	PrintMagicSquare(matrix, n);
	cout << endl;
	CheckPerfection(matrix, n);
	cout << endl;
}

void CheckPerfection(int **matrix, int n) {
	int sum = 0;
	int tempsum = 0;
	for (int a = 0; a < n; a++) {
		sum += matrix[a][0];
	}
	cout << "Checking the sums of every column:   ";
	for (int a = 0; a < n; a++) {
		for (int b = 0; b < n; b++) {
			tempsum += matrix[b][a];
		}
		if (tempsum != sum) {
			cout << "落下面玩跑步";
			return;
		}
		cout << tempsum << " ";
		tempsum = 0;
	}
	cout << endl;
	cout << "Checking the sums of every row:      ";
	for (int a = 0; a < n; a++) {
		for (int b = 0; b < n; b++) {
			tempsum += matrix[a][b];
		}
		if (tempsum != sum) {
			cout << "玩够一百下";
			return;
		}
		cout << tempsum << " ";
		tempsum = 0;
	}
	cout << endl;
	cout << "Checking the sums of every diagnoal: ";
	for (int b = 0; b < n; b++) {
		tempsum += matrix[b][b];
	}
	if (tempsum != sum) {
		cout << "点解昨日唔返工啊";
		return;
	}

	cout << tempsum << " ";
	tempsum = 0;
	for (int b = 0; b < n; b++) {
		tempsum += matrix[n - b - 1][n - b - 1];
	}
	if (tempsum != sum) {
		cout << "报告非凡哥警员有权请事假嘅";
		return;
	}
	cout << tempsum << " ";
	cout << endl;

}

void Rotate90(int **matrix, int n) {
	int X = 0;
	for (int r = 0; r < n; r++) {//This is the transpose part 
		for (int c = 0; c < n - r; c++) {
			X = matrix[n - r - 1][c];
			matrix[n - r - 1][c] = matrix[c][n - r - 1];
			matrix[c][n - r - 1] = X;
		}
	}
	SwapMagicSquare(matrix, n);//Invert on row side
}


void SwapMagicSquare(int **matrix, int n) {//Swaps rows
	int X = 0;
	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < n; j++) {
			X = matrix[i][j];
			matrix[i][j] = matrix[n - 1 - i][j];
			matrix[n - 1 - i][j] = X;
		}
	}
}

void SwapMagicSquare2(int **matrix, int n) {//Swaps columns
	int  X = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n / 2; j++) {
			X = matrix[i][j];
			matrix[i][j] = matrix[i][n - 1 - j];
			matrix[i][n - 1 - j] = X;
		}
	}
}

void SwapMagicSquare3(int **matrix, int n) {//Swaps the first column and the last column
	for (int i = 0; i < n; i++) {
		int X = matrix[i][0];
		matrix[i][0] = matrix[i][n - 1];
		matrix[i][n - 1] = X;
	}
}

void PrintMagicSquare(int **matrix, int n) {

	for (int a = 0; a < n; a++) {
		for (int b = 0; b < n; b++) {
			cout << matrix[a][b] << " ";
		}
		cout << endl;

	}
}