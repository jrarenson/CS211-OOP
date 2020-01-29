#include <iostream>
using namespace std;

int main(){
	int b[8][8] = {0},r,c,i,j;
	int cntr = 0;
	b[0][0] = 1;
	c = 0;
next_col:
	c++;
	if (c==8)
	{
	cntr++;
	goto print;
	}
	r = -1;
next_row:

	r++;
	if (r==8) goto back_track;

	for (i=0;i<c;i++)
	{
	if (b[r][i] == 1) goto next_row;
	}

	for(i=1; (r-i>=0) && (c-i>=0); i++)
	if (b[r-i][c-i] == 1)
	goto next_row;

	for (i=1; (r+i<8) && (c-i>=0); i++)
	if (b[r+i][c-i] == 1)
	goto next_row;
	b[r][c] =1;
	goto next_col;
back_track:
	c--;
	if (c== -1) exit(0);
	r = 0;
	while (b[r][c] == 0) r++;
	b[r][c] = 0;
	goto next_row;
print:
	cout << "\nSolution# " << cntr << endl;
	for ( i = 0; i <8; i++)
	{
	for (j=0; j<8; j++)
	cout << b[i][j] << " ";
	cout << endl;
	}
	goto back_track;

return 0;
}