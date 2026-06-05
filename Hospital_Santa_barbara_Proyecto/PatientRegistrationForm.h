#pragma once
// UTF-8 encoding directive
#pragma execution_character_set("utf-8")

#include "EmployeeData.h"
#include "PatientMainForm.h"

namespace HospitalSantabarbaraProyecto {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class PatientRegistrationForm : public System::Windows::Forms::Form
	{
	public:
		PatientRegistrationForm(String^ idPaciente)
		{
			pacienteID = idPaciente;
			InitializeComponent();
		}

	protected:
		~PatientRegistrationForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		String^ pacienteID;
		System::Windows::Forms::Label^ labelTitulo;
		System::Windows::Forms::Label^ labelSubtitulo;
		System::Windows::Forms::Label^ labelNombre;
		System::Windows::Forms::TextBox^ textBoxNombre;
		System::Windows::Forms::Label^ labelCedula;
		System::Windows::Forms::TextBox^ textBoxCedula;
		System::Windows::Forms::Label^ labelEmail;
		System::Windows::Forms::TextBox^ textBoxEmail;
		System::Windows::Forms::Label^ labelTelefono;
		System::Windows::Forms::TextBox^ textBoxTelefono;
		System::Windows::Forms::Label^ labelDireccion;
		System::Windows::Forms::TextBox^ textBoxDireccion;
		System::Windows::Forms::Label^ labelContrasena;
		System::Windows::Forms::TextBox^ textBoxContrasena;
		System::Windows::Forms::Button^ buttonGuardar;
		System::Windows::Forms::Button^ buttonCancelar;
		System::Windows::Forms::Label^ labelError;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->labelTitulo = (gcnew System::Windows::Forms::Label());
			this->labelSubtitulo = (gcnew System::Windows::Forms::Label());
			this->labelNombre = (gcnew System::Windows::Forms::Label());
			this->textBoxNombre = (gcnew System::Windows::Forms::TextBox());
			this->labelCedula = (gcnew System::Windows::Forms::Label());
			this->textBoxCedula = (gcnew System::Windows::Forms::TextBox());
			this->labelEmail = (gcnew System::Windows::Forms::Label());
			this->textBoxEmail = (gcnew System::Windows::Forms::TextBox());
			this->labelTelefono = (gcnew System::Windows::Forms::Label());
			this->textBoxTelefono = (gcnew System::Windows::Forms::TextBox());
			this->labelDireccion = (gcnew System::Windows::Forms::Label());
			this->textBoxDireccion = (gcnew System::Windows::Forms::TextBox());
			this->labelContrasena = (gcnew System::Windows::Forms::Label());
			this->textBoxContrasena = (gcnew System::Windows::Forms::TextBox());
			this->buttonGuardar = (gcnew System::Windows::Forms::Button());
			this->buttonCancelar = (gcnew System::Windows::Forms::Button());
			this->labelError = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();

			// labelTitulo
			this->labelTitulo->AutoSize = true;
			this->labelTitulo->BackColor = System::Drawing::Color::Transparent;
			this->labelTitulo->Font = (gcnew System::Drawing::Font(L"Arial", 28, System::Drawing::FontStyle::Bold));
			this->labelTitulo->ForeColor = System::Drawing::Color::FromArgb(0, 102, 204);
			this->labelTitulo->Location = System::Drawing::Point(150, 20);
			this->labelTitulo->Name = L"labelTitulo";
			this->labelTitulo->Size = System::Drawing::Size(600, 54);
			this->labelTitulo->TabIndex = 0;
			this->labelTitulo->Text = L"Registro de Paciente";

			// labelSubtitulo
			this->labelSubtitulo->AutoSize = true;
			this->labelSubtitulo->BackColor = System::Drawing::Color::Transparent;
			this->labelSubtitulo->Font = (gcnew System::Drawing::Font(L"Arial", 11));
			this->labelSubtitulo->ForeColor = System::Drawing::Color::FromArgb(100, 100, 100);
			this->labelSubtitulo->Location = System::Drawing::Point(150, 75);
			this->labelSubtitulo->Name = L"labelSubtitulo";
			this->labelSubtitulo->Size = System::Drawing::Size(700, 21);
			this->labelSubtitulo->TabIndex = 1;
			this->labelSubtitulo->Text = L"Complete su información personal para continuar";

