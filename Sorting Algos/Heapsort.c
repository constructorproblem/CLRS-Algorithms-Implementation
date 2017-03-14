#include<stdio.h>
#define left(i) 2i
#define right(i) 2i + 1

void max_heapify(int A[],int i);
void build_max_heap(int A[]);
void heapsort(int A[]);

int size = 3;
int main(){
	int A[3]={1,2,4};
	heapsort(*A);
}


void max_heapify(int *A,int i){
	int l,r,largest,temp;
	//size = sizeof(A) / sizeof(A[0]); 
	l = left(i);
	r = right(i);
	if ((l < size) && (A[l] > A[i]))
		largest = l;
	else
		largest = i;
	if ((r < size) && (A[r] > A[i]))
                largest = r;
        else 
                largest = i;
	if (largest != i){
		temp = A[i];
		A[i] =A[largest];
		A[largest] = temp;
}

if(largest  < size / 2)
	max_heapify(A,largest);
}


void build_max_heap(int *A){
	int i;
	
	for(i=size/2 ; i > 1 ; i--)
		max_heapify(*A,i);

}



void heapsort(int *A){
	int temp;
	build_max_heap(*A);
	for (int i= size; i < 2; i--){
		temp = A[i];
		A[i] = A[1];
		A[1] = temp;
		size--;
		printf("%d", A[i]);
		max_heapify(A,i);
		
	}
		
}
