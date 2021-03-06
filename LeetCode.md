## LinkedList

### 技巧

* 设立 dummy head
  * Q203 删除元素
  * **当头节点可能也要进行操作，而cur节点是要操作节点前一个时**
  
* 双指针技术

  * Q19

  * **从后的第n个元素操作时，可以用一个长度固定为n/n+1的双指针进行移动，直到后一个指针指向null**




### 2. Add 2 Numbers





### 19 Remove Nth Node From end

* 问题

  * 给定链表，删除倒数第n个节点

* 思路

  1. 暴力

     * 遍历一边统计长度
     * 第二遍遍历找到待删除的前一个节点

  2. **双指针**

     * 既然是倒着的第n个，那只要使用一个 **相隔距离为n+1的双指针，当后一个指针指向null时，代表前一个指针指向了待删除的前一个节点**

     * 注意使用 dummyHead

       

### 

### 21 Merge LinkedList





### 24 Swap Nodes

* 问题
  * 给定链表，对于每两个相邻节点，交换位置
* 思路
  * **类似滑动窗口，只是此处窗口大小固定为2**
  * **设立dummyHead，因为每次交换需要这对节点的前一个节点，和这对节点**





### 25 Reverse in K



### 61 Rotate List



### 82 Remove Duplicates 2





### 83 Remove Duplicates





### 86 Partition List



### 92. Reverse2

* 问题表述

  * 反转一个链表从m到n的节点

* 思路

  * **因为这里首先要找到第m个节点，而找到了以后就跟从头开始reverse一样了，即 m == 1的情况**

  * **考虑递归**

    * ListNode* reverseN(ListNode* head, int n)
    * **reverse从head开始的n个节点**
    * reverseN内部仍然递归

  * **问题**

    * 最终head需要连接的下一个节点丢失了，即第n+1（如果存在) 个节点
    * **用一个succesor成员变量存储，在n==1时赋值**


### 143 Reorder List



### 148 Sort List

* 问题

  * 对链表排序 要求：` O(nlogn)` time and `O(1)` memory

* 思路

  * `O(nlogn)` ：mergeSort or quickSort or heapSort
  * `O(1)`memory : mergeSort.  快排因为递归，空间复杂度为 `O(logn)` ， 而堆排序需要一个新的数组 `O(n)`
  * **mergeSort**
    * 

  

### 203 Remove Elements

* 问题描述
  * 删除链表的元素
* 思路
  * 使用一个cur节点，**其下一个节点代表待删除节点，**当找到待删除元素后，执行 `cur->next = cur->next->next` 再删除节点
  * 如果待删除是最后一个节点 仍然适用
  * **如果是第一个节点则出问题，因为之前没有节点 -》 使用dummy head**



### 206. Reverse

* 问题描述
  
  * 反转链表
  
* 思路

  * 设计三个指针 pre, cur, next 

    * pre: head
    * cur: head->next;
    * next: cur->next

  * 每一轮

    * ```c++
       while (next != nullptr){
                  cur->next = pre;
                  pre = cur;
                  cur = next;
                  next = next->next;
              }
      ```

    * **最终还要 cur -> next = pre， 考虑只有两个的情况**

  * 优化

    * pre指向null, cur: head, next: next
    * 此时改为判断cur是否为null
    * 更少的代码行数



### 234 Palindrome LinkedList

* 问题
  * 判断一个LinkedList是否为 Palindrome
* 思路
  1. 遍历一遍统计length，然后使用stack 
  2. **利用string，判断reverse(string) == string**





### 237 Delete Node 

* 问题
  * 给定一个节点，删除该节点
  * **此处给定的是节点，而不是值，因此不能像之前那样遍历找到对应的前一个节点来删除**
* 思路
  * **此处只能使用修改node的值了**
    * 将下一个node的值赋值给该node，然后delete下一个node即可





### 328 Odd Even LinkedList

* 问题描述

  * 链表偶节点在前，奇节点在后面

* 思路

  * 设立两个指针oddCur 和 evenCur

  * ```c++
     while (evenCur != nullptr) {
                if (evenCur->next == nullptr) {
                    break;
                } else {
                    oddCur->next = evenCur->next;
                    oddCur = oddCur->next;
                    evenCur->next = oddCur->next;
                    evenCur = evenCur->next;
               }
           }
       	oddCur->next = evenHead;
     ```
  
  



### 445 Add 2 Nums 2









## 栈/队列

### 技巧

* 递归模拟系统**栈**
  
  * 参考 BST的遍历 Q94 Q144 Q145
  
* **队列实现 广度优先遍历**
  
  * Q102 
  * **广度优先遍历可以每层单独遍历** Q199
    * 每次记录size
    * 然后for size 取出，并push进下一层，结束即遍历了这一层
  
