#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,m,mat[300][300],last[300];
bool inr[300],inc[300];
int zero(int x){
    if(x==m)last[1]=0;
    else last[1]=1;

    for(int i=1;i<=m;i++)inc[i]=false;
    for(int i=1;i<=m;i++){
        if(i<=x){
            if(mat[1][i]==1){inc[i]=true;}
        }
        else{
            if(mat[1][i]==0){inc[i]=true;}
        }
    }

}
int type(int r){
    int ch=0;
    for(int i=2;i<=m;i++){
        int temp1,temp2;
        temp1 = mat[r][i-1];
        if(inc[i-1]){temp1 = 1 - temp1;}

        temp2 = mat[r][i];
        if(inc[i]){temp2 = 1-temp2;}

        if(temp2!=temp1){ch++;}
        if(ch>1){break;}
    }

    if(ch<=1){return ch;}
    else{return 2;}
}
bool sorted(){
    bool s = true;
    for(int i=1;i<=n;i++)inr[i]=false;
    for(int i=2;i<=n;i++){
        int ty = type(i);
        if(ty==2){s=false;break;}

        if(last[i-1]==0){
            if(ty==1){
                int temp = mat[i][1];
                if(inc[1]){temp=1-temp;}
                if(temp==1)inr[i]=true;
                last[i]=1;
            }
            else{
                int temp = mat[i][1];
                if(inc[1]){temp=1-temp;}
                if(temp==1)inr[i]=true;
                last[i]=0;
            }
        }
        else if(last[i-1]==1){
            if(ty==1){s=false;break;}
            else{
                int temp = mat[i][1];
                if(inc[1]){temp = 1 - temp;}
                if(temp==0) inr[i]=true;
                last[i]=1;
            }
        }
    }
    return s;
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&mat[i][j]);
        }
    }
    bool ans=false;

    for(int i=0;i<=m;i++){
        zero(i);
        ans = sorted();
        if(ans){break;}
    }

    if(ans){
        printf("YES\n");
        for(int i=1;i<=n;i++)cout<<inr[i];cout<<endl;
        for(int i=1;i<=m;i++)cout<<inc[i];cout<<endl;
    }
    else{printf("NO\n");}
}
