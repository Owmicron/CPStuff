#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,m,b,rock;
int sum[100][100],stone[100][100];
int mx = -1000000000;
void check (int startx, int starty, int endx, int endy){
    int value=0;
    int batu=0;
    for(int i=starty;i<=endy;i++){
        value += sum[i][endx] - sum[i][startx-1];
        batu += stone[i][endx] - stone[i][startx-1];
        if(batu>b){break;}
    }
    if(batu<=b){
        if(value>mx){
            mx = value;
            rock = batu;
        }
    }
}
int main(){
    scanf("%d %d %d",&n,&m,&b);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int q;scanf("%d",&q);
            if(q!=9999){
                sum[i][j]=q+sum[i][j-1];
                stone[i][j]=stone[i][j-1];
            }
            else{
                sum[i][j]=sum[i][j-1];
                stone[i][j]=1+stone[i][j-1];
            }
        }
    }
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=m;j++){
//            cout<<stone[i][j]<<" ";
//        }cout<<endl;
//    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int a=i;a<=n;a++){
                for(int c=j;c<=m;c++){
                    //cout<<i<<" "<<j<<" | "<<a<<" "<<c<<endl;
                    check(j,i,c,a);
                }
            }
        }
    }
    printf("%d %d\n",mx,rock);
}
