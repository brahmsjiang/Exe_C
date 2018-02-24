#include <stdio.h>
#include <stdlib.h>

void quick_sort(int a[], int low, int high)
{
	int i, j, pivot;
	if (low < high){
		pivot = a[low];
		i = low;
		j = high;
		while(i<j)
		{
			while(i<j && a[j]>=pivot)
				j--;
			if(i<j)
				a[i++]=a[j];
			while(i<j && a[i]<pivot)
				i++;
			if(i<j)
				a[j--]=a[i];
		}
		a[i] = pivot;
		display(a, low, high);
		quick_sort(a, low, i-1);
		quick_sort(a, i+1, high);
	}	
}

void display(int a[],int low,int high)
{
	int i = 0;
	for (i = low;i <= high; i++)
		printf("%d ",a[i]);
	printf("\n");
}

int main(int argc,char* argv[])
{
	int arrtosort[] = {10,2,3,7,9,1,4,5,6,11,32,8};
	int len = 0;
	printf("sizeof arrtosort: %d\n", len = (int)(sizeof(arrtosort)/sizeof(int)));
	quick_sort(arrtosort, 0, len-1);
	display(arrtosort, 0, len-1);
	return 0;	
}




