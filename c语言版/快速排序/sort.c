#include<stdio.h>

//快速排序的平均时间复杂度是O(NlogN)，他比冒泡快是因为冒泡的交换距离大

int array[10]={22,0,23,45,65,3,7,0,100,47};

//显示排序后的结果
void show_result()
{
	int i =0;
	for(i=0;i<10;i++)
	{
		printf("%d:%d\n",i,array[i]);
	}

}

//快速排序
void quick_sort(int left,int right)
{
	int temp=0;
	int base=0;
	int i,j = 0;
	if(left>=right)
	{
		return;
	}
	//取基准
	base=array[left];
	i = left;
	j = right;
	while(i!=j)
	{
		//从右边开始，找到小于base的数（据说顺序重要，暂时还没发现）
		while((array[j]>=base)&&(j>i))
		{
			j--;
		}
		//左边开始，寻找大于base的数
		while((array[i]<=base)&&(j>i))
		{
			i++;
		}
		if(i<j)
		{
			//交换数据
			temp = array[i];
			array[i]=array[j];
			array[j]=temp;			
		}

	}
	
	//基准归位
	array[left] = array[i];
	array[i]=base;
	//迭代
	quick_sort(left,i-1);
	//迭代
	quick_sort(i+1,right);	
}



void main()
{
	quick_sort(0,9);
	show_result();	
	return; 
}
