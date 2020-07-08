# 学习笔记--并查集
## 1. 基本概念

并查集，在一些有N个元素的集合应用问题中，我们通常是在开始时让每个元素构成一个单元素的集合，然后按一定顺序将属于同一组的元素所在的集合合并，其间要反复查找一个元素在哪个集合中。    

这一类问题看似并不复杂，但数据量极大，若用正常的数据结构来描述的话，往往在空间上过大，计算机无法承受；即使在空间上勉强通过，运行的时间复杂度也极高，只能用并查集来描述。    

并查集是一种树型的数据结构，用于处理一些不相交集合（Disjoint Sets）的合并及查询问题。常常在使用中以森林来表示。

## 2. 主要操作   

**初始化：**  
把每个点所在集合初始化为其自身。
通常来说，这个步骤在每次使用该数据结构时只需要执行一次，无论何种实现方式，时间复杂度均为O(N)。  
**查找：**  
查找元素所在的集合，即根节点。   
**合并：**  
将两个元素所在的集合合并为一个集合。
通常来说，合并之前，应先判断两个元素是否属于同一集合，这可用上面的“查找”操作实现。

## 3. cpp实现
```cpp
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

    bool connected(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        return rootP == rootQ;
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
```
