#pragma once
#pragma execution_character_set("utf-8")

#include "EmployeeData.h"

namespace HospitalSantabarbaraProyecto {

	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;

	public ref class StaffRegistrationForm : public System::Windows::Forms::Form
	{
	public:
		StaffRegistrationForm(String^ idInicial, String^ rolInicial)
		{
			this->idInicial = idInicial;
			this->rolInicial = rolInicial;
			InitializeComponent();
		}

	protected:
		~StaffRegistrationForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		String^ idInicial;
		String^ rolInicial;
		Label^ labelTitulo;
		Label^ labelRol;
		Label^ labelId;
		Label^ labelNombre;
		Label^ labelPassword;
		Label^ labelEspecialidad;
		Label^ labelEstado;
		ComboBox^ comboRol;
		TextBox^ textBoxId;
		TextBox^ textBoxNombre;
		TextBox^ textBoxPassword;
		TextBox^ textBoxEspecialidad;
		Button^ buttonGuardar;
		Button^ buttonCancelar;
		System::ComponentModel::Container^ components;

		void InitializeComponent(void)
		{
			this->labelTitulo = gcnew Label();
			this->labelRol = gcnew Label();
			this->labelId = gcnew Label();
			this->labelNombre = gcnew Label();
			this->labelPassword = gcnew Label();
			this->labelEspecialidad = gcnew Label();
			this->labelEstado = gcnew Label();
			this->comboRol = gcnew ComboBox();
			this->textBoxId = gcnew TextBox();
			this->textBoxNombre = gcnew TextBox();
			this->textBoxPassword = gcnew TextBox();
			this->textBoxEspecialidad = gcnew TextBox();
			this->buttonGuardar = gcnew Button();
			this->buttonCancelar = gcnew Button();
			this->SuspendLayout();

			this->labelTitulo->AutoSize = true;
			this->labelTitulo->Font = gcnew System::Drawing::Font(L"Arial", 22, FontStyle::Bold);
			this->labelTitulo->ForeColor = Color::FromArgb(0, 102, 204);
			this->labelTitulo->Location = Point(30, 25);
			this->labelTitulo->Text = L"Registro de Personal";

			ConfigurarEtiqueta(this->labelRol, L"Rol", 35, 95);
			this->comboRol->DropDownStyle = ComboBoxStyle::DropDownList;
			this->comboRol->Font = gcnew System::Drawing::Font(L"Arial", 11);
			this->comboRol->Location = Point(190, 90);
			this->comboRol->Size = System::Drawing::Size(260, 30);
			this->comboRol->Items->Add(L"Doctor");
			this->comboRol->Items->Add(L"Enfermero");
			this->comboRol->SelectedIndex = (rolInicial == L"Enfermero") ? 1 : 0;
			this->comboRol->SelectedIndexChanged += gcnew EventHandler(this, &StaffRegistrationForm::comboRol_SelectedIndexChanged);

			ConfigurarEtiqueta(this->labelId, L"ID", 35, 140);
			ConfigurarTexto(this->textBoxId, idInicial, 190, 135, 260);
			ConfigurarEtiqueta(this->labelNombre, L"Nombre", 35, 185);
			ConfigurarTexto(this->textBoxNombre, L"", 190, 180, 360);
			ConfigurarEtiqueta(this->labelPassword, L"Contraseña", 35, 230);
			ConfigurarTexto(this->textBoxPassword, L"", 190, 225, 260);
			this->textBoxPassword->UseSystemPasswordChar = true;
			ConfigurarEtiqueta(this->labelEspecialidad, L"Especialidad", 35, 275);
			ConfigurarTexto(this->textBoxEspecialidad, L"General", 190, 270, 360);

			this->buttonGuardar->BackColor = Color::FromArgb(0, 153, 76);
			this->buttonGuardar->ForeColor = Color::White;
			this->buttonGuardar->Font = gcnew System::Drawing::Font(L"Arial", 11, FontStyle::Bold);
			this->buttonGuardar->Location = Point(190, 330);
			this->buttonGuardar->Size = System::Drawing::Size(160, 42);
			this->buttonGuardar->Text = L"Registrar";
			this->buttonGuardar->UseVisualStyleBackColor = false;
			this->buttonGuardar->Click += gcnew EventHandler(this, &StaffRegistrationForm::buttonGuardar_Click);

			this->buttonCancelar->BackColor = Color::FromArgb(100, 100, 100);
			this->buttonCancelar->ForeColor = Color::White;
			this->buttonCancelar->Font = gcnew System::Drawing::Font(L"Arial", 11, FontStyle::Bold);
			this->buttonCancelar->Location = Point(370, 330);
			this->buttonCancelar->Size = System::Drawing::Size(160, 42);
			this->buttonCancelar->Text = L"Cancelar";
			this->buttonCancelar->UseVisualStyleBackColor = false;
			this->buttonCancelar->Click += gcnew EventHandler(this, &StaffRegistrationForm::buttonCancelar_Click);

			this->labelEstado->AutoSize = true;
			this->labelEstado->Font = gcnew System::Drawing::Font(L"Arial", 10, FontStyle::Bold);
			this->labelEstado->Location = Point(190, 390);

			this->Controls->Add(this->labelTitulo);
			this->Controls->Add(this->labelRol);
			this->Controls->Add(this->comboRol);
			this->Controls->Add(this->labelId);
			this->Controls->Add(this->textBoxId);
			this->Controls->Add(this->labelNombre);
			this->Controls->Add(this->textBoxNombre);
			this->Controls->Add(this->labelPassword);
			this->Controls->Add(this->textBoxPassword);
			this->Controls->Add(this->labelEspecialidad);
			this->Controls->Add(this->textBoxEspecialidad);
			this->Controls->Add(this->buttonGuardar);
			this->Controls->Add(this->buttonCancelar);
			this->Controls->Add(this->labelEstado);
			this->ClientSize = System::Drawing::Size(620, 460);
			this->BackColor = Color::FromArgb(240, 240, 240);
			this->StartPosition = FormStartPosition::CenterParent;
			this->Text = L"Hospital Santa Bárbara - Registro de Personal";
			ActualizarEspecialidad();
			this->ResumeLayout(false);
			this->PerformLayout();
		}

		void ConfigurarEtiqueta(Label^ label, String^ texto, int x, int y) {
			label->AutoSize = true;
			label->Font = gcnew System::Drawing::Font(L"Arial", 11);
			label->Location = Point(x, y);
			label->Text = texto;
		}

		void ConfigurarTexto(TextBox^ textBox, String^ texto, int x, int y, int ancho) {
			textBox->Font = gcnew System::Drawing::Font(L"Arial", 11);
			textBox->Location = Point(x, y);
			textBox->Size = System::Drawing::Size(ancho, 28);
			textBox->Text = texto;
		}

		void ActualizarEspecialidad() {
			bool esDoctor = this->comboRol->SelectedItem->ToString() == L"Doctor";
			this->labelEspecialidad->Visible = esDoctor;
			this->textBoxEspecialidad->Visible = esDoctor;
		}

		System::Void comboRol_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
			ActualizarEspecialidad();
		}

