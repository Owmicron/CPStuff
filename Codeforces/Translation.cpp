#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
str rev(str s){
    str t="";
    for(ll i=s.size()-1;i>=0;i--){
        t+=s[i];
    }
    return t;
}
int main(){
    str s,t;
    cin>>s;
    cin>>t;
    if(t==rev(s)){cout<<"YES";}
    else{cout<<"NO";}

}
