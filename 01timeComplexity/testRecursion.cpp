#include <iostream>
#include <ctime>
#include <cassert>
#include <cstdlib>
using namespace std;
//
int fibonacci(int n){
	assert(n>0);
	if(n==1 || n==2){
		return 1;
	}
	return fibonacci(n-1)+fibonacci(n-2);
}

// sorted array
int binarySearch( int num, int * arr , int size, int start, int end ){
	assert(size > 0 && start >=0 && end <size);
	int mid = (start+end)/2;    // mid = start + (end-start)/2 ;   avid overflow int
	if(start > end){
		return -1;
	}else if( arr[mid] == num){
		return mid;
	}else{
		if(arr[mid] > num)
			return binarySearch(num, arr, size, start, mid-1);
		else
			return binarySearch(num, arr, size, mid+1, end); 
	}
}

void test(){
	cout << fibonacci(5) << std::endl;
	int arr[10] = {0, 2, 4, 5, 8 ,9 ,10 ,13, 45,333};
	std::cout << binarySearch(3, arr, 10, 0, 9) << std::endl;
	std::cout << binarySearch(8, arr, 10, 0, 9) << std::endl;
}

void testFibonacci(){
	clock_t startTime, endTime;
	for(int i=1; i<40; ++i){
	 	startTime = clock();
		int res = fibonacci(i);
		endTime = clock();
	 	cout << i << "\t"<<res <<"\t"<< (double) (endTime - startTime)/CLOCKS_PER_SEC <<endl;
	}
}
#define NTIME 100000
void testBinarySearch(){
	for(int i=10; i<10000000; i = 2*i){
		int *arr = new int[i];
		arr[0] = 0;
		for(int j=1; j<i; ++j){
			arr[j] = arr[j-1] + (rand()%3+1);
		}	
		
		clock_t startTime, endTime;
		int num[NTIME];
 		int res[NTIME];
		startTime = clock();
		for(int cnt=0; cnt<NTIME; ++cnt){
			num[cnt] = rand()% (2*i);
			res[cnt] = binarySearch(num[cnt], arr, i, 0, i-1);
		}
		endTime = clock();
		cout << i <<"\t" << (double)(endTime-startTime)/CLOCKS_PER_SEC <<endl;
		for(int cnt = 0; cnt<NTIME; cnt = cnt+NTIME/10){
			cout << "\t" << num[cnt] << "\t" << res[cnt] << "\t" << (res[cnt] >= 0 ? arr[res[cnt]] : -1)  << endl;
		}
		free(arr);	
	}
}
int main(){
	testBinarySearch();
}


