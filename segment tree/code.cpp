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