#ifndef ANODE_H
#define ANODE_H
template <typename T>
class ANode
{
public:
	T info;
	int next;
	ANode() : next(-1)
	{ }
	ANode(T val) :info(val), next(-1)
	{ }	
};
#endif // !ANODE_H