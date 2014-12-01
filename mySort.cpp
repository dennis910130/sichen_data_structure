#include "mySort.hpp"

namespace sichen{
	template <typename Dtype>
	void MySort<Dtype>::swap(Dtype *data, int i, int j) {
		Dtype tmp = data[i];
		data[i] = data[j];
		data[j] = tmp;
	}
	
	template <typename Dtype>
	bool MySort<Dtype>::compare(Dtype a, Dtype b) {
		return a < b;
	}

	template <typename Dtype>
	void MySort<Dtype>::selectionSort(Dtype *data, int len, bool (*pComp) (Dtype, Dtype)) {
		for (int i = 0; i < len; i++) {
			int min_pos = i;
			for (int j = i; j < len; j++) {
				if (pComp(data[j], data[min_pos])) min_pos = j;
			}
			swap(data, i, min_pos);
		}
	}
	
	template <typename Dtype>
	void MySort<Dtype>::printOut(Dtype *data, int len) {
		for (int i = 0; i < len; i++) {
			std::cout << data[i] << " ";
			if (i == len - 1) std::cout << std::endl;
		}
	}
	
	template <typename Dtype>
	void MySort<Dtype>::insertionSort(Dtype *data, int len, bool (*pComp) (Dtype, Dtype)) {
		for (int i = 0; i < len; i++) {
			for (int j = i; j >= 1; j--) {
				if (pComp(data[j], data[j-1])) {
					swap(data, j, j-1);
				}
				else {
					break;
				}
			}
		}
	}
	
	template <typename Dtype>
	void MySort<Dtype>::quickSortHelper(Dtype *data, int i, int j, bool (*pComp) (Dtype, Dtype)) {
		int left = i;
		int right = j;
		Dtype pivot = data[left + (right - left) / 2];
		while (left <= right) {
			while (data[left] < pivot) {
				left ++;
			}
			while (data[right] > pivot) {
				right --;
			}
			if (left <= right) {
				swap(data, left, right);
				left ++;
				right --;
			}
		}
		if (left < j) quickSortHelper(data, left, j, pComp);
		if (i < right) quickSortHelper(data, i, right, pComp);
	}
	
	template <typename Dtype>
	void MySort<Dtype>::quickSort(Dtype *data, int len, bool (*pComp) (Dtype, Dtype)) {
		quickSortHelper(data, 0, len-1, pComp);
	}
	
	template <typename Dtype>
	void MySort<Dtype>::merge(Dtype *data, Dtype *aux, int low, int mid, int high, bool (*pComp) (Dtype, Dtype)) {
		for (int i = low; i <= high; i++) {
			aux[i] = data[i];
		}
		int k = low;
		int i = low;
		int j = mid+1;
		while (i <= mid && j <= high) {
			if (pComp(aux[i], aux[j])) {
				data[k] = aux[i];
				i++;
				k++;
			}
			else {
				data[k] = aux[j];
				j++;
				k++;
			}
		}
		while (i <= mid) {
			data[k] = aux[i];
			k++;
			i++;
		}
		while (j <= high) {
			data[k] = aux[j];
			j++;
			k++;
		}
	}
	
	template <typename Dtype>
	void MySort<Dtype>::msort(Dtype *data, Dtype *aux, int low, int high, bool(*pComp) (Dtype, Dtype)) {
		if (low >= high) return;
		int mid = low + (high-low) / 2;
		msort(data, aux, low, mid, pComp);
		msort(data, aux, mid+1, high, pComp);
		merge(data, aux, low, mid, high, pComp);
	}
	
	template <typename Dtype>
	void MySort<Dtype>::mergeSort(Dtype *data, int len, bool(*pComp) (Dtype, Dtype)) {
		Dtype *aux = new Dtype[len];
		msort(data, aux, 0, len-1, pComp);
		delete[] aux;
	}
	
	template <typename Dtype>
	void MySort<Dtype>::bubbleSort(Dtype *data, int len, bool(*pComp) (Dtype, Dtype)) {
		for (int i = len; i > 0; i--) {
			for (int j = 0; j < i - 1; j++) {
				if (!pComp(data[j], data[j+1])) {
					swap(data, j, j+1);
				}
			}
		}
	}
	
}