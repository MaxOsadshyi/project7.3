#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
int SumRowsWithoutNegatives(int** a, const int rowCount, const int colCount);
int MinDiagonalSums(int** a, const int rowCount, const int colCount);

int main() {
    srand((unsigned)time(NULL));
    int Low = -17;
    int High = 15;
    int rowCount, colCount;
    cout << "rowCount = "; cin >> rowCount;
    colCount = rowCount;
    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    Create(a, rowCount, colCount, Low, High);
    Print(a, rowCount, colCount);

    int sumWithoutNegatives = SumRowsWithoutNegatives(a, rowCount, colCount);
    cout << "Sum of rows without negatives: " << sumWithoutNegatives << endl;

    int minDiagonalSums = MinDiagonalSums(a, rowCount, colCount);
    cout << "Minimum sum of parallel diagonal elements: " << minDiagonalSums << endl;

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High) {
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            a[i][j] = Low + rand() % (High - Low + 1);
        }
    }
}

void Print(int** a, const int rowCount, const int colCount) {
    cout << endl;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            cout << setw(4) << a[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

int SumRowsWithoutNegatives(int** a, const int rowCount, const int colCount) {
    int sum = 0;
    for (int i = 0; i < rowCount; i++) {
        bool hasNegative = false;
        for (int j = 0; j < colCount; j++) {
            if (a[i][j] < 0) {
                hasNegative = true;
                break;
            }
        }
        if (!hasNegative) {
            for (int j = 0; j < colCount; j++) {
                sum += a[i][j];
            }
        }
    }
    return sum;
}

int MinDiagonalSums(int** a, const int rowCount, const int colCount) {
    int minSum=INT_MAX;
    for (int i = 1; i < rowCount; i++) {
        int sum = 0;
        for (int j = 0; j < colCount && i + j < rowCount; j++) {
            sum += a[i + j][j];
        }
        if (sum < minSum) {
            minSum = sum;
        }
    }
    for (int j = 1; j < colCount; j++) {
        int sum = 0;
        for (int i = 0; i < rowCount && i + j < colCount; i++) {
            sum += a[i][i + j];
        }
        if (sum < minSum) {
            minSum = sum;
        }
    }
    return minSum;
}
