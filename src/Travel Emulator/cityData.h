#pragma once
#include<iostream>
namespace TravelEmulator {
	using namespace System::Collections;
	using namespace System;
	public ref class cityData{
	public:
		cityData(String^ toName) {
			name = toName;
		};
		String^ name;
		~cityData() {};

	private:

	};
}
