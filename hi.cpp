#include <iostream>
using namespace std;

void sort_in_rows(int* A, int rows, int cols);
void sort_in_cols(int* A, int rows, int cols);
void sort_in_diags(int* A, int rows, int cols);
void output(const int* A, int rows, int cols);

template <int ROWS, int COLS>
void sort_in_rows(int (&A)[ROWS][COLS]) {
    sort_in_rows(&A[0][0], ROWS, COLS);
}

template <int ROWS, int COLS>
void sort_in_cols(int (&A)[ROWS][COLS]) {
    sort_in_cols(&A[0][0], ROWS, COLS);
}

template <int ROWS, int COLS>
void sort_in_diags(int (&A)[ROWS][COLS]) {
    sort_in_diags(&A[0][0], ROWS, COLS);
}

template <int ROWS, int COLS>
void output(const int (&A)[ROWS][COLS]) {
    output(&A[0][0], ROWS, COLS);
}

int main()
{
    
	const int ROWS = 2;
    const int COLS = 12;

    int A[ROWS][COLS] ;
    
	{for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) 
			A[i][j] = rand() % 41  - 10;
		} 
}
	 
	    cout << "Vipadkoviy massiv" << endl;
    output(A);
    cout << endl;

    cout << "Sortuvannya po stovpcyah" << endl;
    sort_in_cols(A);
    output(A);
    cout << endl;

    cout << "Sortuvannya po strokam" << endl;
    sort_in_rows(A);
    output(A);
    cout << endl;

    cout << "sort_in_diaganal" << endl;
    sort_in_diags(A);
    output(A);
    cout << endl;

    return 0;
}

void ptr_select_sort(int* pp[], int elems) {
    for (int j = 0; j < (elems - 1); ++j) {
        int iMin = j;
        for (int i = (j + 1); i < elems; ++i) {
            if (*pp[i] < *pp[iMin])
                iMin = i;
        }
        if(iMin != j) {
            int tmp = *pp[j];
            *pp[j] = *pp[iMin];
            *pp[iMin] = tmp;
        }
    }
}

void sort_in_rows(int* A, int rows, int cols)
{
    int elems = rows * cols;
    int** pp = new int*[rows * cols];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            pp[i * cols + j] = &A[i * cols + j];
        }
    }
    ptr_select_sort(pp, elems);
    delete [] pp;
}

void sort_in_cols(int* A, int rows, int cols)
{
    int elems = rows * cols;
    int** pp = new int*[rows * cols];
    for (int j = 0; j < cols; ++j) {
        for (int i = 0; i < rows; ++i) {
            pp[i + j * rows] = &A[i * cols + j];
        }
    }
    ptr_select_sort(pp, elems);
    delete [] pp;
}

void sort_in_diags(int* A, int rows, int cols)
{
    int elems = rows * cols;
    int** pp = new int*[rows * cols];
    int k = 0;
    for (int i_start = 0; i_start < (rows + cols - 1); ++i_start) {
        int i = i_start;
        int j_start = 0;
        while(i > (rows - 1)) {
            --i;
            ++j_start;
        }
        for (int j = j_start; (j < cols) && (i >= 0); ++j)
            pp[k++] = &A[i-- * cols + j];
    }
    ptr_select_sort(pp, elems);
    delete [] pp;
}

void output(const int* A, int rows, int cols)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << A[i * cols + j] << " ";
        cout << endl;
    }
}