#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
str s;
int sum[200000],l,r,m;
int main(){
    cin>>s;
    for(int i=0;i<s.size()-1;i++){
        sum[i+1]=sum[i];
        if(s[i]==s[i+1])sum[i+1]++;
    }
    sum[s.size()]=sum[s.size()-1];
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        int ans=0;
        scanf("%d %d",&l,&r);
        ans = sum[r]-sum[l-1];
        if(s[r-1]==s[r]){ans--;}
        if(ans<0)ans=0;
        printf("%d\n",ans);
    }
}
