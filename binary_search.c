#include<stdio.h>
#define size 10
void main()
{
	int arr[size];
	printf("Enter size elements in the array\n");
	
	int i,j;
	for(i=0;i<size;i++)
		scanf("%d",&arr[i]);
		
	int search;
	printf("Enter the element you want to search\n");
	scanf("%d",&search);
	
	//sorting the array
	
	for(i=0;i<size;i++)
	{
		for(j=i+1;j<size-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	
	//binary searching the element 
	
	int left=0,right=9,found=0;
	while(left<=right)
	{
		int mid=(left+right)/2;
		
		if(arr[mid]==search)
		{
			found=1;
			break;
		}
		else if(arr[mid]>search)
		right=mid-1;
		else
		left=mid+1;
	}
	
	if(found==0)
	printf("Element not present\n");
	else
	printf("Element present in the array\n");
}

