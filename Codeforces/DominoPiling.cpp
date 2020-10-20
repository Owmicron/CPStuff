#include<bits/stdc++.h>
using namespace std;
int main(){
int m,n,f;
cin>>m>>n;
f=0;
f+=(m / 2)*n;
if (m % 2 != 0){f+=(n / 2);}
cout<<f;

}
