/*

	Class Node.h

*/
//------------------------------------------------------------
#pragma once
//------------------------------------------------------------
#include <vector>
//------------------------------------------------------------
using namespace std;
class Node {
//------------------------------------------------------------
public:
	Node(int Row, int Col, int Prop);
	~Node();
	int GetCol();
	int GetRow();
	int GetProperty();
	Node* GetParent();
	vector<Node*> GetAdyacentNodes();
//------------------------------------------------------------
	bool SetParent(Node* Parent);
//------------------------------------------------------------
private:
	Node * m_pkParentNode;
	bool m_bIsOpen;
	int m_iProperty; // 0- Empty / -1 Solid / 0 < x Cost.
	int m_iRow;
	int m_iCol;
	vector<Node*> m_pvkAdyacentNode;
	vector<Node*>::iterator m_pvkiAdyNodIt;
//------------------------------------------------------------
};
