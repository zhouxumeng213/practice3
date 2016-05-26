#include<stdio.h>
#include<assert.h>
#include<stack>
//��Ŀһ������һ����������������е�����k����㡣Ϊ�˷��ϴ�����˵�ϰ�ߣ������1��ʼ����
//�������β����ǵ�����һ����㡣����һ��������6����㣬��ͷ�ڵ㿪ʼ���ǵ�ֵ������1��2��3
//4��5��6.�������ĵ��������������ֵΪ4�Ľ��

//�����㶨�����£�
struct ListNode
{
	int data;
	ListNode* next;
};
//ע�⣺�����ָ�롢k==0���������ֹ��ѭ��
//�����Ŀ��1����������м��㣨��ָ��һ������������ָ��һ����һ����
//          2���ж�һ�����������Ƿ���л�����ָ��һ������������ָ��һ����һ���������ָ��׷����ָ�룬��˵���л���

//˼·��������K����㣬�����߾��ǵ�n-k+1������������ָ�룬��ָ������k-1����Ȼ����ָ������
//����ָ��պ����K-1��������ָ�뵽βʱ����ָ��պõ�������k����㡣
ListNode* FindNodeK(ListNode* pList, int k)
{
	assert(pList);
	if (k == 0)
		return NULL;
	ListNode* fast = pList;
	ListNode* slow = pList;
	//��ָ������k-1��
	while (k > 1 && fast != NULL)
	{
		--k;
		fast = fast->next;
	}
	//����ָ��ͬʱ��
	while (fast->next != NULL)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}


//��Ŀ��������һ������������һ�������ͷ��㣬��ת�����������ת�������ͷ��㡣������
//��������


//˼·����Ϊ�ǵ�������û��ָ��ǰһ������ָ�룬����ֻ��һ��һ�����ȡ��Ȼ��ͷ�塣��ȡͷ���
//�����������ͷ��㣬Ȼ��ȡ����Ľ��ͷ�塣
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
		//ȡͷ��㵱��newHead
		newHead = pList;
		ListNode* begin = pList->next;
		newHead->next = NULL;
		//ͷ��
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





//��Ŀ��������������������������ϲ�����������ʹ�������еĽ����Ȼ�ǰ��յ�������ġ�
//���������£�

struct ListNode
{
	int data;
	ListNode* next;
};
//�ǵݹ�
//ע�⣺�����³���ԣ�ָ������İ�ȫ��

//˼·�����ȱȽ����������ͷ��㣬��С����Ϊ�������ͷ��㣬Ȼ��ָ��С�Ľ���ָ�����
//�ٽ��бȽϣ�ֱ������Ϊ��
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
//�ݹ飺
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
	if (pList1->data < pList2->data)//�ж�������������ݣ���С�ĸ���������
	{
		pList = pList1;
		pList->next = MergeList(pList1->next, pList2);//�ݹ��ж�
	}
	else
	{
		pList = pList2;
		pList = MergeList(pList1, pList2->next);
	}
	return pList;
}



//��Ŀ�ģ��������ö�����A��B���ж�B�ǲ���A���ӽṹ�����������Ķ������£�

//ע�⣺��������ָ��Ĳ����Ƚ϶࣬ע��ָ���пա�
//˼·������ȡB��ͷ����A��ͷ�����бȽϣ������ͬ����Ƚ�ͷ�������ҽڵ㣬�����
//��ȣ�ȡA��������Ϊͷ��㣬�ٽ��бȽ�
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
		if (tree1->data == tree2->data)//��������ȣ�����JudgeChild�����ӽڵ���ж�
			result = JudgeChild(tree1, tree2);
		if (!result)//�ݹ��ж�����
			result = IsChildTree(tree1->left, tree2);
		if (!result)//�ݹ��ж��Һ���
			result = IsChildTree(tree1->right, tree2);
	}
	return result;
}

//��Ŀ�壺�����һ������������һ�����������ú���������ľ���
//�������Ľ�㶨�����£�

//˼·�������ľ���Ĺ��̾��Ǳ�������ͬʱ������Ҷ�ӽ������ҽ�㡣
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
	//�������ҽڵ�
	BinaryTreeNode* tmp = tree->left;
	tree->left = tree->right;
	tree->right = tmp;

	//�ݹ��ж�����
	if (tree->left)
		TreeImage(tree->left);
	//�ݹ��ж��Һ���
	if (tree->right)
		TreeImage(tree->right);
}


//��Ŀ��������һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ�����֡������������¾���
//1    2   3   4
//5    6   7   8
//9   10  11  12
//13  14  15  16
//��һ�δ�ӡ������1��2��3��4��8��12��16��15��14��13��9��5��6��7��11��10

//˼·����ÿһȦ�Ĵ�ӡ��Ϊ�Ĳ���һ�������Ҵ�ӡһ�У��������ϵ��´�ӡһ�У��������ҵ���
//��ӡһ�У��ġ����µ��ϴ�ӡһ�С���Ҫע���ӡÿһ����ǰ������

void PrintCircle(int matrix[][4], int rows, int clos, int start)
{
	assert(matrix);
	int endX = clos - 1 - start;
	int endY = rows - 1 - start;
	//�������Ҵ�ӡһ��
	for (int i = start; i <= endX; i++)
	{
		int num = matrix[start][i];
		printf("%d ", num);
	}
	//���ϵ��´�ӡһ��
	if (start < endY)//����һ��
	{
		for (int i = start + 1; i <= endX; i++)
		{
			int num = matrix[i][endX];
			printf("%d ", num);
		}
	}
	//���������ӡһ��
	if (start < endX && start < endY)
	{
		for (int i = endX - 1; i >= start; i--)
		{
			int num = matrix[endY][i];
			printf("%d ", num);
		}
	}
	//���µ��ϴ�ӡһ��
	if (start < endX && start < endY - 1)//��������,��������
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


//��Ŀ�ߣ�����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ����СԪ�ص�min�������ڸ�ջ�У�
//����min��push��pop��ʱ�临�Ӷȶ���O(1)��

//˼�룺����һ������ջ�������ǽ���С����push������ջ,�Ϳ��Ա�֤����ջ��ջ��һֱ������СԪ��

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
