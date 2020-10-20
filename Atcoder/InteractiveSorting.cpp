#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
vector <int> v;
int n,q;
str ans;
str verdict;
void ask (int a, int b){
    cout<<"? "<<char(a+64)<<" "<<char(b+64)<<endl;
    fflush(stdout);
}
void ins (int x, int z){
    vector<int>temp;
    for(int i=0;i<x;i++){
        temp.push_back(v[i]);
    }
    temp.push_back(z);
    for(int i=x;i<v.size();i++){
        temp.push_back(v[i]);
    }
    v=temp;
}
void solve (int x){
    int l,r,mid;
    l = 0;
    r = x;
    bool asked [30];
    for(int i=0;i<=27;i++){
        asked[i]=false;
    }
    while(l!=r){
        mid = (l+r)/2;
        if(asked[mid]){mid++;}
        //cout<<l<<" "<<r<<" "<<mid<<endl;
        if(mid==0){
            ask(x,v[0]);
            cin>>verdict;
            if(verdict=="<"){
                l=mid;
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        else{
            ask(v[mid-1],x);
            cin>>verdict;
            if(verdict=="<"){
                l=mid;
                if(mid==x-1){l=mid;r=mid;}
            }
            else{
                r=mid-1;
            }
        }
        asked[mid]=true;
    }
    ins(l,x);
}
int main(){
    cin>>n>>q;
    cout<<"? A B\n";
    fflush(stdout);
    cin>>verdict;
    if(verdict==">"){v.push_back(2);v.push_back(1);}
    else{v.push_back(1);v.push_back(2);}

    for(int i=3;i<=n;i++){
        solve(i);
    }
    ans="! ";
    for(int i=0;i<v.size();i++){
        ans+=char(v[i]+64);
    }
    cout<<ans<<endl;
}
