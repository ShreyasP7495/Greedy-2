//Time Complexity-O(n)
//Space Complexity-O(n)
//Did the code execute on Leetcode? yes

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n==0)
        {
            return tasks.size();
        }
        int maxcount=0;
        int maxfreq=0;
        unordered_map<char,int>m;
        for(int i=0;i<tasks.size();i++)
        {
            m[tasks[i]]++;
            maxfreq=max(maxfreq,m[tasks[i]]);
        }
        for(auto i=m.begin();i!=m.end();i++)
        {
            if(i->second==maxfreq)
            {
                maxcount++;
            }
        }
        int partition=maxfreq-1;
        int empty_spots=(n-(maxcount-1))*partition;
        int available_spots=tasks.size()-(maxfreq*maxcount);
        int idle=max(0,empty_spots-available_spots);
        int res=tasks.size()+idle;
        return res;
    }
};