			// labelNombre
			this->labelNombre->AutoSize = true;
			this->labelNombre->Font = (gcnew System::Drawing::Font(L"Arial", 11));
			this->labelNombre->ForeColor = System::Drawing::Color::Black;
			this->labelNombre->Location = System::Drawing::Point(150, 120);
			this->labelNombre->Name = L"labelNombre";
			this->labelNombre->Size = System::Drawing::Size(70, 21);
			this->labelNombre->TabIndex = 2;
			this->labelNombre->Text = L"Nombre";

			// textBoxNombre
			this->textBoxNombre->BackColor = System::Drawing::Color::White;
			this->textBoxNombre->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBoxNombre->Font = (gcnew System::Drawing::Font(L"Arial", 11));
			this->textBoxNombre->Location = System::Drawing::Point(150, 145);
			this->textBoxNombre->Name = L"textBoxNombre";
			this->textBoxNombre->Size = System::Drawing::Size(450, 27);
			this->textBoxNombre->TabIndex = 0;

			// labelCedula
			this->labelCedula->AutoSize = true;
			this->labelCedula->Font = (gcnew System::Drawing::Font(L"Arial", 11));
			this->labelCedula->ForeColor = System::Drawing::Color::Black;
			this->labelCedula->Location = System::Drawing::Point(150, 185);
			this->labelCedula->Name = L"labelCedula";
			this->labelCedula->Size = System::Drawing::Size(67, 21);
			this->labelCedula->TabIndex = 3;
			this->labelCedula->Text = L"Cédula";

			// textBoxCedula
			this->textBoxCedula->BackColor = System::Drawing::Color::White;
			this->textBoxCedula->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBoxCedula->Font = (gcnew System::Drawing::Font(L"Arial", 11));
			this->textBoxCedula->Location = System::Drawing::Point(150, 210);
			this->textBoxCedula->Name = L"textBoxCedula";
			this->textBoxCedula->Size = System::Drawing::Size(450, 27);
			this->textBoxCedula->TabIndex = 1;

			// labelEmail
			this->labelEmail->AutoSize = true;
			this->labelEmail->Font = (gcnew System::Drawing::Font(L"Arial", 11));
			this->labelEmail->ForeColor = System::Drawing::Color::Black;
			this->labelEmail->Location = System::Drawing::Point(150, 250);
			this->labelEmail->Name = L"labelEmail";
			this->labelEmail->Size = System::Drawing::Size(52, 21);
			this->labelEmail->TabIndex = 4;
			this->labelEmail->Text = L"Email";

			// textBoxEmail
			this->textBoxEmail->BackColor = System::Drawing::Color::White;
			this->textBoxEmail->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBoxEmail->Font = (gcnew System::Drawing::Font(L"Arial", 11));
			this->textBoxEmail->Location = System::Drawing::Point(150, 275);
			this->textBoxEmail->Name = L"textBoxEmail";
			this->textBoxEmail->Size = System::Drawing::Size(450, 27);
			this->textBoxEmail->TabIndex = 2;

			// labelTelefono
			this->labelTelefono->AutoSize = true;
			this->labelTelefono->Font = (gcnew System::Drawing::Font(L"Arial", 11));
			this->labelTelefono->ForeColor = System::Drawing::Color::Black;
			this->labelTelefono->Location = System::Drawing::Point(150, 315);
			this->labelTelefono->Name = L"labelTelefono";
			this->labelTelefono->Size = System::Drawing::Size(75, 21);
			this->labelTelefono->TabIndex = 5;
			this->labelTelefono->Text = L"Teléfono";

