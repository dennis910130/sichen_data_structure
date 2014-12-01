#ifndef SICHEN_SORT_HPP_
#define SICHEN_SORT_HPP_

#include <iostream>

namespace sichen{
	template <typename Dtype>
	class MySort {
		private:
			static void swap(Dtype *data, int i, int j);
			static bool compare(Dtype a, Dtype b);
			
			//for quick sort
			static void quickSortHelper(Dtype *data, int i, int j, bool(*pComp) (Dtype, Dtype));
			
			//for merge sort
			static void msort(Dtype *data, Dtype *aux, int low , int high, bool(*pComp) (Dtype, Dtype));
			static void merge(Dtype *data, Dtype *aux, int low, int mid, int high, bool(*pComp) (Dtype, Dtype));
			
		public:			
			static void selectionSort(Dtype* data, int len, bool(*pComp) (Dtype, Dtype) = compare);
			static void quickSort(Dtype* data, int len, bool(*pComp) (Dtype, Dtype) = compare);
			static void mergeSort(Dtype* data, int len, bool(*pComp) (Dtype, Dtype) = compare);
			static void insertionSort(Dtype* data, int len, bool(*pComp) (Dtype, Dtype) = compare);
			static void bubbleSort(Dtype *data, int len, bool(*pComp) (Dtype, Dtype) = compare);
			
			static void printOut(Dtype* data, int len);
	};
	

}
#include "mySort.cpp"
#endif