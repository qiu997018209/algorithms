#include <iostream>  
#include <vector>  
#include <stack> 
#include <limits.h> 
using namespace std; 

int map[][5] = {                     //定义有向图  
    {0, 10, INT_MAX, INT_MAX, 5},  
    {INT_MAX, 0, 1, INT_MAX, 2},  
    {INT_MAX, INT_MAX, 0, 4, INT_MAX},  
    {7, INT_MAX, 6, 0, INT_MAX},  
    {INT_MAX, 3, 9, 2, 0}  
}; 

//参数依次为:源节点的index，总的节点数，保存源节点到每一个节点的距离，记录节点的路径
void Dijkstra(int StartIndex,int number,int Distance[],int PreVector[])
{
	vector<bool> isInS;//是否已经在S集合中
	//reserve(n)后，若容器的capacity<n，则重新分配内存空间，从而使得capacity等于n。如果capacity>=n呢？capacity无变化。 
	isInS.reserve(0);
	isInS.assign(number,false);

	//初始化源节点到每一个节点的距离
	for(int i = 0;i<number;i++)
	{
		Distance[i] = map[StartIndex][i];
		if(Distance[i]<INT_MAX)
		{
			//记录当前点的前一个点
			PreVector[i] = StartIndex;
		}
		else
		{
			PreVector[i] = -1;
		}
	}
	
	//源节点前没有节点
	PreVector[StartIndex] = -1;
	//将当前的源节点放到S中
	isInS[StartIndex] = true;
	
	int u = StartIndex;
	//*开始使用贪心思想循环处理不在S集合中的每一个节点
	//此时StartIndex已经被放到S中，所以从1开始
	for(int i=1;i<number;i++)
	{
		int TempDistance = INT_MAX;
		int next = u; ;
		for (int j = 0;j<number;j++)
		{
			if((false == isInS[j])&&(Distance[j]<TempDistance))
			{
				TempDistance = Distance[j];
				next = j;
			}
		}
		//将距离最小的点放到S中
		isInS[next] = true;
		u = next;
		//核心:更新到源点距离
		for(int j = 0;j<number;j++)
		{
			//确保next点到某一点是可达的
			if((false==isInS[j]) && (map[u][j]<INT_MAX))
			{
				//更新next节点周围可达点的所有距离，因为此时将源和next视为一个点
				int Temp = Distance[u]+map[u][j];
				if(Temp<Distance[j])
				{
					//此处很关键:必须要S->K->j的路径必须要小于S->j的路径时才更新，因为只保留最短的
					Distance[j] = Temp;
					PreVector[j] = u;
				}
					
			}

		}

	}
	
	



}



int main()
{
	int Distance[5] = {0};
	int PreVector[5] = {0};
	
	//计算以每一个节点为Start的路径
	for(int i =0;i<5;i++)
	{
		Dijkstra(i,5,Distance,PreVector);
		for(int j=0;j<5;j++)
		{
			int index = j;
			stack<int> trace;
			while(-1!=PreVector[index])
			{
				trace.push(PreVector[index]);
				index=PreVector[index];				
			}
			cout << "路径:";
			while(!trace.empty())
			{
				//最上面的那个点一定是原点
				cout<<trace.top()<<"---";
				trace.pop();
			}
			//在压栈的时候，自己是没有被放进去的，此处补上
			cout <<j;
			cout << "距离:"<<Distance[j]<<endl;

		}

	}



}
