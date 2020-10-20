#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n;str s;bool exist[27];
bool existence(char c){
    if(int(c)>=97){exist[int(c)-96]=true;}
    else{exist[int(c)-64]=true;}
}
bool pangram(){
    bool cn=true;
    for(ll i=1;i<=26;i++){
        if(!exist[i]){cn=false;break;}
    }
    return cn;
}
int main(){
    str s;
    cin>>n;
    cin>>s;

    for(ll i=0;i<n;i++){
        existence(s[i]);
    }
    if(pangram()){cout<<"YES";}
    else{cout<<"NO";}
}

