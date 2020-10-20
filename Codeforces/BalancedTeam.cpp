#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,a[300000];
int src (int x){
    int l=1;
    int r=n;
    while(l<=r){
        int mid = (l+r)/2;
        if((a[mid]<=x)&&(a[mid+1]>x)){return mid;}
        else if((a[mid]<=x)&&(a[mid+1]<=x)){l=mid+1;}
        else if(a[mid]>x){r=mid-1;}
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
    a[n+1]=a[n]+10000;

    int mx=-1;
    for(int i=1;i<=n;i++){
        int up = a[i]+5;
        int u = src(up);
        int temp = u-i+1;
        mx = max(mx,temp);
        //cout<<i<<" "<<u<<" "<<mx<<endl;
    }
    cout<<mx<<endl;
}


