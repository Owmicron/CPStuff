#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int x[30][30];
int n,m;
void runtuh (int c[30][30]){
    bool found = true;
    while(found){
    found=false;
        for(int i=n;i>1;i--){
            for(int j=1;j<=m;j++){
                if((c[i][j] == 0)&&(c[i-1][j]!=0)){
                    found=true;
                    swap(c[i][j],c[i-1][j]);
                }
            }
        }
    }
}
bool visitable (int y, int x){
    if(y<=0 || y>n || x<=0 || x>m){return false;}
    else return true;
}
void salin (int m1[30][30],int m2[30][30]){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            m2[i][j]=m1[i][j];
        }
    }
}
int dfs(int c[30][30], bool d[30][30],int y,int x){
    int val=1;
    d[y][x]=true;
    if((visitable (y,x+1)) && (c[y][x+1] == c[y][x]) && (!d[y][x+1])){val+=dfs(c,d,y,x+1);}
    if((visitable (y,x-1)) && (c[y][x-1] == c[y][x]) && (!d[y][x-1])){val+=dfs(c,d,y,x-1);}
    if((visitable (y+1,x)) && (c[y+1][x] == c[y][x]) && (!d[y+1][x])){val+=dfs(c,d,y+1,x);}
    if((visitable (y-1,x)) && (c[y-1][x] == c[y][x]) && (!d[y-1][x])){val+=dfs(c,d,y-1,x);}
    c[y][x]=0;
    return val;
}
int jaw (int a[30][30]){
    int b[30][30];
    bool vis[30][30];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            vis[i][j]=false;
        }
    }
    bool next = true;
    int mx = 0;
    while (next){
        next=false;
        salin(a,b);
        for(int i=1;i<=n;i++){
            bool br=false;
            for(int j=1;j<=m;j++){
                if(!vis[i][j] && (b[i][j]!=0)){
                    int v = dfs(b,vis,i,j);
                    v *= (v-1);
                    if(v>0){
                        runtuh(b);
                        v += jaw(b);
                        next=true;
                        br=true;
                        if (v>mx){mx=v;}
                        break;
                    }
                    else{next=true;br=true;break;}
                }
            }
            if(br)break;
        }
    }
    return mx;
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&x[i][j]);

    printf("%d\n",jaw(x));
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=m;j++){
//            cout<<x[i][j];
//        }cout<<endl;
//    }cout<<endl;
}
