#include <iostream>
#include <cstdlib>
#include <cassert>
// rand() -->  stdlib.h
using namespace std;
int binary_search(int arr[], size_t sz, int num){
	if(sz==0)
		return -1;
	int l = 0, r = sz-1, m;  //search [l, r];    // be careful to use size_t, overflow
	while(l <= r){ 			 // l <= r  ; if not NULL
		m = l + (r-l)/2;
		if(arr[m] == num ){
			return m;
		}
		if(arr[m] < num){
			l = m + 1;
		}else{
			r = m - 1;
		}
	}
	return -1;
}

int * getArr(int n){
	int * arr = (int *) malloc ( n * sizeof(int));// c++ must cast
	for(size_t i=0; i<n; ++i)
		arr[i] = i;
	return arr;
}
// test
int main(){
	int * arr = getArr(1000);
    for( int i = 0; i < 100; ++i){
		int num = rand()%1200-200;
		int idx = binary_search(arr, 1000, num);
		if( num >= 0 ){
	//		cout << idx <<"\t" << num << "\t" << arr[num] <<endl;
			assert(idx == num);
		}
		if(num<0)
			assert(idx == -1);
	}		
	free(arr);
}

