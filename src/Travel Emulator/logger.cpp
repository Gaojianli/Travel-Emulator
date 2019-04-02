#include "logger.h"
logger::Logger::Logger(MaterialWinforms::Controls::MaterialTextBox^ writer)
	: writerBox(writer) {}
void logger::Logger::writeLog(String^ log, logLevel level) {
	String^ logLevelString;
	switch (level) {
	case logLevel::Warning:
		logLevelString = gcnew String("Warning");
		break;
	case logLevel::Info:
		logLevelString = gcnew String("Info");
		break;
	case logLevel::Error:
		logLevelString = gcnew String("Error");
		break;
	default:
		logLevelString = gcnew String("Unknown");
		break;
	}
	if (writerBox) {
		auto time = DateTime::Now.ToString("yyyy-MM-dd HH:mm::ss");
		auto temp = System::Text::Encoding::Default->GetBytes(time + "\t" + "[" + logLevelString +
			"]\t" + log + "\n");//convert to utf8
		writerBox->Text = writerBox->Text + System::Text::Encoding::UTF8->GetString(temp);
		delete time;
		delete temp;
	}
}