#include "form.h"
using namespace TravelEmulator;

[STAThread]

int main(array<System::String^>^ args) {
	Application::EnableVisualStyles();
	Application::Run(gcnew form());
	return 0;
}