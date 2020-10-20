#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
str s;
bool d;
int f[30],n;
int main(){

    cin>>n;

    for(int i=1;i<=n;i++){
    cin>>s;
    sort(s.begin(),s.end());
    d=true;
    for(int i=1;i<s.size();i++){
        int tempa,tempb;
        tempa = int(s[i-1]);
        tempb = int(s[i]);
        if(tempb-tempa==1){}
        else{d=false;break;}

    }
    if(d){cout<<"Yes\n";}
    else{cout<<"No\n";}


    }
}
