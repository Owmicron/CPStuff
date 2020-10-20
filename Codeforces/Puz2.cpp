#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
long n,m,f[1001],lit,ans;
bool c;
vector <long>v,w;
int main(){
    cin>>n>>m;
    for(long i=1;i<=m;i++){
        cin>>f[i];
    }

    sort(f+1,f+m+1);

    ans=10000;
    for(long i=n;i<=m;i++){
        lit=(f[i]-f[i-n+1]);
        if(lit<ans){ans=lit;}
    }
    cout<<ans;

}
