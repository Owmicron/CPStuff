#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,a[400000],sel;
priority_queue <int> small;
priority_queue <int> ans;
int main(){
    scanf("%d",&n);
    sel = n-1;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);

    int l=1;int r=n;
    while(sel>0){
        small.push(-1*a[l]);
        small.push(-1*a[r]);

        int mn = small.top()*-1;
        ans.push(-1 * (mn/sel));

        sel--;
        if(abs(l-r)>1){l++;r--;}
    }
    printf("%d\n",-1*ans.top());

}
