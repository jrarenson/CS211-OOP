#include <iostream>
#include <vector>

using namespace std;

void move(int n, int from, int to){
    
    static int move=0;
    vector <int> t[3]; 
    
    for (int i=n+1; i>=1; i--)
        t[0].push_back(i);
    
    t[1].push_back(n+1);
    t[2].push_back(n+1);
    
    int candidate=t[from].back();
    
    if (n%2==1){
        
        while (t[1].size() < n+1){
            cout <<++move <<") Transfer ring " <<candidate <<" from tower " <<char(from+65) <<" to tower " <<char(to+65) <<endl;
            
            t[to].push_back(t[from].back());
            t[from].pop_back();
            
            if (t[char(to+1)%3].back()<t[char(to+2)%3].back())
                from=char(to+1)%3;
            else
                from=char(to+2)%3;
            
            candidate=t[from].back();
            
            if (t[char(from)].back()<t[char(from+1)%3].back())
                to=char(from+1)%3;
            else
                to=char(from+2)%3;
        }
    }
    
    if (n%2==0){ 
        
        to=2;
        
        while (t[1].size()<n+1){ 
            cout <<++move <<") Transfer ring " <<candidate <<" from tower " <<char(from+65) <<" to tower " <<char(to+65) <<endl;
            
            t[to].push_back(t[from].back());
            t[from].pop_back();
            
            
            if (t[char(to+2)%3].back()<t[char(to+1)%3].back())
                from=char(to+2)%3;
            else
                from=char(to+1)%3;
            
            if (t[char(from+2)%3].back()<t[char(from)].back())
                to=char(from+1)%3;
            else
                to=char(from+2)%3;
            
            candidate=t[from].back();
        }
    }
}

int main(){
    
    int n;
    cout <<"Please enter an ODD number of rings to move: ";
    cin >>n;
    
    move(n, 0, 1);
    
    return 0;
 
}

