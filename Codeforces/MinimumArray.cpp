#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
set <int> s;
int n,a[300000],f[300000],c[300000];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        int temp;scanf("%d",&temp);
        s.insert(temp);
        f[temp]++;
    }

    for(int i=1;i<=n;i++){
        int ideal = n-a[i];
        if(ideal==n){ideal=0;}

        if(s.count(ideal)){
            f[ideal]--;
            if(f[ideal]==0)s.erase(ideal);
        }
        else{
            int last = *s.rbegin();
            if(ideal>last){ideal = *s.begin();}
            else{ideal = *s.upper_bound(ideal);}
            f[ideal]--;
            if(f[ideal]==0)s.erase(ideal);
        }

        c[i] = (a[i]+ideal) % n;
    }
    for(int i=1;i<=n;i++)printf("%d ",c[i]);
}
