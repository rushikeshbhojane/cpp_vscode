// { Driver Code Starts


#include <iostream>
#include <vector>
#include <algorithm> 
#include <string>
#include <queue>
#include <cmath>
using namespace std;



 // } Driver Code Ends

class Solution
{
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;
    public:
    //Function to insert heap.
    void insertHeap(int &x)
    {
        if (!maxHeap.empty()) {
            int top = maxHeap.top();
            if (x > top) {
                if ((minHeap.size() == maxHeap.size())
                    || (minHeap.size() == maxHeap.size() - 1)) {
                    minHeap.push(x);
                } else {
                    balanceHeaps();
                    minHeap.push(x);
                }
            } else {
                if ((maxHeap.size() == minHeap.size())
                    || (maxHeap.size() == minHeap.size() - 1)) {
                    maxHeap.push(x);
                } else {
                    balanceHeaps();
                    maxHeap.push(x);
                }
            }
        } else {
            maxHeap.push(x);
        }
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        if (minHeap.size() > maxHeap.size()) {
            int top = minHeap.top();
            minHeap.pop();
            maxHeap.push(top);
        } else {
            int top = maxHeap.top();
            maxHeap.pop();
            minHeap.push(top);
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        if (minHeap.size() > maxHeap.size()) {
            return (double)minHeap.top();
        } else if (maxHeap.size() > minHeap.size()) {
            return (double)maxHeap.top();
        } else {
            return (double)(minHeap.top() * 1.0 + maxHeap.top() * 1.0 )/ 2;
        }
    }
};


// { Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << "Hello " <<  i << "    "  <<  floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}  // } Driver Code Ends