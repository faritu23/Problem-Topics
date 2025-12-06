

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
void SOD(vector<pair<int,int>> v)
{
    int ans=1;
    for(int i=0;i<v.size();i++)
    {
        int p=v[i].first;
        int a=v[i].second;
        int sum=0;
        for(int j=0;j<=a;j++)
        {
            sum+=pow(p,j);
        }
        ans*=sum;
    }
    cout<< ans;
}

void solve()
{
   int n; cin>>n;
   vector<pair<int,int>> v;
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
        v.push_back({x,cnt});
   }
   SOD(v);
   
}
main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();
    solve();
    return 0;
}



// long long SumOfDivisors(long long num) {
//     long long total = 1;

//     for (long long i = 2; i * i <= num; i++) {
//         if (num % i == 0) {
//             int e = 0;
//             do {
//                 e++;
//                 num /= i;
//             } while (num % i == 0);

//             long long sum = 0, pow = 1;
//             do {
//                 sum += pow;
//                 pow *= i;
//             } while (e-- > 0);
//             total *= sum;
//         }
//     }
//     if (num > 1) {
//         total *= (1 + num);
//     }
//     return total;
// }