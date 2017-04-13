#include<stdio.h>
#include<string.h>

//归并排序有几个子问题，链表分割，有序链表合并
struct list_node {
	int val;
	list_node *next;	
	list_node(int x):val(x),next(NULL){}
};

class solution {
public:
	//给链表下插入一些节点
	void insert(list_node*head,int val)
	{
		while(head->next)
		{
			head=head->next;
		}
		head->next = new list_node(val);
		return;
	}

	//链表合并
	list_node *merge_list(list_node *left,list_node *right)
	{
		list_node *head=NULL;
		list_node *p=NULL;

		if(left->val<=right->val)
		{
			head = left;
			left = left->next;	
		}
		else
		{
			head = right;
			right = right->next;
		}

		p=head;
		while(left&&right)
		{
			if(left->val<=right->val)
			{
				p->next = left;
				left=left->next;
				p=p->next;
			}
			else
			{
				p->next = right;
				right=right->next;
				p=p->next;
			}
		}
		
		//将没有排完序的剩余部分进行排序
		while(right)
		{
			p->next = right;
			p = p->next;
			right= right->next;
		}
		while(left)
		{
			p->next = left;
			p = p->next;
			left = left->next;
		}
		
		return head;
	}


	//递归：链表分割
	list_node *sort_list(list_node*head)
	{
		list_node* fast= head;
		list_node* low = head;

		if((NULL==head)||(NULL==head->next))
		{
			return head;
		}
		
		//用快慢指针查找中间点:当快的到达结尾的时候，慢的刚好到达中间
		while((NULL!=fast->next)&&(NULL!=fast->next->next))
		{
			fast = fast->next->next;
			low = low->next;
		}
		//只有两个节点
		if(fast==head)
		{
			//无需递归，直接合并
			fast=fast->next;
			low->next = NULL;
			return merge_list(fast,low);
		}
		//low是链表中间节点，从此处开始切分成2条链表
		fast = low->next;
		low->next = NULL;
		//排序前部分：注意此时low已经是最后一个了
		low=sort_list(head);
		//排序后部分
		fast=sort_list(fast);
		//合并链表
		return merge_list(low,fast);
	}

	//显示结果并销毁内存
	void show_and_del_list(list_node *head)
	{
		int num=1;
		list_node * temp = head;
		while(head)
		{
			temp = head;
			head = head->next;
			printf ("%d:%d\n",num,temp->val);
			num++;
			delete(temp);
		}

		return;
	}
};



int main()
{
	solution test;
	list_node *end;
	list_node *head = new list_node(1);

	//插入一些节点	
	test.insert(head,10);
	test.insert(head,100);
	test.insert(head,50);
	test.insert(head,49);
	test.insert(head,79);
	test.insert(head,179);
	test.insert(head,13);
	test.insert(head,33);
	test.insert(head,0);
	test.insert(head,2);

	//进行排序:返回的是链表的最后一个
	head=test.sort_list(head);

	//显示结果并释放内存
	test.show_and_del_list(head);
	return 0;	
}

