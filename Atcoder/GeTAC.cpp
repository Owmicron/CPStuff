#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,q;
str s;
int sum[200000];
bool neg[200000];
int main(){
    cin>>n>>q;
    cin>>s;
    s = " "+s;
    sum[0]=0;
    for(int i=1;i<s.size();i++){
        sum[i]=sum[i-1];
        if(s[i]=='C' && s[i-1]=='A'){sum[i]++;neg[i]=true;}
    }

    for(int i=1;i<=q;i++){
        int l,r;
        cin>>l>>r;
        int ans;
        ans = sum[r]-sum[l-1];
        if(neg[l])ans--;
        cout<<ans<<endl;
    }
}
