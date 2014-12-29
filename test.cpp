#include "mySort.hpp"
#include "myTools.hpp"
#include "myPQ.hpp"
#include "myHash.hpp"

bool compare(int a, int b) {
	return a > b;
}

int main (int argc, char** argv) {
	//test sort
	cout << "Sort Test:" << endl;
	sichen::MyTools::generateRandomFiles("random_samples.txt", 100, 10000, 'f');
	float *a;
	int len = sichen::MyTools::readFloatsFromFiles("random_samples.txt", a);
	clock_t start = clock();
	sichen::MySort<float>::quickSort(a, len);
	clock_t end = clock();
	double t = (double) (end - start) / CLOCKS_PER_SEC;
	cout << "Time used: " << t << endl;
	sichen::MyTools::writeFloatsToFiles("sorted_samples.txt", a, len);
	
	//test heap
	//use the heap to maintain the highest 10 number of all 1000 numbers generated.
	/*
	cout << "Heap Test:" << endl;
	int b[] = {5,3,2,1,10};
	sichen::MyPQ<int> tmp(b,5,20);
	cout << "Empty? " << tmp.empty() << endl;
	srand(time(NULL));
	tmp.print();
	for (int i = 0; i < 5; i++) {
		tmp.insert(rand()%100);
		tmp.print();
	}
	for (int i = 0; i < 1000; i++) {
		tmp.insert(rand()%100);
		tmp.removeMax();
		tmp.print();
	}
	*/
	//test Hash
	sichen::MyHash hash(10000);
	hash.set("chensi");
	hash.find("chensi");
	hash.erase("chensi");
	hash.erase("chensi");
	
	
	return 0;
}
