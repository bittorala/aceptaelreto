// bittor
#include <stdio.h>
#include <vector>
#include <queue>

#define INT_MAX ~(0x01 << 31)
#define gcu getchar_unlocked

struct vert_dist
{
    int v, d;
};

bool operator<(const vert_dist & a, const vert_dist & b)
{
    return a.d > b.d;
}

int lines_at_station[10000];

inline int fastscan()
{
    int num = 0; char c;
    for (c = gcu(); c < '0' || c > '9'; c = gcu());
    for (; c >= '0' && c <= '9'; c = gcu())
        num = num * 10 + c - '0';
    return num;
}

class Graph
{
    public:
    Graph(int N) : N(N), adj(std::vector<std::vector<int>>(N)) {}
    void make_edge(int i, int j)
    {
        adj[i].emplace_back(j);
        adj[j].emplace_back(i);
    }

    void bfs_distances(int src, std::vector<int> & dist_to, int important_stations)
    {
        std::queue<int> queue;
        for (int & i : dist_to) i = INT_MAX;
        dist_to[src] = 0;
        queue.push(src);
        int count = 1;
        while (!queue.empty() && count < important_stations)
        {
            int v = queue.front();
            queue.pop();
            for (int w : adj[v])
            {
                if (dist_to[w] == INT_MAX)
                { 
                    dist_to[w] = dist_to[v] + 1;
                    if (lines_at_station[w] >= 2) ++count;
                    queue.push(w);
                }
            }
        }
    }
    int N;
    std::vector<std::vector<int>> adj;
};

int main()
{
    int N, L, result;
    for (N = fastscan(), L = fastscan(); N != 0 || L != 0; N = fastscan(), L = fastscan())
    {
        Graph graph(N);
        int min_sum = INT_MAX;
        for (int i = 0; i < N; ++i) lines_at_station[i] = 0;
        std::vector<int> dist_to(N);
        std::vector<int> important_stations;
        int i,j;
        for (int l = 0; l < L; ++l)
        {
            i = fastscan(); j = fastscan(); --i; --j;
            ++lines_at_station[i];
            while (j != -1)
            {
                graph.make_edge(i,j);
                ++lines_at_station[j];
                i = j;
                j = fastscan(); --j;
            }
        }   
        for (int i = 0; i < N; ++i)
        {
            if (lines_at_station[i] >= 2)
            {
                important_stations.emplace_back(i);
            }
        }
        for (int v : important_stations)
        {
            int sum = 0;
            graph.bfs_distances(v, dist_to, important_stations.size());
            for (int w : important_stations) sum += dist_to[w];
            if (sum < min_sum) 
            {
                min_sum = sum;
                result = v;
            }
        }
        printf("%i\n", ++result);
    }
    return 0;
}