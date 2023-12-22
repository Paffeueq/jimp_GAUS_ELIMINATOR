#include "gauss.h"
#include<stdlib.h>
#include<stdio.h>

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *A, Matrix *b){
    /**
  	 * Tutaj należy umieścić właściwą implemntację.
	 */
	int r = A->r; 
	int c = A->c; 
	float* liczbyA;
	float liczbyb;
	liczbyA = (float*)malloc(c*sizeof(float));

	for(int przej = 0; przej < r-1; przej++)
	{
		int max = A->data[przej][przej];
		for(int i = 0 + przej; i < r; i++)
		{
			if( abs(A->data[i][przej]) > max)
			{
				max = i;
			}
		}
		if(max != przej)
		{
			for(int a = 0 + przej; a < c; a ++)
			{
				liczbyA[a] = A->data[max][a];
				A->data[max][a] = A->data[przej][a];
				A->data[przej][a] = liczbyA[a];
				liczbyA[a] = 0;
				liczbyb = b->data[max][0];
			}
			liczbyb = b->data[max][0];
			b->data[max][0] = b->data[przej][0];
			b->data[przej][0] = liczbyb;
			liczbyb = 0;
		}  
		for(int i = 1 + przej; i < r; i++)
		{
			if(A->data[przej][przej] == 0)
			{
				return 1;
			}

			float mnoznik = (A->data[i][przej])/(A->data[przej][przej]);
			b->data[i][0] = (b->data[i][0] - mnoznik*(b->data[przej][0]));
			for(int a = 0 + przej; a < c; a ++)
			{
				A->data[i][a] = (A->data[i][a] - mnoznik*(A->data[przej][a]));
			}
		}
	}
	return 0;
}

