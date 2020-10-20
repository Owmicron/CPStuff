#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n;str s;
int closest (char a, char b){
    int x,y;
    x = int(a)-64;
    y = int(b)-64;
    if(y<x)swap(y,x);
    int m1 = abs(x-y);
    int m2 = 26-m1;
    return min(m1,m2);
}
int cnt (int fin){
    int a,b,c,d;
    a = closest (char(s[fin-3]),'A');
    b = closest (char(s[fin-2]),'C');
    c = closest (char(s[fin-1]),'T');
    d = closest (char(s[fin]),'G');
    return a+b+c+d;
}
int main(){
    cin>>n;
    cin>>s;
    int mn = INT_MAX;
    for(int i=3;i<s.size();i++){
        mn = min(mn,cnt(i));
    }
    cout<<mn;
}
