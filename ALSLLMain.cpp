#include"ALSLL.h"
int main()
{
	ALSLL<int> q;
	q.insertAtTail(1);
	q.insertAtTail(2);
	q.insertAtTail(3);
	q.insertAtTail(4);
	
	q.deleteBefore(5);
	q.display();

	return 0;
}