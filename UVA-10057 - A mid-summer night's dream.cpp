#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
int main()
{
    string line;
    while (getline(cin , line))
    {
        int n;
        sscanf(line.c_str(), "%d", &n);

        int arr[n], sum = 0;
        for (int i = 0; i < n; i++)
        {
            getline(cin , line);
            sscanf(line.c_str(), "%d", &arr[i]);
            sum += arr[i];
        }

        int avg = sum / n, avgsum = 0, avgCount = 0;
        int avg1 = avg1 - 1, avg1sum = 0, avg1Count = 0;
        int avg2 = avg1 + 1, avg2sum = 0, avg2Count = 0;


        for (int i = 0; i < n; i++)
        {
            avgsum += abs(avg - arr[i]);
            avg1sum += abs(avg1 - arr[i]);
            avg2sum += abs(avg2 - arr[i]);

            if (avg == arr[i]) avgCount++; 
            if (avg1 == arr[i]) avg1Count++; 
            if (avg2 == arr[i]) avg2Count++; 
        }
    }
    
    return 0;
}