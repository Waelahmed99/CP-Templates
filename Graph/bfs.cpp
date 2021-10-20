#include <bits/stdc++.h>

using namespace std;

vector<int> BFS(int s, vector<vector<int>> &adjList)
{
    vector<int> len(adjList.size(), INT_MAX);
    queue<int> q;
    q.push(s), len[s] = 0;

    int depth = 0, curr = s, sz = 1;
    while (!q.empty())
    {
        depth++, sz = q.size();
        while (sz--)
        {
            curr = q.front(), q.pop();
            for (auto child : adjList[curr])
            {
                if (len[child] == INT_MAX)
                {
                    q.push(child);
                    len[child] = depth + 1;
                }
            }
        }
    }

    return len; // [curr] is the furthest node from s with depth [depth]
}

vector<int> BFSPath(int s, int d, vector<vector<int>> &adjList)
{
    vector<int> len(adjList.size(), INT_MAX);
    vector<int> par(adjList.size(), -1);
    queue<int> q;
    q.push(s), len[s] = 0;

    int depth = 0, curr = s, sz = 1;
    bool ok = true;

    while (ok && !q.empty())
    {
        depth++, sz = q.size();
        for (auto child : adjList[curr])
        {
            if (len[child] == INT_MAX)
            {
                q.push(child);
                len[child] = depth + 1;
                par[child] = curr;

                if (child == d)
                {
                    ok = false;
                    break;
                }
            }
        }
    }

    vector<int> path;
    while (d != -1)
    {
        path.push_back(d);
        d = par[d];
    }

    reverse(path.begin(), path.end());

    return path;
}
