#pragma once
#pragma unmanaged
#include "utils.h"
#include<vector>
using namespace std;
struct ArcNode {
	int adjvex;
	double cost;
	int timeCost;
	struct ArcNode* next;
};
using ArcNode=struct ArcNode;

struct vertexNode {
	int id;
	ArcNode* firstArc;
};
using vertexNode=struct vertexNode;

struct city {
	int id;
};
using city=struct city;

enum transportType {
	plane = 1,
	train = 2,
	bus = 3
};

struct timeTable {
	char* shift;
	transportType type;
	int departureID;
	int destinationID;
	char* start;
	char* arrive;
	double cost;
};
using timeTable=struct timeTable;

class graph {
public:
	static graph* getInstance(int vertexNum, int numArc, vector<city>* cityList, vector<timeTable>* timeTable);
	int numvertex;
	int numarc;
private:
	graph(int vertexNum, int numArc, vector<city>* cityList, vector<timeTable>* timeTable);
	vertexNode* table;
	int currentCount = 0;
	static graph* _instance;
};

vector<city>* convertCityList(System::Collections::Generic::List <cities^>^ list);

vector<timeTable>* convertTimeTable(System::Collections::Generic::List <Transport^>^ list);