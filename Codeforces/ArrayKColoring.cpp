#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,k,f[6000],a[6000];
int start[6000];
bool valid;
vector<int> num;
int main(){
    cin>>n>>k;
    valid=true;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(f[a[i]]==0){num.push_back(a[i]);}
        f[a[i]]++;
        if(f[a[i]]>k){valid=false;}
    }
    sort(num.begin(),num.end());
    if(!valid){
        cout<<"NO\n";
    }
    else{
        int idx = 1;
        for(int i=0;i<num.size();i++){
            int cur = num[i];
            start[cur] = idx;
            idx += f[cur];
            if(idx>k) idx %=k;
            if(idx==0)idx=k;
        }
        for(int i=1;i<=n;i++){
            int cur = a[i];
            cout<<start[cur]<<" ";
            start[cur]++;
            if(start[cur]>k){start[cur]%=k;}
        }
    }

}
