#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,a[100],BIT[100];
int getsum (int idx){
    int sum = 0;
    idx++;
    while(idx>0){
        sum += BIT[idx];
        idx -= idx & (-idx);
    }
    return sum;
}
void update (int idx, int val){
    idx ++ ;
    while(idx<=n){
        BIT[idx]+=val;
        idx += idx & (-idx);
    }
}
void construct (){
    for(int i=1;i<=n;i++){
        update(i,a[i]);
    }
}
int main(){
    n = 6;
    for(int i=1;i<=n;i++)a[i]=1;
    construct();
    cout<<getsum(3);
}
