#include <iostream>
using namespace std;
class Rat{
private:
    int n;
    int d;
public:
    
    
    Rat(){
        n=0;
        d=1;
    }
    
    Rat(int i, int j){
        n=i;
        d=j;
    }

    Rat(int i){
        n=i;
        d=1;
    }
    
    int getN(){ return n;}
    int getD(){ return d;}
    void setN(int i){ n=i;}
    void setD(int i){ d=i;}
    
    
    Rat operator+(Rat r){
        Rat t;
        t.n=n*r.d+d*r.n;
        t.d=d*r.d;
        return t;
    }
    Rat operator-(Rat r){
        Rat t;
        t.n=n*r.d-d*r.n;
        t.d=d*r.d;
        return t;
    }
    Rat operator*(Rat r){
        Rat t;
        t.n=n*r.n;
        t.d=d*r.d;
        return t;
    }
    Rat operator/(Rat r){
        Rat t;
        t.n=n*r.d;
        t.d=d*r.n;
        return t;
    }
    
    friend ostream& operator<<(ostream& os, Rat r);
    friend istream& operator>>(istream& is, Rat& r);
}; 


ostream& operator<<(ostream& os, Rat r){
    for(int i=2; i<r.d;i++){
        if(r.n%i==0&&r.d%i==0){
            r.n=r.n/i;
            r.d=r.d/i;
        }
    }
    int a;
    if(r.d<r.n){
        a=r.n/r.d;
        r.n=r.n%r.d;
        os<<a<<" "<<r.n<<"/"<<r.d<<endl;
    }
    else os<<r.n<<"/"<<r.d<<endl;
    return os;
}
// operator>>() is NOT a member function but since it was declared a friend of Rat
// it has access to its provate parts.
istream& operator>>(istream& is, Rat& r){
    is>>r.n>>r.d;
    return is;
}
int main(){
    Rat x(1,2), y(2,3), z;
    z=x+y;
    cout<<z;
    
    x.setN(3);
    y.setD(2);
    z=x+y;
    cout<<z;
    cin>>x;
    cout<<x;
    z= x+5;
    cout<<z;
    return 0;
}