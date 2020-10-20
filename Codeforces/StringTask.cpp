#include<bits/stdc++.h>
using namespace std;
int main()
{
string a;int n;
cin>>a;
for(int i=0;i<=((a.size())-1);i++){
    if(int(a[i])>=65 && int(a[i])<=90){a[i]=char(a[i]+32);}
}
int i;

for(int i=0;i<=a.size()-1;i++){
    if(a[i]=='a' || a[i]=='e' || a[i]=='i' || a[i]=='o' || a[i]=='u' || a[i]=='y'){}
    else{cout<<"."<<a[i];}
}
}

