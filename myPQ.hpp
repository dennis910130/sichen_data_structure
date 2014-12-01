#ifndef SICHEN_PQ_HPP_
#define SICHEN_PQ_HPP_

#include <iostream>
using namespace std;
namespace sichen {
template <typename Dtype>
class MyPQ {
	private:
		Dtype *data;
		int capacity_;
		int N;
		bool compare(Dtype a, Dtype b);
		void swap(int i, int j);
		void swim(int k);
		void sink(int k);
		
	public:
		MyPQ(Dtype *data, int len, int max_cap);
		void insert(Dtype new_data);
		void removeMax();
		inline bool empty() {return N == 0;}
		void print();
		
		

};

}
#include "myPQ.cpp"
#endif