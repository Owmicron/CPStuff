#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll m,n,a[101][101];
int main(){
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            cin>>a[i][j];

        }
    }

    for(ll i=1;i<=m;i++){
        for(ll j=n;j>=1;j--){
            cout<<a[j][i];
            if(j>1){cout<<" ";}
        }
        cout<<endl;

    }
}

