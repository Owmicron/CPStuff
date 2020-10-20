#include<bits/stdc++.h>
using namespace std;
int main(){
int n,a,b,c,f,t;
cin>>n;t=0;
for(int i=1;i<=n;i++){
    cin>>a>>b>>c;
    f=0;
    if (a==1){f++;}
    if (b==1){f++;}
    if (c==1){f++;}
    if (f>=2){t++;}

}
cout<<t;

}
