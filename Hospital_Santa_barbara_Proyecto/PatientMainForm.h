#pragma once

#include "EmployeeData.h"

namespace HospitalSantabarbaraProyecto {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class PatientMainForm : public System::Windows::Forms::Form
	{
	public:
		PatientMainForm(void)
		{
			InitializeComponent();
		}

	protected:
		~PatientMainForm()
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
		System::Windows::Forms::Button^ buttonDatos;
		System::Windows::Forms::Button^ buttonCitas;
		System::Windows::Forms::Button^ buttonRecetas;
		System::Windows::Forms::Button^ buttonHistorial;
		System::Windows::Forms::Button^ buttonSolicitarCita;
		System::Windows::Forms::Button^ buttonCerrarSesion;
		System::Windows::Forms::Panel^ panelContent;
		System::Windows::Forms::ListBox^ listBoxContent;
		System::Windows::Forms::Label^ labelContentTitle;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->panelHeader = (gcnew System::Windows::Forms::Panel());
			this->labelTitulo = (gcnew System::Windows::Forms::Label());
			this->labelFecha = (gcnew System::Windows::Forms::Label());
			this->labelUsuario = (gcnew System::Windows::Forms::Label());
			this->panelSidebar = (gcnew System::Windows::Forms::Panel());
			this->buttonDatos = (gcnew System::Windows::Forms::Button());
			this->buttonCitas = (gcnew System::Windows::Forms::Button());
			this->buttonRecetas = (gcnew System::Windows::Forms::Button());
			this->buttonHistorial = (gcnew System::Windows::Forms::Button());
			this->buttonSolicitarCita = (gcnew System::Windows::Forms::Button());
			this->buttonCerrarSesion = (gcnew System::Windows::Forms::Button());
			this->panelContent = (gcnew System::Windows::Forms::Panel());
			this->listBoxContent = (gcnew System::Windows::Forms::ListBox());
			this->labelContentTitle = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();

			// panelHeader
			this->panelHeader->BackColor = System::Drawing::Color::FromArgb(100, 150, 200);
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
			this->panelSidebar->BackColor = System::Drawing::Color::FromArgb(70, 110, 160);
			this->panelSidebar->Dock = System::Windows::Forms::DockStyle::Left;
			this->panelSidebar->Width = 200;
			this->panelSidebar->Name = L"panelSidebar";

			// Botones del Sidebar
			this->buttonDatos->BackColor = System::Drawing::Color::FromArgb(70, 110, 160);
			this->buttonDatos->ForeColor = System::Drawing::Color::White;
			this->buttonDatos->Font = (gcnew System::Drawing::Font(L"Arial", 11));
			this->buttonDatos->Location = System::Drawing::Point(0, 10);
			this->buttonDatos->Size = System::Drawing::Size(200, 50);
			this->buttonDatos->Text = L"Mis Datos";
			this->buttonDatos->Click += gcnew System::EventHandler(this, &PatientMainForm::buttonDatos_Click);
			this->panelSidebar->Controls->Add(this->buttonDatos);

			this->buttonCitas->BackColor = System::Drawing::Color::FromArgb(70, 110, 160);
			this->buttonCitas->ForeColor = System::Drawing::Color::White;
			this->buttonCitas->Font = (gcnew System::Drawing::Font(L"Arial", 11));
			this->buttonCitas->Location = System::Drawing::Point(0, 70);
			this->buttonCitas->Size = System::Drawing::Size(200, 50);
			this->buttonCitas->Text = L"Mis Citas";
			this->buttonCitas->Click += gcnew System::EventHandler(this, &PatientMainForm::buttonCitas_Click);
			this->panelSidebar->Controls->Add(this->buttonCitas);

			this->buttonRecetas->BackColor = System::Drawing::Color::FromArgb(70, 110, 160);
			this->buttonRecetas->ForeColor = System::Drawing::Color::White;
			this->buttonRecetas->Font = (gcnew System::Drawing::Font(L"Arial", 11));
			this->buttonRecetas->Location = System::Drawing::Point(0, 130);
			this->buttonRecetas->Size = System::Drawing::Size(200, 50);
			this->buttonRecetas->Text = L"Mis Recetas";
			this->buttonRecetas->Click += gcnew System::EventHandler(this, &PatientMainForm::buttonRecetas_Click);
			this->panelSidebar->Controls->Add(this->buttonRecetas);

			this->buttonHistorial->BackColor = System::Drawing::Color::FromArgb(70, 110, 160);
			this->buttonHistorial->ForeColor = System::Drawing::Color::White;
			this->buttonHistorial->Font = (gcnew System::Drawing::Font(L"Arial", 11));
			this->buttonHistorial->Location = System::Drawing::Point(0, 190);
			this->buttonHistorial->Size = System::Drawing::Size(200, 50);
			this->buttonHistorial->Text = L"Historial Médico";
			this->buttonHistorial->Click += gcnew System::EventHandler(this, &PatientMainForm::buttonHistorial_Click);
			this->panelSidebar->Controls->Add(this->buttonHistorial);

