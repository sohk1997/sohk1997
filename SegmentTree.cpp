#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e5+100;
struct data{int sum;};
struct SegmentTree{
    data IT[4*MAXN];
    int lazy[4*MAXN];
    void update(int x,int l,int r,int le,int ri,int val)
    {
        if(lazy[x] > 0)
        {
            IT[x].sum += lazy[x]*(r-l+1);
            if(l != r)
            {
                lazy[2*x] += lazy[x];
                lazy[2*x+1] += lazy[x];
            }
            lazy[x] = 0;
        }
        if(le <= l && r <= ri)
        {
            IT[x].sum += val*(r-l+1);
            if(l != r)
            {
                lazy[2*x] += val;
                lazy[2*x+1] += val;
            }
            return;
        }
        if(l > ri || le > r)    return;
        update(2*x,l,(l+r)>>1,le,ri,val);
        update(2*x+1,((l+r)>>1)+1,r,le,ri,val);
        IT[x].sum = IT[2*x+1].sum+IT[2*x].sum;
    }
    int query(int x,int l,int r,int le,int ri)
    {
        if(lazy[x] > 0)
        {
            IT[x].sum += lazy[x]*(r-l+1);
            if(l != r)
            {
                lazy[2*x] += lazy[x];
                lazy[2*x+1] += lazy[x];
            }
            lazy[x] = 0;
        }
        if(le <= l && r <= ri)  return IT[x].sum;
        if(l > ri || le > r)    return 0;
        return query(2*x,l,(l+r)>>1,le,ri)+query(2*x+1,((l+r)>>1)+1,r,le,ri);
    }
};
SegmentTree IT;
int main()
{
    IT.update(1,1,1e5,1,1e5,1);
    cout << IT.query(1,1,1e5,1,1e5-1);
}

