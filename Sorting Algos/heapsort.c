#include<stdio.h>
#define left 2*i + 1
#define right 2*i + 2


void max_heapify(int A[],int length,int i);
void build_max_heap(int A[],int length);
void heapsort(int A[], int n);


void max_heapify(int A[],int length, int i){
	int largest,l,r,temp;
	l=left;
	r=right;
	if( l < length && A[l] > A [i])
		largest = l;
	else 
		largest = i;
	if(r < length && A[r] > A[largest])
		largest =r;
	if(largest != i){
		temp = A[largest];
		A[largest] = A[i];
		A[i] = temp;
		max_heapify(A,length,largest);
	}
}
//construction of max heap
void build_max_heap(int A[],int length){
	for(int i=length/2 -1 ; i >= 0; i--)
		max_heapify(A,length,i); 
}


void heapsort(int A[],int length){
	int temp;
	for(int i=length -1 ; i >=  0; i--){
		temp = A[0];
		A[0] = A[i];
		A[i] = temp;
		length --;
		max_heapify(A,length,0);
	}
}


int main(){
	 int A[] = {5,13,2,25,7,17,20,8,4};
         int length = sizeof(A)/sizeof(A[0]);
 	build_max_heap(A,length);
	//Prints the Max Heap 
	for(int i =0 ;i<length;i++)
		printf("%d\t",A[i]);
	heapsort(A,length);
	//Prints the sorted Array
	printf("\n");
	   for(int i =0 ;i<length;i++)
                printf("%d\t",A[i]);

}	
