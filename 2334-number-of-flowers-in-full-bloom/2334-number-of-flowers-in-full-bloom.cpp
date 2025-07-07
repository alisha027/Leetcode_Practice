class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int,int> temp;
        for(int i=0;i<flowers.size();i++){
            temp[flowers[i][0]]++;
            temp[flowers[i][1]+1]--;
        }
        int cnt=0;
        for(auto& x:temp){
            cnt+=x.second;
            x.second=cnt;
        }
        vector<int> res;
        for(int i=0;i<people.size();i++){
            auto it=temp.upper_bound(people[i]);
            if(it==temp.begin()){
                res.push_back(0);
            }else{
                res.push_back(prev(it)->second);
            }
        }
        return res;
    }
};

