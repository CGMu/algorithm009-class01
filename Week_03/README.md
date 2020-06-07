# 学习笔记
## 递归  
递归算法的实质是是把问题分解成规模缩小的同类问题的子问题，然后递归调用方法来表示问题的解。  
<p> 递归模板（python）：   

    def recursion(level, param1, param2,...):  
        # 递归终止条件  
        if level>Max_level:
            process_result
            return
        # 处理当前层
        process(level, data)
        # 下探至下一层
        self.recursion(level+1, p1, p2,...)
        # 如果需要，保存本层状态
        example:process_global  

<p> 写递归时，三个思维：   

1. 不要进行人肉递归（最大误区）
2. 找到最近最简方法，将其拆解成可重复解决的子问题
3. 数学归纳法思维


<p> 递归缺点：       

1. 递归调用，占用栈空间大
2. 递归深度大，导致栈溢出
3. 存在重复计算，指数级时间复杂度


## 分治
把一个复杂的问题不断分成更多的相同或相似的子问题，直到最后子问题可以简单的直接求解，原问题的解即子问题的解的合并。   

<p> 分治模板：（python）    
    
    def divide_conqure(problem, p1, p2, ...):
        # 递归终止条件
        if problem is None:
            process_result
            return
        # 准备数据
        data=prepare_data(problem)
        subProblems=split_problem(problem, data)
        # 解决子问题
        subResult1=self.divide_conqure(subProblems[0], p1,...)
        subResult2=self.divide_conqure(subProblems[1], p1,...)
        ...
        # 处理和生成最终结果
        result=process_result(subResult1, subResult2)
        # 保存本层状态
        example:process_global

## 回溯
回溯法也称试探法，基本思想是：从问题的某一种状态（初始状态）出发，搜索从这种状态出发所能达到的所有“状态”，当一条路走到“尽头”的时候（不能再前进），再后退一步或若干步，从另一种可能“状态”出发，继续搜索，直到所有的“路径”（状态）都试探过。这种不断“前进”、不断“回溯”寻找解的方法，称作“回溯法”。


递归实现：
1. 找到一个可能存在的正确答案
2. 尝试所有可能分布方法后，宣布问题没有答案
3. 本质是穷举法，指数级时间复杂度 



