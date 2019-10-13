#pragma once
using namespace System;
public enum transportType {
	plane = 1,
	train = 2,
	bus = 3
};
public ref class Transport {
public:
	Transport(
		int id,
		String^ shift,
		transportType type,
		int departureID,
		int destinationID,
		DateTime start,
		DateTime arrive,
		double cost);
	String^ shift;
	transportType type;
	int departureID;
	int destinationID;
	DateTime start;
	DateTime arrive;
	double cost;
private:
	int id;
	static int count = 0;
};

