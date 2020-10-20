#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
str s;
int d[30];
ll ans;
ll p (ll a, ll b){
    ll res=1;
    for(int i=1;i<=b;i++)res*=a;
    return res;
}
void compare (int start){
    if(start==0 && d[start]==1){
        ll pro=1;
        pro = p(9,s.size()-1);
        ans = max(ans,pro);
    }
    else{
        ll pro=1;
        for(int i=0;i<s.size();i++){pro*=d[i];}
        ans=max(ans,pro);
        if(d[start]>1){
            pro=1;
            for(int i=0;i<start;i++){pro*=d[i];}
            pro*=d[start]-1;
            pro*=p(9,s.size()-start-1);
            ans=max(ans,pro);
        }
    }

}

int main(){
    cin>>s;
    for(int i=0;i<s.size();i++){
        d[i] = int(s[i])-48;
    }
    //for(int i=0;i<s.size();i++)cout<<d[i];
    ans=d[s.size()-1];
    for(int i=0;i<s.size()-1;i++){
        compare(i);
    }
    cout<<ans<<endl;
}
