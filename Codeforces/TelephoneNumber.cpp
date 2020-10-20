#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int t,n;
bool eight;
str s;
int main(){
    cin>>t;
    for(int cases=1;cases<=t;cases++){
        cin>>n;
        cin>>s;
        int f = 0;
        eight=false;
        for(int i=0;i<s.size();i++){
            if(s[i]=='8'){eight=true;}
            if(eight){f++;}
        }
        if(f>=11){cout<<"YES\n";}
        else{cout<<"NO\n";}
    }
}
