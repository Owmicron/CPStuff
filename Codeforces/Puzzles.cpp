#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
long n,m,f[1001],lit,ans;
bool c;
vector <long>v,w;
int main(){
    cin>>n>>m;
    for(long i=1;i<=m;i++){
        cin>>f[i];
    }

    sort(f+1,f+m);

    lit=10000;
    for(long i=2;i<=m;i++){
        if(f[i]-f[i-1]<lit){lit=f[i]-f[i-1];}
    }

    for(long i=1;i<=m;i++){
        v.push_back(f[i]);
        w.push_back(f[i]);
    }

    for(long i=1;i<=m-n;i++){
        if(c){v.pop_back();w.erase(w.begin());}
        else{w.pop_back();v.erase(v.begin());}
        c=not c;

    }
//
//    cout<<v.front()<<" "<<v.back()<<"\n";
//    cout<<w.front()<<" "<<w.back()<<"\n";

    ans=min(v.back()-v.front(),w.back()-w.front());
    ans=min(ans,lit);

    cout<<ans;

}
