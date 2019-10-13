//utils.h the utils which the program used
#pragma once
#include "cities.h"
#include "timeTable.h"
#include "core.h"
#include "sql.h"
#define convertToUtf8(toConvert) System::Text::Encoding::UTF8->GetString(System::Text::Encoding::Default->GetBytes(toConvert))
template<typename T>
void RemoveNull(System::Collections::Generic::List<T>^ list);
template<typename T>
inline void RemoveNull(System::Collections::Generic::List<T>^ list) {
	// Find Fist Null Element in O(n)
	int count = list->Count;
	for (int i = 0; i < count; i++) {
		if (list[i] == nullptr) {
			// Current Position
			int newCount = i++;
			// Copy non-empty elements to current position in O(n)
			for (; i < count; i++) {
				if (list[i] != nullptr) {
					list[newCount++] = list[i];
				}
			}
			// Remove Extra Positions O(n)
			list->RemoveRange(newCount, count - newCount);
			break;
		}
	}
}
template<typename T>
public value class FindCityPredic
{
	T Value;
public:

	FindCityPredic(T value)
	{
		Value = value;
	}
	bool IsMatch(cities^ comp)
	{
		if constexpr (std::is_same_v<T, String^>)
			return comp->name == Value;
		else
			return comp->id == Value;
	}
};

public value class FindShiftPredic
{
	String^ Value;
public:

	FindShiftPredic(String^ value)
	{
		Value = value;
	}
	bool IsMatch(Transport^ comp)
	{
		return comp->shift == Value;
	}
};
