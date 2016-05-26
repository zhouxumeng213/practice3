#include<stdio.h>
#include<assert.h>
#include<stack>
//题目一：输入一个链表，输出该链表中倒数第k个结点。为了符合大多数人的习惯，本题从1开始计数
//即链表的尾结点是倒数第一个结点。例如一个链表有6个结点，从头节点开始他们的值依次是1、2、3
//4、5、6.这个链表的倒数第三个结点是值为4的结点

//链表结点定义如下：
struct ListNode
{
	int data;
	ListNode* next;
};
//注意：处理空指针、k==0的情况，防止死循环
//相关题目：1、求链表的中间结点（快指针一次走两步，慢指针一次走一步）
//          2、判断一个单向链表是否带有环（快指针一次走两步，慢指针一次走一步，如果快指针追上慢指针，就说明有环）

//思路：求倒数第K个结点，正向走就是第n-k+1步，定义两个指针，快指针先走k-1步，然后慢指针再走
//两个指针刚好相差K-1步，当快指针到尾时，慢指针刚好到倒数第k个结点。
ListNode* FindNodeK(ListNode* pList, int k)
{
	assert(pList);
	if (k == 0)
		return NULL;
	ListNode* fast = pList;
	ListNode* slow = pList;
	//快指针先走k-1步
	while (k > 1 && fast != NULL)
	{
		--k;
		fast = fast->next;
	}
	//两个指针同时走
	while (fast->next != NULL)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}


//题目二：定义一个函数，输入一个链表的头结点，反转该链表并输出反转后链表的头结点。链表结点
//定义如下


//思路：因为是单向链表，没有指向前一个结点的指针，所以只能一个一个结点取，然后头插。先取头结点
//当作新链表的头结点，然后取后面的结点头插。
struct ListNode
{
	int data;
	ListNode* next;
};
ListNode* Reverse(ListNode* pList)
{
	assert(pList);
	ListNode* newHead = NULL;
	if (pList != NULL)
	{
		//取头结点当作newHead
		newHead = pList;
		ListNode* begin = pList->next;
		newHead->next = NULL;
		//头插
		while (begin != NULL)
		{
			ListNode* tmp = begin;
			begin = begin->next;
			tmp->next = newHead;
			newHead = tmp;
		}
	}
	return newHead;
}





//题目三：输入两个递增排序的链表，合并这两个链表并使新链表中的结点仍然是按照递增排序的。
//链表定义如下：

struct ListNode
{
	int data;
	ListNode* next;
};
//非递归
//注意：代码的鲁棒性，指针操作的安全性

//思路：首先比较两个链表的头结点，把小的作为新链表的头结点，然后将指向小的结点的指针后移
//再进行比较，直到链表为空
ListNode* MergeList(ListNode* pList1, ListNode* pList2)
{
	assert(pList1);
	assert(pList2);
	ListNode* pList = NULL;
	ListNode* end = NULL;
	if (pList1 == NULL)
		return pList2;
	if (pList2 == NULL)
		return pList1;
	if (pList1 == pList2)
		return pList1;
	if (pList1->data < pList2->data)
	{
		pList = pList1;
		pList1 = pList1->next;
	}
	else
	{
		pList = pList2;
		pList2 = pList2->next;
	}
	end = pList;
	while (pList1 && pList2)
	{
		ListNode* tmp;
		if (pList1->data < pList2->data)
		{
			tmp = pList1;
			pList1 = pList1->next;
		}
		else
		{
			tmp = pList2;
			pList2 = pList2->next;
		}
		end->next = tmp;
		end = tmp;
		if (pList1)
			end->next = pList1;
		if (pList2)
			end->next = pList2;
	}
	return pList;
}
//递归：
ListNode* MergeList(ListNode* pList1, ListNode* pList2)
{
	assert(pList1);
	assert(pList2);
	ListNode* pList = NULL;
	if (pList1 == NULL)
		return pList2;
	if (pList2 == NULL)
		return pList1;
	if (pList1 == pList2)
		return pList1;
	if (pList1->data < pList2->data)//判断两个链表的数据，把小的赋给新链表
	{
		pList = pList1;
		pList->next = MergeList(pList1->next, pList2);//递归判断
	}
	else
	{
		pList = pList2;
		pList = MergeList(pList1, pList2->next);
	}
	return pList;
}



//题目四：输入两棵二叉树A和B，判断B是不是A的子结构。二叉树结点的定义如下：

