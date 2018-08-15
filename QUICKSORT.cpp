#include <iostream>

using namespace std;


int partition(int *A,int start,int end) {
    int pivot,i,pIndex;
    pivot = A[end] ; 
    pIndex = start;
    for(i=start;i<end;i++) { 
        if(A[i]<=pivot) { 
            swap(A[i],A[pIndex]);
            pIndex++;
        }
    }
    
    swap(A[pIndex],A[end]); 
   
  
    return pIndex;
}


    


void quicksort(int *A,int start,int end) {
    int pi;
  
    if(start<end) {
        pi = partition(A,start,end);
        
        quicksort(A,start,pi-1);
        quicksort(A,pi+1,end);
        
    }
    
}



int main() {
	int A[] = {10,80,30,90,40,50,70};
	quicksort(A,0,6) ;
	for(int i=0;i<7;i++) cout<<A[i]<<" " ;
	
    return 0;
}
