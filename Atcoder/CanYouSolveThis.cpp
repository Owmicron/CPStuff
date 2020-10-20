#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,m,a[200][200],b[200],c,ans;
bool pass(int row){
    int tot = c;
    for(int i=1;i<=m;i++){
        tot+=a[row][i]*b[i];
    }
    if(tot>0)return true;
    else return false;
}
int main(){
    cin>>n>>m>>c;
    for(int i=1;i<=m;i++)cin>>b[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        if(pass(i))ans++;
    }
    cout<<ans<<endl;
}
