#include <stdio.h>
#include <time.h>

void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

int sort_small(int arr[],int n,int k)
{
	int i,j,min;
	for(i=0;i<k;i++)
	{
		min=i;
		for(j=i+1;j<n-1;j++)
		{
			if(arr[j]<arr[min])
				min=j;
		}
		swap(&arr[i],&arr[min]);
	}
	return arr[k-1];
}


int main()
{
	int arr[100];
	int size,i;
	int k,result;
	
	double time;
	clock_t start,end;
	
	printf("Enter the size of an array\n");
	scanf("%d",&size);
	
	printf("Enter the array elements\n");
	for(i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	printf("Enter k'th smallest element to search\n");
	scanf("%d",&k);
	
	result=sort_small(arr,size,k);
	printf("k'th smallest element is %d\n",result);
	
	end=clock();
	
	time=(double)(end-start)/CLOCKS_PER_SEC;
	printf("Time complexity is %f\n",time); 
	
	return 0;
}