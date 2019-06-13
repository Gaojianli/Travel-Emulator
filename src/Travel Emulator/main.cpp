#include "form.h"
using namespace TravelEmulator;
using namespace System::Reflection;

[assembly:AssemblyVersionAttribute("4.7.2")] ;
[STAThread]

int main(array<System::String^>^ args) {

	Application::EnableVisualStyles();
	Application::Run(gcnew form());
	return 0;
}