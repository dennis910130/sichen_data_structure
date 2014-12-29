#ifndef MY_HASH_HPP_
#define MY_HASH_HPP_

#include <iostream>
#include <vector>
#include <string>

using namespace std;
namespace sichen {
	
	struct ListNode {
		string val;
		ListNode *next;
		ListNode(string in) : val(in), next(NULL) {}
	};
	
	class MyHash {
		public:
			MyHash(int capacity) {
				this->capacity = capacity;
				cout << "capacity: " << this->capacity << endl;
				table.assign(this->capacity, NULL);
			}
			bool set(const string s);
			bool find(const string s);
			bool erase(const string s);
			
			~MyHash(void);
					
		private:
			int capacity;
			vector<ListNode*> table;
			unsigned long hashFunc(const string s);
	};
}
#include "myHash.cpp"
#endif