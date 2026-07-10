#pragma once
// UTF-8 encoding directive
#pragma execution_character_set("utf-8")

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
		System::Windows::Forms::Label^ labelEstado;
		System::Windows::Forms::TextBox^ textBoxNombre;
		System::Windows::Forms::TextBox^ textBoxEmail;
		System::Windows::Forms::TextBox^ textBoxTelefono;
		System::Windows::Forms::TextBox^ textBoxDireccion;
		System::Windows::Forms::ComboBox^ comboDoctor;
		System::Windows::Forms::DateTimePicker^ datePickerCita;
		System::Windows::Forms::TextBox^ textBoxHora;
		System::Windows::Forms::RichTextBox^ richTextBoxRazon;

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
			this->labelEstado = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();

			this->panelHeader->BackColor = System::Drawing::Color::FromArgb(100, 150, 200);
			this->panelHeader->Dock = System::Windows::Forms::DockStyle::Top;
			this->panelHeader->Height = 80;
			this->panelHeader->Name = L"panelHeader";

			this->labelTitulo->AutoSize = true;
			this->labelTitulo->Font = (gcnew System::Drawing::Font(L"Arial", 24, System::Drawing::FontStyle::Bold));
			this->labelTitulo->ForeColor = System::Drawing::Color::White;
			this->labelTitulo->Location = System::Drawing::Point(15, 15);
			this->labelTitulo->Text = L"Hospital Santa Bárbara";

			this->labelFecha->AutoSize = true;
			this->labelFecha->Font = (gcnew System::Drawing::Font(L"Arial", 11));
			this->labelFecha->ForeColor = System::Drawing::Color::White;
			this->labelFecha->Location = System::Drawing::Point(900, 20);
			this->labelFecha->Text = System::DateTime::Now.ToString(L"dd/MM/yyyy HH:mm");

			this->labelUsuario->AutoSize = true;
			this->labelUsuario->Font = (gcnew System::Drawing::Font(L"Arial", 11));
			this->labelUsuario->ForeColor = System::Drawing::Color::White;
			this->labelUsuario->Location = System::Drawing::Point(850, 50);
			this->labelUsuario->Text = L"Usuario: " + HospitalData::usuarioActual;

			this->panelHeader->Controls->Add(this->labelTitulo);
			this->panelHeader->Controls->Add(this->labelFecha);
			this->panelHeader->Controls->Add(this->labelUsuario);

			this->panelSidebar->BackColor = System::Drawing::Color::FromArgb(70, 110, 160);
			this->panelSidebar->Dock = System::Windows::Forms::DockStyle::Left;
			this->panelSidebar->Width = 200;
			this->panelSidebar->Name = L"panelSidebar";

			ConfigurarBotonMenu(this->buttonDatos, L"Mis Datos", 10, gcnew System::EventHandler(this, &PatientMainForm::buttonDatos_Click));
			ConfigurarBotonMenu(this->buttonCitas, L"Mis Citas", 70, gcnew System::EventHandler(this, &PatientMainForm::buttonCitas_Click));
			ConfigurarBotonMenu(this->buttonRecetas, L"Mis Recetas", 130, gcnew System::EventHandler(this, &PatientMainForm::buttonRecetas_Click));
			ConfigurarBotonMenu(this->buttonHistorial, L"Historial Médico", 190, gcnew System::EventHandler(this, &PatientMainForm::buttonHistorial_Click));
			ConfigurarBotonMenu(this->buttonSolicitarCita, L"Solicitar Cita", 250, gcnew System::EventHandler(this, &PatientMainForm::buttonSolicitarCita_Click));
			this->buttonSolicitarCita->BackColor = System::Drawing::Color::FromArgb(0, 153, 76);

			this->buttonCerrarSesion->BackColor = System::Drawing::Color::FromArgb(204, 0, 0);
			this->buttonCerrarSesion->ForeColor = System::Drawing::Color::White;
			this->buttonCerrarSesion->Font = (gcnew System::Drawing::Font(L"Arial", 11, System::Drawing::FontStyle::Bold));
			this->buttonCerrarSesion->Location = System::Drawing::Point(0, 600);
			this->buttonCerrarSesion->Size = System::Drawing::Size(200, 50);
			this->buttonCerrarSesion->Text = L"Cerrar Sesión";
			this->buttonCerrarSesion->Click += gcnew System::EventHandler(this, &PatientMainForm::buttonCerrarSesion_Click);
			this->panelSidebar->Controls->Add(this->buttonCerrarSesion);

			this->panelContent->BackColor = System::Drawing::Color::White;
			this->panelContent->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelContent->Name = L"panelContent";

			this->labelContentTitle->AutoSize = true;
			this->labelContentTitle->Font = (gcnew System::Drawing::Font(L"Arial", 16, System::Drawing::FontStyle::Bold));
			this->labelContentTitle->Location = System::Drawing::Point(20, 20);

			this->labelEstado->AutoSize = true;
			this->labelEstado->Font = (gcnew System::Drawing::Font(L"Arial", 10, System::Drawing::FontStyle::Bold));
			this->labelEstado->Location = System::Drawing::Point(20, 470);

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
			CargarPantallaDatos();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

		void ConfigurarBotonMenu(Button^ boton, String^ texto, int y, EventHandler^ evento) {
			boton->BackColor = System::Drawing::Color::FromArgb(70, 110, 160);
			boton->ForeColor = System::Drawing::Color::White;
			boton->Font = (gcnew System::Drawing::Font(L"Arial", 11));
			boton->Location = System::Drawing::Point(0, y);
			boton->Size = System::Drawing::Size(200, 50);
			boton->Text = texto;
			boton->Click += evento;
			this->panelSidebar->Controls->Add(boton);
		}

		void LimpiarContenido(String^ titulo) {
			this->panelContent->Controls->Clear();
			this->labelContentTitle->Text = titulo;
			this->labelContentTitle->Location = System::Drawing::Point(20, 20);
			this->panelContent->Controls->Add(this->labelContentTitle);
			this->labelEstado->Text = L"";
			this->labelEstado->ForeColor = System::Drawing::Color::Green;
		}

		Label^ CrearEtiqueta(String^ texto, int x, int y) {
			Label^ label = gcnew Label();
			label->AutoSize = true;
			label->Font = (gcnew System::Drawing::Font(L"Arial", 11));
			label->Location = System::Drawing::Point(x, y);
			label->Text = texto;
			this->panelContent->Controls->Add(label);
			return label;
		}

		TextBox^ CrearTexto(String^ valor, int x, int y, int ancho) {
			TextBox^ textBox = gcnew TextBox();
			textBox->Font = (gcnew System::Drawing::Font(L"Arial", 11));
			textBox->Location = System::Drawing::Point(x, y);
			textBox->Size = System::Drawing::Size(ancho, 28);
			textBox->Text = valor;
			this->panelContent->Controls->Add(textBox);
			return textBox;
		}

		Button^ CrearBoton(String^ texto, int x, int y, EventHandler^ evento) {
			Button^ boton = gcnew Button();
			boton->BackColor = System::Drawing::Color::FromArgb(0, 153, 76);
			boton->ForeColor = System::Drawing::Color::White;
			boton->Font = (gcnew System::Drawing::Font(L"Arial", 11, System::Drawing::FontStyle::Bold));
			boton->Location = System::Drawing::Point(x, y);
			boton->Size = System::Drawing::Size(180, 42);
			boton->Text = texto;
			boton->UseVisualStyleBackColor = false;
			boton->Click += evento;
			this->panelContent->Controls->Add(boton);
			return boton;
		}

		Patient^ PacienteActual() {
			return HospitalData::BuscarPaciente(HospitalData::usuarioActual);
		}

		void CargarPantallaDatos() {
			LimpiarContenido(L"Mis Datos");
			Patient^ paciente = PacienteActual();
			if (paciente == nullptr) {
				CrearEtiqueta(L"No se encontró el paciente actual.", 20, 70);
				return;
			}

			CrearEtiqueta(L"ID", 20, 75);
			CrearEtiqueta(paciente->id, 180, 75);
			CrearEtiqueta(L"Nombre", 20, 120);
			this->textBoxNombre = CrearTexto(paciente->nombre, 180, 115, 380);
			CrearEtiqueta(L"Email", 20, 165);
			this->textBoxEmail = CrearTexto(paciente->email, 180, 160, 380);
			CrearEtiqueta(L"Teléfono", 20, 210);
			this->textBoxTelefono = CrearTexto(paciente->telefono, 180, 205, 380);
			CrearEtiqueta(L"Dirección", 20, 255);
			this->textBoxDireccion = CrearTexto(paciente->direccion, 180, 250, 520);
			CrearBoton(L"Guardar Datos", 180, 310, gcnew System::EventHandler(this, &PatientMainForm::buttonGuardarDatos_Click));
			this->panelContent->Controls->Add(this->labelEstado);
		}

		void CargarPantallaCitas() {
			LimpiarContenido(L"Mis Citas");
			this->listBoxContent = gcnew ListBox();
			this->listBoxContent->Font = (gcnew System::Drawing::Font(L"Arial", 11));
			this->listBoxContent->Location = System::Drawing::Point(20, 70);
			this->listBoxContent->Size = System::Drawing::Size(760, 330);
			for each (Appointment^ c in HospitalData::citas) {
				if (c->idPaciente == HospitalData::usuarioActual) {
					this->listBoxContent->Items->Add(c->fecha + L" " + c->hora + L" | " + c->doctor + L" | " + c->razon);
				}
			}
			if (this->listBoxContent->Items->Count == 0) {
				this->listBoxContent->Items->Add(L"No tienes citas registradas.");
			}
			this->panelContent->Controls->Add(this->listBoxContent);
		}

		void CargarPantallaRecetas() {
			LimpiarContenido(L"Mis Recetas");
			this->listBoxContent = gcnew ListBox();
			this->listBoxContent->Font = (gcnew System::Drawing::Font(L"Arial", 11));
			this->listBoxContent->Location = System::Drawing::Point(20, 70);
			this->listBoxContent->Size = System::Drawing::Size(760, 330);
			for each (Recipe^ r in HospitalData::recetas) {
				if (r->idPaciente == HospitalData::usuarioActual) {
					this->listBoxContent->Items->Add(r->fecha + L" | " + r->medicamentos + L" | Dosis: " + r->dosis + L" | " + r->indicaciones);
				}
			}
			if (this->listBoxContent->Items->Count == 0) {
				this->listBoxContent->Items->Add(L"No tienes recetas registradas.");
			}
			this->panelContent->Controls->Add(this->listBoxContent);
		}

		void CargarPantallaHistorial() {
			LimpiarContenido(L"Historial Médico");
			this->listBoxContent = gcnew ListBox();
			this->listBoxContent->Font = (gcnew System::Drawing::Font(L"Arial", 11));
			this->listBoxContent->Location = System::Drawing::Point(20, 70);
			this->listBoxContent->Size = System::Drawing::Size(760, 330);
			for each (MedicalHistory^ h in HospitalData::historialMedico) {
				if (h->idPaciente == HospitalData::usuarioActual) {
					this->listBoxContent->Items->Add(h->fecha + L" | " + h->doctor + L" | " + h->diagnostico + L" | " + h->tratamiento);
				}
			}
			if (this->listBoxContent->Items->Count == 0) {
				this->listBoxContent->Items->Add(L"No tienes historial médico registrado.");
			}
			this->panelContent->Controls->Add(this->listBoxContent);
		}

		void CargarPantallaSolicitarCita() {
			LimpiarContenido(L"Solicitar Cita");
			CrearEtiqueta(L"Doctor", 20, 80);
			this->comboDoctor = gcnew ComboBox();
			this->comboDoctor->DropDownStyle = ComboBoxStyle::DropDownList;
			this->comboDoctor->Font = (gcnew System::Drawing::Font(L"Arial", 11));
			this->comboDoctor->Location = System::Drawing::Point(180, 75);
			this->comboDoctor->Size = System::Drawing::Size(380, 30);
			for each (Doctor^ d in HospitalData::doctores) {
				this->comboDoctor->Items->Add(d->nombre + L" (" + d->id + L")");
			}
			if (this->comboDoctor->Items->Count == 0) {
				CrearEtiqueta(L"Primero debe registrarse un doctor en el sistema.", 180, 115);
				this->panelContent->Controls->Add(this->labelEstado);
				return;
			}
			this->comboDoctor->SelectedIndex = 0;
			this->panelContent->Controls->Add(this->comboDoctor);

			CrearEtiqueta(L"Fecha", 20, 125);
			this->datePickerCita = gcnew DateTimePicker();
			this->datePickerCita->Font = (gcnew System::Drawing::Font(L"Arial", 11));
			this->datePickerCita->Format = DateTimePickerFormat::Short;
			this->datePickerCita->Location = System::Drawing::Point(180, 120);
			this->datePickerCita->Size = System::Drawing::Size(180, 30);
			this->panelContent->Controls->Add(this->datePickerCita);

			CrearEtiqueta(L"Hora", 20, 170);
			this->textBoxHora = CrearTexto(L"09:00", 180, 165, 180);
			CrearEtiqueta(L"Razón", 20, 215);
			this->richTextBoxRazon = gcnew RichTextBox();
			this->richTextBoxRazon->Font = (gcnew System::Drawing::Font(L"Arial", 11));
			this->richTextBoxRazon->Location = System::Drawing::Point(180, 210);
			this->richTextBoxRazon->Size = System::Drawing::Size(520, 120);
			this->panelContent->Controls->Add(this->richTextBoxRazon);
			CrearBoton(L"Guardar Cita", 180, 350, gcnew System::EventHandler(this, &PatientMainForm::buttonGuardarCita_Click));
			this->panelContent->Controls->Add(this->labelEstado);
		}

	private:
		System::Void buttonDatos_Click(System::Object^ sender, System::EventArgs^ e) {
			CargarPantallaDatos();
		}

		System::Void buttonCitas_Click(System::Object^ sender, System::EventArgs^ e) {
			CargarPantallaCitas();
		}

		System::Void buttonRecetas_Click(System::Object^ sender, System::EventArgs^ e) {
			CargarPantallaRecetas();
		}

		System::Void buttonHistorial_Click(System::Object^ sender, System::EventArgs^ e) {
			CargarPantallaHistorial();
		}

		System::Void buttonSolicitarCita_Click(System::Object^ sender, System::EventArgs^ e) {
			CargarPantallaSolicitarCita();
		}

		System::Void buttonGuardarDatos_Click(System::Object^ sender, System::EventArgs^ e) {
			Patient^ paciente = PacienteActual();
			if (paciente == nullptr) return;
			if (this->textBoxNombre->Text->Trim()->Length == 0) {
				this->labelEstado->Text = L"El nombre no puede estar vacío.";
				this->labelEstado->ForeColor = System::Drawing::Color::Red;
				return;
			}
			paciente->nombre = this->textBoxNombre->Text->Trim();
			paciente->email = this->textBoxEmail->Text->Trim();
			paciente->telefono = this->textBoxTelefono->Text->Trim();
			paciente->direccion = this->textBoxDireccion->Text->Trim();
			HospitalData::GuardarDatosJson();
			this->labelEstado->Text = L"Datos actualizados correctamente.";
			this->labelEstado->ForeColor = System::Drawing::Color::Green;
		}

		System::Void buttonGuardarCita_Click(System::Object^ sender, System::EventArgs^ e) {
			Patient^ paciente = PacienteActual();
			if (paciente == nullptr) return;
			if (this->comboDoctor->SelectedIndex == -1 || this->richTextBoxRazon->Text->Trim()->Length == 0) {
				this->labelEstado->Text = L"Seleccione un doctor e ingrese la razón de la cita.";
				this->labelEstado->ForeColor = System::Drawing::Color::Red;
				return;
			}

			Appointment^ cita = gcnew Appointment();
			cita->idPaciente = paciente->id;
			cita->nombrePaciente = paciente->nombre;
			cita->doctor = this->comboDoctor->SelectedItem->ToString();
			cita->fecha = this->datePickerCita->Value.ToString(L"yyyy-MM-dd");
			cita->hora = this->textBoxHora->Text->Trim();
			cita->razon = this->richTextBoxRazon->Text->Trim();
			HospitalData::citas->Add(cita);
			HospitalData::GuardarDatosJson();
			this->labelEstado->Text = L"Cita solicitada correctamente.";
			this->labelEstado->ForeColor = System::Drawing::Color::Green;
			this->richTextBoxRazon->Clear();
		}

		System::Void buttonCerrarSesion_Click(System::Object^ sender, System::EventArgs^ e) {
			HospitalData::usuarioActual = L"";
			HospitalData::rolActual = L"";
			this->Close();
		}
	};
}
