#include "myPQ.hpp"

namespace sichen {

	template <typename Dtype>
	MyPQ<Dtype>::MyPQ(Dtype *data, int len, int max_cap) {
		N = len;
		this->data = new Dtype[max_cap+1];
		capacity_ = len*2;
		for (int i = 0; i < len; i++) {
			this->data[i+1] = data[i]; 
		}
		
		for (int k = N/2; k >= 1; k--) {
			sink(k);
		}
	}

	template <typename Dtype>
	void MyPQ<Dtype>::insert(Dtype new_data) {
		this->data[N+1] = new_data;
		swim(N+1);
		N += 1;
	}
	
	template <typename Dtype>
	void MyPQ<Dtype>::removeMax() {
		swap(1, N);
		N -= 1;
		sink(1);
	}

	template <typename Dtype>
	bool MyPQ<Dtype>::compare(Dtype a, Dtype b) {
		return a > b;
	}
	
	template <typename Dtype>
	void MyPQ<Dtype>::swap(int i, int j) {
		Dtype tmp = data[i];
		data[i] = data[j];
		data[j] = tmp;
	}
	
	template <typename Dtype>
	void MyPQ<Dtype>::swim(int k) {
		while (k > 1 && compare(data[k/2], data[k])) {
			swap(k,k/2);
			k /= 2;
		}
	}
	
	template <typename Dtype>
	void MyPQ<Dtype>::sink(int k) {
		while (2*k <= N) {
			int j = 2*k;
			if (j < N && compare(data[j], data[j+1])) j++;
			if (compare(data[k], data[j])) {
				swap(k,j);
				k = j;
			} 
			else {
				break;
			}
		}
	}
	
	template <typename Dtype>
	void MyPQ<Dtype>::print() {
		for (int i = 0; i < N; i++) {
			cout << data[i+1] << " ";
		}
		cout << endl;
	}
	

}