#pragma once
// UTF-8 encoding directive
#pragma execution_character_set("utf-8")

#include "EmployeeData.h"
#include "RoleSelectionForm.h"
#include "DoctorMainForm.h"
#include "NurseMainForm.h"
#include "PatientMainForm.h"
#include "PatientRegistrationForm.h"

namespace HospitalSantabarbaraProyecto {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class LoginForm : public System::Windows::Forms::Form
	{
	public:
		LoginForm(void)
		{
			InitializeComponent();
			this->textBoxID->Clear();
			this->textBoxPassword->Clear();
			this->textBoxID->Focus();
		}

	protected:
		~LoginForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::Windows::Forms::Label^ labelTitulo;
		System::Windows::Forms::Label^ labelSubtitulo;
		System::Windows::Forms::Label^ labelID;
		System::Windows::Forms::TextBox^ textBoxID;
		System::Windows::Forms::Label^ labelPassword;
		System::Windows::Forms::TextBox^ textBoxPassword;
		System::Windows::Forms::Button^ buttonIngresar;
		System::Windows::Forms::Button^ buttonSalir;
		System::Windows::Forms::Label^ labelError;
		System::Windows::Forms::PictureBox^ pictureBoxLogo;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(LoginForm::typeid));

			this->labelTitulo = (gcnew System::Windows::Forms::Label());
			this->labelSubtitulo = (gcnew System::Windows::Forms::Label());
			this->labelID = (gcnew System::Windows::Forms::Label());
			this->textBoxID = (gcnew System::Windows::Forms::TextBox());
			this->labelPassword = (gcnew System::Windows::Forms::Label());
			this->textBoxPassword = (gcnew System::Windows::Forms::TextBox());
			this->buttonIngresar = (gcnew System::Windows::Forms::Button());
			this->buttonSalir = (gcnew System::Windows::Forms::Button());
			this->labelError = (gcnew System::Windows::Forms::Label());
			this->pictureBoxLogo = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxLogo))->BeginInit();
			this->SuspendLayout();

			// labelTitulo
			this->labelTitulo->AutoSize = true;
			this->labelTitulo->BackColor = System::Drawing::Color::Transparent;
			this->labelTitulo->Font = (gcnew System::Drawing::Font(L"Arial", 32, System::Drawing::FontStyle::Bold));
			this->labelTitulo->ForeColor = System::Drawing::Color::FromArgb(0, 102, 204);
			this->labelTitulo->Location = System::Drawing::Point(200, 40);
			this->labelTitulo->Name = L"labelTitulo";
			this->labelTitulo->Size = System::Drawing::Size(873, 62);
			this->labelTitulo->TabIndex = 0;
			this->labelTitulo->Text = L"Hospital Santa Bárbara";

			// labelSubtitulo
			this->labelSubtitulo->AutoSize = true;
			this->labelSubtitulo->BackColor = System::Drawing::Color::Transparent;
			this->labelSubtitulo->Font = (gcnew System::Drawing::Font(L"Arial", 14));
			this->labelSubtitulo->ForeColor = System::Drawing::Color::FromArgb(100, 100, 100);
			this->labelSubtitulo->Location = System::Drawing::Point(250, 110);
			this->labelSubtitulo->Name = L"labelSubtitulo";
			this->labelSubtitulo->Size = System::Drawing::Size(773, 27);
			this->labelSubtitulo->TabIndex = 1;
			this->labelSubtitulo->Text = L"Sistema de Gestión Hospitalaria - Iniciar Sesión";

			// labelID
			this->labelID->AutoSize = true;
			this->labelID->BackColor = System::Drawing::Color::Transparent;
			this->labelID->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->labelID->ForeColor = System::Drawing::Color::Black;
			this->labelID->Location = System::Drawing::Point(400, 200);
			this->labelID->Name = L"labelID";
			this->labelID->Size = System::Drawing::Size(32, 23);
			this->labelID->TabIndex = 2;
			this->labelID->Text = L"ID";

			// textBoxID
			this->textBoxID->BackColor = System::Drawing::Color::White;
			this->textBoxID->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBoxID->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->textBoxID->ForeColor = System::Drawing::Color::Black;
			this->textBoxID->Location = System::Drawing::Point(400, 230);
			this->textBoxID->Name = L"textBoxID";
			this->textBoxID->Size = System::Drawing::Size(350, 30);
			this->textBoxID->TabIndex = 0;

			// labelPassword
			this->labelPassword->AutoSize = true;
			this->labelPassword->BackColor = System::Drawing::Color::Transparent;
			this->labelPassword->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->labelPassword->ForeColor = System::Drawing::Color::Black;
			this->labelPassword->Location = System::Drawing::Point(400, 280);
			this->labelPassword->Name = L"labelPassword";
			this->labelPassword->Size = System::Drawing::Size(103, 23);
			this->labelPassword->TabIndex = 3;
			this->labelPassword->Text = L"Contraseña";

			// textBoxPassword
			this->textBoxPassword->BackColor = System::Drawing::Color::White;
			this->textBoxPassword->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBoxPassword->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->textBoxPassword->ForeColor = System::Drawing::Color::Black;
			this->textBoxPassword->Location = System::Drawing::Point(400, 310);
			this->textBoxPassword->Name = L"textBoxPassword";
			this->textBoxPassword->Size = System::Drawing::Size(350, 30);
			this->textBoxPassword->TabIndex = 1;
			this->textBoxPassword->UseSystemPasswordChar = true;

			// buttonIngresar
			this->buttonIngresar->BackColor = System::Drawing::Color::FromArgb(0, 153, 76);
			this->buttonIngresar->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold));
			this->buttonIngresar->ForeColor = System::Drawing::Color::White;
			this->buttonIngresar->Location = System::Drawing::Point(400, 380);
			this->buttonIngresar->Name = L"buttonIngresar";
			this->buttonIngresar->Size = System::Drawing::Size(170, 45);
			this->buttonIngresar->TabIndex = 2;
			this->buttonIngresar->Text = L"Ingresar";
			this->buttonIngresar->UseVisualStyleBackColor = false;
			this->buttonIngresar->Click += gcnew System::EventHandler(this, &LoginForm::buttonIngresar_Click);

			// buttonSalir
			this->buttonSalir->BackColor = System::Drawing::Color::FromArgb(204, 0, 0);
			this->buttonSalir->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold));
			this->buttonSalir->ForeColor = System::Drawing::Color::White;
			this->buttonSalir->Location = System::Drawing::Point(580, 380);
			this->buttonSalir->Name = L"buttonSalir";
			this->buttonSalir->Size = System::Drawing::Size(170, 45);
			this->buttonSalir->TabIndex = 3;
			this->buttonSalir->Text = L"Salir";
			this->buttonSalir->UseVisualStyleBackColor = false;
			this->buttonSalir->Click += gcnew System::EventHandler(this, &LoginForm::buttonSalir_Click);

			// labelError
			this->labelError->AutoSize = true;
			this->labelError->BackColor = System::Drawing::Color::Transparent;
			this->labelError->Font = (gcnew System::Drawing::Font(L"Arial", 11, System::Drawing::FontStyle::Bold));
			this->labelError->ForeColor = System::Drawing::Color::Red;
			this->labelError->Location = System::Drawing::Point(400, 350);
			this->labelError->Name = L"labelError";
			this->labelError->Size = System::Drawing::Size(0, 21);
			this->labelError->TabIndex = 4;

			// LoginForm
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(240, 240, 240);
			this->ClientSize = System::Drawing::Size(1200, 700);
			this->Controls->Add(this->labelError);
			this->Controls->Add(this->buttonSalir);
			this->Controls->Add(this->buttonIngresar);
			this->Controls->Add(this->textBoxPassword);
			this->Controls->Add(this->labelPassword);
			this->Controls->Add(this->textBoxID);
			this->Controls->Add(this->labelID);
			this->Controls->Add(this->labelSubtitulo);
			this->Controls->Add(this->labelTitulo);
			this->DoubleBuffered = true;
			this->Name = L"LoginForm";
			this->Text = L"Hospital Santa Bárbara - Iniciar Sesión";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxLogo))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

	private: 
		System::Void buttonIngresar_Click(System::Object^ sender, System::EventArgs^ e) {
			String^ id = this->textBoxID->Text->Trim();
			String^ contrasena = this->textBoxPassword->Text;

			// Validación de campos vacíos
			if (id->Length == 0 || contrasena->Length == 0) {
				this->labelError->Text = L"Por favor complete todos los campos";
				this->labelError->ForeColor = System::Drawing::Color::Red;
				this->textBoxID->Focus();
				return;
			}

			// Validación de longitud mínima
			if (id->Length < 3) {
				this->labelError->Text = L"El ID debe tener al menos 3 caracteres";
				this->labelError->ForeColor = System::Drawing::Color::Red;
				this->textBoxID->Focus();
				return;
			}

			if (contrasena->Length < 4) {
				this->labelError->Text = L"La contraseña debe tener al menos 4 caracteres";
				this->labelError->ForeColor = System::Drawing::Color::Red;
				this->textBoxPassword->Focus();
				return;
			}

			// Verificar si es Doctor
			if (HospitalData::AutenticarDoctor(id, contrasena)) {
				HospitalData::usuarioActual = id;
				HospitalData::rolActual = L"Doctor";
				Doctor^ doc = HospitalData::BuscarDoctor(id);

				DoctorMainForm^ doctorForm = gcnew DoctorMainForm();
				this->Hide();
				doctorForm->Show();
				return;
			}

			// Verificar si es Enfermero
			if (HospitalData::AutenticarEnfermero(id, contrasena)) {
				HospitalData::usuarioActual = id;
				HospitalData::rolActual = L"Enfermero";
				Nurse^ enf = HospitalData::BuscarEnfermero(id);

				NurseMainForm^ nurseForm = gcnew NurseMainForm();
				this->Hide();
				nurseForm->Show();
				return;
			}

			// Verificar si es Paciente registrado
			Patient^ paciente = HospitalData::BuscarPaciente(id);
			if (paciente != nullptr && HospitalData::AutenticarPaciente(id, contrasena)) {
				HospitalData::usuarioActual = id;
				HospitalData::rolActual = L"Paciente";

				PatientMainForm^ patientForm = gcnew PatientMainForm();
				this->Hide();
				patientForm->Show();
				return;
			}

			// Si no existe paciente, mostrar diálogo para registrarse
			if (paciente == nullptr) {
				System::Windows::Forms::DialogResult resultado = MessageBox::Show(
					L"El usuario no existe. ¿Desea registrarse como nuevo paciente?",
					L"Usuario No Registrado",
					System::Windows::Forms::MessageBoxButtons::YesNo,
					System::Windows::Forms::MessageBoxIcon::Question
				);

				if (resultado == System::Windows::Forms::DialogResult::Yes) {
					PatientRegistrationForm^ registrationForm = gcnew PatientRegistrationForm(id);
					registrationForm->ShowDialog();
					this->textBoxPassword->Clear();
					return;
				}
				else {
					this->labelError->Text = L"Por favor ingrese credenciales válidas";
					this->labelError->ForeColor = System::Drawing::Color::Red;
					this->textBoxPassword->Clear();
					return;
				}
			}

			// Si existe pero contraseña es incorrecta
			this->labelError->Text = L"Credenciales inválidas. Intente nuevamente.";
			this->labelError->ForeColor = System::Drawing::Color::Red;
			this->textBoxPassword->Clear();
		}

		System::Void buttonSalir_Click(System::Object^ sender, System::EventArgs^ e) {
			Application::Exit();
		}
	};
}
