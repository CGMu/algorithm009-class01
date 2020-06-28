# 学习笔记-LeetCode303.区域和检索-数组不可变    

### 解题思路   

1. 暴力，通过   

2. 哈希，时间超出限制    

3. 前缀和，最优解   


### 代码

```cpp
 class numarray {
 // 1. 暴力法，时间复杂度高
 public:
     vector<int> data;
 public:
     numarray(vector<int>& nums) {
         data=nums;
     }

     int sumrange(int i, int j) {
         int sum=0;
         for(int k=i;k<=j;k++) sum+=data[k];
         return sum;
     }
 };

 class NumArray {
 // 2. Hash缓存（超出时间限制）
 public:
     map<tuple<int, int>, int> myMap;
 public:
     NumArray(vector<int>& nums) {
         for(int i=0;i<nums.size();i++){
             int sum=0;
             for(int j=i;j<nums.size();j++){
                 sum+=nums[j];
                 tuple<int, int> pair(i, j);
                 myMap[pair]=sum;
             }

         }
     }
  
     int sumRange(int i, int j) {
         tuple<int, int> pair(i, j);
         return myMap[pair];
     }
 };


class NumArray {
// 3. 一维前缀和
public:
    int* sum;
public:
    NumArray(vector<int>& nums) {
        sum=new int[nums.size()+1];
        for(int i=0;i<nums.size();i++){
            sum[i+1]=sum[i]+nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        return sum[j+1]-sum[i];
    }
};


/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
```