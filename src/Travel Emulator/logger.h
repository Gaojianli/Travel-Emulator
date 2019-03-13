#pragma once
#include <functional>
using namespace System::IO;
using namespace System;
namespace logger {
	enum class logLevel {
		Warning, Info, Error
	};
	ref class Logger {
	private:
		MaterialWinforms::Controls::MaterialTextBox^ writerBox;

	public:
		Logger(MaterialWinforms::Controls::MaterialTextBox^ writer);
		void writeLog(String^ log, logLevel level);
	};
};  // namespace logger