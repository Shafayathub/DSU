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

    int n, e;
    cin >> n >> e;
    bool cycle = false;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        int leaderA = find(a);
        int leaderB = find(b);

        if (leaderA == leaderB)
        {
            cycle = true;
        }
        else
        {
            dsu_union(a, b);
        }
    }

    if (cycle)
    {
        cout << "Cycle detected\n";
    }
    else
    {
        cout << "No cycle\n";
    }

    return 0;
}