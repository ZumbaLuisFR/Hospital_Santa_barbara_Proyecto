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
		System::Windows::Forms::Button^ buttonCitas;
		System::Windows::Forms::Button^ buttonHistorial;
		System::Windows::Forms::Button^ buttonNotas;
		System::Windows::Forms::Button^ buttonDiagnostico;
		System::Windows::Forms::Button^ buttonTratamiento;
		System::Windows::Forms::Button^ buttonRecetas;
		System::Windows::Forms::Button^ buttonCerrarSesion;
		System::Windows::Forms::Panel^ panelContent;
		System::Windows::Forms::ListBox^ listBoxContent;
		System::Windows::Forms::Label^ labelContentTitle;
		System::Windows::Forms::Label^ labelEstado;
		System::Windows::Forms::ComboBox^ comboPaciente;
		System::Windows::Forms::TextBox^ textBoxMedicamentos;
		System::Windows::Forms::TextBox^ textBoxDosis;
		System::Windows::Forms::RichTextBox^ richTextBoxPrincipal;
		System::Windows::Forms::RichTextBox^ richTextBoxSecundario;

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
			this->buttonCitas = (gcnew System::Windows::Forms::Button());
			this->buttonHistorial = (gcnew System::Windows::Forms::Button());
			this->buttonNotas = (gcnew System::Windows::Forms::Button());
			this->buttonDiagnostico = (gcnew System::Windows::Forms::Button());
			this->buttonTratamiento = (gcnew System::Windows::Forms::Button());
			this->buttonRecetas = (gcnew System::Windows::Forms::Button());
			this->buttonCerrarSesion = (gcnew System::Windows::Forms::Button());
			this->panelContent = (gcnew System::Windows::Forms::Panel());
			this->labelContentTitle = (gcnew System::Windows::Forms::Label());
			this->labelEstado = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();

			this->panelHeader->BackColor = System::Drawing::Color::FromArgb(0, 102, 204);
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

			this->panelSidebar->BackColor = System::Drawing::Color::FromArgb(51, 102, 153);
			this->panelSidebar->Dock = System::Windows::Forms::DockStyle::Left;
			this->panelSidebar->Width = 200;

			ConfigurarBotonMenu(this->buttonPacientes, L"Mis Pacientes", 10, gcnew System::EventHandler(this, &DoctorMainForm::buttonPacientes_Click));
			ConfigurarBotonMenu(this->buttonCitas, L"Citas Pendientes", 70, gcnew System::EventHandler(this, &DoctorMainForm::buttonCitas_Click));
			ConfigurarBotonMenu(this->buttonHistorial, L"Historial Médico", 130, gcnew System::EventHandler(this, &DoctorMainForm::buttonHistorial_Click));
			ConfigurarBotonMenu(this->buttonNotas, L"Notas Médicas", 190, gcnew System::EventHandler(this, &DoctorMainForm::buttonNotas_Click));
			ConfigurarBotonMenu(this->buttonDiagnostico, L"Diagnóstico", 250, gcnew System::EventHandler(this, &DoctorMainForm::buttonDiagnostico_Click));
			ConfigurarBotonMenu(this->buttonTratamiento, L"Tratamiento", 310, gcnew System::EventHandler(this, &DoctorMainForm::buttonTratamiento_Click));
			ConfigurarBotonMenu(this->buttonRecetas, L"Emitir Recetas", 370, gcnew System::EventHandler(this, &DoctorMainForm::buttonRecetas_Click));

			this->buttonCerrarSesion->BackColor = System::Drawing::Color::FromArgb(204, 0, 0);
			this->buttonCerrarSesion->ForeColor = System::Drawing::Color::White;
			this->buttonCerrarSesion->Font = (gcnew System::Drawing::Font(L"Arial", 11, System::Drawing::FontStyle::Bold));
			this->buttonCerrarSesion->Location = System::Drawing::Point(0, 600);
			this->buttonCerrarSesion->Size = System::Drawing::Size(200, 50);
			this->buttonCerrarSesion->Text = L"Cerrar Sesión";
			this->buttonCerrarSesion->Click += gcnew System::EventHandler(this, &DoctorMainForm::buttonCerrarSesion_Click);
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
			this->Name = L"DoctorMainForm";
			this->Text = L"Hospital Santa Bárbara - Portal del Doctor";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			CargarPantallaPacientes();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

		void ConfigurarBotonMenu(Button^ boton, String^ texto, int y, EventHandler^ evento) {
			boton->BackColor = System::Drawing::Color::FromArgb(51, 102, 153);
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

		void CargarListaPacientesDetallada() {
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

		void CargarPantallaPacientes() {
			LimpiarContenido(L"Mis Pacientes");
			CargarListaPacientesDetallada();
		}

		void CargarPantallaCitas() {
			LimpiarContenido(L"Citas Pendientes");
			this->listBoxContent = gcnew ListBox();
			this->listBoxContent->Font = (gcnew System::Drawing::Font(L"Arial", 11));
			this->listBoxContent->Location = System::Drawing::Point(20, 70);
			this->listBoxContent->Size = System::Drawing::Size(860, 360);

			for each (Appointment^ c in HospitalData::citas) {
				this->listBoxContent->Items->Add(c->fecha + L" " + c->hora + L" | " + c->nombrePaciente + L" (" + c->idPaciente + L") | " + c->doctor + L" | " + c->razon);
			}

			if (this->listBoxContent->Items->Count == 0) {
				this->listBoxContent->Items->Add(L"No hay citas pendientes.");
			}

			this->panelContent->Controls->Add(this->listBoxContent);
		}

		void CargarPantallaHistorial() {
			LimpiarContenido(L"Historial Médico");
			CrearEtiqueta(L"Paciente", 20, 75);
			CrearSelectorPacientes(170, 70);
			CrearBoton(L"Ver Historial", 610, 68, gcnew System::EventHandler(this, &DoctorMainForm::buttonVerHistorial_Click));
			this->listBoxContent = gcnew ListBox();
			this->listBoxContent->Font = (gcnew System::Drawing::Font(L"Arial", 11));
			this->listBoxContent->Location = System::Drawing::Point(20, 130);
			this->listBoxContent->Size = System::Drawing::Size(820, 300);
			this->panelContent->Controls->Add(this->listBoxContent);
		}

		void CargarPantallaNotas() {
			LimpiarContenido(L"Notas Médicas");
			CrearEtiqueta(L"Paciente", 20, 80);
			CrearSelectorPacientes(170, 75);
			CrearBoton(L"Abrir Notas", 170, 130, gcnew System::EventHandler(this, &DoctorMainForm::buttonAbrirNotas_Click));
		}

		void CargarPantallaDiagnostico() {
			LimpiarContenido(L"Registrar Diagnóstico");
			CrearEtiqueta(L"Paciente", 20, 80);
			CrearSelectorPacientes(170, 75);
			CrearEtiqueta(L"Diagnóstico", 20, 130);
			this->richTextBoxPrincipal = CrearArea(L"", 170, 125, 560, 150);
			CrearBoton(L"Guardar", 170, 300, gcnew System::EventHandler(this, &DoctorMainForm::buttonGuardarDiagnostico_Click));
			this->panelContent->Controls->Add(this->labelEstado);
		}

		void CargarPantallaTratamiento() {
			LimpiarContenido(L"Registrar Tratamiento");
			CrearEtiqueta(L"Paciente", 20, 80);
			CrearSelectorPacientes(170, 75);
			CrearEtiqueta(L"Tratamiento", 20, 130);
			this->richTextBoxPrincipal = CrearArea(L"", 170, 125, 560, 150);
			CrearBoton(L"Guardar", 170, 300, gcnew System::EventHandler(this, &DoctorMainForm::buttonGuardarTratamiento_Click));
			this->panelContent->Controls->Add(this->labelEstado);
		}

		void CargarPantallaRecetas() {
			LimpiarContenido(L"Emitir Recetas");
			CrearEtiqueta(L"Paciente", 20, 80);
			CrearSelectorPacientes(170, 75);
			CrearEtiqueta(L"Medicamentos", 20, 130);
			this->textBoxMedicamentos = CrearTexto(L"", 170, 125, 560);
			CrearEtiqueta(L"Dosis", 20, 175);
			this->textBoxDosis = CrearTexto(L"", 170, 170, 260);
			CrearEtiqueta(L"Indicaciones", 20, 220);
			this->richTextBoxPrincipal = CrearArea(L"", 170, 215, 560, 120);
			CrearBoton(L"Guardar Receta", 170, 360, gcnew System::EventHandler(this, &DoctorMainForm::buttonGuardarReceta_Click));
			this->panelContent->Controls->Add(this->labelEstado);
		}

		void GuardarHistorial(String^ diagnostico, String^ tratamiento) {
			String^ pacienteID = ObtenerPacienteSeleccionadoId();
			Patient^ paciente = HospitalData::BuscarPaciente(pacienteID);
			if (paciente == nullptr) {
				this->labelEstado->Text = L"Seleccione un paciente.";
				this->labelEstado->ForeColor = System::Drawing::Color::Red;
				return;
			}
			if (diagnostico->Trim()->Length == 0 && tratamiento->Trim()->Length == 0) {
				this->labelEstado->Text = L"Ingrese información para guardar.";
				this->labelEstado->ForeColor = System::Drawing::Color::Red;
				return;
			}

			MedicalHistory^ hist = gcnew MedicalHistory();
			hist->idPaciente = paciente->id;
			hist->nombrePaciente = paciente->nombre;
			hist->diagnostico = diagnostico->Trim();
			hist->tratamiento = tratamiento->Trim();
			hist->fecha = System::DateTime::Now.ToString(L"yyyy-MM-dd HH:mm");
			hist->doctor = HospitalData::usuarioActual;
			HospitalData::historialMedico->Add(hist);
			HospitalData::GuardarDatosJson();
			this->labelEstado->Text = L"Información guardada correctamente.";
			this->labelEstado->ForeColor = System::Drawing::Color::Green;
			this->richTextBoxPrincipal->Clear();
		}

	private:
		System::Void buttonPacientes_Click(System::Object^ sender, System::EventArgs^ e) {
			CargarPantallaPacientes();
		}

		System::Void buttonCitas_Click(System::Object^ sender, System::EventArgs^ e) {
			CargarPantallaCitas();
		}

		System::Void buttonHistorial_Click(System::Object^ sender, System::EventArgs^ e) {
			CargarPantallaHistorial();
		}

		System::Void buttonNotas_Click(System::Object^ sender, System::EventArgs^ e) {
			CargarPantallaNotas();
		}

		System::Void buttonDiagnostico_Click(System::Object^ sender, System::EventArgs^ e) {
			CargarPantallaDiagnostico();
		}

		System::Void buttonTratamiento_Click(System::Object^ sender, System::EventArgs^ e) {
			CargarPantallaTratamiento();
		}

		System::Void buttonRecetas_Click(System::Object^ sender, System::EventArgs^ e) {
			CargarPantallaRecetas();
		}

		System::Void buttonVerHistorial_Click(System::Object^ sender, System::EventArgs^ e) {
			String^ pacienteID = ObtenerPacienteSeleccionadoId();
			this->listBoxContent->Items->Clear();
			for each (MedicalHistory^ h in HospitalData::historialMedico) {
				if (h->idPaciente == pacienteID) {
					this->listBoxContent->Items->Add(h->fecha + L" | " + h->doctor + L" | Diagnóstico: " + h->diagnostico + L" | Tratamiento: " + h->tratamiento);
				}
			}
			if (this->listBoxContent->Items->Count == 0) this->listBoxContent->Items->Add(L"El paciente no tiene historial registrado.");
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

		System::Void buttonGuardarDiagnostico_Click(System::Object^ sender, System::EventArgs^ e) {
			GuardarHistorial(this->richTextBoxPrincipal->Text, L"");
		}

		System::Void buttonGuardarTratamiento_Click(System::Object^ sender, System::EventArgs^ e) {
			GuardarHistorial(L"", this->richTextBoxPrincipal->Text);
		}

		System::Void buttonGuardarReceta_Click(System::Object^ sender, System::EventArgs^ e) {
			String^ pacienteID = ObtenerPacienteSeleccionadoId();
			Patient^ paciente = HospitalData::BuscarPaciente(pacienteID);
			if (paciente == nullptr || this->textBoxMedicamentos->Text->Trim()->Length == 0) {
				this->labelEstado->Text = L"Seleccione un paciente e ingrese medicamentos.";
				this->labelEstado->ForeColor = System::Drawing::Color::Red;
				return;
			}

			Recipe^ receta = gcnew Recipe();
			receta->idPaciente = paciente->id;
			receta->nombrePaciente = paciente->nombre;
			receta->medicamentos = this->textBoxMedicamentos->Text->Trim();
			receta->dosis = this->textBoxDosis->Text->Trim();
			receta->indicaciones = this->richTextBoxPrincipal->Text->Trim();
			receta->fecha = System::DateTime::Now.ToString(L"yyyy-MM-dd HH:mm");
			HospitalData::recetas->Add(receta);
			HospitalData::GuardarDatosJson();
			this->labelEstado->Text = L"Receta guardada correctamente.";
			this->labelEstado->ForeColor = System::Drawing::Color::Green;
			this->textBoxMedicamentos->Clear();
			this->textBoxDosis->Clear();
			this->richTextBoxPrincipal->Clear();
		}

		System::Void buttonCerrarSesion_Click(System::Object^ sender, System::EventArgs^ e) {
			HospitalData::usuarioActual = L"";
			HospitalData::rolActual = L"";
			this->Close();
		}
	};
}
