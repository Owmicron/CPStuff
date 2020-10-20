#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,m,a[600][600],b[600][600];
bool ans;
bool dia (int sy, int sx){
    vector<int> c,d;
    while(sy>0 && sx<=m){
        c.push_back(a[sy][sx]);
        d.push_back(b[sy][sx]);
        sy--;sx++;
    }
    sort(c.begin(),c.end());
    sort(d.begin(),d.end());
    bool same=true;
    for(int i=0;i<c.size();i++){
        if(c[i]!=d[i]){same=false;break;}
    }
    return same;
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&b[i][j]);

    ans = true;
    for(int i=1;i<=n;i++){
        if(!dia(i,1)){ans=false;break;}
    }

    if(ans){
        for(int j=2;j<=m;j++){
            if(!dia(n,j)){ans=false;break;}
        }
    }
    if(ans){printf("YES\n");}
    else{printf("NO\n");}

}
