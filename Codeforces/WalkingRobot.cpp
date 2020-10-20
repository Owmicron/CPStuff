#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,b,a,s[300000],c,ma;
int main(){
    scanf("%d %d %d",&n,&b,&a);
    ma=a;
    for(int i=0;i<n;i++){
        scanf("%d",&s[i]);
    }
    while(c<n && (b>0 || a>0)){
        if(s[c]==1){
            if(b>0){
                c++;
                if(a==ma){a--;}
                else{b--;a++;}
//                b--;
//                a++;
//                if(a>ma){a=ma;}
            }
            else{
                a--;
                c++;
            }
        }
        else{
            if(a>0){
                a--;
                c++;
            }
            else{
                b--;
                c++;
            }
        }
    }
    printf("%d\n",c);
}
