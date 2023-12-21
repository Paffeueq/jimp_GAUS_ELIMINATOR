#include "gauss.h"
int eliminate(Matrix *mat, Matrix *b)
{
    for ( int i = 0; i < mat->r; i++ )
    	//schodkowanie w przypadku gdy element jest nie zerowy
	{
        if ( mat->data[i][i] != 0 ) 
        {
            for ( int x = i + 1; x < mat->r; x++ )
            {
                while ( mat->data[x][i] != 0 )
                {
                    double det = mat->data[i][i] / mat->data[x][i];
                    for (int z = i; z < mat->c; z++)
                    {
                        mat->data[x][z] = mat->data[x][z] - (mat->data[i][z] / det);
                    }
                   b->data[x][0] = b->data[x][0] - (b->data[i][0] / det);

                }
            }
        }
        else 
	// zamiana wiersza miejscami
        {
		double *zmn_x = mat->data[i];
		double *zmn_y = b->data[i];
		int z = i;
        int maxtmp;
        int max = 0;
		while ( z < mat->r )
        {
            if ( mat->data[z][i] > max )
            {
                max = mat->data[z][i];
                maxtmp = z;
            }
            z++;
        }
		mat->data[i] = mat->data[maxtmp];
		b->data[i] = b->data[maxtmp];
		mat->data[maxtmp] = zmn_x;
		b->data[maxtmp] = zmn_y;
		i--;
        }
    }

    return 0;
}
