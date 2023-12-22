#include "backsubst.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *A, Matrix *b) 
{
	int r = A->r;
	int c = A->c;

	if(A->r != A->c || b->c != 1)
	{
		return 2;
	}

	for(int i = 0; i < A->r; i ++)
	{
		if(A->data[i][i] == 0)
		{
			return 1;
		}
	}
	float ostatni = b->data[r-1][0]/A->data[r-1][c-1];
	x->data[r-1][0] = ostatni;
	for (int i = A->r-2; i >= 0; i--)
	{
		float pom = (1/A->data[i][i]); 
		x->data[i][0] = pom*(b->data[i][0]);
		for(int a = 0; a < (A->c - 1 - i); a++)
		{
			x->data[i][0] = x->data[i][0] - pom*(A->data[i][i+1+a]*(x->data[i+1+a][0])); 
		}
	}
	return 0;
}


