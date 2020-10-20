#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,a[200],memo[200][10];
bool calc[200][10];
int dp (int day, int bef){
    if(day>n)return 0;
    else if(calc[day][bef])return memo[day][bef];
    else{
        int m=0;
        if(a[day]==0){
            m = 1+dp (day+1,0);
        }
        else if(a[day]==1){
            if(bef == 2){
                m = 1+dp (day+1,0);
            }
            else{
                m = min (1+dp(day+1,0), dp(day+1,2));
            }
        }
        else if(a[day]==2){
            if(bef == 1){
                m = 1+dp (day+1,0);
            }
            else{
                m = min(1+dp(day+1,0),dp(day+1,1));
            }
        }
        else{
            if(bef==0){
                m = min (dp(day+1,1),dp(day+1,2));
                m = min (m, 1 + dp(day+1,0));
            }
            else if(bef==1){
                m = min(1+dp(day+1,0),dp(day+1,2));
            }
            else if(bef==2){
                m = min(1+dp(day+1,0),dp(day+1,1));
            }
        }
        calc[day][bef]=true;
        memo[day][bef]=m;
        return m;
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    printf("%d\n",dp(1,0));
}
