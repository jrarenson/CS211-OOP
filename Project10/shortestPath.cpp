#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

const int rows = 5;
const int cols = 6;

int cost(int i, int j){ 
    int weight[rows][cols]={
        {3,4,1,2,8,6},
        {6,1,8,2,7,4},
        {5,9,3,9,9,5},
        {8,4,1,3,2,6},
        {3,7,2,8,6,4}
    };
    
    //base case
    if(j==0)
        return weight[i][0];
    
    // recursive call
    int w = weight[i][j];
    int left = w + cost(i, j-1);
    int up = w + cost(abs(i-1)%rows, j-1);
    int down = w + cost((i+1)%rows, j-1);  
    
    //find the value of the shortest path through cell (i,j)
    int min = left;
    
    if (up < min)
        min = up;
    
    else if (down < min)
        min = down;
    
    return min;
}

int main(){
    int ex[rows];
    
    // get the shortest path out of each cell on the right
    for(int i=0; i<rows; i++)
        ex[i] = cost(i, cols-1);
    
    // the smallest of them
    int min = ex[0];
    
    for (int i=0; i<rows; i++)
        if (ex[i] < min)
            min = ex[i];
    
    cout <<"The shortest path is of length " << min <<endl;
    
   
    return 0;
}



