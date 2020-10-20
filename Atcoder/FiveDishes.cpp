#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int a[60],b[60],sum;
int mn;
int main(){
    for(int i=0;i<5;i++){
        cin>>a[i];
        b[i] = a[i];
        int pl = 10 - a[i]% 10;
        if(pl==10)pl=0;
        b[i]+=pl;
        sum += b[i];
    }
    mn = 1000;
    for(int i=0;i<5;i++){
        int temp;
        temp = sum-b[i]+a[i];
        mn = min(mn,temp);
    }
    cout<<mn<<endl;

}
