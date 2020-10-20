#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
typedef double dbl;
int n,r,a,b;
int main(){
    scanf("%d",&n);
    bool can=true;
    for(int i=1;i<=n;i++){
        scanf("%d",&r);
        if(r==25){a++;}
        else if(r==50){
            if(a>0){a--;b++;}
            else{can=false;}
        }
        else{
            if((a>0)&&(b>0)){a--;b--;}
            else if(a>=3){a-=3;}
            else{can=false;}
        }
    }
    if(!can){printf("NO\n");}
    else{printf("YES\n");}
}
