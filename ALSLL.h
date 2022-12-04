#ifndef ALSLL_H
#define ALSLL_H
#include"ANode.h"
#include<iostream>
using namespace std;
template<typename T>
class ALSLL
{
	int size;
	ANode<T> * arr;
	int ulh;
	int alh;
	int getNewNode();
	void returnNode(int ind);
public:
	ALSLL(int=0);
	void insertAtHead(const T& val);
	void insertAtTail(const T& val);
	void insertBefore(const T& key, const T& val);
	void insertAfter(const T& key, const T& val);
	void deleteAtHead();
	void deleteAtTail();
	void deleteAfter(const T& key);
	void deleteBefore(const T& key);
	void display();

};




#endif // !ALSLL_H