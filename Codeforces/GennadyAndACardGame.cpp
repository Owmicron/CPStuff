#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
str c,c1,c2,c3,c4,c5;
bool stat=false;
int main(){
    cin>>c;
    cin>>c1;
    if(c1[0]==c[0]){stat=true;}
    else if(c1[1]==c[1]){stat=true;}
    cin>>c2;
    if(c2[0]==c[0]){stat=true;}
    else if(c2[1]==c[1]){stat=true;}
    cin>>c3;
    if(c3[0]==c[0]){stat=true;}
    else if(c3[1]==c[1]){stat=true;}
    cin>>c4;
    if(c4[0]==c[0]){stat=true;}
    else if(c4[1]==c[1]){stat=true;}
    cin>>c5;
    if(c5[0]==c[0]){stat=true;}
    else if(c5[1]==c[1]){stat=true;}
    if(stat){cout<<"YES";}
    else{cout<<"NO";}
}

