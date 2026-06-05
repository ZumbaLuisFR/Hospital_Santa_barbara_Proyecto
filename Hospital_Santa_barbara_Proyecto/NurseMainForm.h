#pragma once
// UTF-8 encoding directive
#pragma execution_character_set("utf-8")

#include "EmployeeData.h"
#include "MedicalNotesForm.h"

namespace HospitalSantabarbaraProyecto {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class NurseMainForm : public System::Windows::Forms::Form
	{
	public:
		NurseMainForm(void)
		{
			InitializeComponent();
		}

	protected:
		~NurseMainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::Windows::Forms::Panel^ panelHeader;
		System::Windows::Forms::Label^ labelTitulo;
		System::Windows::Forms::Label^ labelFecha;
		System::Windows::Forms::Label^ labelUsuario;
		System::Windows::Forms::Panel^ panelSidebar;
		System::Windows::Forms::Button^ buttonPacientes;
		System::Windows::Forms::Button^ buttonNotas;
		System::Windows::Forms::Button^ buttonSignosVitales;
		System::Windows::Forms::Button^ buttonObservaciones;
		System::Windows::Forms::Button^ buttonEstado;
		System::Windows::Forms::Button^ buttonCerrarSesion;
		System::Windows::Forms::Panel^ panelContent;
		System::Windows::Forms::ListBox^ listBoxContent;
		System::Windows::Forms::Label^ labelContentTitle;
		System::Windows::Forms::Button^ buttonAbrirNotas;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->panelHeader = (gcnew System::Windows::Forms::Panel());
			this->labelTitulo = (gcnew System::Windows::Forms::Label());
			this->labelFecha = (gcnew System::Windows::Forms::Label());
			this->labelUsuario = (gcnew System::Windows::Forms::Label());
			this->panelSidebar = (gcnew System::Windows::Forms::Panel());
			this->buttonPacientes = (gcnew System::Windows::Forms::Button());
			this->buttonNotas = (gcnew System::Windows::Forms::Button());
			this->buttonSignosVitales = (gcnew System::Windows::Forms::Button());
			this->buttonObservaciones = (gcnew System::Windows::Forms::Button());
			this->buttonEstado = (gcnew System::Windows::Forms::Button());
			this->buttonCerrarSesion = (gcnew System::Windows::Forms::Button());
			this->panelContent = (gcnew System::Windows::Forms::Panel());
			this->listBoxContent = (gcnew System::Windows::Forms::ListBox());
			this->labelContentTitle = (gcnew System::Windows::Forms::Label());
			this->buttonAbrirNotas = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();

			// panelHeader
			this->panelHeader->BackColor = System::Drawing::Color::FromArgb(0, 153, 76);
			this->panelHeader->Dock = System::Windows::Forms::DockStyle::Top;
			this->panelHeader->Height = 80;
			this->panelHeader->Name = L"panelHeader";

			// labelTitulo
			this->labelTitulo->AutoSize = true;
			this->labelTitulo->Font = (gcnew System::Drawing::Font(L"Arial", 24, System::Drawing::FontStyle::Bold));
			this->labelTitulo->ForeColor = System::Drawing::Color::White;
			this->labelTitulo->Location = System::Drawing::Point(15, 15);
			this->labelTitulo->Name = L"labelTitulo";
			this->labelTitulo->Size = System::Drawing::Size(532, 46);
			this->labelTitulo->TabIndex = 0;
			this->labelTitulo->Text = L"Hospital Santa Bárbara";

			// labelFecha
			this->labelFecha->AutoSize = true;
			this->labelFecha->Font = (gcnew System::Drawing::Font(L"Arial", 11));
			this->labelFecha->ForeColor = System::Drawing::Color::White;
			this->labelFecha->Location = System::Drawing::Point(900, 20);
			this->labelFecha->Name = L"labelFecha";
			this->labelFecha->Size = System::Drawing::Size(100, 21);
			this->labelFecha->TabIndex = 1;
			this->labelFecha->Text = System::DateTime::Now.ToString(L"dd/MM/yyyy HH:mm");

			// labelUsuario
			this->labelUsuario->AutoSize = true;
			this->labelUsuario->Font = (gcnew System::Drawing::Font(L"Arial", 11));
			this->labelUsuario->ForeColor = System::Drawing::Color::White;
			this->labelUsuario->Location = System::Drawing::Point(850, 50);
			this->labelUsuario->Name = L"labelUsuario";
			this->labelUsuario->Size = System::Drawing::Size(200, 21);
			this->labelUsuario->TabIndex = 2;
			this->labelUsuario->Text = L"Usuario: " + HospitalData::usuarioActual;

