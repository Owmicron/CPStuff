#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,m,ans;
int f[40];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int temp;
            cin>>temp;
            f[temp]++;
        }
    }
    for(int i=1;i<=m;i++){
        if(f[i]==n){ans++;}
    }
    cout<<ans<<endl;
}
