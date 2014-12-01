#include "mySort.hpp"
#include "myTools.hpp"
#include "myPQ.hpp"

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
	cout << "Heap Test:" << endl;
	int b[] = {5,3,2,1,10};
	sichen::MyPQ<int> tmp(b,5,200);
	cout << "Empty? " << tmp.empty() << endl;
	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		tmp.insert(rand()%1000);
		tmp.print();
	}
	return 0;
}
