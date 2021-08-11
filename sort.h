#include "Array.h"
template<class datatype>
class Sort{
	public:
		void fill(int* a, int arrange, int size);
		void bubble(int* a, int size, int& iteration, int& swap);
		void insertion(int a[], int size, int& iteration, int& swap);
		void merge(int* a, int l, int m, int r);
		void mergeS(int* a, int l, int r, int& iteration, int& swap);
		void shiftRight(int* a, int left, int right);
		void heapify(int* a, int left, int right);
		void heap(int* a, int size, int& iteration, int& swap);
		void shell(int* a, int size, int& iteration, int& swap);
		/*void quicksort(int a[], int left, int right, int& iteration, int& swap);
		void selectionsort(int a[], int size, int& iteration, int& swap);
		int binarysearch(int a[], int searchkey, int size);*/
	private:
		int size, iteration, swap;
};
#include "sort.cpp"
