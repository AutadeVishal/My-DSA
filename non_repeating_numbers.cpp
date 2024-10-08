//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        unordered_map<int, int> m;
        vector<int> v;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }
           for (auto& pair : m) {
            if (pair.second == 1) {
                v.push_back(pair.first);
                if (v.size() == 2) {
                  break;
                }
            }
        }
        if (v[0] > v[1]) {
            swap(v[0], v[1]);
        }

        return v;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends