# Graph相关



## FloodFill

### 200 岛屿数量



### 695岛屿面积

* 题目描述

  给定一个0和1的二维数组，岛屿是由四个方向的1（土地）构成的组合，(必须水平或者竖直连接起来的)，求最大岛屿面积

* 思路

  转换为求 **连通图中最多有多少个顶点**

* 方法1: trick

  * 把二维数组映射成一维 (n, m) -> n*len + m
  * 四连通
    * 建立 directions = [[-1, 0], [0, 1], [1, 0], [0, -1]]
  * 转换为图后，使用dfs且dfs有int的返回值

* 方法2:

  不转换为1维的邻接表，直接在grid上dfs

  



### 1020飞地数量



### 130被围绕的区域



### 733图像渲染



### 1034边框着色



### 827最大人工岛屿







## 搜索BFS/DFS

### 785二分图

 Is Graph Bipartite?

* 思路：使用遍历（dfs/bfs），进行染色

  w : adj(v)

  * 如果 !visited[w] 则继续dfs(w, 1-color)
  * 否则，判断colors[w] == colors[v] 如果相等则错误



### 1091二进制矩阵最短路径

* 题目：

  给定一个n*n的数组，0代表空旷，1代表堵塞，

  八联通（可以斜着走），返回最短路径的长度

* 思路
  * 无权图的最短路径：BFS





### 752打开转盘锁

* 题目

  一把4位的转盘锁，每一位从0到9，每次转动一位，且只能按0-9这样正反变换（从0可到9，从9可到0）

  给出一组deadends是不能转到的，求从初始状态最少转多少次可以到target，如果不行则返回-1

* 思路

  * **状态转移**：某些状态之间可以转移，则认为有边相连，每个状态就是顶点
  * 无权图的最短路径 -> BFS

* trick

  * 因为每次要检查s是否在deadends中，因此为了避免线性查找-》Hashset存储deadends
  * visited使用hashset存储，便于查找, 因为此时是string了
    * 又因为要存储到初始点的距离，因此直接使用HashMap来同时记录visited和distance
    * 如果有这个数据则代表访问过
  * 状态转移部分

  ```java
  ArrayList<String> nexts = new ArrayList<>();
  for (int i = 0; i < 4; i++) {
    char o = curarray[i];
    curarray[i] = Character.forDigit((curarray[i] - '0' + 1) % 10, 10);
    nexts.add(new String(curarray));
    curarray[i] = o;
  
    curarray[i] = Character.forDigit((curarray[i] - '0' + 9) % 10, 10);
    nexts.add(new String(curarray));
  
    curarray[i] = o;
  }
  ```



### 装水问题

* 问题

  两个无刻度的水桶，一个能装5升水，一个3升，怎么得到4升水

* 思路

  * 状态转移（x, y）能变成
    * (5, y), (x, 3)
    * (0, y), (x, 0)
    * 把x的水倒向y或者y倒向x
  * 最终变成 (4, ?) 
  * 无权图最短路径 **BFS**

* trick

  * 10 * x + y代表 (x, y) 因此x,y 都小于10

  * 状态转移部分

    ```java
    ArrayList<Integer> nexts = new ArrayList<>();
    nexts.add(5 * 10 + b);
    nexts.add(a * 10 + 3);
    
    nexts.add(a * 10);
    nexts.add(b);
    
    // 这步很细
    int x = Math.min(a, 3 - b);
    nexts.add((a - x ) * 10 + ( b + x));
    int y = Math.min(5 - a, b);
    nexts.add((a + y) * 10 + (b - y));
    
    ```

  * 使用pre数组记录路径



### 773滑动谜题

* 题目

  2x3的板上有5块瓦 1-5表示，一块空缺用0表示，一次移动定义为0和一个相邻的数组交换，需要最终结果为[[1, 2, 3], [4, 5, 0]]， 求最少多少次能够做到，不能则返回-1

* 思路：

  * 如何表达状态
    * 6位数
    * 字符串
  * BFS找最短路径

  





## 哈密尔顿路径



### 980不同路径III

* 题目：

  * grid中，1为起始方格且只有一个，2表示结束方格，0表示可以走过的空方格，-1表示无法走的障碍

    返回从起始到结束的不同路径的数目，**每个无障碍方格都要走一次**

* 思路

  * 使用dfs + 回溯
  * 使用left变量记录访问了多少节点

* trick

  * 对于起始点1和终止点2，记录后赋值为0

  * 面对终止条件 left == 0时，不要忘记回溯

  * visited 使用状态压缩，使用一个int表示

  * 

    





