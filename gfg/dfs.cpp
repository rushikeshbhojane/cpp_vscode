// { Driver Code Starts
#include <iostream>
#include <vector>
#include <algorithm> 
#include <string>
#include <stack>
using namespace std; 

 // } Driver Code Ends


class Solution 
{
    public:
	//Function to return a list containing the DFS traversal of the graph.
	vector<int>dfsOfGraph(int V, vector<int> adj[])
	{
	    vector<int> traversal;
	    stack<int> s;
	    vector<bool> visited (V, false) ;
	    
	    s.push(0);
	    while (!s.empty()) {
	        int top = s.top();
	        s.pop();
	        
	        if (!visited[top]) {
	            traversal.push_back(top);
	            visited[top] = true;
	            for (int i: adj[top]) {
	                if (!visited[i]) {
	                    s.push(i);
	                }
	            }
	        }
	        
	    }
	    
	    return traversal;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.dfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  // } Driver Code Ends