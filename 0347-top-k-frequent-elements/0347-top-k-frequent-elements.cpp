class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;

        for (int x : nums)
            freq[x]++;

        vector<vector<int>> bucket(n + 1);
        for (auto &p : freq)
        {
            int number = p.first;
            int frequency = p.second;

            bucket[frequency].push_back(number);
        }
        vector<int> ans;

        for (int i = bucket.size() - 1; i >= 0; i--)
        {
            if(bucket[i].size() != 0)
                for (int x : bucket[i])
                {
                    ans.push_back(x);
                    if(ans.size() == k)
                        return ans;
                }
        }
        return ans;
    }
};