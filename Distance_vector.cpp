#include <bits/stdc++.h>
using namespace std;

#define INF 9999

int main()
{
    int n;
    cout << "Enter the number of nodes (routers): ";
    cin >> n;

    vector<vector<int>> cost(n, vector<int>(n));
    cout << "\nEnter the cost matrix:\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> cost[i][j];

    // For each router as source
    for(int src = 0; src < n; src++)
    {
        vector<int> dist(n), nextHop(n);

        // Initialization
        for(int i = 0; i < n; i++)
        {
            dist[i] = cost[src][i];
            if(cost[src][i] != INF && i != src)
                nextHop[i] = i;
            else
                nextHop[i] = src;
        }
        dist[src] = 0;
        nextHop[src] = src;

        // Bellman-Ford (Distance Vector)
        for(int k = 0; k < n - 1; k++)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(dist[i] != INF && cost[i][j] != INF &&
                       dist[i] + cost[i][j] < dist[j])
                    {
                        dist[j] = dist[i] + cost[i][j];
                        nextHop[j] = nextHop[i];
                    }
                }
            }
        }

        // Output Routing Table
        cout << "\nRouting Table for Router " << src + 1 << ":\n";
        cout << "Destination     Next Hop        Distance\n";
        for(int i = 0; i < n; i++)
        {
            cout << setw(5) << i + 1
                 << setw(14) << nextHop[i] + 1
                 << setw(16) << dist[i] << endl;
        }
    }

    return 0;
}
 