// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    int getMinIndex(vector<int>& distance, vector<bool>& visited, int V) {
        int minValue = INT_MAX, minIndex;
        
        for (int i = 0; i < V; i++) {
            if (!visited[i] && distance[i] <= minValue) {
                minValue = distance[i];
                minIndex = i;
            }
            
        }
        return minIndex;
    }
    
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> distance(V, INT_MAX);
        vector<bool> visited(V, false);
        
        distance[S] = 0;
        
        for (int count = 0; count < V-1; count++) {
            int u = getMinIndex(distance, visited, V);
            visited[u] = true;
            
            
            for (int v = 0; v < V; v++) {
                if (!visited[v]
                    && (distance[u] != INT_MAX)
                    && (distance[u] + adj[u][v] < distance[v])) {
                    distance[v] = distance[u] + adj[u][v];
                }
            }
        }

        return distance;
    }
    
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends