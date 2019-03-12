#pragma once
#include <functional>
using namespace System::IO;
using namespace System;
namespace logger {
	 enum class logLevel { Warning, Info, Error };
ref class Logger {
 private:
  MaterialWinforms::Controls::MaterialTextBox ^ writerBox;

 public:
 
  Logger(MaterialWinforms::Controls::MaterialTextBox ^ writer)
      : writerBox(writer){};
  void writeLog(String ^ log, logLevel level) {
    String ^ logLevelString;
    ;
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
      writerBox->Text = gcnew String(writerBox->Text + time + "\t" + "[" +
                                     logLevelString + "]\t" + log + "\n");
    }
  }
};
}  // namespace logger