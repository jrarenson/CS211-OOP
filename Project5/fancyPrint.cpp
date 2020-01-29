#include <iostream>
#include<cstdlib>
#include <cmath>
using namespace std;

bool ok(int q[], int col){
    for (int i = 0; i < col; i++)
        if ((q[col] == q[i]) || ((col-i) == abs(q[col] - q[i]))) return false;
    return true;
}

void print(int q[]){
    static int count = 0;
    int i,j,k,l;
    cout<<" "<<endl;
    cout <<"Solution #: " <<  ++count << endl << endl;
    
    typedef char box[5][7];
    box bb,wb,bq,wq,*board[8][8];
    
    for (i=0; i<5;i++)
        for (j=0; j<7; j++){
            wb[i][j]=' ';
            bb[i][j]=char(219);
        }
   
    for (i=0; i<5; i++)
        for(j=0; j<7; j++){
            wb[i][j]=' ';
            bb[i][j]=char(219);
        }

    for (j = 0; j < 7; j++){
        wq[0][j]=char(219);
    }for (i=0; i<5; i++){
        wq[i][6]=char(219);
    }for (i=0; i<5; i++){
        wq[i][0]=char(219);
    }for (j=0; j<7; j++){
        wq[4][j]=char(219);
    }for (i = 1; i < 4; i++){
        for (j = 1; j < 6; j++){
            wq[i][j]=' ';
        }
    }

    wq[1][2]=char(219);
    wq[1][4]=char(219);
    
    for (j=0; j<7; j++){
        bq[0][j]=' ';
    }for (i=0; i<5; i++){
        bq[i][6]= ' ';
    }for (i=0; i<5; i++){
        bq[i][0]=' ';
    }for (j=0; j<7; j++){
        bq[4][j]=' ';
    }
    for (i=1; i<4; i++){
        for (j=1; j<6; j++){
            bq[i][j]=char(219);
        }
    }

    bq[1][2]=' ';
    bq[1][4]=' ';
    
    for (i=0; i<8;i++)
        for (j=0; j<8; j++)
            if ((i + j)%2 == 0){
                if (q[i]== j){
                    board[i][j] = &bq;
                }else {
                    board[i][j]==&wb;
                }
            }else {
                if (q[i] == j){
                    board[i][j] = &wq;
                }else {
                    board[i][j] = &bb;
                }
            }
    
    cout << " ";
    for(i=0; i<7*8; i++)
        cout << '_';
    cout << endl;
   
    
    for (i=0; i<8; i++)
        for (k=0; k<5;k++){
            cout <<" "<< char(179); 
            for (j=0; j< 8;j++)
                for (l=0; l<7; l++)
                    cout << (*board[i][j])[k][l];
            cout << char(179)<<endl; 
        }
   
    cout << " ";
    for (i = 0;i < 7 * 8;i++)
        cout << char(196);
    cout << endl;
}

int main(){
    int q[8];
    int c = 0;
    
    bool next_col=true;
    
    while (c >= 0){
        if (next_col){ 
            q[c] = 0;
            next_col = false; 
        }
        else q[c]++; 
        
        if (q[c] >= 8){ 
            c--;
            continue;
        }
        
        if (ok(q,c)){ 
            if (c == 7) 
                print(q);
            else {
                c++; 
                next_col = true;
            }
        }
    }

    return 0;
}
