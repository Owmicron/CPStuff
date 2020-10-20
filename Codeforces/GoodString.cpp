#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int t,n;
str s;
int main(){
    scanf("%d",&t);
    for(int cases=1;cases<=t;cases++){
        scanf("%d",&n);
        cin>>s;
        int a,b;
        for(int i=0;i<s.size();i++){
            if(s[i]=='>'){a=i;break;}
        }
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='<'){b=s.size()-1-i;break;}
        }
        int ans=min(a,b);
        printf("%d\n",ans);
    }

}
