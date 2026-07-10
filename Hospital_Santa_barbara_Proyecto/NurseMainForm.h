#pragma once
// UTF-8 encoding directive
#pragma execution_character_set("utf-8")

#include "EmployeeData.h"
#include "MedicineDispatchForm.h"
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
		System::Windows::Forms::Button^ buttonDespachoMedicinas;
		System::Windows::Forms::Button^ buttonCerrarSesion;
		System::Windows::Forms::Panel^ panelContent;
		System::Windows::Forms::ListBox^ listBoxContent;
		System::Windows::Forms::Label^ labelContentTitle;
		System::Windows::Forms::Label^ labelEstado;
		System::Windows::Forms::ComboBox^ comboPaciente;
		System::Windows::Forms::ComboBox^ comboEstado;
		System::Windows::Forms::TextBox^ textBoxTemperatura;
		System::Windows::Forms::TextBox^ textBoxPresion;
		System::Windows::Forms::TextBox^ textBoxPulso;
		System::Windows::Forms::RichTextBox^ richTextBoxDetalle;

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
			this->buttonDespachoMedicinas = (gcnew System::Windows::Forms::Button());
			this->buttonCerrarSesion = (gcnew System::Windows::Forms::Button());
			this->panelContent = (gcnew System::Windows::Forms::Panel());
			this->labelContentTitle = (gcnew System::Windows::Forms::Label());
			this->labelEstado = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();

			this->panelHeader->BackColor = System::Drawing::Color::FromArgb(0, 153, 76);
			this->panelHeader->Dock = System::Windows::Forms::DockStyle::Top;
			this->panelHeader->Height = 80;

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

			this->panelSidebar->BackColor = System::Drawing::Color::FromArgb(0, 120, 60);
			this->panelSidebar->Dock = System::Windows::Forms::DockStyle::Left;
			this->panelSidebar->Width = 200;

			ConfigurarBotonMenu(this->buttonPacientes, L"Pacientes Asignados", 10, gcnew System::EventHandler(this, &NurseMainForm::buttonPacientes_Click));
			ConfigurarBotonMenu(this->buttonNotas, L"Notas Médicas", 70, gcnew System::EventHandler(this, &NurseMainForm::buttonNotas_Click));
			ConfigurarBotonMenu(this->buttonSignosVitales, L"Signos Vitales", 130, gcnew System::EventHandler(this, &NurseMainForm::buttonSignosVitales_Click));
			ConfigurarBotonMenu(this->buttonObservaciones, L"Observaciones", 190, gcnew System::EventHandler(this, &NurseMainForm::buttonObservaciones_Click));
			ConfigurarBotonMenu(this->buttonEstado, L"Actualizar Estado", 250, gcnew System::EventHandler(this, &NurseMainForm::buttonEstado_Click));
			ConfigurarBotonMenu(this->buttonDespachoMedicinas, L"Despacho Medicinas", 310, gcnew System::EventHandler(this, &NurseMainForm::buttonDespachoMedicinas_Click));

			this->buttonCerrarSesion->BackColor = System::Drawing::Color::FromArgb(204, 0, 0);
			this->buttonCerrarSesion->ForeColor = System::Drawing::Color::White;
			this->buttonCerrarSesion->Font = (gcnew System::Drawing::Font(L"Arial", 11, System::Drawing::FontStyle::Bold));
			this->buttonCerrarSesion->Location = System::Drawing::Point(0, 600);
			this->buttonCerrarSesion->Size = System::Drawing::Size(200, 50);
			this->buttonCerrarSesion->Text = L"Cerrar Sesión";
			this->buttonCerrarSesion->Click += gcnew System::EventHandler(this, &NurseMainForm::buttonCerrarSesion_Click);
			this->panelSidebar->Controls->Add(this->buttonCerrarSesion);

			this->panelContent->BackColor = System::Drawing::Color::White;
			this->panelContent->Dock = System::Windows::Forms::DockStyle::Fill;

			this->labelContentTitle->AutoSize = true;
			this->labelContentTitle->Font = (gcnew System::Drawing::Font(L"Arial", 16, System::Drawing::FontStyle::Bold));
			this->labelContentTitle->Location = System::Drawing::Point(20, 20);

			this->labelEstado->AutoSize = true;
			this->labelEstado->Font = (gcnew System::Drawing::Font(L"Arial", 10, System::Drawing::FontStyle::Bold));
			this->labelEstado->Location = System::Drawing::Point(20, 500);

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
			CargarPantallaPacientes();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

		void ConfigurarBotonMenu(Button^ boton, String^ texto, int y, EventHandler^ evento) {
			boton->BackColor = System::Drawing::Color::FromArgb(0, 120, 60);
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

		RichTextBox^ CrearArea(String^ valor, int x, int y, int ancho, int alto) {
			RichTextBox^ area = gcnew RichTextBox();
			area->Font = (gcnew System::Drawing::Font(L"Arial", 11));
			area->Location = System::Drawing::Point(x, y);
			area->Size = System::Drawing::Size(ancho, alto);
			area->Text = valor;
			this->panelContent->Controls->Add(area);
			return area;
		}

		Button^ CrearBoton(String^ texto, int x, int y, EventHandler^ evento) {
			Button^ boton = gcnew Button();
			boton->BackColor = System::Drawing::Color::FromArgb(0, 153, 76);
			boton->ForeColor = System::Drawing::Color::White;
			boton->Font = (gcnew System::Drawing::Font(L"Arial", 11, System::Drawing::FontStyle::Bold));
			boton->Location = System::Drawing::Point(x, y);
			boton->Size = System::Drawing::Size(190, 42);
			boton->Text = texto;
			boton->UseVisualStyleBackColor = false;
			boton->Click += evento;
			this->panelContent->Controls->Add(boton);
			return boton;
		}

		void CrearSelectorPacientes(int x, int y) {
			this->comboPaciente = gcnew ComboBox();
			this->comboPaciente->DropDownStyle = ComboBoxStyle::DropDownList;
			this->comboPaciente->Font = (gcnew System::Drawing::Font(L"Arial", 11));
			this->comboPaciente->Location = System::Drawing::Point(x, y);
			this->comboPaciente->Size = System::Drawing::Size(420, 30);
			for each (Patient^ p in HospitalData::pacientes) {
				this->comboPaciente->Items->Add(p->nombre + L" (ID: " + p->id + L")");
			}
			if (this->comboPaciente->Items->Count > 0) this->comboPaciente->SelectedIndex = 0;
			this->panelContent->Controls->Add(this->comboPaciente);
		}

		String^ ObtenerPacienteSeleccionadoId() {
			if (this->comboPaciente == nullptr || this->comboPaciente->SelectedIndex == -1) return L"";
			String^ item = this->comboPaciente->SelectedItem->ToString();
			int startIndex = item->LastIndexOf(L"ID: ") + 4;
			int endIndex = item->LastIndexOf(L")");
			if (startIndex < 4 || endIndex <= startIndex) return L"";
			return item->Substring(startIndex, endIndex - startIndex);
		}

		void GuardarNotaEnHistorial(String^ diagnostico, String^ tratamiento) {
			String^ pacienteID = ObtenerPacienteSeleccionadoId();
			Patient^ paciente = HospitalData::BuscarPaciente(pacienteID);
			if (paciente == nullptr) {
				this->labelEstado->Text = L"Seleccione un paciente.";
				this->labelEstado->ForeColor = System::Drawing::Color::Red;
				return;
			}

			MedicalHistory^ hist = gcnew MedicalHistory();
			hist->idPaciente = paciente->id;
			hist->nombrePaciente = paciente->nombre;
			hist->diagnostico = diagnostico;
			hist->tratamiento = tratamiento;
			hist->fecha = System::DateTime::Now.ToString(L"yyyy-MM-dd HH:mm");
			hist->doctor = HospitalData::usuarioActual;
			HospitalData::historialMedico->Add(hist);
			HospitalData::GuardarDatosJson();
			this->labelEstado->Text = L"Registro guardado correctamente.";
			this->labelEstado->ForeColor = System::Drawing::Color::Green;
		}

		void CargarPantallaPacientes() {
			LimpiarContenido(L"Pacientes Asignados");
			this->listBoxContent = gcnew ListBox();
			this->listBoxContent->Font = (gcnew System::Drawing::Font(L"Arial", 11));
			this->listBoxContent->Location = System::Drawing::Point(20, 70);
			this->listBoxContent->Size = System::Drawing::Size(820, 360);
			for each (Patient^ p in HospitalData::pacientes) {
				this->listBoxContent->Items->Add(p->id + L" | " + p->nombre + L" | " + p->telefono + L" | " + p->email);
			}
			if (this->listBoxContent->Items->Count == 0) this->listBoxContent->Items->Add(L"No hay pacientes registrados.");
			this->panelContent->Controls->Add(this->listBoxContent);
		}

		void CargarPantallaNotas() {
			LimpiarContenido(L"Notas Médicas");
			CrearEtiqueta(L"Paciente", 20, 80);
			CrearSelectorPacientes(170, 75);
			CrearBoton(L"Abrir Notas", 170, 130, gcnew System::EventHandler(this, &NurseMainForm::buttonAbrirNotas_Click));
		}

		void CargarPantallaSignos() {
			LimpiarContenido(L"Signos Vitales");
			CrearEtiqueta(L"Paciente", 20, 80);
			CrearSelectorPacientes(170, 75);
			CrearEtiqueta(L"Temperatura", 20, 130);
			this->textBoxTemperatura = CrearTexto(L"36.5", 170, 125, 160);
			CrearEtiqueta(L"Presión", 20, 175);
			this->textBoxPresion = CrearTexto(L"120/80", 170, 170, 160);
			CrearEtiqueta(L"Pulso", 20, 220);
			this->textBoxPulso = CrearTexto(L"80", 170, 215, 160);
			CrearBoton(L"Guardar", 170, 270, gcnew System::EventHandler(this, &NurseMainForm::buttonGuardarSignos_Click));
			this->panelContent->Controls->Add(this->labelEstado);
		}

		void CargarPantallaObservaciones() {
			LimpiarContenido(L"Observaciones");
			CrearEtiqueta(L"Paciente", 20, 80);
			CrearSelectorPacientes(170, 75);
			CrearEtiqueta(L"Observación", 20, 130);
			this->richTextBoxDetalle = CrearArea(L"", 170, 125, 560, 150);
			CrearBoton(L"Guardar", 170, 300, gcnew System::EventHandler(this, &NurseMainForm::buttonGuardarObservacion_Click));
			this->panelContent->Controls->Add(this->labelEstado);
		}

		void CargarPantallaEstado() {
			LimpiarContenido(L"Actualizar Estado");
			CrearEtiqueta(L"Paciente", 20, 80);
			CrearSelectorPacientes(170, 75);
			CrearEtiqueta(L"Estado", 20, 130);
			this->comboEstado = gcnew ComboBox();
			this->comboEstado->DropDownStyle = ComboBoxStyle::DropDownList;
			this->comboEstado->Font = (gcnew System::Drawing::Font(L"Arial", 11));
			this->comboEstado->Location = System::Drawing::Point(170, 125);
			this->comboEstado->Size = System::Drawing::Size(260, 30);
			this->comboEstado->Items->Add(L"Estable");
			this->comboEstado->Items->Add(L"En observación");
			this->comboEstado->Items->Add(L"Urgente");
			this->comboEstado->Items->Add(L"Alta médica");
			this->comboEstado->SelectedIndex = 0;
			this->panelContent->Controls->Add(this->comboEstado);
			CrearEtiqueta(L"Detalle", 20, 180);
			this->richTextBoxDetalle = CrearArea(L"", 170, 175, 560, 120);
			CrearBoton(L"Guardar", 170, 320, gcnew System::EventHandler(this, &NurseMainForm::buttonGuardarEstado_Click));
			this->panelContent->Controls->Add(this->labelEstado);
		}

	private:
		System::Void buttonPacientes_Click(System::Object^ sender, System::EventArgs^ e) {
			CargarPantallaPacientes();
		}

		System::Void buttonNotas_Click(System::Object^ sender, System::EventArgs^ e) {
			CargarPantallaNotas();
		}

		System::Void buttonAbrirNotas_Click(System::Object^ sender, System::EventArgs^ e) {
			String^ pacienteID = ObtenerPacienteSeleccionadoId();
			if (pacienteID->Length == 0) {
				MessageBox::Show(L"Por favor selecciona un paciente", L"Selecciona Paciente");
				return;
			}
			MedicalNotesForm^ notesForm = gcnew MedicalNotesForm(pacienteID);
			notesForm->ShowDialog();
		}

		System::Void buttonSignosVitales_Click(System::Object^ sender, System::EventArgs^ e) {
			CargarPantallaSignos();
		}

		System::Void buttonObservaciones_Click(System::Object^ sender, System::EventArgs^ e) {
			CargarPantallaObservaciones();
		}

		System::Void buttonEstado_Click(System::Object^ sender, System::EventArgs^ e) {
			CargarPantallaEstado();
		}

		System::Void buttonDespachoMedicinas_Click(System::Object^ sender, System::EventArgs^ e) {
			MedicineDispatchForm^ formDespacho = gcnew MedicineDispatchForm();
			formDespacho->ShowDialog();
		}

		System::Void buttonGuardarSignos_Click(System::Object^ sender, System::EventArgs^ e) {
			String^ detalle = L"Temperatura: " + this->textBoxTemperatura->Text->Trim() +
				L" | Presión: " + this->textBoxPresion->Text->Trim() +
				L" | Pulso: " + this->textBoxPulso->Text->Trim();
			GuardarNotaEnHistorial(L"Control de signos vitales", detalle);
		}

		System::Void buttonGuardarObservacion_Click(System::Object^ sender, System::EventArgs^ e) {
			if (this->richTextBoxDetalle->Text->Trim()->Length == 0) {
				this->labelEstado->Text = L"Ingrese una observación.";
				this->labelEstado->ForeColor = System::Drawing::Color::Red;
				return;
			}
			GuardarNotaEnHistorial(L"Observación de enfermería", this->richTextBoxDetalle->Text->Trim());
			this->richTextBoxDetalle->Clear();
		}

		System::Void buttonGuardarEstado_Click(System::Object^ sender, System::EventArgs^ e) {
			String^ estado = this->comboEstado->SelectedItem->ToString();
			String^ detalle = L"Estado: " + estado + L". " + this->richTextBoxDetalle->Text->Trim();
			GuardarNotaEnHistorial(L"Actualización de estado", detalle);
			this->richTextBoxDetalle->Clear();
		}

		System::Void buttonCerrarSesion_Click(System::Object^ sender, System::EventArgs^ e) {
			HospitalData::usuarioActual = L"";
			HospitalData::rolActual = L"";
			this->Close();
		}
	};
}
