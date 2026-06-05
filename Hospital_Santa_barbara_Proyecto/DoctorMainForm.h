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

	public ref class DoctorMainForm : public System::Windows::Forms::Form
	{
	public:
		DoctorMainForm(void)
		{
			InitializeComponent();
		}

	protected:
		~DoctorMainForm()
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
		System::Windows::Forms::Button^ buttonHistorial;
		System::Windows::Forms::Button^ buttonNotas;
		System::Windows::Forms::Button^ buttonDiagnostico;
		System::Windows::Forms::Button^ buttonTratamiento;
		System::Windows::Forms::Button^ buttonRecetas;
		System::Windows::Forms::Button^ buttonCerrarSesion;
		System::Windows::Forms::Panel^ panelContent;
		System::Windows::Forms::ListBox^ listBoxPacientes;
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
			this->buttonHistorial = (gcnew System::Windows::Forms::Button());
			this->buttonNotas = (gcnew System::Windows::Forms::Button());
			this->buttonDiagnostico = (gcnew System::Windows::Forms::Button());
			this->buttonTratamiento = (gcnew System::Windows::Forms::Button());
			this->buttonRecetas = (gcnew System::Windows::Forms::Button());
			this->buttonCerrarSesion = (gcnew System::Windows::Forms::Button());
			this->panelContent = (gcnew System::Windows::Forms::Panel());
			this->listBoxPacientes = (gcnew System::Windows::Forms::ListBox());
			this->labelContentTitle = (gcnew System::Windows::Forms::Label());
			this->buttonAbrirNotas = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();

			// panelHeader
			this->panelHeader->BackColor = System::Drawing::Color::FromArgb(0, 102, 204);
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
			this->panelSidebar->BackColor = System::Drawing::Color::FromArgb(51, 102, 153);
			this->panelSidebar->Dock = System::Windows::Forms::DockStyle::Left;
			this->panelSidebar->Width = 200;
			this->panelSidebar->Name = L"panelSidebar";

			// Botones del Sidebar
			this->buttonPacientes->BackColor = System::Drawing::Color::FromArgb(51, 102, 153);
			this->buttonPacientes->ForeColor = System::Drawing::Color::White;
			this->buttonPacientes->Font = (gcnew System::Drawing::Font(L"Arial", 11));
			this->buttonPacientes->Location = System::Drawing::Point(0, 10);
			this->buttonPacientes->Size = System::Drawing::Size(200, 50);
			this->buttonPacientes->Text = L"Mis Pacientes";
			this->buttonPacientes->Click += gcnew System::EventHandler(this, &DoctorMainForm::buttonPacientes_Click);
			this->panelSidebar->Controls->Add(this->buttonPacientes);

			this->buttonHistorial->BackColor = System::Drawing::Color::FromArgb(51, 102, 153);
			this->buttonHistorial->ForeColor = System::Drawing::Color::White;
			this->buttonHistorial->Font = (gcnew System::Drawing::Font(L"Arial", 11));
			this->buttonHistorial->Location = System::Drawing::Point(0, 70);
			this->buttonHistorial->Size = System::Drawing::Size(200, 50);
			this->buttonHistorial->Text = L"Historial Médico";
			this->buttonHistorial->Click += gcnew System::EventHandler(this, &DoctorMainForm::buttonHistorial_Click);
			this->panelSidebar->Controls->Add(this->buttonHistorial);

			this->buttonNotas->BackColor = System::Drawing::Color::FromArgb(51, 102, 153);
			this->buttonNotas->ForeColor = System::Drawing::Color::White;
			this->buttonNotas->Font = (gcnew System::Drawing::Font(L"Arial", 11));
			this->buttonNotas->Location = System::Drawing::Point(0, 130);
			this->buttonNotas->Size = System::Drawing::Size(200, 50);
			this->buttonNotas->Text = L"Notas Médicas";
			this->buttonNotas->Click += gcnew System::EventHandler(this, &DoctorMainForm::buttonNotas_Click);
			this->panelSidebar->Controls->Add(this->buttonNotas);

			this->buttonDiagnostico->BackColor = System::Drawing::Color::FromArgb(51, 102, 153);
			this->buttonDiagnostico->ForeColor = System::Drawing::Color::White;
			this->buttonDiagnostico->Font = (gcnew System::Drawing::Font(L"Arial", 11));
			this->buttonDiagnostico->Location = System::Drawing::Point(0, 190);
			this->buttonDiagnostico->Size = System::Drawing::Size(200, 50);
			this->buttonDiagnostico->Text = L"Diagnóstico";
			this->buttonDiagnostico->Click += gcnew System::EventHandler(this, &DoctorMainForm::buttonDiagnostico_Click);
			this->panelSidebar->Controls->Add(this->buttonDiagnostico);

			this->buttonTratamiento->BackColor = System::Drawing::Color::FromArgb(51, 102, 153);
			this->buttonTratamiento->ForeColor = System::Drawing::Color::White;
			this->buttonTratamiento->Font = (gcnew System::Drawing::Font(L"Arial", 11));
			this->buttonTratamiento->Location = System::Drawing::Point(0, 190);
			this->buttonTratamiento->Size = System::Drawing::Size(200, 50);
			this->buttonTratamiento->Text = L"Registrar Tratamiento";
			this->buttonTratamiento->Click += gcnew System::EventHandler(this, &DoctorMainForm::buttonTratamiento_Click);
			this->panelSidebar->Controls->Add(this->buttonTratamiento);

			this->buttonRecetas->BackColor = System::Drawing::Color::FromArgb(51, 102, 153);
			this->buttonRecetas->ForeColor = System::Drawing::Color::White;
			this->buttonRecetas->Font = (gcnew System::Drawing::Font(L"Arial", 11));
			this->buttonRecetas->Location = System::Drawing::Point(0, 250);
			this->buttonRecetas->Size = System::Drawing::Size(200, 50);
			this->buttonRecetas->Text = L"Emitir Recetas";
			this->buttonRecetas->Click += gcnew System::EventHandler(this, &DoctorMainForm::buttonRecetas_Click);
			this->panelSidebar->Controls->Add(this->buttonRecetas);

			this->buttonCerrarSesion->BackColor = System::Drawing::Color::FromArgb(204, 0, 0);
			this->buttonCerrarSesion->ForeColor = System::Drawing::Color::White;
			this->buttonCerrarSesion->Font = (gcnew System::Drawing::Font(L"Arial", 11, System::Drawing::FontStyle::Bold));
			this->buttonCerrarSesion->Location = System::Drawing::Point(0, 600);
			this->buttonCerrarSesion->Size = System::Drawing::Size(200, 50);
			this->buttonCerrarSesion->Text = L"Cerrar Sesión";
			this->buttonCerrarSesion->Click += gcnew System::EventHandler(this, &DoctorMainForm::buttonCerrarSesion_Click);
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
			this->labelContentTitle->Text = L"Mis Pacientes";

			// listBoxPacientes
			this->listBoxPacientes->Location = System::Drawing::Point(20, 60);
			this->listBoxPacientes->Size = System::Drawing::Size(700, 300);
			this->listBoxPacientes->TabIndex = 1;

			// Cargar pacientes
			for each (Patient^ p in HospitalData::pacientes) {
				this->listBoxPacientes->Items->Add(p->nombre + L" (ID: " + p->id + L")");
			}

			// buttonAbrirNotas
			this->buttonAbrirNotas->BackColor = System::Drawing::Color::FromArgb(0, 153, 76);
			this->buttonAbrirNotas->Font = (gcnew System::Drawing::Font(L"Arial", 11, System::Drawing::FontStyle::Bold));
			this->buttonAbrirNotas->ForeColor = System::Drawing::Color::White;
			this->buttonAbrirNotas->Location = System::Drawing::Point(20, 380);
			this->buttonAbrirNotas->Size = System::Drawing::Size(250, 45);
			this->buttonAbrirNotas->Text = L"Abrir Notas Médicas";
			this->buttonAbrirNotas->Click += gcnew System::EventHandler(this, &DoctorMainForm::buttonAbrirNotas_Click);

			this->panelContent->Controls->Add(this->labelContentTitle);
			this->panelContent->Controls->Add(this->listBoxPacientes);
			this->panelContent->Controls->Add(this->buttonAbrirNotas);

			// DoctorMainForm
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1200, 700);
			this->Controls->Add(this->panelContent);
			this->Controls->Add(this->panelSidebar);
			this->Controls->Add(this->panelHeader);
			this->DoubleBuffered = true;
			this->Name = L"DoctorMainForm";
			this->Text = L"Hospital Santa Bárbara - Portal del Doctor";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

	private:
		System::Void buttonPacientes_Click(System::Object^ sender, System::EventArgs^ e) {
			this->listBoxPacientes->Items->Clear();
			this->labelContentTitle->Text = L"Mis Pacientes";
			for each (Patient^ p in HospitalData::pacientes) {
				this->listBoxPacientes->Items->Add(p->nombre + L" (ID: " + p->id + L")");
			}
		}

		System::Void buttonHistorial_Click(System::Object^ sender, System::EventArgs^ e) {
			this->listBoxPacientes->Items->Clear();
			this->labelContentTitle->Text = L"Historial Médico";
			for each (MedicalHistory^ h in HospitalData::historialMedico) {
				this->listBoxPacientes->Items->Add(h->nombrePaciente + L": " + h->diagnostico);
			}
		}

		System::Void buttonNotas_Click(System::Object^ sender, System::EventArgs^ e) {
			this->listBoxPacientes->Items->Clear();
			this->labelContentTitle->Text = L"Seleccionar Paciente - Notas Médicas";
			for each (Patient^ p in HospitalData::pacientes) {
				this->listBoxPacientes->Items->Add(p->nombre + L" (ID: " + p->id + L")");
			}
		}

		System::Void buttonAbrirNotas_Click(System::Object^ sender, System::EventArgs^ e) {
			if (this->listBoxPacientes->SelectedIndex == -1) {
				MessageBox::Show(L"Por favor selecciona un paciente", L"Selecciona Paciente");
				return;
			}

			String^ selectedItem = this->listBoxPacientes->SelectedItem->ToString();
			int startIndex = selectedItem->LastIndexOf(L"ID: ") + 4;
			int endIndex = selectedItem->LastIndexOf(L")");
			String^ pacienteID = selectedItem->Substring(startIndex, endIndex - startIndex);

			MedicalNotesForm^ notesForm = gcnew MedicalNotesForm(pacienteID);
			notesForm->ShowDialog();
		}

		System::Void buttonDiagnostico_Click(System::Object^ sender, System::EventArgs^ e) {
			MessageBox::Show(L"Función para registrar diagnósticos", L"Registrar Diagnóstico");
		}

		System::Void buttonTratamiento_Click(System::Object^ sender, System::EventArgs^ e) {
			MessageBox::Show(L"Función para registrar tratamientos", L"Registrar Tratamiento");
		}

		System::Void buttonRecetas_Click(System::Object^ sender, System::EventArgs^ e) {
			this->listBoxPacientes->Items->Clear();
			this->labelContentTitle->Text = L"Recetas Emitidas";
			for each (Recipe^ r in HospitalData::recetas) {
				this->listBoxPacientes->Items->Add(r->nombrePaciente + L": " + r->medicamentos);
			}
		}

		System::Void buttonCerrarSesion_Click(System::Object^ sender, System::EventArgs^ e) {
			HospitalData::usuarioActual = L"";
			HospitalData::rolActual = L"";
			this->Close();
		}
	};
}
