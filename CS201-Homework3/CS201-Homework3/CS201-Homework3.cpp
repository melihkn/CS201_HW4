#include <iostream>
#include <string.h>
#include <iomanip>
#include <vector>

using namespace std;

int operationInput() {
	int op;
	cout << "Pick a choice from the list:" << endl << "1- Addition Operation" << endl\
		<< "2- Multiplication Operation" << endl << "3- Power Operation" << endl\
		<< "4- Transpose Operation" << endl << "5- Exit" << endl << "Choice:" << endl;
	cin >> op;

	return op;
}

void input2(int& row1, int& col1, int& row2, int& col2) {
	cout << "Please enter the dimensions of the first matrix: ";
	cin >> row1 >> col1;
	cout << "Please enter the dimensions of the second matrix: ";
	cin >> row2 >> col2;
}

void input1(int& row, int& column) {
	cout << "Please enter the dimensions of the matrix: ";
	cin >> row >> column;
}

void printMatrix(const vector<vector<int>>& mat) {
	int i, j;
	int size = mat.size(), col = mat[0].size();
	for (i = 0; i < size; i++) {
		for (j = 0; j < col; j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void fillMatrix(vector<vector<int>>& myMatrix) {
	int row = myMatrix.size(), column = myMatrix[0].size();
	int i, j;

	for (i = 0; i < row; i++) {
		cout << "Enter the numbers for row #" << i + 1 << ": ";
		for (j = 0; j < column; j++) {
			int a;
			cin >> a;
			myMatrix[i][j] = a;
		}
	}
}

void additionMatrix(vector<vector<int>>& myMatrix1, vector<vector<int>>& myMatrix2) {
	
	cout << "The two matrices have the same dimensions. Addition can be performed." << endl << endl;
		
	cout << "Please enter the numbers for the first matrix." << endl;

	fillMatrix(myMatrix1);
	cout << "The first matrix is:" << endl;
	printMatrix(myMatrix1);

	
	cout << "Please enter the numbers for the second matrix." << endl;

	fillMatrix(myMatrix2);
	cout << "The second matrix is:" << endl;
	printMatrix(myMatrix2);

	int row = myMatrix1.size(), column = myMatrix1[0].size();
	int i, j;

	vector<vector<int>> newMatrix(row, vector<int>(column, 0));
	for (i = 0; i < row; i++) {
		for (j = 0; j < column; j++) {
			newMatrix[i][j] += myMatrix1[i][j] + myMatrix2[i][j];
		}
	}

	cout << "Result of the Sum Operation:" << endl;
	printMatrix(newMatrix);
}

void multiplicationMatrix(vector<vector<int>>& myMatrix1, vector<vector<int>>& myMatrix2) {

	cout << "The number of columns in the first matrix is equal to the number of rows in the second matrix. Multiplication can be performed." << endl;

	int i, j, k;
	cout << "Please enter the numbers for the first matrix." << endl;

	fillMatrix(myMatrix1);
	cout << "The first matrix is:" << endl;
	printMatrix(myMatrix1);


	cout << "Please enter the numbers for the second matrix." << endl;

	fillMatrix(myMatrix2);
	cout << "The second matrix is:" << endl;
	printMatrix(myMatrix2);

	int row1 = myMatrix1.size(), column1 = myMatrix1[0].size(), column2 = myMatrix2[0].size();
	int row = myMatrix1.size(), column = myMatrix2[0].size();
	vector<vector<int>> newMatrix(row, vector<int>(column, 0));

	for (i = 0; i < row1; i++) {
		for (j = 0; j < column1; j++) {
			for (k = 0; k < column2; k++) {
				newMatrix[i][k] += myMatrix1[i][j] * myMatrix2[j][k];
			}
		}
	}

	cout << "Result of the Multiplication Operation:" << endl;
	printMatrix(newMatrix);
}

void powerMatrix(vector<vector<int>>& myMatrix) {
	unsigned int power;

	cout << "The matrix has the same number of rows as columns. Power can be performed." << endl << endl;

	cout << "Please enter the numbers for the matrix." << endl;
	fillMatrix(myMatrix);

	cout << "The matrix is:" << endl;
	printMatrix(myMatrix);

	do {
		cout << "Please enter the power: ";
		cin >> power;
	} while (power < 1);
	

	int i, j, k, t;
	int row = myMatrix.size(), column = myMatrix[0].size();
	vector<vector<int>> newMatrix(row, vector<int>(column, 0));
	newMatrix = myMatrix;

	for (t = 0; t < (power - 1); t++) {
		vector<vector<int>> multMat(row, vector<int>(column, 0));
		for (i = 0; i < row; i++) {
			for (j = 0; j < column; j++) {
				for (k = 0; k < column; k++) {
					multMat[i][k] += newMatrix[i][j] * myMatrix[j][k];
				}
				
			}
		}
		newMatrix = multMat;
	}
	cout << "Result of the Power Operation:" << endl;
	printMatrix(newMatrix);
}

void transposeMatrix(vector<vector<int>>& myMatrix) {
	cout << "Please enter the numbers for the matrix." << endl;

	fillMatrix(myMatrix);
	cout << "The matrix is:" << endl;
	printMatrix(myMatrix);

	int row = myMatrix.size(), column = myMatrix[0].size();
	vector<vector<int>> newMatrix(column, vector<int>(row));

	int i, j;
	for (i = 0; i < column; i++) {
		for (j = 0; j < row; j++) {
			newMatrix[i][j] = myMatrix[j][i];
		}
	}

	cout << "Result of the Transpose Operation:" << endl;
	printMatrix(newMatrix);
}

int main() {
	int op;

	do {
		op = operationInput();
		if (op == 1) {
			int row1, col1, row2, col2;
			input2(row1, col1, row2, col2);

			if (row1 != row2 || col1 != col2) {
				cout << "The two matrices do not have the same dimensions. Addition cannot be performed." << endl;
			}
			else {
				vector<vector<int>> myMatrix1(row1, vector<int>(col1, 0));
				vector<vector<int>> myMatrix2(row2, vector<int>(col2, 0));
				additionMatrix(myMatrix1, myMatrix2);
			}
		}
		else if (op == 2) {
			int row1, col1, row2, col2;
			input2(row1, col1, row2, col2);

			if (col1 != row2) {
				cout << "The number of columns in the first matrix must be equal to the number of rows in the second matrix." << endl << "Multiplication cannot be performed." << endl;
			}
			else {
				vector<vector<int>> myMatrix1(row1, vector<int>(col1, 0));
				vector<vector<int>> myMatrix2(row2, vector<int>(col2, 0));
				multiplicationMatrix(myMatrix1, myMatrix2);
			}
		}
		else if (op == 3) {
			int row, column;
			input1(row, column);

			if (row != column) {
				cout << "The matrix does not have the same number of rows as columns. Power cannot be performed." << endl << endl;
			}
			else {
				vector<vector<int>> myMatrix(row, vector<int>(column, 0));
				powerMatrix(myMatrix);
			}
		}
		else if (op == 4) {
			int row, column;
			input1(row, column);
			vector<vector<int>> myMatrix(row, vector<int>(column, 0));
			transposeMatrix(myMatrix);
		}
	} while (op != 5);

	return 0;
}

