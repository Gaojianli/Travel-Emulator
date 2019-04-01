#include "timeTable.h"

Transport::Transport(
	int id,
	String^ shift,
	transportType type,
	int departureID,
	int destinationID,
	DateTime startTime,
	DateTime arriveTime,
	double cost)
	: id(id),
	shift(shift),
	type(type),
	departureID(departureID),
	destinationID(destinationID),
	start(startTime),
	arrive(arriveTime),
	cost(cost) {
	count++;
}
