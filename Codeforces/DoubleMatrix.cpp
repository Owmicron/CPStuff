#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,m,a[60][60],b[60][60];
pair <int,int> mat[60][60];
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&b[i][j]);

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            mat[i][j] = make_pair (min(a[i][j],b[i][j]),max(a[i][j],b[i][j]));

    bool strict = true;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i>1){
                if (mat[i][j].first > mat[i-1][j].first  && mat[i][j].second > mat[i-1][j].second){}
                else {strict=false;break;}
            }
            if(j>1){
                if (mat[i][j].first > mat[i][j-1].first  && mat[i][j].second > mat[i][j-1].second){}
                else {strict=false;break;}
            }
        }
    }
    if(strict)printf("Possible\n");
    else printf("Impossible\n");
}
