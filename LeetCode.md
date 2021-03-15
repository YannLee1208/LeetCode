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



### 237 Delete Node 

* 问题
  * 给定一个节点，删除该节点
  * **此处给定的是节点，而不是值，因此不能像之前那样遍历找到对应的前一个节点来删除**
* 思路
  * **此处只能使用修改node的值了**
    * 将下一个node的值赋值给该node，然后delete下一个node即可













### 328 Odd Even LinkedList





### 445 Add 2 Nums 2





















## 栈/队列

### 技巧

* 递归模拟系统栈
  * 参考 BST的遍历 Q94 Q144 Q145
* 

### Q20 Valid Parentheses

* 问题描述
  * 括号匹配, 只考虑 {,  [,  (  6种字符
* 思路
  * 使用stack，如果为左边的则push，不是的话就pop
  * **注意，size遍历完一遍以后，要判断一下stack是否为empty，因为有可能左边太多了，右边可能只有一个，也是会跳出循环的**





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



### Q341 Flattern Nested









