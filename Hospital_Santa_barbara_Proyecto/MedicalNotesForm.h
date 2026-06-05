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

	public ref struct PatientNote {
		String^ idPaciente;
		String^ profesional;
		String^ tipoProfesional;
		String^ fecha;
		String^ descripcion;
		String^ diagnostico;
	};

	public ref class MedicalNotesForm : public System::Windows::Forms::Form
	{
	public:
		MedicalNotesForm(String^ idPaciente)
		{
			pacienteID = idPaciente;
			notas = gcnew List<PatientNote^>();
			InitializeComponent();
			CargarNotas();
		}

	protected:
		~MedicalNotesForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		String^ pacienteID;
		List<PatientNote^>^ notas;
		System::Windows::Forms::Label^ labelTitulo;
		System::Windows::Forms::ListBox^ listBoxNotas;
		System::Windows::Forms::Label^ labelPaciente;
		System::Windows::Forms::Label^ labelDescripcion;
		System::Windows::Forms::RichTextBox^ richTextBoxDescripcion;
		System::Windows::Forms::Label^ labelDiagnostico;
		System::Windows::Forms::RichTextBox^ richTextBoxDiagnostico;
		System::Windows::Forms::Button^ buttonGuardar;
		System::Windows::Forms::Button^ buttonVolver;
		System::Windows::Forms::Label^ labelError;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->labelTitulo = (gcnew System::Windows::Forms::Label());
			this->listBoxNotas = (gcnew System::Windows::Forms::ListBox());
			this->labelPaciente = (gcnew System::Windows::Forms::Label());
			this->labelDescripcion = (gcnew System::Windows::Forms::Label());
			this->richTextBoxDescripcion = (gcnew System::Windows::Forms::RichTextBox());
			this->labelDiagnostico = (gcnew System::Windows::Forms::Label());
			this->richTextBoxDiagnostico = (gcnew System::Windows::Forms::RichTextBox());
			this->buttonGuardar = (gcnew System::Windows::Forms::Button());
			this->buttonVolver = (gcnew System::Windows::Forms::Button());
			this->labelError = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();

			// labelTitulo
			this->labelTitulo->AutoSize = true;
			this->labelTitulo->Font = (gcnew System::Drawing::Font(L"Arial", 24, System::Drawing::FontStyle::Bold));
			this->labelTitulo->ForeColor = System::Drawing::Color::FromArgb(0, 102, 204);
			this->labelTitulo->Location = System::Drawing::Point(20, 20);
			this->labelTitulo->Name = L"labelTitulo";
			this->labelTitulo->Size = System::Drawing::Size(500, 46);
			this->labelTitulo->TabIndex = 0;
			this->labelTitulo->Text = L"Notas Médicas";

			// labelPaciente
			this->labelPaciente->AutoSize = true;
			this->labelPaciente->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->labelPaciente->ForeColor = System::Drawing::Color::Black;
			this->labelPaciente->Location = System::Drawing::Point(20, 70);
			this->labelPaciente->Name = L"labelPaciente";
			this->labelPaciente->Size = System::Drawing::Size(500, 23);
			this->labelPaciente->TabIndex = 1;
			this->labelPaciente->Text = L"Paciente: ";

			// listBoxNotas
			this->listBoxNotas->BackColor = System::Drawing::Color::White;
			this->listBoxNotas->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->listBoxNotas->Font = (gcnew System::Drawing::Font(L"Arial", 10));
			this->listBoxNotas->Location = System::Drawing::Point(20, 100);
			this->listBoxNotas->Name = L"listBoxNotas";
			this->listBoxNotas->Size = System::Drawing::Size(300, 250);
			this->listBoxNotas->TabIndex = 2;

			// labelDescripcion
			this->labelDescripcion->AutoSize = true;
			this->labelDescripcion->Font = (gcnew System::Drawing::Font(L"Arial", 11));
			this->labelDescripcion->ForeColor = System::Drawing::Color::Black;
			this->labelDescripcion->Location = System::Drawing::Point(340, 100);
			this->labelDescripcion->Name = L"labelDescripcion";
			this->labelDescripcion->Size = System::Drawing::Size(100, 21);
			this->labelDescripcion->TabIndex = 3;
			this->labelDescripcion->Text = L"Descripción";

			// richTextBoxDescripcion
			this->richTextBoxDescripcion->BackColor = System::Drawing::Color::White;
			this->richTextBoxDescripcion->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->richTextBoxDescripcion->Font = (gcnew System::Drawing::Font(L"Arial", 10));
			this->richTextBoxDescripcion->Location = System::Drawing::Point(340, 130);
			this->richTextBoxDescripcion->Name = L"richTextBoxDescripcion";
			this->richTextBoxDescripcion->Size = System::Drawing::Size(400, 80);
			this->richTextBoxDescripcion->TabIndex = 4;
			this->richTextBoxDescripcion->Text = L"";

			// labelDiagnostico
			this->labelDiagnostico->AutoSize = true;
			this->labelDiagnostico->Font = (gcnew System::Drawing::Font(L"Arial", 11));
			this->labelDiagnostico->ForeColor = System::Drawing::Color::Black;
			this->labelDiagnostico->Location = System::Drawing::Point(340, 220);
			this->labelDiagnostico->Name = L"labelDiagnostico";
			this->labelDiagnostico->Size = System::Drawing::Size(103, 21);
			this->labelDiagnostico->TabIndex = 5;
			this->labelDiagnostico->Text = L"Diagnóstico";

			// richTextBoxDiagnostico
			this->richTextBoxDiagnostico->BackColor = System::Drawing::Color::White;
			this->richTextBoxDiagnostico->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->richTextBoxDiagnostico->Font = (gcnew System::Drawing::Font(L"Arial", 10));
			this->richTextBoxDiagnostico->Location = System::Drawing::Point(340, 250);
			this->richTextBoxDiagnostico->Name = L"richTextBoxDiagnostico";
			this->richTextBoxDiagnostico->Size = System::Drawing::Size(400, 100);
			this->richTextBoxDiagnostico->TabIndex = 6;
			this->richTextBoxDiagnostico->Text = L"";

			// labelError
			this->labelError->AutoSize = true;
			this->labelError->Font = (gcnew System::Drawing::Font(L"Arial", 10, System::Drawing::FontStyle::Bold));
			this->labelError->ForeColor = System::Drawing::Color::Red;
			this->labelError->Location = System::Drawing::Point(340, 360);
			this->labelError->Name = L"labelError";
			this->labelError->Size = System::Drawing::Size(0, 19);
			this->labelError->TabIndex = 7;

			// buttonGuardar
			this->buttonGuardar->BackColor = System::Drawing::Color::FromArgb(0, 153, 76);
			this->buttonGuardar->Font = (gcnew System::Drawing::Font(L"Arial", 11, System::Drawing::FontStyle::Bold));
			this->buttonGuardar->ForeColor = System::Drawing::Color::White;
			this->buttonGuardar->Location = System::Drawing::Point(340, 390);
			this->buttonGuardar->Name = L"buttonGuardar";
			this->buttonGuardar->Size = System::Drawing::Size(180, 45);
			this->buttonGuardar->TabIndex = 8;
			this->buttonGuardar->Text = L"Guardar Nota";
			this->buttonGuardar->UseVisualStyleBackColor = false;
			this->buttonGuardar->Click += gcnew System::EventHandler(this, &MedicalNotesForm::buttonGuardar_Click);

			// buttonVolver
			this->buttonVolver->BackColor = System::Drawing::Color::FromArgb(100, 100, 100);
			this->buttonVolver->Font = (gcnew System::Drawing::Font(L"Arial", 11, System::Drawing::FontStyle::Bold));
			this->buttonVolver->ForeColor = System::Drawing::Color::White;
			this->buttonVolver->Location = System::Drawing::Point(560, 390);
			this->buttonVolver->Name = L"buttonVolver";
			this->buttonVolver->Size = System::Drawing::Size(180, 45);
			this->buttonVolver->TabIndex = 9;
			this->buttonVolver->Text = L"Volver";
			this->buttonVolver->UseVisualStyleBackColor = false;
			this->buttonVolver->Click += gcnew System::EventHandler(this, &MedicalNotesForm::buttonVolver_Click);

			// MedicalNotesForm
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(240, 240, 240);
			this->ClientSize = System::Drawing::Size(800, 500);
			this->Controls->Add(this->labelError);
			this->Controls->Add(this->buttonVolver);
			this->Controls->Add(this->buttonGuardar);
			this->Controls->Add(this->richTextBoxDiagnostico);
			this->Controls->Add(this->labelDiagnostico);
			this->Controls->Add(this->richTextBoxDescripcion);
			this->Controls->Add(this->labelDescripcion);
			this->Controls->Add(this->labelPaciente);
			this->Controls->Add(this->listBoxNotas);
			this->Controls->Add(this->labelTitulo);
			this->DoubleBuffered = true;
			this->Name = L"MedicalNotesForm";
			this->Text = L"Hospital Santa Bárbara - Notas Médicas";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

		void CargarNotas() {
			Patient^ paciente = HospitalData::BuscarPaciente(pacienteID);
			if (paciente != nullptr) {
				this->labelPaciente->Text = L"Paciente: " + paciente->nombre + L" (" + pacienteID + L")";
			}

			// Cargar historial médico del paciente
			for each (MedicalHistory^ hist in HospitalData::historialMedico) {
				if (hist->idPaciente == pacienteID) {
					PatientNote^ nota = gcnew PatientNote();
					nota->idPaciente = hist->idPaciente;
					nota->profesional = hist->doctor;
					nota->tipoProfesional = L"Doctor";
					nota->fecha = hist->fecha;
					nota->diagnostico = hist->diagnostico;
					nota->descripcion = hist->tratamiento;
					notas->Add(nota);
					this->listBoxNotas->Items->Add(nota->fecha + L" - " + nota->profesional);
				}
			}
		}

	private:
		System::Void buttonGuardar_Click(System::Object^ sender, System::EventArgs^ e) {
			String^ descripcion = this->richTextBoxDescripcion->Text->Trim();
			String^ diagnostico = this->richTextBoxDiagnostico->Text->Trim();

			if (descripcion->Length == 0 && diagnostico->Length == 0) {
				this->labelError->Text = L"Ingrese al menos descripción o diagnóstico";
				this->labelError->ForeColor = System::Drawing::Color::Red;
				return;
			}

			// Crear nueva nota
			PatientNote^ nota = gcnew PatientNote();
			nota->idPaciente = pacienteID;
			nota->profesional = HospitalData::usuarioActual;
			nota->tipoProfesional = HospitalData::rolActual;
			nota->fecha = System::DateTime::Now.ToString(L"yyyy-MM-dd HH:mm");
			nota->descripcion = descripcion;
			nota->diagnostico = diagnostico;
			notas->Add(nota);

			// Guardar en historial médico
			MedicalHistory^ hist = gcnew MedicalHistory();
			hist->idPaciente = pacienteID;
			hist->nombrePaciente = HospitalData::BuscarPaciente(pacienteID)->nombre;
			hist->doctor = HospitalData::usuarioActual;
			hist->fecha = nota->fecha;
			hist->diagnostico = diagnostico;
			hist->tratamiento = descripcion;
			HospitalData::historialMedico->Add(hist);

			this->listBoxNotas->Items->Add(nota->fecha + L" - " + nota->profesional);
			this->richTextBoxDescripcion->Clear();
			this->richTextBoxDiagnostico->Clear();
			this->labelError->Text = L"Nota guardada exitosamente";
			this->labelError->ForeColor = System::Drawing::Color::Green;
		}

		System::Void buttonVolver_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}
	};
}
