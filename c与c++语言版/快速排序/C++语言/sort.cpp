#include<iostream>
#include<vector>
#include<stdlib.h>
void create_array(std::vector<int> &vArray){
	for(size_t i = 0;i<10;i++){	
		vArray.push_back(rand()%10);
	}
}
void show_array(std::vector<int> &vArray,std::string sInfo){
	std::cout<<sInfo<<std::endl;
	for(size_t i = 0;i<vArray.size();i++){
		std::cout<<vArray[i]<<std::endl;
	}
}

void quick_sort(int left,int right,std::vector<int> &vArray){
	//设置迭代停止条件
	if(left >= right){
		return;
	}

	//取基准
	int base = vArray[left];
	int i = left;
	int j = right;
	while(i<j){
		//处理右边的,找出小于base的
		while((j>i)&&(vArray[j] >= base)){
			j--;
		}
		//处理左边的,找出大于base的		
		while((i<j)&&(vArray[i] <= base)){
			i++;
		}
		//交换数据
		if(i<j){
			int temp = vArray[i];
			vArray[i] = vArray[j];
			vArray[j] = temp;
		}
	}
	//将基准数字放在中间，由于vArray[i]不会小于base,交换数据无影响
	vArray[left] = vArray[i]; 
	vArray[i] = base;

	//进行递归
	quick_sort(left,i-1,vArray);
	quick_sort(i+1,right,vArray);
	return;
}
void sort_array(std::vector<int> &vArray){
	quick_sort(0,vArray.size()-1,vArray);
}

int main(){
	std::vector<int> vArray;
	//生成待排序的
	create_array(vArray);
	//显示待排序的内容
	show_array(vArray,"待排序的顺序");
	//快速排序
	sort_array(vArray);
	//已排序好的内容
	show_array(vArray,"已排序的顺序");
	return 0;	
}
