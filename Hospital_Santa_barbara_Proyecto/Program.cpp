// UTF-8 encoding directive
#pragma execution_character_set("utf-8")
#include "LoginForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace HospitalSantabarbaraProyecto;

[STAThreadAttribute]
int main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	LoginForm^ form = gcnew LoginForm();
	Application::Run(form);

	return 0;
}
