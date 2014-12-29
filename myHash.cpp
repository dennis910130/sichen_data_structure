#include "myHash.hpp"

namespace sichen {
	MyHash::~MyHash(void) {
		//to do: implement this function 
	}
	unsigned long MyHash::hashFunc(const string s) {
		unsigned long out = 0;
		for (int i = 0; i < s.length(); i++) {
			out *= 33;
			out += s[i];
		}
		//cout << "debug" << out << endl;
		out = out % capacity;
		cout << "hashKey: " <<out << endl;
		return out;
	}
	bool MyHash::set(const string s) {
		unsigned long hashKey = hashFunc(s);
		if (table[hashKey] == NULL) {
			table[hashKey] = new ListNode(s);
			std::cout << s << " inserted!" << std::endl;
		}
		else {
			ListNode *tmp = table[hashKey];
			while (tmp->next != NULL && tmp->val != s) {
				tmp = tmp->next;
			}
			if (tmp->val == s) {
				std::cout << s << " already existed!" << std::endl;
			}
			else {
				tmp->next = new ListNode(s);
				std::cout << s << "inserted!" << std::endl;
			}
		}
		return true;
	}
	bool MyHash::find(const string s) {
		unsigned long hashKey = hashFunc(s);
		ListNode *tmp = table[hashKey];
		while (tmp != NULL) {
			if (tmp->val == s) {
				cout << "found!" << endl;
				return true;
			}
			tmp = tmp->next;
		}
		return false;
	}
	bool MyHash::erase(const string s) {
		unsigned long hashKey = hashFunc(s);
		ListNode *tmp = table[hashKey];
		if (tmp == NULL) {
			std::cout << s << " not found! " << std::endl;
			return false;
		}
		else {
			if (tmp->val == s) {
				ListNode *prev = tmp;
				table[hashKey] = tmp->next;
				delete prev;
				cout << "delete!" << endl;
				return true;
			}
			else{
				ListNode *prev = tmp;
				tmp = tmp->next;
				while (tmp != NULL && tmp->val != s) {
					tmp = tmp->next;
					prev = prev->next;
				}
				if (tmp == NULL) {
					std::cout << s << " not found! " << std::endl;
					return false;
				}
				else {
					prev->next = tmp->next;
					delete tmp;
					cout << "delete!" << endl;
					return true;
				}
			}
			
		}
	}
}