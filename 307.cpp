// bittorala
#include <stdio.h>
#include <queue>
#include <vector>
#define gcu getchar_unlocked

inline bool fastscan(int & num)
{
    num = 0; char c;
    for (c = gcu(); (c < '0' || c > '9') && c >= 0; c = gcu());
    if (c < 0) return false;
    for (; c >= '0' && c <= '9'; c = gcu())
        num = num * 10 + c - '0';
    return c >= 0;
}

struct intint
{
    int a,b;
};

class Graph
{
    public:
    Graph(int N) : N(N), adj(std::vector<std::vector<int>>(N)) {}
    void make_edge(int i, int j)
    {
        adj[i].emplace_back(j);
        adj[j].emplace_back(i);
    }

    bool bfs_connected_without_cycles()
    {
        std::queue<intint> queue;
        queue.push({0,-1});
        bool valid = true;
        std::vector<bool> visited(N);
        int count = 0;
        while (!queue.empty() && valid)
        {
            intint v_and_prev = queue.front();
            queue.pop();
            for (int w : adj[v_and_prev.a])
            {
                if (w == v_and_prev.b) continue;
                if (visited[w])
                    valid = false;
                    queue.push({w,v_and_prev.a});
            }
            visited[v_and_prev.a] = true; ++count;
        }
        return valid && count == N;
    }
    int N;
    std::vector<std::vector<int>> adj;
};

int main()
{
    int V, E, u, v;
    while (fastscan(V))
    {
        Graph graph(V);
        fastscan(E);
        for (int i = 0; i < E; ++i)
        {
            fastscan(u); fastscan(v);
            graph.make_edge(u,v);
        }
        graph.bfs_connected_without_cycles() ? puts("SI") : puts("NO");
    }
    return 0;
}