			// textBoxTelefono
			this->textBoxTelefono->BackColor = System::Drawing::Color::White;
			this->textBoxTelefono->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBoxTelefono->Font = (gcnew System::Drawing::Font(L"Arial", 11));
			this->textBoxTelefono->Location = System::Drawing::Point(150, 340);
			this->textBoxTelefono->Name = L"textBoxTelefono";
			this->textBoxTelefono->Size = System::Drawing::Size(450, 27);
			this->textBoxTelefono->TabIndex = 3;

			// labelDireccion
			this->labelDireccion->AutoSize = true;
			this->labelDireccion->Font = (gcnew System::Drawing::Font(L"Arial", 11));
			this->labelDireccion->ForeColor = System::Drawing::Color::Black;
			this->labelDireccion->Location = System::Drawing::Point(150, 380);
			this->labelDireccion->Name = L"labelDireccion";
			this->labelDireccion->Size = System::Drawing::Size(80, 21);
			this->labelDireccion->TabIndex = 6;
			this->labelDireccion->Text = L"Dirección";

			// textBoxDireccion
			this->textBoxDireccion->BackColor = System::Drawing::Color::White;
			this->textBoxDireccion->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBoxDireccion->Font = (gcnew System::Drawing::Font(L"Arial", 11));
			this->textBoxDireccion->Location = System::Drawing::Point(150, 405);
			this->textBoxDireccion->Name = L"textBoxDireccion";
			this->textBoxDireccion->Size = System::Drawing::Size(450, 27);
			this->textBoxDireccion->TabIndex = 4;

			// labelContrasena
			this->labelContrasena->AutoSize = true;
			this->labelContrasena->Font = (gcnew System::Drawing::Font(L"Arial", 11));
			this->labelContrasena->ForeColor = System::Drawing::Color::Black;
			this->labelContrasena->Location = System::Drawing::Point(150, 445);
			this->labelContrasena->Name = L"labelContrasena";
			this->labelContrasena->Size = System::Drawing::Size(103, 21);
			this->labelContrasena->TabIndex = 7;
			this->labelContrasena->Text = L"Contraseña";

			// textBoxContrasena
			this->textBoxContrasena->BackColor = System::Drawing::Color::White;
			this->textBoxContrasena->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBoxContrasena->Font = (gcnew System::Drawing::Font(L"Arial", 11));
			this->textBoxContrasena->Location = System::Drawing::Point(150, 470);
			this->textBoxContrasena->Name = L"textBoxContrasena";
			this->textBoxContrasena->Size = System::Drawing::Size(450, 27);
			this->textBoxContrasena->TabIndex = 5;
			this->textBoxContrasena->UseSystemPasswordChar = true;

			// labelError
			this->labelError->AutoSize = true;
			this->labelError->Font = (gcnew System::Drawing::Font(L"Arial", 10, System::Drawing::FontStyle::Bold));
			this->labelError->ForeColor = System::Drawing::Color::Red;
			this->labelError->Location = System::Drawing::Point(150, 510);
			this->labelError->Name = L"labelError";
			this->labelError->Size = System::Drawing::Size(0, 19);
			this->labelError->TabIndex = 8;

			// buttonGuardar
			this->buttonGuardar->BackColor = System::Drawing::Color::FromArgb(0, 153, 76);
			this->buttonGuardar->Font = (gcnew System::Drawing::Font(L"Arial", 11, System::Drawing::FontStyle::Bold));
			this->buttonGuardar->ForeColor = System::Drawing::Color::White;
			this->buttonGuardar->Location = System::Drawing::Point(150, 550);
			this->buttonGuardar->Name = L"buttonGuardar";
			this->buttonGuardar->Size = System::Drawing::Size(200, 45);
			this->buttonGuardar->TabIndex = 6;
			this->buttonGuardar->Text = L"Guardar y Continuar";
			this->buttonGuardar->UseVisualStyleBackColor = false;
			this->buttonGuardar->Click += gcnew System::EventHandler(this, &PatientRegistrationForm::buttonGuardar_Click);

