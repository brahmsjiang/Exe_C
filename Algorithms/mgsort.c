#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display(int arr[], int low, int high);
void merge_sort(int arr[], int low, int high);
void merge(int arr[],int low, int mid, int high);

int main(int argc, char * argv[])
{
	int arrtosort[] = {67,13};
	int len = (int)(sizeof(arrtosort)/sizeof(int));
	printf("len is: %d\n",len);
	merge_sort(arrtosort, 0, len-1);

	display(arrtosort, 0, len-1);
}

void display(int arr[], int low, int high)
{
	int i = 0;
	for(i = low;i <= high; i++)
	{
		printf("arr[%d] %d ",i,arr[i]);
	}
	printf("\n");
}

void merge_sort(int arr[], int low, int high)
{
	if (low >= high)
		return;
	int mid = (low + high)/2;
	merge_sort(arr, low, mid);
	merge_sort(arr, mid+1, high);
	printf("before merge: ");
	display(arr, low, high);
	merge(arr, low, mid, high);
}

void merge(int arr[],int low, int mid, int high)
{
	int len = high - low + 1;
	int i = low, j = mid + 1;
	int k = 0;
	int tmp[len]={0};
	while(i <= mid && j <= high)
	{
		if(arr[i] <= arr[j]){
			tmp[k] = arr[i];
			printf("tmp[%d]: %d",k,tmp[k]);
			i++;
			k++;
		}
		else {
			tmp[k] = arr[j];
			j++;
			k++;
			printf("tmp[%d]: %d",k,tmp[k]);
		}	
	}
	while(i > mid && j <= high){ 
		tmp[k] = arr[j];
		printf("tmp[%d]: %d",k,tmp[k]);
		j++;
		k++;	
	}
	while(j > high && i <= mid){
		tmp[k] = arr[i];
		printf("tmp[%d]: %d",k,tmp[k]);
		i++;
		k++;
	}

	//memcpy(&arr[low], tmp, len);
	printf("after merge: ");
	display(arr, low, high);
}












