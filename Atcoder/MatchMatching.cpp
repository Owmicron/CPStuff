#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
str memo[200000];
bool calc[200000];
int use[10];
int cost[10];
int n,m;
str larger (str a,str b){
    if(a[0]=='-' && b[0]=='-'){return b;}
    else if(b[0]=='-'){return a;}
    else if(a[0]=='-'){return b;}
    else if(a.size()>b.size())return a;
    else if(a.size()<b.size())return b;
    else{
        for(int i=0;i<a.size();i++){
            if(a[i]>b[i]){return a;}
            else if(a[i]<b[i]){return b;}
        }
        return a;
    }
}
str dp (int x){
    if(x==0)return "";
    else if(x<0)return "-";
    else if(calc[x])return memo[x];
    else{
        str mx = "-";
        for(int i=1;i<=9;i++){
            if(use[i]){
                str tmp = "";
                tmp+=char(i+48);
                mx = larger (mx, dp (x-cost[i]) + tmp );
            }
        }
        memo[x]=mx;
        calc[x]=true;
        return mx;
    }
}
int main(){
    cost[1]=2;
    cost[2]=5;
    cost[3]=5;
    cost[4]=4;
    cost[5]=5;
    cost[6]=6;
    cost[7]=3;
    cost[8]=7;
    cost[9]=6;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int temp;
        cin>>temp; use[temp]=true;
    }
    cout<<dp(n)<<endl;
}
