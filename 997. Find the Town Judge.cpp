class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        
        int trustArray[N+1];
        int j = 0;
        for(; j<=N; ++j)
            trustArray[j] = 0;
        
        for (j = 0; j < trust.size(); ++j)
        {
            ++trustArray[trust[j][1]];
            --trustArray[trust[j][0]];
        }
        for (j = 1; j <= N; ++j)
        {
            if (trustArray[j] == N - 1)
                return j;
        }
        return -1;
    }
};
