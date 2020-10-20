#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
short a[10010],k,n,f[10010][1010],x;
short num[1010];
short INF = 22000;
int main(){
    scanf("%d %d",&x,&k);
    for(int i=1;i<=x;i++){
        short temp;
        scanf("%d",&temp);
        if(temp>1000){continue;}
        if (num[temp] < k/temp) {n++;num[temp]++;a[n]=temp;}
    }
    //scanf("%d",&k);
    //cout<<"a";
    sort(a+1,a+1+n);
    for(int i=1;i<=k;i++){
        f[0][i]=INF;
    }
    //cout<<"a";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            int temp = INF;
            for(int k=0;k<=min(1,j/a[i]);k++){
                //short temp;
                temp = min (temp , k + f[i-1][j-a[i]*k]);
            }
            f[i][j]=temp;
            //f[i][j] = min( (j/a[i]) + f[i-1][j%a[i]] , f[i-1][j]);
            //printf("%d %d %d\n",i,j,f[i][j]);
        }

    }
    if(f[n][k]>=INF)f[n][k]=-1;
    printf("%d\n",f[n][k]);
}