		System::Void buttonGuardar_Click(System::Object^ sender, System::EventArgs^ e) {
			String^ rol = this->comboRol->SelectedItem->ToString();
			String^ id = this->textBoxId->Text->Trim();
			String^ nombre = this->textBoxNombre->Text->Trim();
			String^ contrasena = this->textBoxPassword->Text;

			if (id->Length < 3 || nombre->Length == 0 || contrasena->Length < 4) {
				this->labelEstado->Text = L"Complete ID, nombre y contraseña mínima de 4 caracteres.";
				this->labelEstado->ForeColor = Color::Red;
				return;
			}

			if (rol == L"Doctor") {
				if (HospitalData::BuscarDoctor(id) != nullptr) {
					this->labelEstado->Text = L"Ya existe un doctor con ese ID.";
					this->labelEstado->ForeColor = Color::Red;
					return;
				}
				Doctor^ doctor = gcnew Doctor();
				doctor->id = id;
				doctor->nombre = nombre;
				doctor->contrasena = contrasena;
				doctor->especialidad = this->textBoxEspecialidad->Text->Trim()->Length == 0 ? L"General" : this->textBoxEspecialidad->Text->Trim();
				HospitalData::doctores->Add(doctor);
			}
			else {
				if (HospitalData::BuscarEnfermero(id) != nullptr) {
					this->labelEstado->Text = L"Ya existe un enfermero con ese ID.";
					this->labelEstado->ForeColor = Color::Red;
					return;
				}
				Nurse^ enfermero = gcnew Nurse();
				enfermero->id = id;
				enfermero->nombre = nombre;
				enfermero->contrasena = contrasena;
				HospitalData::enfermeros->Add(enfermero);
			}

			HospitalData::GuardarDatosJson();
			MessageBox::Show(L"Registro guardado. Ahora puede iniciar sesión.", L"Registro Completado");
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Close();
		}

		System::Void buttonCancelar_Click(System::Object^ sender, System::EventArgs^ e) {
			this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->Close();
		}
	};
}
