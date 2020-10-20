#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int t[200][200],a[200],b[200],ans[200][200],n,m,h;
int main(){
    scanf("%d %d %d",&n,&m,&h);
    for(int i=1;i<=m;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)scanf("%d",&b[i]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&t[i][j]);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(t[i][j]>0){
                ans[i][j] = min(b[i],a[j]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%d",ans[i][j]);
            if(j<m)printf(" ");
            else printf("\n");
        }
    }
}
