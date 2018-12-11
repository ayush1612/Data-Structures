#include<stdio.h>
#define size 10
int arr[size],search;

int binary_search(int left,int right)
{
	if(left<=right)
	{
		int mid=(left+right)/2;
		
		if(arr[mid]==search)
		{
			return 1;
		}
		else if(arr[mid]>search)
		binary_search(left,mid-1);
		else
		binary_search(mid+1,right);
	}
	else
	return 0;
}

void main()
{
	printf("Enter 10 elements in the array\n");
	
	int i,j;
	for(i=0;i<size;i++)
		scanf("%d",&arr[i]);
	printf("Enter the element you want to search\n");
	scanf("%d",&search);
	
	//binary searching the element 
	
	

	if(binary_search(0,size-1)==0)
	printf("Element not present\n");
	else
	printf("Element present in the array\n");
}