			this->panelHeader->Controls->Add(this->labelTitulo);
			this->panelHeader->Controls->Add(this->labelFecha);
			this->panelHeader->Controls->Add(this->labelUsuario);

			// panelSidebar
			this->panelSidebar->BackColor = System::Drawing::Color::FromArgb(0, 120, 60);
			this->panelSidebar->Dock = System::Windows::Forms::DockStyle::Left;
			this->panelSidebar->Width = 200;
			this->panelSidebar->Name = L"panelSidebar";

			// Botones del Sidebar
			this->buttonPacientes->BackColor = System::Drawing::Color::FromArgb(0, 120, 60);
			this->buttonPacientes->ForeColor = System::Drawing::Color::White;
			this->buttonPacientes->Font = (gcnew System::Drawing::Font(L"Arial", 11));
			this->buttonPacientes->Location = System::Drawing::Point(0, 10);
			this->buttonPacientes->Size = System::Drawing::Size(200, 50);
			this->buttonPacientes->Text = L"Pacientes Asignados";
			this->buttonPacientes->Click += gcnew System::EventHandler(this, &NurseMainForm::buttonPacientes_Click);
			this->panelSidebar->Controls->Add(this->buttonPacientes);

			this->buttonNotas->BackColor = System::Drawing::Color::FromArgb(0, 120, 60);
			this->buttonNotas->ForeColor = System::Drawing::Color::White;
			this->buttonNotas->Font = (gcnew System::Drawing::Font(L"Arial", 11));
			this->buttonNotas->Location = System::Drawing::Point(0, 70);
			this->buttonNotas->Size = System::Drawing::Size(200, 50);
			this->buttonNotas->Text = L"Notas Médicas";
			this->buttonNotas->Click += gcnew System::EventHandler(this, &NurseMainForm::buttonNotas_Click);
			this->panelSidebar->Controls->Add(this->buttonNotas);

			this->buttonSignosVitales->BackColor = System::Drawing::Color::FromArgb(0, 120, 60);
			this->buttonSignosVitales->ForeColor = System::Drawing::Color::White;
			this->buttonSignosVitales->Font = (gcnew System::Drawing::Font(L"Arial", 11));
			this->buttonSignosVitales->Location = System::Drawing::Point(0, 130);
			this->buttonSignosVitales->Size = System::Drawing::Size(200, 50);
			this->buttonSignosVitales->Text = L"Signos Vitales";
			this->buttonSignosVitales->Click += gcnew System::EventHandler(this, &NurseMainForm::buttonSignosVitales_Click);
			this->panelSidebar->Controls->Add(this->buttonSignosVitales);

			this->buttonObservaciones->BackColor = System::Drawing::Color::FromArgb(0, 120, 60);
			this->buttonObservaciones->ForeColor = System::Drawing::Color::White;
			this->buttonObservaciones->Font = (gcnew System::Drawing::Font(L"Arial", 11));
			this->buttonObservaciones->Location = System::Drawing::Point(0, 190);
			this->buttonObservaciones->Size = System::Drawing::Size(200, 50);
			this->buttonObservaciones->Text = L"Observaciones";
			this->buttonObservaciones->Click += gcnew System::EventHandler(this, &NurseMainForm::buttonObservaciones_Click);
			this->panelSidebar->Controls->Add(this->buttonObservaciones);

			this->buttonEstado->BackColor = System::Drawing::Color::FromArgb(0, 120, 60);
			this->buttonEstado->ForeColor = System::Drawing::Color::White;
			this->buttonEstado->Font = (gcnew System::Drawing::Font(L"Arial", 11));
			this->buttonEstado->Location = System::Drawing::Point(0, 250);
			this->buttonEstado->Size = System::Drawing::Size(200, 50);
			this->buttonEstado->Text = L"Actualizar Estado";
			this->buttonEstado->Click += gcnew System::EventHandler(this, &NurseMainForm::buttonEstado_Click);
			this->panelSidebar->Controls->Add(this->buttonEstado);

			this->buttonCerrarSesion->BackColor = System::Drawing::Color::FromArgb(204, 0, 0);
			this->buttonCerrarSesion->ForeColor = System::Drawing::Color::White;
			this->buttonCerrarSesion->Font = (gcnew System::Drawing::Font(L"Arial", 11, System::Drawing::FontStyle::Bold));
			this->buttonCerrarSesion->Location = System::Drawing::Point(0, 600);
			this->buttonCerrarSesion->Size = System::Drawing::Size(200, 50);
			this->buttonCerrarSesion->Text = L"Cerrar Sesión";
			this->buttonCerrarSesion->Click += gcnew System::EventHandler(this, &NurseMainForm::buttonCerrarSesion_Click);
			this->panelSidebar->Controls->Add(this->buttonCerrarSesion);

