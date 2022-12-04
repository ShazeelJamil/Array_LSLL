#include"ALSLL.h"
template<typename T>
ALSLL<T>::ALSLL(int s)
{
	arr = new Node<T>(size);
	int i = 0;
	while (i < size)
	{
		arr[i].next = i + 1;
		i++;
	}
	arr[i - 1].next = -1;
	ulh = -1;
	alh = 0;
}
template<typename T>
void ALSLL<T>::insertAtHead(const T& val)
{
	int in = getNewNode();
	if (in == -1)
		return;
	arr[in].next = ulh;
	arr[in].info = val;
	ulh = in;
}
template<typename T>
void ALSLL<T>::insertAtTail(const T& val)
{
	if (ulh==-1)
	{
		insertAtHead(val);
		return;
	}
	int in = getNewNode();
	if (in == -1)
		return;
	int temp = ulh;
	while (arr[temp].next != -1)
		temp = arr[temp].next;
	arr[temp].next = in;
	arr[in].info = val;
	arr[in].next = -1;
}
template<typename T>
void ALSLL<T>::insertAfter(const T& key, const T& val)
{
	if (ulh == -1)
		return;
	int in = ulh;
	while (in != -1)
	{
		if (arr[in].info == key)
		{
			int temp = getNewNode();
			if (temp == -1)
				return;
			arr[temp].info = val;
			arr[temp].next = arr[in].next;
			arr[in].next = temp;
			return;
		}
		in = arr[in].next;
	}
}
template<typename T>
void ALSLL<T>::insertBefore(const T& key, const T& val)
{
	if (ulh == -1)
		return;
	if (arr[ulh].info == key)
	{
		insertAtHead(val);
		return;
	}
	int prev = ulh;
	int in = arr[ulh].next;
	while (in != -1)
	{
		if (arr[in].info == key)
		{
			int temp = getNewNode();
			if (temp == -1)
				return;
			arr[temp].info = val;
			arr[temp].next = in;
			arr[prev].next = temp;
			return;
		}
		prev = in;
		in = arr[in].next;
	}
}
template<typename T>
void ALSLL<T>::deleteAtHead()
{
	if (ulh == -1)
		return;
	int temp = ulh;
	ulh = arr[ulh].next;
	returnNode(temp);
}
template<typename T>
void ALSLL<T>::deleteAtTail()
{
	if (ulh == -1)
		return;
	if (arr[ulh].next == -1)
	{
		deleteAtHead();
		return;
	}
	int n = ulh;
	int prev = arr[n].next;
	while (arr[n].next != -1)
	{
		prev = n;
		n = arr[n].next;
	}
	arr[prev].next = -1;
	returnNode(n);
}
template<typename T>
void ALSLL<T>::deleteAfter(const T& key)
{
	if (ulh == -1)
		return;
	int in = ulh;
	while (in != -1)
	{
		if (arr[in].info == key)
		{
			int temp = arr[in].next;
			arr[in].next = arr[temp].next;
			returnNode(temp);
			return;
		}
		in = arr[in].next;
	}
}
template<typename T>
void ALSLL<T>::deleteBefore(const T& key)
{
	if (ulh == -1)
		return;
	if (arr[arr[ulh].next].info == key)
	{
		deleteAtHead();
		return;
	}
	int prev = ulh;
	int in = arr[ulh].next;
	while (in != -1)
	{
		if (arr[arr[in].next].info == key)
		{
			arr[prev].next = arr[in].next;
			returnNode(in);
			return;
		}
		prev = in;
		in = arr[in].next;
	}
}
template<typename T>
int ALSLL<T>::getNewNode()
{
	if (alh == -1)
		return -1;
	int temp = alh;
	alh = arr[alh].next;
	return temp;
}
template<typename T>
void ALSLL<T>::returnNode(int ind)
{
	if (ind < 0 || ind >= SIZE)
		return;
	arr[ind].next = alh;
	alh = ind;
}
template<typename T>
void ALSLL<T>::display()
{
	if (ulh == -1)
		return;
	int n = ulh;
	do
	{
		cout << arr[n].info << " ";
		n = arr[n].next;
	} while (n != -1);
	
}