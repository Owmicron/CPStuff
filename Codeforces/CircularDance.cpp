#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
vector<int> ans;
int n,l[300000],r[300000];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>l[i]>>r[i];

    ans.push_back(1);

    while(ans.size()<n){
        int now = ans.back();
        int a,b;
        a = l[now]; b = r[now];

        int x = l[now];
        int c,d;
        c = l[x]; d=r[x];
        if(c==b || d==b){
            ans.push_back(a);ans.push_back(b);
        }
        else{
            ans.push_back(b);ans.push_back(a);
        }
    }
    for(int i=0;i<n;i++)cout<<ans[i]<<" ";

}