			this->buttonSolicitarCita->BackColor = System::Drawing::Color::FromArgb(0, 153, 76);
			this->buttonSolicitarCita->ForeColor = System::Drawing::Color::White;
			this->buttonSolicitarCita->Font = (gcnew System::Drawing::Font(L"Arial", 11, System::Drawing::FontStyle::Bold));
			this->buttonSolicitarCita->Location = System::Drawing::Point(0, 250);
			this->buttonSolicitarCita->Size = System::Drawing::Size(200, 50);
			this->buttonSolicitarCita->Text = L"Solicitar Cita";
			this->buttonSolicitarCita->Click += gcnew System::EventHandler(this, &PatientMainForm::buttonSolicitarCita_Click);
			this->panelSidebar->Controls->Add(this->buttonSolicitarCita);

			this->buttonCerrarSesion->BackColor = System::Drawing::Color::FromArgb(204, 0, 0);
			this->buttonCerrarSesion->ForeColor = System::Drawing::Color::White;
			this->buttonCerrarSesion->Font = (gcnew System::Drawing::Font(L"Arial", 11, System::Drawing::FontStyle::Bold));
			this->buttonCerrarSesion->Location = System::Drawing::Point(0, 600);
			this->buttonCerrarSesion->Size = System::Drawing::Size(200, 50);
			this->buttonCerrarSesion->Text = L"Cerrar Sesión";
			this->buttonCerrarSesion->Click += gcnew System::EventHandler(this, &PatientMainForm::buttonCerrarSesion_Click);
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
			this->labelContentTitle->Text = L"Mis Datos";

			// listBoxContent
			this->listBoxContent->Location = System::Drawing::Point(20, 60);
			this->listBoxContent->Size = System::Drawing::Size(700, 300);
			this->listBoxContent->TabIndex = 1;

			// Cargar datos del paciente
			Patient^ paciente = HospitalData::BuscarPaciente(HospitalData::usuarioActual);
			if (paciente != nullptr) {
				this->listBoxContent->Items->Add(L"Nombre: " + paciente->nombre);
				this->listBoxContent->Items->Add(L"Email: " + paciente->email);
				this->listBoxContent->Items->Add(L"Teléfono: " + paciente->telefono);
				this->listBoxContent->Items->Add(L"Dirección: " + paciente->direccion);
			}

			this->panelContent->Controls->Add(this->labelContentTitle);
			this->panelContent->Controls->Add(this->listBoxContent);

			// PatientMainForm
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1200, 700);
			this->Controls->Add(this->panelContent);
			this->Controls->Add(this->panelSidebar);
			this->Controls->Add(this->panelHeader);
			this->DoubleBuffered = true;
			this->Name = L"PatientMainForm";
			this->Text = L"Hospital Santa Bárbara - Portal del Paciente";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

	private:
		System::Void buttonDatos_Click(System::Object^ sender, System::EventArgs^ e) {
			this->listBoxContent->Items->Clear();
			this->labelContentTitle->Text = L"Mis Datos";
			Patient^ paciente = HospitalData::BuscarPaciente(HospitalData::usuarioActual);
			if (paciente != nullptr) {
				this->listBoxContent->Items->Add(L"Nombre: " + paciente->nombre);
				this->listBoxContent->Items->Add(L"Email: " + paciente->email);
				this->listBoxContent->Items->Add(L"Teléfono: " + paciente->telefono);
				this->listBoxContent->Items->Add(L"Dirección: " + paciente->direccion);
			}
		}

		System::Void buttonCitas_Click(System::Object^ sender, System::EventArgs^ e) {
			this->listBoxContent->Items->Clear();
			this->labelContentTitle->Text = L"Mis Citas";
			for each (Appointment^ c in HospitalData::citas) {
				if (c->idPaciente == HospitalData::usuarioActual) {
					this->listBoxContent->Items->Add(c->fecha + L" - " + c->hora + L": " + c->doctor);
				}
			}
		}

		System::Void buttonRecetas_Click(System::Object^ sender, System::EventArgs^ e) {
			this->listBoxContent->Items->Clear();
			this->labelContentTitle->Text = L"Mis Recetas";
			for each (Recipe^ r in HospitalData::recetas) {
				if (r->idPaciente == HospitalData::usuarioActual) {
					this->listBoxContent->Items->Add(r->medicamentos + L" - " + r->dosis);
				}
			}
		}

		System::Void buttonHistorial_Click(System::Object^ sender, System::EventArgs^ e) {
			this->listBoxContent->Items->Clear();
			this->labelContentTitle->Text = L"Historial Médico";
			for each (MedicalHistory^ h in HospitalData::historialMedico) {
				if (h->idPaciente == HospitalData::usuarioActual) {
					this->listBoxContent->Items->Add(h->diagnostico + L" - " + h->fecha);
				}
			}
		}

		System::Void buttonSolicitarCita_Click(System::Object^ sender, System::EventArgs^ e) {
			MessageBox::Show(L"Formulario para solicitar cita médica", L"Solicitar Cita");
		}

		System::Void buttonCerrarSesion_Click(System::Object^ sender, System::EventArgs^ e) {
			HospitalData::usuarioActual = L"";
			HospitalData::rolActual = L"";
			this->Close();
		}
	};
}
