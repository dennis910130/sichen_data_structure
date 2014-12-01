#ifndef MY_TOOLS_HPP_
#define MY_TOOLS_HPP_

#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <time.h>
using namespace std;

namespace sichen {
	class MyTools {
		public:
			void static generateRandomFiles(string filename, int max_val, int len, char type);
			int static readFloatsFromFiles(string filename, float* &data);
			void static writeFloatsToFiles(string filename, float* data, int len);
	};

}



#include "myTools.cpp"
#endif