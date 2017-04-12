#include<stdio.h>

//（从小到大排序）存在10个不同大小的气泡，由底至上地把较少的气泡逐步地向上升，这样经过遍历一次后，最小的气泡就会被上升到顶（下标为0），然后再从底至上地这样升，循环直至十个气泡大小有序。

void swap(int *a,int *b)
{
	int temp=0;

	temp = *a;
	*a = *b;
	*b = temp;
	return;	
}

void show(int *array)
{
	int i =0;
	for(i=0;i<10;i++)
	{
		printf ("%d:%d\n",i,array[i]);
	}
	return;
}

void main()
{
	int array[10]={12,11,6,79,45,0,23,55,77,134};
	int i=0;
	int j=0;

	for(i=0;i<10;i++)
	{
		for(j=9;j>i;j--)
		{
			
			if (array[j]<array[j-1])
			{
				swap(&array[j],&array[j-1]);
				
			}
		}
		
	}

	show(array);
	return;
}



