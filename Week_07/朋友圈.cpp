class UionFind{
private:
    int count;     // 连通分量个数
    int* parent;   // 存储树数组指针
    int* size;     // 记录树的重量数组指针
public:
    UionFind(int n){
        this->count=n;
        parent=new int[n];
        size=new int[n];
        for(int i=0;i<n;i++){
            parent[i]=i;
            size[i]=1;
        }       
    }
    ~UionFind(){
        delete [] parent;
        delete [] size;
    }

    int find(int x){
        // 路径压缩，思想很巧妙！
        while(parent[x]!=x){
            parent[x]=parent[parent[x]];
            x=parent[x];
        }
        return x;
    }

    void Union(int p, int q){
        int rootp=find(p);
        int rootq=find(q);
        if(rootp==rootq) return;
        
        // 小树合并到大树下，维持树的平衡
        if(size[rootp]>size[rootq]){
            parent[rootq]=rootp;
            size[rootp]+=size[rootq];
        }else{
            parent[rootp]=rootq;
            size[rootq]+=size[rootp];
        }

        count--;  // 每次的合并，意味着连通分量减一
    }

    int Count(){
        return count;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n=M.size();
        UionFind uf(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(M[i][j]==1) uf.Union(i, j);
            }
        }
        return uf.Count();
    }
};