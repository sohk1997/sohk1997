#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e5+100;
const int MAXL = 20;
struct SpareTable{

       int RMQ[MAXN][MAXL];
       int A[MAXN];
       void build(int a[],int n)
       {
           for(int i = 0 ; i < n ; i++)     A[i] = a[i];
           for(int i = 0 ; i < n-1 ; i++)   RMQ[i][0] = max(A[i],A[i+1]);
           for(int i = n ; i >= 0 ; i--)
                for(int j = 1 ; j < MAXL ; j++)
                    if(i+(1<<(j-1)) < n)    RMQ[i][j] = max(RMQ[i][j-1],RMQ[i+(1<<(j-1))][j-1]);
       }
       int query(int l,int r)
       {
           if(l == r)   return A[l];
           int k = __lg(r-l);
           return max(RMQ[l][k],RMQ[r-(1<<k)][k]);
       }
};
int a[10] = {1,2,3,4,5,6,7,8,9,10};
SpareTable RMQ;
int main()
{
    RMQ.build(a,10);
    cout <<RMQ.query(2,8);
}

