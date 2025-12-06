

#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
const ll N = 1e7 + 5;
vector<int> prime;
vector<int> small_divisor(N,0);
void sieve()
{
    small_divisor[1]=1;
    for(int i=2;i<N;i++)
    {
        if(!small_divisor[i])
        {
            prime.push_back(i);
            for(int j=i;j<N;j+=i)
            {
                if(!small_divisor[j])
                small_divisor[j]=i;
            }
        }
    }
}
void NOD(vector<int> v)
{
    int ans=1;
    for(int i=0;i<v.size();i++)
    {
        ans*=(v[i]+1);
    }
    cout<< ans;
}

void solve()
{
   int n; cin>>n;
   vector<int> v;
   int m=n;
   while(m>1)
   {
        int x=small_divisor[m];
        int cnt=0;
        while(m%x==0)
        {
            m/=x;
            cnt++;
        }
        v.push_back(cnt);
   }
   NOD(v);
   
}
main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();
    solve();
    return 0;
}
