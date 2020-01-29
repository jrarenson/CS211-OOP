#include<iostream>
#include<cmath>
using namespace std;

    bool ok(int q[], int c){
        for(int i=0; i<c; i++){
            if ((q[i]==q[c]) || (c-i==abs(q[c]-q[i]))) return false;
        }
        return true;
    }

    void print(int q[], int c){
        int i,j,k,l;
        typedef char box[5][7];
        box bb,wb,bq,wq,*board[8][8];

        for(i=0;i<5;i++){
            for( j=0;j<7;j++){
                wb[i][j]=' ';
                bb[i][j]=char(219);
                if(i==2 && j==3) wq[i][j]=char(81);
                else if((i>=1 && i<=3)&&(j>=2 && j<=4)) wq[i][j]=char(176);
                else wq[i][j]=' ';
                if(i==2 && j==3) bq[i][j]=char(81);
                else if((i>=1 && i<=3)&&(j>=2 && j<=4)) bq[i][j]=char(176);
                else bq[i][j]=char(219);
            }
        }

        for(i=0;i<8;i++){
            for(j=0;j<8;j++){
                if((i+j)%2==0){
                    if(((i+j)%2==0) && (q[j]==i)) board[i][j]=&wq;
                    else board[i][j]=&wb;
                }
                else{
                    if(q[j]==i) board[i][j]=&bq;
                    else board[i][j]=&bb;
                }
            }
        }
        cout <<endl;
        cout << "Solution # " << c <<endl;
        cout<<"  ";
        for(i=0;i<7*8;i++){
            cout<<'_';
        }
        cout<<endl;

        for(i=0;i<8;i++){
            for(k=0;k<5;k++){
                cout<<" "<<char(179);
                for(j=0;j<8;j++){
                    for(l=0;l<7;l++){
                    cout<<(*board[i][j])[k][l];
                    }
                }
                cout<<char(179)<<endl;
            }
        }

        cout<<"  ";
        for(i=0;i<7*8;i++){
            cout<<char(196);
        }
        cout<<endl;
        cout << endl;
    }

    int main(){
        int q[8]={0};
        int index=0;
        int c=0;
        while(c>=0){
            q[c]=0;
            while(!ok(q, c)){
                q[c]++;
                if(q[c]>7){
                    q[c]=0;
                    c--;
                    if(q[c]==7){
                        q[c]=0;
                        c--;
                    }
                    q[c]++;
                }
            }
            if(c==-1) {
                exit(0);
            }
            c++;
            if(c==8) {
                print(q,++index);
            }
        }
        system("PAUSE");
        return 0;
}
