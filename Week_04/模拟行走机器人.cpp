class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_map<int, unordered_set<int> > myMap;
        for(int i=0;i<obstacles.size();i++){
            myMap[obstacles[i][0]].insert(obstacles[i][1]);
        }
        int maxDist=0;
        int x=0, y=0;
        int dir=0;
        vector<vector<int> > d={{0,1}, {1,0},{0,-1},{-1,0}};
        for(int i=0;i<commands.size();i++){
            dir=(commands[i]==-2)?(dir+3)%4:dir;
            dir=(commands[i]==-1)?(dir+1)%4:dir;
            int x1=x, y1=y;
            for(int k=0;k<commands[i];k++){
                x1+=d[dir][0];
                y1+=d[dir][1];
                if(myMap[x1].find(y1)!=myMap[x1].end()) break;
                x=x1;
                y=y1;
                maxDist=max(maxDist, x*x+y*y);
            }
        }
        return maxDist;
    }
};