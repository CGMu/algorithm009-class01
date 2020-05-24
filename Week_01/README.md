# 学习笔记
**1. 第一周学习内容总结**  
	**数组（Array）**：连续内存空间存储数据，因此支持随机访问和缓存加载，访问时间O(1)，查找时间O(n),插入和删除由于数据搬移时间复杂度O(n)；当元素个数超过容量时，需要重新开辟内存新的更大内存，并将之前数据全部拷贝到新申请的内存中。  
	**链表（Linked List）**：不需要连续内存空间，每个结点需要存储指向下一结点的指针，常见的链表有单链表，双链表(结点同时存储指向前后结点的指针)，循环链表(尾结点指向头结点)；访问和查找时间O(n)，删除和插入时间O(1)。  
    **跳表（Skip List）**：空间换时间思想，对有序链表通过增加索引维度，提升查询效率。在链表基础上增加多级索引查找时间复杂度降为O(logN)，插入删除时间复杂度退化为O(logN)。需要额外的空间存储多级索引，空间复杂度为O(n)。  
	**栈（Stack）**：先入后出的数据结构，访问和查询时间复杂度为O(n)，插入和删除操作时间复杂度为O(1)。  
	**队列（Queue）**：先入先出，查询时间复杂度为O(n)，插入和删除操作时间复杂度为O(1)。  
	**双端队列（Deque）**：支持两端插入和删除操作，查询时间复杂度为O(n)，插入和删除操作时间复杂度为O(1)。  
	**优先级队列（Priority Queue）**：队列元素增加优先级设置，插入和取出操作时间复杂度不唯一，取决于底层具体实现，常见实现方式有heap，bst，treap。    

**2. 用add first或add last这套新的API改写Deque的代码**

	import java.util.Deque;
	import java.util.LinkedList;
	class test  
	{
		public static void main (String[] args)  
		{
			Deque<String> deque=new LinkedList<String>();
			deque.addFirst("a");  
			deque.addFirst("b");  
			deque.addFirst("c");  
			System.out.println(deque);
			
			String str=deque.peek();
			System.out.println(str);
			System.out.println(deque);
			
			while(deque.size()>0){
				System.out.println(deque.pop());
			}
			
			System.out.println(deque);
		}
	}  
打印结果：  

	[c, b, a]  
	c  
	[c, b, a]  
	c  
	b  
	a  
	[]  

**3. 分析Queue和Priority Queue的源码**  
**3.1 Queue**

	三个私有属性，分别表征队列首尾节点，队列元素个数  
	private int n;         // number of elements on queue  
    private Node first;    // beginning of queue  
    private Node last;     // end of queue  

	isEmpty(): 判断队列元素是否为空  
	public boolean isEmpty() {  
        return first == null;  
    }  

    size(): 返回当前列表中元素个数  
    public int size() {  
        return n;  
    }  

    length(): 返回当前列表中元素个数  
	public int length() {  
        return n;  
    }  

	peek(): 返回队列中第一个元素，队列为空时，抛出异常  
	public Item peek() {  
        if (isEmpty()) throw new NoSuchElementException("Queue underflow");  
        return first.item;  
    }  

	enqueue(): 入队操作，创建新的节点置于队列最后，让旧的末尾节点指向新节点，同时队列元素个数自增1  
	public void enqueue(Item item) {  
        Node oldlast = last;  
        last = new Node();  
        last.item = item;  
        last.next = null;  
        if (isEmpty()) first = last;  
        else oldlast.next = last;  
        n++;  
    }  

	dequeue(): 出队操作，队列为空时抛出异常，否则，first指针后移，指向队列首元素，队列元素个数自减1  
	public Item dequeue() {  
        if (isEmpty()) throw new NoSuchElementException("Queue underflow");  
        Item item = first.item;  
        first = first.next;  
        n--;  
        if (isEmpty()) last = null;   // to avoid loitering  
        return item;  
    }  

**3.2 Priority Queue**

    offer(): 新增操作，不允许插入空对象，插入新元素后，重新排序以维持堆的特性  
	public boolean offer(E o)  
	{
		if (o == null)  
		throw new NullPointerException();  

		int slot = findSlot(-1);  

		storage[slot] = o;  
		++used;  
		bubbleUp(slot);  

		return true;  
	}  

    peek(): 查看队列首元素，队列为空时，返回null
	public E peek()
	{
		return used == 0 ? null : storage[0];
	}

	poll(): 返回并且删除队列首元素，队列为空时，返回null
	public E poll()
	{
		if (used == 0)
		return null;
		E result = storage[0];
		remove(0);
		return result;
	}

    remove(Object o): 删除队列中指定元素，找不到直接返回false，否则返回true
	public boolean remove(Object o)
	{
		if (o != null)
		{
		for (int i = 0; i < storage.length; ++i)
		{
			if (o.equals(storage[i]))
			{
			remove(i);
			return true;
			}
		}
		}
		return false;
	}

    remove(int index): 删除队列中指定下标元素，为维持堆的特性，找到最小子节点占据index所在位置  
	同时，队列的使用元素个数自减1
	void remove(int index)
	{
		// Remove the element at INDEX.  We do this by finding the least
		// child and moving it into place, then iterating until we reach
		// the bottom of the tree.
		while (storage[index] != null)
		{
			int child = 2 * index + 1;

			// See if we went off the end.
			if (child >= storage.length)
			{
				storage[index] = null;
				break;
			}

			// Find which child we want to promote.  If one is not null,
			// we pick it.  If both are null, it doesn't matter, we're
			// about to leave.  If neither is null, pick the lesser.
			if (child + 1 >= storage.length || storage[child + 1] == null)
			{
				// Nothing.
			}
			else if (storage[child] == null
				|| (Collections.compare(storage[child], storage[child + 1],
							comparator) > 0))
			++child;
			storage[index] = storage[child];
			index = child;
		}
		--used;
	}