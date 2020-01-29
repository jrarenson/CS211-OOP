#include <iostream>
#include <cmath>
using namespace std;

bool ok(int adj_table[], int k);
void next(int adj_table[], int k);
void print(int adj_table[]);

bool ok(int adj_table[], int k){
	static int adj[8][5] = {
		{-1}, 
		{0,-1},
		{0,1,-1}, 
		{0,2,-1}, 
		{1,2,-1}, 
		{1,2,3,4,-1}, 
		{2,3,5,-1}, 
		{4,5,6,-1}};
	
	for(int j = 0; j < k; j++)
		if(adj_table[k] == adj_table[j]) return false;

	for(int i = 0; adj[k][i] != -1; i++){
		if(abs(adj_table[k] - adj_table[adj[k][i]]) == 1)
			return false;
	}
	
	return true;
}

void next(int adj_table[], int k){
	if(k == 8) print(adj_table);
	else
		for(adj_table[k] = 1; adj_table[k] <= 8; adj_table[k]++)
			if(ok(adj_table, k))
				next(adj_table, k+1);
}

void print(int adj_table[]){
	static int answers = 0;
	cout<<"Solution #: "<< ++answers << "\n " << adj_table[1] <<
	adj_table[4] << "\n" << adj_table[0] << adj_table[2] << 
	adj_table[5] << adj_table[7] << "\n " <<adj_table[3] <<
	adj_table[6]<< "\n\n";
}

int main(){
	int a[8];
	next(a, 0);
	return 0;
}
