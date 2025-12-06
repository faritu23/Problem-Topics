#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
const int N=1e5+7;
int a[N];
int tree[3*N];
void build(int u,int i,int j)
{
    if(i==j) {
        tree[u]=a[i];
        return;
    }
    int mid=(i+j)/2;
    build(u*2,i,mid);
    build((u*2)+1,mid+1,j);

    tree[u]=tree[u*2]+tree[(u*2)+1];
    // tree[u]=tree[u*2]*tree[(u*2)+1];
    // tree[u]=tree[u*2]|tree[(u*2)+1];
    // tree[u]=tree[u*2]&tree[(u*2)+1];
    // tree[u]=tree[u*2]^tree[(u*2)+1];

}
void update(int u,int i,int j,int idx,int x)
{
    if(i==j)
    {
        tree[u]=x;
        a[i]=x;
        return;
    }

    int mid=(i+j)/2;

    if(idx<=mid) update(u*2,i,mid,idx,x);// left
    else update((u*2)+1,mid+1,j,idx,x); //right

    tree[u]=tree[u*2]+tree[(u*2)+1];
}
int query(int u,int i,int j,int b,int e)
{
    if(i>e || j<b) return 0; //overflow

    if(i>=b && j<=e) //in full under
    {
        return tree[u];
    }

    int mid=(i+j)/2;

    int right=query(u*2,i,mid,b,e);
    int left=query((u*2)+1,mid+1,j,b,e);
    return right+left;
}
void solve()
{
   int n;
   cin>>n;
   for(int i=1;i<=n;i++) cin>>a[i];

   build(1,1,n);
   cout<<query(1,1,n,1,5)<<endl;
//    cout<<a[4]<<endl;
   update(1,1,n,4,8);
//    cout<<a[4]<<endl;
   cout<<query(1,1,n,1,5)<<endl;


   
}
main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}






#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
const ll N = 1e7 + 5;
vector<int> prime;
vector<bool> sieve_algo(N,true);
void sieve()
{
    sieve_algo[0]=false;
    sieve_algo[1]=false;
    for(int i=2;i<N;i++)
    {
        if(sieve_algo[i])
        {
            prime.push_back(i);
            for(int j=i*i;j<N;j+=i)
            {
                sieve_algo[j]=false;
            }
        }
    }
}
string binary_convert(int n)
{
    string s;
    for(int i=0;i<=32;i++)
    {
        if((n>>i)&1)s.push_back('1');
        else s.push_back('0');
    }
    return s;
}

vector<int> div(int n)
{
    vector<int> v;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            v.push_back(i);
            if(n/i != i)v.push_back(n/i);
        }
    }
    sort(v.begin(),v.end());
    return v;
}
void float_num(float num)
{
    std::cout <<std::fixed<< std::setprecision(10) << num << endl;
} 
void solve()
{
   
}
main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t=1;cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}