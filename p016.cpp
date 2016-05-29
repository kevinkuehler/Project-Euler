/*
	Project Euler Problem 16
	Kevin Kuehler
	https://github.com/kevinkuehler/Project-Euler

	*****************************************************************************

	Prompt:
	2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
	What is the sum of the digits of the number 2^1000?
*/

#include <iostream>
using namespace std;

struct node {
	short val;
	node *next;
};

void insertAfter(node *& p, int x);
void shlListTwo(node *& root);
int splitValSum(short val);

int main() {
	node *root = new node; 
	root->val = 1;
	root->next = NULL;
	
	// LLL holds 2^n, each node holds 3 digits.
	for (int i = 1; i <= 1000; i++) 
		shlListTwo(root);
	
	// Sum and delete the list
	node *p = root;
	node *q = NULL;			   // lag ptr
	int sum = 0;
	while (p != NULL) {
		sum+=splitValSum(p->val);
		if (q != NULL)
			delete q; 
		q = p;
		p = p->next; 
	}

	cout << "Sum of digits: " << sum << endl;

	return 0;
}

void insertAfter(node *& p, int x) {
	node *n = new node;
	n->val = x;
	n->next = NULL;
	p->next = n;
}

void shlListTwo(node *& root) {
	node *p = root;
	short carry = 0;
	short save = 0;
	while (p != NULL) {
		p->val = (p->val << 1) + carry;
		carry = 0;
		if (p->val >= 1000) {
			carry = p->val / 1000;
			save = p->val % 1000;
			if (p->next != NULL)
				p->val = save;
			else {
				p->val = save;
				insertAfter(p, carry);
				break;	// new node means only a carry is left
			}
		}
		p = p->next;
	}
}

int splitValSum(short val) {
	if (val < 10)	        // one digit
		return val;
	else if (val < 100)     // two digits
		return (val / 10) + (val % 10);
	else				    // three digits
		return (val / 100) + ((val % 100) / 10) + val % 10;
}

