#pragma once
#pragma execution_character_set("utf-8")

#include "EmployeeData.h"

namespace HospitalSantabarbaraProyecto {

	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;

	public ref class MedicineDispatchForm : public System::Windows::Forms::Form
	{
	public:
		MedicineDispatchForm(void)
		{
			InitializeComponent();
			CargarPacientes();
			CargarDespachos();
		}

	protected:
		~MedicineDispatchForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		Panel^ panelContenedor;
		Panel^ panelFormulario;
		Label^ labelTitulo;
		Label^ labelLista;
		Label^ labelPaciente;
		Label^ labelMedicina;
		Label^ labelFecha;
		Label^ labelHistoria;
		Label^ labelEstado;
		ComboBox^ comboPaciente;
		TextBox^ textBoxMedicina;
		DateTimePicker^ datePickerEntrega;
		RichTextBox^ richTextBoxHistoria;
		DataGridView^ dataGridDespachos;
		Button^ buttonGuardar;
		Button^ buttonLeer;
		HScrollBar^ scrollDecorativo;
		System::ComponentModel::Container^ components;

		void InitializeComponent(void)
		{
			this->panelContenedor = gcnew Panel();
			this->panelFormulario = gcnew Panel();
			this->labelTitulo = gcnew Label();
			this->labelLista = gcnew Label();
			this->labelPaciente = gcnew Label();
			this->labelMedicina = gcnew Label();
			this->labelFecha = gcnew Label();
			this->labelHistoria = gcnew Label();
			this->labelEstado = gcnew Label();
			this->comboPaciente = gcnew ComboBox();
			this->textBoxMedicina = gcnew TextBox();
			this->datePickerEntrega = gcnew DateTimePicker();
			this->richTextBoxHistoria = gcnew RichTextBox();
			this->dataGridDespachos = gcnew DataGridView();
			this->buttonGuardar = gcnew Button();
			this->buttonLeer = gcnew Button();
			this->scrollDecorativo = gcnew HScrollBar();
			this->SuspendLayout();

			this->BackColor = Color::FromArgb(16, 16, 16);
			this->ClientSize = System::Drawing::Size(940, 620);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->StartPosition = FormStartPosition::CenterParent;
			this->Text = L"Hospital Santa Barbara - Despacho de Medicinas";

			this->panelContenedor->BackColor = Color::FromArgb(20, 20, 20);
			this->panelContenedor->BorderStyle = BorderStyle::FixedSingle;
			this->panelContenedor->Location = Point(12, 12);
			this->panelContenedor->Size = System::Drawing::Size(916, 596);

			this->labelTitulo->AutoSize = true;
			this->labelTitulo->Font = gcnew System::Drawing::Font(L"Arial", 11, FontStyle::Regular);
			this->labelTitulo->ForeColor = Color::Gainsboro;
			this->labelTitulo->Location = Point(14, 12);
			this->labelTitulo->Text = L"Formulario de despacho de medicinas";

			this->scrollDecorativo->Enabled = false;
			this->scrollDecorativo->Location = Point(332, 47);
			this->scrollDecorativo->Size = System::Drawing::Size(140, 18);

			this->panelFormulario->BackColor = Color::FromArgb(18, 18, 18);
			this->panelFormulario->BorderStyle = BorderStyle::FixedSingle;
			this->panelFormulario->Location = Point(20, 70);
			this->panelFormulario->Size = System::Drawing::Size(808, 260);

			ConfigurarEtiqueta(this->labelPaciente, L"Paciente:", 24, 34);
			ConfigurarEtiqueta(this->labelMedicina, L"Medicina:", 24, 82);
			ConfigurarEtiqueta(this->labelFecha, L"Fecha de entrega:", 24, 130);
			ConfigurarEtiqueta(this->labelHistoria, L"Historia clinica:", 24, 178);

			this->comboPaciente->BackColor = Color::FromArgb(24, 24, 24);
			this->comboPaciente->DropDownStyle = ComboBoxStyle::DropDownList;
			this->comboPaciente->FlatStyle = FlatStyle::Flat;
			this->comboPaciente->Font = gcnew System::Drawing::Font(L"Arial", 10);
			this->comboPaciente->ForeColor = Color::Gainsboro;
			this->comboPaciente->Location = Point(180, 28);
			this->comboPaciente->Size = System::Drawing::Size(410, 27);

			ConfigurarEntrada(this->textBoxMedicina, L"Ingrese medicina", 180, 76, 410);

			this->datePickerEntrega->CalendarMonthBackground = Color::FromArgb(24, 24, 24);
			this->datePickerEntrega->Font = gcnew System::Drawing::Font(L"Arial", 10);
			this->datePickerEntrega->Format = DateTimePickerFormat::Short;
			this->datePickerEntrega->Location = Point(180, 124);
			this->datePickerEntrega->Size = System::Drawing::Size(410, 27);

			this->richTextBoxHistoria->BackColor = Color::FromArgb(24, 24, 24);
			this->richTextBoxHistoria->BorderStyle = BorderStyle::FixedSingle;
			this->richTextBoxHistoria->Font = gcnew System::Drawing::Font(L"Arial", 10);
			this->richTextBoxHistoria->ForeColor = Color::Gainsboro;
			this->richTextBoxHistoria->Location = Point(180, 172);
			this->richTextBoxHistoria->Size = System::Drawing::Size(410, 72);
			this->richTextBoxHistoria->Text = L"";

			ConfigurarBoton(this->buttonGuardar, L"Guardar", 660, 94, Color::FromArgb(34, 34, 34));
			this->buttonGuardar->Click += gcnew EventHandler(this, &MedicineDispatchForm::buttonGuardar_Click);

			ConfigurarBoton(this->buttonLeer, L"Leer JSON", 660, 156, Color::FromArgb(34, 34, 34));
			this->buttonLeer->Click += gcnew EventHandler(this, &MedicineDispatchForm::buttonLeer_Click);

			this->panelFormulario->Controls->Add(this->labelPaciente);
			this->panelFormulario->Controls->Add(this->labelMedicina);
			this->panelFormulario->Controls->Add(this->labelFecha);
			this->panelFormulario->Controls->Add(this->labelHistoria);
			this->panelFormulario->Controls->Add(this->comboPaciente);
			this->panelFormulario->Controls->Add(this->textBoxMedicina);
			this->panelFormulario->Controls->Add(this->datePickerEntrega);
			this->panelFormulario->Controls->Add(this->richTextBoxHistoria);
			this->panelFormulario->Controls->Add(this->buttonGuardar);
			this->panelFormulario->Controls->Add(this->buttonLeer);

			this->labelLista->AutoSize = true;
			this->labelLista->Font = gcnew System::Drawing::Font(L"Arial", 10, FontStyle::Regular);
			this->labelLista->ForeColor = Color::WhiteSmoke;
			this->labelLista->Location = Point(20, 342);
			this->labelLista->Text = L"- Lista de despachos registrados";

			this->dataGridDespachos->AllowUserToAddRows = false;
			this->dataGridDespachos->AllowUserToDeleteRows = false;
			this->dataGridDespachos->AllowUserToResizeRows = false;
			this->dataGridDespachos->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridDespachos->BackgroundColor = Color::FromArgb(20, 20, 20);
			this->dataGridDespachos->BorderStyle = BorderStyle::FixedSingle;
			this->dataGridDespachos->ColumnHeadersHeight = 36;
			this->dataGridDespachos->EnableHeadersVisualStyles = false;
			this->dataGridDespachos->Font = gcnew System::Drawing::Font(L"Arial", 10);
			this->dataGridDespachos->GridColor = Color::FromArgb(150, 150, 150);
			this->dataGridDespachos->Location = Point(20, 370);
			this->dataGridDespachos->ReadOnly = true;
			this->dataGridDespachos->RowHeadersVisible = false;
			this->dataGridDespachos->RowTemplate->Height = 36;
			this->dataGridDespachos->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
			this->dataGridDespachos->Size = System::Drawing::Size(808, 180);
			this->dataGridDespachos->ColumnHeadersDefaultCellStyle->BackColor = Color::FromArgb(22, 22, 22);
			this->dataGridDespachos->ColumnHeadersDefaultCellStyle->ForeColor = Color::WhiteSmoke;
			this->dataGridDespachos->ColumnHeadersDefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
			this->dataGridDespachos->DefaultCellStyle->BackColor = Color::FromArgb(18, 18, 18);
			this->dataGridDespachos->DefaultCellStyle->ForeColor = Color::Gainsboro;
			this->dataGridDespachos->DefaultCellStyle->SelectionBackColor = Color::FromArgb(0, 90, 140);
			this->dataGridDespachos->DefaultCellStyle->SelectionForeColor = Color::White;
			this->dataGridDespachos->Columns->Add(L"Paciente", L"Paciente");
			this->dataGridDespachos->Columns->Add(L"Medicina", L"Medicina");
			this->dataGridDespachos->Columns->Add(L"FechaEntrega", L"Fecha de entrega");
			this->dataGridDespachos->Columns->Add(L"HistoriaClinica", L"Historia clinica");

			this->labelEstado->AutoSize = true;
			this->labelEstado->Font = gcnew System::Drawing::Font(L"Arial", 10, FontStyle::Bold);
			this->labelEstado->ForeColor = Color::FromArgb(80, 190, 255);
			this->labelEstado->Location = Point(20, 562);
			this->labelEstado->Text = L"";

			this->panelContenedor->Controls->Add(this->labelTitulo);
			this->panelContenedor->Controls->Add(this->scrollDecorativo);
			this->panelContenedor->Controls->Add(this->panelFormulario);
			this->panelContenedor->Controls->Add(this->labelLista);
			this->panelContenedor->Controls->Add(this->dataGridDespachos);
			this->panelContenedor->Controls->Add(this->labelEstado);
			this->Controls->Add(this->panelContenedor);
			this->ResumeLayout(false);
		}

		void ConfigurarEtiqueta(Label^ label, String^ texto, int x, int y) {
			label->AutoSize = true;
			label->Font = gcnew System::Drawing::Font(L"Arial", 10);
			label->ForeColor = Color::WhiteSmoke;
			label->Location = Point(x, y);
			label->Text = texto;
		}

		void ConfigurarEntrada(TextBox^ textBox, String^ texto, int x, int y, int ancho) {
			textBox->BackColor = Color::FromArgb(24, 24, 24);
			textBox->BorderStyle = BorderStyle::FixedSingle;
			textBox->Font = gcnew System::Drawing::Font(L"Arial", 10);
			textBox->ForeColor = Color::Gainsboro;
			textBox->Location = Point(x, y);
			textBox->Size = System::Drawing::Size(ancho, 27);
			textBox->Text = L"";
		}

		void ConfigurarBoton(Button^ button, String^ texto, int x, int y, Color colorFondo) {
			button->BackColor = colorFondo;
			button->FlatStyle = FlatStyle::Flat;
			button->FlatAppearance->BorderColor = Color::FromArgb(160, 160, 160);
			button->FlatAppearance->BorderSize = 1;
			button->Font = gcnew System::Drawing::Font(L"Arial", 10, FontStyle::Bold);
			button->ForeColor = Color::WhiteSmoke;
			button->Location = Point(x, y);
			button->Size = System::Drawing::Size(120, 48);
			button->Text = texto;
			button->UseVisualStyleBackColor = false;
		}

		void CargarPacientes() {
			this->comboPaciente->Items->Clear();
			for each (Patient^ p in HospitalData::pacientes) {
				this->comboPaciente->Items->Add(p->nombre + L" (ID: " + p->id + L")");
			}
			if (this->comboPaciente->Items->Count > 0) {
				this->comboPaciente->SelectedIndex = 0;
			}
		}

		String^ ObtenerPacienteSeleccionadoId() {
			if (this->comboPaciente->SelectedIndex == -1) return L"";
			String^ item = this->comboPaciente->SelectedItem->ToString();
			int startIndex = item->LastIndexOf(L"ID: ") + 4;
			int endIndex = item->LastIndexOf(L")");
			if (startIndex < 4 || endIndex <= startIndex) return L"";
			return item->Substring(startIndex, endIndex - startIndex);
		}

		void CargarDespachos() {
			this->dataGridDespachos->Rows->Clear();
			for each (MedicineDispatch^ d in HospitalData::despachosMedicinas) {
				this->dataGridDespachos->Rows->Add(d->nombrePaciente, d->medicina, d->fechaEntrega, d->historiaClinica);
			}
			if (this->dataGridDespachos->Rows->Count == 0) {
				this->labelEstado->Text = L"No hay despachos registrados.";
				this->labelEstado->ForeColor = Color::FromArgb(80, 190, 255);
			}
		}

		System::Void buttonGuardar_Click(System::Object^ sender, System::EventArgs^ e) {
			String^ pacienteID = ObtenerPacienteSeleccionadoId();
			Patient^ paciente = HospitalData::BuscarPaciente(pacienteID);
			String^ medicina = this->textBoxMedicina->Text->Trim();
			String^ historiaClinica = this->richTextBoxHistoria->Text->Trim();

			if (paciente == nullptr || medicina->Length == 0 || historiaClinica->Length == 0) {
				this->labelEstado->Text = L"Seleccione paciente, medicina e historia clinica.";
				this->labelEstado->ForeColor = Color::FromArgb(255, 90, 90);
				return;
			}

			MedicineDispatch^ despacho = gcnew MedicineDispatch();
			despacho->idPaciente = paciente->id;
			despacho->nombrePaciente = paciente->nombre;
			despacho->medicina = medicina;
			despacho->fechaEntrega = this->datePickerEntrega->Value.ToString(L"yyyy-MM-dd");
			despacho->historiaClinica = historiaClinica;
			despacho->responsable = HospitalData::usuarioActual;
			HospitalData::despachosMedicinas->Add(despacho);
			HospitalData::GuardarDatosJson();

			this->textBoxMedicina->Clear();
			this->richTextBoxHistoria->Clear();
			this->labelEstado->Text = L"Despacho guardado en JSON.";
			this->labelEstado->ForeColor = Color::FromArgb(95, 210, 135);
			CargarDespachos();
		}

		System::Void buttonLeer_Click(System::Object^ sender, System::EventArgs^ e) {
			HospitalData::CargarDatosJson();
			CargarPacientes();
			CargarDespachos();
			this->labelEstado->Text = L"Datos leidos desde JSON.";
			this->labelEstado->ForeColor = Color::FromArgb(95, 210, 135);
		}
	};
}