			// panelContent
			this->panelContent->BackColor = System::Drawing::Color::White;
			this->panelContent->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelContent->Name = L"panelContent";

			// labelContentTitle
			this->labelContentTitle->AutoSize = true;
			this->labelContentTitle->Font = (gcnew System::Drawing::Font(L"Arial", 16, System::Drawing::FontStyle::Bold));
			this->labelContentTitle->Location = System::Drawing::Point(20, 20);
			this->labelContentTitle->Name = L"labelContentTitle";
			this->labelContentTitle->Size = System::Drawing::Size(150, 31);
			this->labelContentTitle->TabIndex = 0;
			this->labelContentTitle->Text = L"Pacientes Asignados";

			// listBoxContent
			this->listBoxContent->Location = System::Drawing::Point(20, 60);
			this->listBoxContent->Size = System::Drawing::Size(700, 300);
			this->listBoxContent->TabIndex = 1;

			// Cargar pacientes
			for each (Patient^ p in HospitalData::pacientes) {
				this->listBoxContent->Items->Add(p->nombre + L" (ID: " + p->id + L")");
			}

			// buttonAbrirNotas
			this->buttonAbrirNotas->BackColor = System::Drawing::Color::FromArgb(0, 153, 76);
			this->buttonAbrirNotas->Font = (gcnew System::Drawing::Font(L"Arial", 11, System::Drawing::FontStyle::Bold));
			this->buttonAbrirNotas->ForeColor = System::Drawing::Color::White;
			this->buttonAbrirNotas->Location = System::Drawing::Point(20, 380);
			this->buttonAbrirNotas->Size = System::Drawing::Size(250, 45);
			this->buttonAbrirNotas->Text = L"Abrir Notas Médicas";
			this->buttonAbrirNotas->Click += gcnew System::EventHandler(this, &NurseMainForm::buttonAbrirNotas_Click);

			this->panelContent->Controls->Add(this->labelContentTitle);
			this->panelContent->Controls->Add(this->listBoxContent);
			this->panelContent->Controls->Add(this->buttonAbrirNotas);

			// NurseMainForm
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1200, 700);
			this->Controls->Add(this->panelContent);
			this->Controls->Add(this->panelSidebar);
			this->Controls->Add(this->panelHeader);
			this->DoubleBuffered = true;
			this->Name = L"NurseMainForm";
			this->Text = L"Hospital Santa Bárbara - Portal del Enfermero";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

	private:
		System::Void buttonPacientes_Click(System::Object^ sender, System::EventArgs^ e) {
			this->listBoxContent->Items->Clear();
			this->labelContentTitle->Text = L"Pacientes Asignados";
			for each (Patient^ p in HospitalData::pacientes) {
				this->listBoxContent->Items->Add(p->nombre + L" (ID: " + p->id + L")");
			}
		}

		System::Void buttonNotas_Click(System::Object^ sender, System::EventArgs^ e) {
			this->listBoxContent->Items->Clear();
			this->labelContentTitle->Text = L"Seleccionar Paciente - Notas Médicas";
			for each (Patient^ p in HospitalData::pacientes) {
				this->listBoxContent->Items->Add(p->nombre + L" (ID: " + p->id + L")");
			}
		}

		System::Void buttonAbrirNotas_Click(System::Object^ sender, System::EventArgs^ e) {
			if (this->listBoxContent->SelectedIndex == -1) {
				MessageBox::Show(L"Por favor selecciona un paciente", L"Selecciona Paciente");
				return;
			}

			String^ selectedItem = this->listBoxContent->SelectedItem->ToString();
			int startIndex = selectedItem->LastIndexOf(L"ID: ") + 4;
			int endIndex = selectedItem->LastIndexOf(L")");
			String^ pacienteID = selectedItem->Substring(startIndex, endIndex - startIndex);

			MedicalNotesForm^ notesForm = gcnew MedicalNotesForm(pacienteID);
			notesForm->ShowDialog();
		}

		System::Void buttonSignosVitales_Click(System::Object^ sender, System::EventArgs^ e) {
			MessageBox::Show(L"Registrar signos vitales del paciente", L"Signos Vitales");
		}

		System::Void buttonObservaciones_Click(System::Object^ sender, System::EventArgs^ e) {
			MessageBox::Show(L"Registrar observaciones del paciente", L"Observaciones");
		}

		System::Void buttonEstado_Click(System::Object^ sender, System::EventArgs^ e) {
			MessageBox::Show(L"Actualizar estado del paciente", L"Actualizar Estado");
		}

		System::Void buttonCerrarSesion_Click(System::Object^ sender, System::EventArgs^ e) {
			HospitalData::usuarioActual = L"";
			HospitalData::rolActual = L"";
			this->Close();
		}
	};
}