//注意：二叉树对指针的操作比较多，注意指针判空。
//思路：首先取B的头结点和A的头结点进行比较，如果相同，则比较头结点的左右节点，如果不
//相等，取A的左孩子作为头结点，再进行比较
struct BinaryTreeNode
{
	int data;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
};
bool JudgeChild(BinaryTreeNode* tree1, BinaryTreeNode* tree2)
{
	if (tree1 == NULL)
		return false;
	if (tree2 == NULL)
		return true;
	if (tree1->data != tree2->data)
		return false;
	return JudgeChild(tree1->left, tree2->left) && JudgeChild(tree1->right, tree2->right);
}
bool IsChildTree(BinaryTreeNode* tree1, BinaryTreeNode* tree2)
{
	bool result = false;
	assert(tree1);
	assert(tree2);
	if (tree1 != NULL && tree2 != NULL)
	{
		if (tree1->data == tree2->data)//如果结点相等，调用JudgeChild进行子节点的判断
			result = JudgeChild(tree1, tree2);
		if (!result)//递归判断左孩子
			result = IsChildTree(tree1->left, tree2);
		if (!result)//递归判断右孩子
			result = IsChildTree(tree1->right, tree2);
	}
	return result;
}

//题目五：请完成一个函数，输入一个二叉树，该函数输出她的镜像
//二叉树的结点定义如下：

//思路：求树的镜像的过程就是遍历树的同时交换非叶子结点的左右结点。
struct BinaryTreeNode
{
	int data;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
};
void TreeImage(BinaryTreeNode* tree)
{
	assert(tree);
	if (tree->left == NULL && tree->right == NULL)
		return;
	//交换左右节点
	BinaryTreeNode* tmp = tree->left;
	tree->left = tree->right;
	tree->right = tmp;

	//递归判断左孩子
	if (tree->left)
		TreeImage(tree->left);
	//递归判断右孩子
	if (tree->right)
		TreeImage(tree->right);
}


//题目六：输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。例如输入以下矩阵：
//1    2   3   4
//5    6   7   8
//9   10  11  12
//13  14  15  16
//则一次打印出数字1、2、3、4、8、12、16、15、14、13、9、5、6、7、11、10

//思路：将每一圈的打印分为四步：一、从左到右打印一行；二、从上到下打印一列；三、从右到左
//打印一行；四、从下到上打印一列。但要注意打印每一步的前提条件

void PrintCircle(int matrix[][4], int rows, int clos, int start)
{
	assert(matrix);
	int endX = clos - 1 - start;
	int endY = rows - 1 - start;
	//从左往右打印一行
	for (int i = start; i <= endX; i++)
	{
		int num = matrix[start][i];
		printf("%d ", num);
	}
	//从上到下打印一列
	if (start < endY)//大于一行
	{
		for (int i = start + 1; i <= endX; i++)
		{
			int num = matrix[i][endX];
			printf("%d ", num);
		}
	}
	//从右往左打印一行
	if (start < endX && start < endY)
	{
		for (int i = endX - 1; i >= start; i--)
		{
			int num = matrix[endY][i];
			printf("%d ", num);
		}
	}
	//从下到上打印一列
	if (start < endX && start < endY - 1)//至少三行,至少两列
	{
		for (int i = endY - 1; i >start; i--)
		{
			int num = matrix[i][start];
			printf("%d ", num);
		}
	}
}
void PrintMatrix(int matrix[][4], int rows, int clos)
{
	assert(matrix);
	if (rows <= 0 || clos <= 0)
		return;
	int start = 0;
	while (rows>start * 2 && clos>start * 2)
	{
		PrintCircle(matrix, rows, clos, start);
		start++;
	}
}
int main()
{
	int matrix[4][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 } };
	PrintMatrix(matrix, 4, 4);
	return 0;
}


//题目七：定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的min函数。在该栈中，
//调用min、push及pop的时间复杂度都是O(1)。

//思想：借助一个辅助栈，，总是将最小的数push进辅助栈,就可以保证辅助栈的栈顶一直都是最小元素

template <typename T> class stack
{
public:
	void push(const T& val)
	{
		stack.push(val);
		if (minStack.size() < 0 || val < minStack.top())
			minStack.push(val);
		else
			minStack.push(minStack.top());
	}
	void pop()
	{
		assert(stack.size());
		assert(minStack.size());
		stack.pop();
		minStack.pop();
	}
	T& min()
	{
		assert(stack.size());
		assert(minStack.size());
		return minStack.top();
	}
private:
	std::stack<int> stack;
	std::stack<int> minStack;
};