			// buttonCancelar
			this->buttonCancelar->BackColor = System::Drawing::Color::FromArgb(204, 0, 0);
			this->buttonCancelar->Font = (gcnew System::Drawing::Font(L"Arial", 11, System::Drawing::FontStyle::Bold));
			this->buttonCancelar->ForeColor = System::Drawing::Color::White;
			this->buttonCancelar->Location = System::Drawing::Point(400, 550);
			this->buttonCancelar->Name = L"buttonCancelar";
			this->buttonCancelar->Size = System::Drawing::Size(200, 45);
			this->buttonCancelar->TabIndex = 7;
			this->buttonCancelar->Text = L"Cancelar";
			this->buttonCancelar->UseVisualStyleBackColor = false;
			this->buttonCancelar->Click += gcnew System::EventHandler(this, &PatientRegistrationForm::buttonCancelar_Click);

			// PatientRegistrationForm
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(240, 240, 240);
			this->ClientSize = System::Drawing::Size(800, 650);
			this->Controls->Add(this->labelError);
			this->Controls->Add(this->buttonCancelar);
			this->Controls->Add(this->buttonGuardar);
			this->Controls->Add(this->textBoxContrasena);
			this->Controls->Add(this->labelContrasena);
			this->Controls->Add(this->textBoxDireccion);
			this->Controls->Add(this->labelDireccion);
			this->Controls->Add(this->textBoxTelefono);
			this->Controls->Add(this->labelTelefono);
			this->Controls->Add(this->textBoxEmail);
			this->Controls->Add(this->labelEmail);
			this->Controls->Add(this->textBoxCedula);
			this->Controls->Add(this->labelCedula);
			this->Controls->Add(this->textBoxNombre);
			this->Controls->Add(this->labelNombre);
			this->Controls->Add(this->labelSubtitulo);
			this->Controls->Add(this->labelTitulo);
			this->DoubleBuffered = true;
			this->Name = L"PatientRegistrationForm";
			this->Text = L"Hospital Santa Bárbara - Registro de Paciente";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

	private:
		System::Void buttonGuardar_Click(System::Object^ sender, System::EventArgs^ e) {
			String^ nombre = this->textBoxNombre->Text->Trim();
			String^ cedula = this->textBoxCedula->Text->Trim();
			String^ email = this->textBoxEmail->Text->Trim();
			String^ telefono = this->textBoxTelefono->Text->Trim();
			String^ direccion = this->textBoxDireccion->Text->Trim();
			String^ contrasena = this->textBoxContrasena->Text;

			// Validación de campos vacíos
			if (nombre->Length == 0 || cedula->Length == 0 || email->Length == 0 || 
				telefono->Length == 0 || direccion->Length == 0 || contrasena->Length == 0) {
				this->labelError->Text = L"Por favor complete todos los campos";
				this->labelError->ForeColor = System::Drawing::Color::Red;
				return;
			}

			// Validación de email básica
			if (!email->Contains(L"@")) {
				this->labelError->Text = L"Email inválido";
				this->labelError->ForeColor = System::Drawing::Color::Red;
				return;
			}

			// Validación de contraseña
			if (contrasena->Length < 4) {
				this->labelError->Text = L"La contraseña debe tener al menos 4 caracteres";
				this->labelError->ForeColor = System::Drawing::Color::Red;
				return;
			}

			// Crear paciente con los datos
			Patient^ paciente = HospitalData::BuscarPaciente(pacienteID);
			if (paciente == nullptr) {
				paciente = gcnew Patient();
				paciente->id = pacienteID;
				HospitalData::pacientes->Add(paciente);
			}

			paciente->nombre = nombre;
			paciente->email = email;
			paciente->telefono = telefono;
			paciente->direccion = direccion;
			paciente->contrasena = contrasena;

			// Guardar los datos persistentemente
			HospitalData::GuardarPacientes();

			HospitalData::usuarioActual = pacienteID;
			HospitalData::rolActual = L"Paciente";

			PatientMainForm^ patientForm = gcnew PatientMainForm();
			this->Hide();
			patientForm->Show();
		}

		System::Void buttonCancelar_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}
	};
}
