#include<iostream> 

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
  
 class Solution {
 public:
	 /*
	  * @param head: a ListNode
	  * @param val: An integer
	  * @return: a ListNode
	  */
	 ListNode * removeElements(ListNode * head, int val) {
		 // write your code here
		 
		 //排除链表为NULL情况
		 if(head == NULL){
			 return head;
		 }
		 //先判断头节点是否为需要删除的
		 while(head->val == val){
			 head = head->next;
			 if(head == NULL){
				 return NULL;
			 }
		 }
		 
		 ListNode *pstTemp = head;
		 
		 while(pstTemp->next != NULL){
			 //节点是待删除的
			 if(pstTemp->next->val == val){
				pstTemp->next = pstTemp->next->next;
			 }else {
				 //更新
				 pstTemp = pstTemp->next;
			 }
		 }
		 
		 return head;
	 }
 };

ListNode * build_list(){
 	ListNode *head = new ListNode(0);
 	ListNode * temp = head;
	for(int i =0;i<5;i++){
		temp->val = i;
		temp->next = new ListNode(0);
		temp = temp->next;
	}
	temp->val = 5;
	temp->next = NULL;
	return head; 
 }

 void show_list(ListNode *head,const std::string &info){
	ListNode * temp = head;
	std::cout<<info<<std::endl;
	while(temp->next != NULL){
		std::cout<<temp->val<<std::endl;
		temp = temp->next;
	}
	std::cout<<temp->val<<std::endl;
 }
 int main(){
	ListNode* head;
	Solution s;
	head = build_list();;
	show_list(head,"删除元素前");	
	s.removeElements(head, 2);
	show_list(head,"删除元素后");
	return 0;
 }
