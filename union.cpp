#include <bits/stdc++.h>
using namespace std;

int par[1005];
int grp_size[1005];

int find(int node)
{
    if (par[node] == -1)
    {
        return node;
    }
    int leader = find(par[node]);
    par[node] = leader;
    return leader;
}

void dsu_union(int node1, int node2)
{
    int leader1 = find(node1);
    int leader2 = find(node2);
    if (grp_size[leader1] >= grp_size[leader2])
    {
        par[leader2] = leader1;
        grp_size[leader1] += grp_size[leader2]; 
    }
    else
    {
        par[leader1] = leader2;
        grp_size[leader2] += grp_size[leader1];
    }
}
 
int main()
{
    memset(par, -1, sizeof(par));
    memset(grp_size, 1, sizeof(grp_size));
    par[0] = 1;
    par[1] = -1;
    par[2] = 1;
    par[3] = 1;
    par[4] = 5;
    par[5] = 3;

    dsu_union(1, 2);

    return 0;
}