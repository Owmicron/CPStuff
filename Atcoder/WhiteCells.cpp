#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int H,W,h,w,ans;
int main(){
    cin>>H>>W;
    cin>>h>>w;
    ans = H*W;
    ans -= ((h*W) + (H*w) - h*w);
    cout<<ans<<endl;
}
