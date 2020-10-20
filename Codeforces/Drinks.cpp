#include <bits/stdc++.h>
using namespace std;

int main() {
   int n;
   cin>>n;
   double sum=0;
   for(int i=1;i<=n; i++){
      int x;
      cin>>x;
      sum+=x;
   }
   cout<<setprecision(14)<<sum/n;

}
