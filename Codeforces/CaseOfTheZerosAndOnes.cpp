#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
str s;
ll one,n;
int main(){
    cin>>n;
    cin>>s;
    for(ll i=0;i<s.size();i++){
        if(s[i]=='1'){one++;}
    }
    cout<<s.size()-2*min(one,s.size()-one);

}
