#include "myTools.hpp"

namespace sichen{
	void MyTools::generateRandomFiles(string filename, int max_val, int len, char type) {
		if (type == 'f') {
			ofstream out(filename);
			srand(time(NULL));
			out << len << ' ';
			for (int i = 0; i < len; i++) {
				float x = (float) rand() / (float) (RAND_MAX/max_val);
				out << x << ' ';
			}
			out.close();
		}
	}
	
	int MyTools::readFloatsFromFiles(string filename, float* &data) {
		ifstream in(filename);
		int len;
		in >> len;
		data = new float[len];
		for (int i = 0; i < len; i++) {
			in >> data[i];
		}
		in.close();
		return len;
	}
	
	void MyTools::writeFloatsToFiles(string filename, float* data, int len) {
		
		ofstream out(filename);
		out << len << ' ';
		for (int i = 0; i < len; i++) {
			out << data[i] << ' ';
		}
		out.close();
		
	}
}