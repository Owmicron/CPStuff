#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
str s;
int main(){
    cin>>s;
    if(s=="A"){s="T";}
    else if(s=="C"){s="G";}
    else if(s=="G"){s="C";}
    else if(s=="T"){s="A";}
    cout<<s<<endl;
}
