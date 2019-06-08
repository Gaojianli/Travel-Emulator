#pragma once
using namespace System::IO;
using namespace System;
namespace logger {
	public enum class logLevel {
		Warning, Info, Error
	};
	public ref class Logger {
	private:
		MaterialWinforms::Controls::MaterialTextBox^ writerBox;

	public:
		Logger(MaterialWinforms::Controls::MaterialTextBox^ writer);
		void writeLog(String^ log, logLevel level);
	};
};  // namespace logger