* 队列实现 **图的最短路径**

  * 把一个问题建模为图 Q279

  * **注意图的广度优先遍历/最短路径，要设置一个visited数组，因为树可以避免重复访问，而图不行**

    

### Q20 Valid Parentheses

* 问题描述
  * 括号匹配, 只考虑 {,  [,  (  6种字符
* 思路
  * 使用stack，如果为左边的则push，不是的话就pop
  * **注意，size遍历完一遍以后，要判断一下stack是否为empty，因为有可能左边太多了，右边可能只有一个，也是会跳出循环的**



### Q23 Merge k sortedLisit





### Q71 Simplify Path

* 问题描述

  * 简化给定的绝对路径
    * ".." -> 上一层路径
    * "." -> 当前路径
    * "..." -> 文件名
    * 无论几个 “/” 都代表一个 "/"

* 思路

  * 看到 “/” 就跳过

  * 读取真正的文件名

    * "." continue
    * ".." -> **stack中pop一个**
    * 其他情况为文件名，放进一个 **stack中**
      * 因为此处考虑到 ".." ， 需要经常取出上一个放进去的，所以要FIFO

    



### Q94 BST Inorder

* 问题

  * 二叉树中序遍历

* 思路

  * 使用栈 **模拟系统，实际执行与推入顺序相反**

    * 推入右子树
    * 推入打印
    * 推入左子树

  * ```c++
    if(node->right)
      stack.push(make_pair(node->right, false));
    stack.push(make_pair(node, true));   
    if(node->left)
      stack.push(make_pair(node->left, false));  
    ```



### Q102 BST Level Order

* 问题

  * 层序遍历，同时要按层打印

* 思路

  * 层序遍历 -》队列

  * 需要level信息 -〉 queue中放入pair\<TreeNode*, int>

    



### Q103 BST Zigzag level order 





### Q107 BST Level Order 2

* 问题描述
  * 从最后一层向上的层序遍历，并且返回 vector\<vector\<int>> 每个分别为每一层
* 思路
  1. 从上向下，再reverse一下
  2. 从上向下，将每层的vector放入一个stack中，最后再从stack中pop



### Q127 Word Ladder

* 问题描述
  * 给定beginword和endword，和一个wordlist数组，找出来一条从beginword到endword的路径，求最小路径长度
* 思路
  * **图的最短路径问题**
    * 如何构建图？
      * 构建邻接表 unordered_map \<string, vector\<string>>，使用一个 '*' 作为过渡
      * "hit" 相邻的有 "*it", "h\*t" , "hi\*"， 而"\*it"相邻添加上 "hit"
    * BFS
      * queue 存储 string和step
      * 因为此处添加了一层 "*it" 作为过渡层，所以当真正找到时，返回的step是 step / 2 + 1. 因为beginword就是endword时算1步





###  Q144 BST Preorder

* 问题

  * 二叉树前序遍历

* 思路

  * 使用栈 **实际执行与推入顺序相反**

    * 推入右子树
    * 推入左子树
    * 推入打印

  * ```C++
    class Solution {
    public:
        vector<int> preorderTraversal(TreeNode* root) {
             vector<int> res;
            if(root == nullptr)
                return res;
    
            // pair中的 bool false代表go命令， true代表print命令
            stack<pair<TreeNode*, bool> > stack;
    
            stack.push(make_pair(root, false));
            while(!stack.empty()){
                auto node = stack.top().first;
                auto if_print = stack.top().second;
                stack.pop();
    
                if(if_print)
                    res.push_back(node->val);
                else{            
                    if(node->right)
                        stack.push(make_pair(node->right, false));
                    if(node->left)
                        stack.push(make_pair(node->left, false));
                     stack.push(make_pair(node, true));          
                }
            }
            return res;
        }
    };
    ```

    

  

  

###  Q145 BST Postorder

* 问题

  * 二叉树后序遍历

* 思路

  * 使用栈 **实际执行与推入顺序相反**

    * 推入打印
    * 推入右子树
    * 推入左子树

  * ```c++
    stack.push(make_pair(node, true));    
    if(node->right)
      stack.push(make_pair(node->right, false));
    if(node->left)
      stack.push(make_pair(node->left, false));   
    ```

    



### Q150 Reverse Polish 

* 问题描述

  * 求解逆波兰表达式的值

  * ```
    Input: tokens = ["4","13","5","/","+"]
    Output: 6
    Explanation: (4 + (13 / 5)) = 6
    ```

* 思路
  * 使用stack，因为这里是后进去的先算
  * 遇到数字放进去，遇到符号取出两个
    * **注意，是n2 / n1 第二个取出来的 / 第一个取出来的**



### Q199 BST Right Side view 

* 问题描述
  * 站在一个BST的右侧看，按顺序打印出所有的节点
* 思路
  * 因为是DFS，所以使用队列
  * **使用队列的每层单独遍历，每次记录q的size，然后for size并push，即遍历了每一层**



### Q279 Perfect Squares

* 问题描述

  * 给出一个正整数n，寻找最少的完全平方数，使其和为n
  * 13 = 4 + 9

* 思路

  1. 贪心算法
     * 每次尝试用最大的数
     * 不成立，因为 12 = 9 + 1 + 1 + 1, 12 = 4 + 4 + 4
  2. 图论建模
     * 每个数代表一个节点，如果差值为完全平方数，则相邻
     * 找出最短路径
     * **参照图的最短路径，设置一个pair\<num, step>**
       * 每次将 num - i * i 和 step + 1推入queue
     * **设立visited数组避免重复访问**

  



### Q341 Flattern Nested

* 问题描述
  * 摊平一个数组 [1,[4,[6]]] 打印  [1,4,6]
  * 实现一个iterator类
* 思路
  * 此处类似于DFS
    * 每次尽可能走得深
    * **因为此处要在构造函数里面初始化，而构造函数不能调用递归，因此设计一个helper函数实现递归**
    * **设计一个全局的queue，或者每次引用传递即可**



### Q347 TopK frequency

* 问题描述
  * 找出前k个出现频率最高的元素
* 思路
  * 扫描一遍统计频率，找出前k个出现
    * O(nlogn) 花在排序
  * 含有k个元素的优先队列。如果遍历到的比队列中最小频率高，则取出并入队
    * O(nlog(k)) 





## Recursive



### 技巧

* 递归的内容
  1. 终止条件
  2. 递归过程



### Q100 Same Tree

* 问题描述
  * 判断两颗二叉树是否相等
* 思路
  * 递归
  * 判断当前节点val是否相等（要判断是否为空），再判断左子树，右子树





### Q101 Symmetric Tree

* 问题
  * 判断一棵树是否镜像对称
* 思路
  * 递归
    * 类似于Q100，设立一个helper子函数，判断两个节点值相等
    * `return l->val == r->val && helper(l->right, r->left) && helper(l->left, r>right);`





### Q104 Max Depth of BST

* 问题描述
  * 求二叉树的最大深度
* 思路
  * 使用递归，返回左右子树的max depth的max + 1





### Q110 Balanced Binary Tree

* 问题描述
  * 判断是否为平衡树，即左右子树的高度差不超过1
* 思路
  * 递归求解左右子树的高度



### Q111 Minimum Depth of Binary Tree

* 问题描述
  * 求二叉树的最低深度
  * **最小深度是从根节点到 叶子节点 的最小距离**
* 思路
  * **与104求最大深度的区别**
    * 最大深度时不需要考虑只有单边的问题，即另一边实际上并不是一个深度，因为不是叶子节点
    * **最小深度需要判断是否是叶子节点**
  * **终止条件改变**
    * 分别获得 ldepth 和 rdepth，如果为0代表是nullptr而不是叶子节点，则返回另一个 + 1



### Q112 Path Sum

* 问题描述

  * 求解在一个二叉树上是否存在一个从 **根到叶子节点** 的路径，和为sum

* 思路

  1. ```c++
     if ( root == nullptr)
       return sum == 0;
     
     if ( hasPath(root->left, sum - root->val))
       return true;
     
     if (hasPath(root->right, sum - root->val)
         return true;
     return false
     ```

     * **终止条件错误，这样的话不是到叶子节点的也可能对，比如root就等于sum**
     * **root == nullptre 这个终止条件忽视了父亲节点是否为叶子节点**

  2. ```c++
     if ( root == nullptr)
       return false;
     
     if (root->left == nullptr && root->right == nullptr)
       return root->val == sum;
     
     if ( hasPath(root->left, sum - root->val))
       return true;
     
     if (hasPath(root->right, sum - root->val)
         return true;
     return false
     ```

     * 这样终止条件改为了root的左右孩子都为空





### Q113 Path Sum2

* 问题描述
  * 求解从 **根到叶子节点** 的**路径**，和为sum





### Q129 Sum Root to Leaf Nums

* 问题描述
  * 从根节点到叶子节点的每条路径表示成一个数，求数的和



### Q222 Count Complete Tree Nodes





### Q226 Invert  BT

Max Howell : **Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so fuck off.**

* 问题描述
  * 反转一颗二叉树
* 思路
  * 分别翻转左右子树
  * 然后再交换（swap）左右子树的值（指针）



### Q257 Binary Tree Paths

* 问题描述
  * 给定一颗二叉树，返回所有表示从根节点到叶子节点路径的字符串
* 思路
  * 递归，在左子树的路径和右子树的路径中分别加上根节点





### Q404 Sum of left leaves





### Q437 Path Sum3

* 问题描述
  * 判断二叉树存在 **多少条路径使和为sum, 不需要从根节点到叶子节点**

* 思路

  * 与之前递归的区别

    * 在一个节点上，要分两种情况
      1. 包含该节点，则在左右节点分别找 sum - node->val
      2. 不包含，在左右节点分别找 sum 

  * 双重递归

    * 一个递归函数处理包含 node的情况
    * 在另一个主递归函数中，分为包含和不包含

  * **为什么不能用单个递归？**

    * 因为必须要区分开 包含和不包含的情况，否则**可能出现一个包含，下一个不包含，下一个又包含的情况，而使用两个递归分别处理的话，findPath单独处理了包含的，而主递归函数实际上是在处理不包含的**








## 动态规划

* 斐波那契数列
  * f(n) = f(n-1) + f(n-2)
  * 使用递归的话，有多次重复计算
  * 设置一个memo数组，记录 f(i) **记忆化搜索**

### 技巧

* 递归与DP	

  * 递归 + 记忆化搜索

    * 自上而下解决问题
    * **重叠子问题 且 最优子结构**
      * 记忆化搜索 ： 自顶向下
      * 动态规划：自底向上

  * 动态规划 

    * 自下而上解决问题

    * ```
      for i:
      	memo[i] = memo[i-1] + memo[i-2];
      ```

  * 先把递归的树一下，从上到下，看一下下面最后都是到一样的问题
  * **通过求子问题的解，能够构建出原问题的解**



### Q62 Unique Paths

* 问题

  * 机器人从左上角，每次只有向右或者向下，求走到右下角有多少条路径

* 思路

  * dp

    * 左上角开始，先把第一行和第一列填为1

    * 然后 dp\[level][index] = dp\[level-1][index] + dp]\[level][index - 1]

      



### Q63 Unique Paths 2

* 问题

  * 在62的基础上，路径上可能有 obstacle

* 思路

  * dp

    * 左上角开始，先把第一行和第一列填充

      * **技巧**

      * ```c++
        for (int i = 1; i < m; ++i) {
                    if (obs[i][0])
                        dp[i][0] = 0;
                    else
                        dp[i][0] = dp[i-1][0];
                }
        ```

    * 然后 判断 obs该处是否为1，不是则 dp\[level][index] = dp\[level-1][index] + dp]\[level][index - 1]





### Q64 Minimum Path Sum

* 问题
  * 给出m * n 的矩阵，寻找一条左上到右下的路径，**每一个为非负整数**，使得沿路的数字和最小
  * 每一步只能左移或者下移
* 



### Q70 Climbing Stairs

* 问题
  * 一个楼梯总共有n级台阶。每次可以上一个台阶，也可以两个，求爬上一共有多少方法
* 思路
  1. 递归
     * f(n) = f(n - 1) + f(n - 2)
  2. 动态规划
     * 自底向上 



### Q91 Decode Ways

* 问题描述
  * 给定一个字符串包含A-Z的字母，每一个字符可以和1-26数字对应，给出一个数字字符串，有多少种方法可以解析数字字符串
  * 12 ： AB或L 返回2
* 思路



### Q120 Triangle

* 问题
  * 找一个triangle从上到下最小的和, 上一行为index i，则下一行index 只能为 i或 i + 1
* 思路
  * 动态规划 
    * 使用一个 `vector<vector<int> > dp` ： **到第(i, j) 位置的最短路径**
    * dp\[i][j] = min (dp\[i-1][j-1],  dp\[i-1][j] ) + triangle\[i][j] 
    * 对于 j = 0 和 j = 当前层最后一个要特殊处理



### Q279 Perfect Squares

* 问题

  * 给定一个数n，寻找最少的完全平方数和为n

* 思路

  * 从头开始设立一个 `vector<int>(n + 1, INT_MAX)`

  * ```c++
    for (int i = 2 ; i < n + 1; ++i) {
                for (int j = 1; i - j * j >= 0 ; ++j) {
                    dp[i] = min(1 + dp[i - j * j], dp[i]);
        }
    }
    ```

    



### Q343 Integer Break

* 问题

  * 给定一个正整数n，把其分割为多个数字的和，使其乘积最大，求分割方案。至少分成两个数，返回最大乘积

* 思路

  * 递归 + 记忆化搜索

    * ```c++
       for (int i = 1; i <= n - 1; ++i) {
                  // 一定要注意此处 因为breakInteger是必须分成两部分的
                  res = max(res, max (i * breakInteger(n - i), i * (n - i)) );
       }
      ```

  * DP

    * ```c++
      for (int i = 2 ; i <= n; ++i) {
        	for (int j = 1; j <= i - 1 ; ++j) {
            	memo[i] = max(memo[i], max(j * (i - j), j * memo[i - j]));
          }
      }
      ```

      



