/*

	Class PathCalculator

*/
//------------------------------------------------------------
#pragma once
//------------------------------------------------------------
#include "Node.h"
#include <vector>
//------------------------------------------------------------
using namespace std;
class PathCalculator {
//------------------------------------------------------------
	PathCalculator();
	~PathCalculator();
//------------------------------------------------------------
public:


//------------------------------------------------------------
private:
	//Methods:
	void OpenNodes();
	void CalculateAdyacentNodes();
	void OpenAdyacentNodes();
	void CalculateCost();
	void PathResult();
	void CloseNode();
	bool IsNodeEnd();
	bool AskForOpenNodes();
//------------------------------------------------------------
	//Propertys:

//------------------------------------------------------------
};