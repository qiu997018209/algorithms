#include<stdio.h>
#include<string.h>

#define bool char
#define true 1

static int huff_num=0; //用来保持二进制数据的index

typedef struct hufftree {
	int data;//数据，只有叶子节点存在
	bool min;//是否是叶子节点
	int weight;//权重
	struct hufftree *left;//左孩子
	struct hufftree * right;//右孩子
}*tree;

struct huffnum {
	int data;//编码对应的真实数据
	char binary[11];//数字对应的二进制编码，暂时取11,可按需扩展
}hfn[100];

void sort_tree(tree tr,int num1)
{
	//需要每次取最小的两个节点，并将他们放到数组的最前面
	//因此对实际有效节点进行冒泡排序
	int i;
	int j;
	struct hufftree temp = {0};
	for(i = 0;i<num1;i++)
	{
		
		for(j=num1-1;j>i;j--)
		{
			if(tr[j].weight<tr[j-1].weight)
			{
				temp = tr[j-1];
				tr[j-1] = tr[j];
				tr[j] = temp;					
			}			
 				
		}
	}
	return; 	

}

tree get_tree(tree tr,int num1,int num2)
{
	//num1代表有效，num2代表实际节点
	//实际所需的节点数为2×有效节点-1

	if(num2!=2*num1-1)
	{
		printf("%s\n","invalid node number");
	}

	int c = 0;
	int i = 0;
	struct hufftree temp = {0};

	while(num1!=num2)
	{
		//第一次取2个最小的，并将他们放在数组的1,2。第二次找出去前2个最小的两个，放在数字的3,4位置....
		for(i = c+1;i<num1;i++)
		{
			if(tr[c].weight>tr[i].weight)
			{
				temp = tr[i];
				tr[i]=tr[c];
				tr[c]=temp; 
			}

		}
		for(i = c+2;i<num1;i++)
		{

			if(tr[c+1].weight>tr[i].weight)
			{
				temp = tr[i];
				tr[i]=tr[c+1];
				tr[c+1]=temp; 
			}

		}
		
		//取最小的两个节点,并生成新的节点,新节点里的权重只是构造出来的而已，没有意义
		tr[num1].weight = tr[c].weight+tr[c+1].weight;
		tr[num1].left = &tr[c];
		tr[num1].right = &tr[c+1];
		c = c+2; 
		num1++;
	}

	//最后一颗生成的就是huffman树
	return &tr[8];
}
//对huffman树进行编码
void tree_binary(tree huffman,char *buf)
{
	int j =0;
	static int i = 0;  //用来记录二进制位

	if(NULL == huffman)
	{
		return;
	}
	//非叶子节点
	if(!huffman->min)
	{
		//左节点编码为0
		buf[i] = '0';
		i++;
		tree_binary(huffman->left,buf);
		//对右节点进行编码
		buf[i] = '1';
		i++;
		tree_binary(huffman->right,buf);
		
	}
	//一直到叶子节点
	if(huffman->min)
	{
		//将对应的数据和二进制编码保存起来，用空间换时间
		hfn[huff_num].data = huffman->data;
		//我们用来存储二进制的数组只有11位,不能取等于，因为前面多加了一次
		while(j<i&&j<11)
		{
			//保存映射关系
			hfn[huff_num].binary[j] = buf[j];
			j++;
		}
		huff_num++;
	}
	//到此处需要退回上一步的
	i--;

	return;

}

void show_binary()
{
	int i = 0;
	while(i<huff_num)
	{
		printf("data:%c,binary:%s\n",hfn[i].data,hfn[i].binary);
		i++;
	}

}

void main()
{

	tree huffman = NULL;

	char buf[100];//用来记录对应的二进制编码

	memset(buf,0,sizeof(buf));

	//有效节点的数量是5，剩余4个是用来存储无用节点的
	struct hufftree tr[9] = {{'a',true,10},{'d',true,5},{'e',true,3},{'c',true,55},{'f',true,15}};

	struct hufftree b = {0};	
	
	huffman=get_tree(tr,5,9);

	//对huffman树进行编码
	tree_binary(huffman,buf);

	//显示编码与数据间的映射关系
	show_binary();
}











