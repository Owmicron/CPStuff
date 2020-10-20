#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,k,mx;
str s;
vector<int> seq,pre;
int main(){
    cin>>n>>k;
    cin>>s;
    int f=1;
    for(int i=1;i<s.size();i++){
        if(s[i]!=s[i-1]){
            seq.push_back(f);
            f=1;
        }
        else{
            f++;
        }
    }
    seq.push_back(f);
    pre.push_back(seq[0]);
    for(int i=1;i<seq.size();i++){
        pre.push_back(seq[i]+pre.back());
    }

    //for(int i=0;i<seq.size();i++)cout<<seq[i]<<" ";cout<<endl;
    bool hand;
    if(s[0]=='1')hand=true;
    else{hand=false;}
    mx = 0;
    for(int i=0;i<seq.size();i++){
        int sum = 0;
        int l,r;
        if(hand){
            l = i;
            int sz = seq.size();sz--;
            r = min(i + 2*k, sz);

            sum = pre[r];
            if(l>0)sum-=pre[l-1];
        }
        else{
            l = i;
            int sz = seq.size();sz--;
            r = min(i + 2*k - 1,sz);

            sum = pre[r];
            if(l>0)sum-=pre[l-1];
        }
        mx = max(sum,mx);
        hand = not hand;
    }
    cout<<mx<<endl;
}
