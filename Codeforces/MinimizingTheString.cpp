#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,ans;str s;
char c;
int main(){
    cin>>n;
    cin>>s;
    ans=-1;
    for(ll i=0;i<s.size()-1;i++){
        if(s[i+1]<s[i]){ans=i;break;}
    }
    if(ans>-1){s.replace(ans,1,"");}
    else{
        ans=1;c='a';
        for(ll i=0;i<s.size();i++){
            if(s[i]>c){ans=i;c=s[i];}
        }
        s.replace(ans,1,"");
    }
    cout<<s<<endl;
}
