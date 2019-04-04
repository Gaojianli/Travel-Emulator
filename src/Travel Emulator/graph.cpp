#include "graph.h"

graph::graph(int vertexNum, int arcNum, vector<city>* cityList, vector<timeTable>* timeTable) :numvertex(vertexNum), numarc(arcNum) {
	table = new vertexNode[vertexNum];

}

graph* graph::getInstance(int vertexNum, int numArc, vector<city>* cityList, vector<timeTable>* timeTable) {
	if (_instance == nullptr)
		_instance = new graph(vertexNum, numArc, cityList, timeTable);
	return _instance;
}

vector<city>* convertCityList(System::Collections::Generic::List <cities^> ^ list) {
	auto toReturn = new vector<city>();
	for each (auto item in list) {
		city toadd;
		toadd.id = item->id;
		toReturn->push_back(toadd);
	}
	return toReturn;
}

vector<timeTable>* convertTimeTable(System::Collections::Generic::List<Transport^> ^ list) {
	auto toReturn = new vector<timeTable>();
	//convert Managed string to unManaged
	auto manToUnman = [](String ^ toConvert)->char* {
		return static_cast<char*>(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(toConvert).ToPointer());
	};
	for each (auto item in list) {
		timeTable toadd;
		toadd.shift = manToUnman(item->shift);
		toadd.type = item->type;
		toadd.departureID = item->departureID;
		toadd.destinationID = item->destinationID;
		toadd.start = manToUnman(item->start.ToString("t"));
		toadd.arrive = manToUnman(item->arrive.ToString("t"));
		toadd.cost = item->cost;
		toReturn->push_back(toadd);
	}
	return toReturn;
}
