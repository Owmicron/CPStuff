#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
set < pair<int,int> > s;
pair<int,int> ab[200000];
int n,m;
bool rotational (int k){
    if(k==n)return false;
    bool r=true;
    for(int i=1;i<=m;i++){
        int a = ab[i].first;
        int b = ab[i].second;
        a+=k;
        b+=k;
        if(a>n){a%=n; if(a==0)a=n;}
        if(b>n){b%=n; if(b==0)b=n;}

        pair<int,int> temp = make_pair(min(a,b),max(a,b));
        if(!s.count(temp)){r=false;break;}
    }
    return r;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        pair<int,int> temp = make_pair(min(a,b),max(a,b));
        ab[i]=temp;
        s.insert(temp);
    }
    bool ans=false;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            if(rotational(i)){ans=true;break;}
            if(rotational(n/i)){ans=true;break;}
        }
    }
    if(ans){cout<<"Yes\n";}
    else{cout<<"No\n";}
}
