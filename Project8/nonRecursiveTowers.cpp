#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<int>t[3];
	int n, candidate, to, from, move=0;
	cout<<"Please enter and ODD number of rings to move:";
	cin>>n;
	cout<<endl;

	for(int i=n+1; i>=1; i--)
		t[0].push_back(i);
	t[1].push_back(n+1);
	t[2].push_back(n+1);

	from=0;
	to=1;
	candidate=1;
	
	while(t[1].size()<n+1){
		cout<<"move number "<<++move<<": Transfer ring"<<candidate<<" from tower "<<char(from+65)<<" to tower "<<char(to+65)<<endl;

if(t[char(to+2)%3].back()<t[char(to+1)%3].back())
	from=char(to+2)%3;
else
	from=char(to+1)%3;

if(t[char(from+2)%3].back()<t[char(from)].back())
	to=char(from+1)%3;
else
	to=char(from+2)%3;
	candidate=t[from].back();
	}
}
