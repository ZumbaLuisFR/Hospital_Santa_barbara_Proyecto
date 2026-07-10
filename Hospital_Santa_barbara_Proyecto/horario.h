#pragma once
// UTF-8 encoding directive
#pragma execution_character_set("utf-8")

namespace HospitalSantabarbaraProyecto {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Ventana de horario y disponibilidad de citas
	/// </summary>
	public ref class horario : public System::Windows::Forms::Form
	{
	public:
		horario(void)
		{
			InitializeComponent();
			this->Load += gcnew System::EventHandler(this, &horario::horario_Load);
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se están usando.
		/// </summary>
		~horario()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::Windows::Forms::Panel^ panelMain;
		System::Windows::Forms::Panel^ panelCalendar;
		System::Windows::Forms::Panel^ panelSchedule;
		System::Windows::Forms::MonthCalendar^ monthCalendar;
		System::Windows::Forms::Label^ labelScheduleTitle;
		System::Windows::Forms::DataGridView^ dataGridViewSchedule;
		System::Windows::Forms::Button^ buttonConfirm;
		System::Windows::Forms::Button^ buttonCancel;
		System::Windows::Forms::Label^ labelSelectedDate;
		System::Windows::Forms::Label^ labelSelectedTime;
		System::Windows::Forms::ComboBox^ comboBoxTime;
		System::Windows::Forms::Label^ labelTimeSelection;

		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panelMain = (gcnew System::Windows::Forms::Panel());
			this->panelCalendar = (gcnew System::Windows::Forms::Panel());
			this->panelSchedule = (gcnew System::Windows::Forms::Panel());
			this->monthCalendar = (gcnew System::Windows::Forms::MonthCalendar());
			this->labelScheduleTitle = (gcnew System::Windows::Forms::Label());
			this->dataGridViewSchedule = (gcnew System::Windows::Forms::DataGridView());
			this->buttonConfirm = (gcnew System::Windows::Forms::Button());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->labelSelectedDate = (gcnew System::Windows::Forms::Label());
			this->labelSelectedTime = (gcnew System::Windows::Forms::Label());
			this->comboBoxTime = (gcnew System::Windows::Forms::ComboBox());
			this->labelTimeSelection = (gcnew System::Windows::Forms::Label());

			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewSchedule))->BeginInit();
			this->SuspendLayout();

			// panelMain
			this->panelMain->BackColor = System::Drawing::Color::FromArgb(240, 240, 240);
			this->panelMain->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelMain->Name = L"panelMain";
			this->panelMain->Padding = System::Windows::Forms::Padding(20);

			// panelCalendar
			this->panelCalendar->BackColor = System::Drawing::Color::White;
			this->panelCalendar->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelCalendar->Location = System::Drawing::Point(20, 20);
			this->panelCalendar->Name = L"panelCalendar";
			this->panelCalendar->Size = System::Drawing::Size(350, 380);
			this->panelCalendar->TabIndex = 0;

			// monthCalendar
			this->monthCalendar->Location = System::Drawing::Point(10, 10);
			this->monthCalendar->Name = L"monthCalendar";
			this->monthCalendar->TabIndex = 0;
			this->monthCalendar->DateSelected += gcnew System::Windows::Forms::DateRangeEventHandler(this, &horario::monthCalendar_DateSelected);
			this->panelCalendar->Controls->Add(this->monthCalendar);

			// panelSchedule
			this->panelSchedule->BackColor = System::Drawing::Color::White;
			this->panelSchedule->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelSchedule->Location = System::Drawing::Point(400, 20);
			this->panelSchedule->Name = L"panelSchedule";
			this->panelSchedule->Size = System::Drawing::Size(550, 380);
			this->panelSchedule->TabIndex = 1;

			// labelScheduleTitle
			this->labelScheduleTitle->AutoSize = true;
			this->labelScheduleTitle->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold));
			this->labelScheduleTitle->Location = System::Drawing::Point(10, 10);
			this->labelScheduleTitle->Name = L"labelScheduleTitle";
			this->labelScheduleTitle->Size = System::Drawing::Size(200, 28);
			this->labelScheduleTitle->TabIndex = 0;
			this->labelScheduleTitle->Text = L"Horarios Disponibles";

			// labelSelectedDate
			this->labelSelectedDate->AutoSize = true;
			this->labelSelectedDate->Font = (gcnew System::Drawing::Font(L"Arial", 11));
			this->labelSelectedDate->Location = System::Drawing::Point(10, 45);
			this->labelSelectedDate->Name = L"labelSelectedDate";
			this->labelSelectedDate->Size = System::Drawing::Size(250, 21);
			this->labelSelectedDate->TabIndex = 1;
			this->labelSelectedDate->Text = L"Fecha seleccionada: " + System::DateTime::Now.ToString(L"dd/MM/yyyy");

			// dataGridViewSchedule
			this->dataGridViewSchedule->AllowUserToAddRows = false;
			this->dataGridViewSchedule->AllowUserToDeleteRows = false;
			this->dataGridViewSchedule->BackgroundColor = System::Drawing::Color::White;
			this->dataGridViewSchedule->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewSchedule->Location = System::Drawing::Point(10, 80);
			this->dataGridViewSchedule->Name = L"dataGridViewSchedule";
			this->dataGridViewSchedule->ReadOnly = true;
			this->dataGridViewSchedule->RowHeadersVisible = false;
			this->dataGridViewSchedule->Size = System::Drawing::Size(530, 220);
			this->dataGridViewSchedule->TabIndex = 2;

			// Configurar columnas
			System::Windows::Forms::DataGridViewTextBoxColumn^ colHora = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			colHora->HeaderText = L"Hora";
			colHora->Name = L"Hora";
			colHora->Width = 100;
			this->dataGridViewSchedule->Columns->Add(colHora);

			System::Windows::Forms::DataGridViewTextBoxColumn^ colDoctor = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			colDoctor->HeaderText = L"Doctor";
			colDoctor->Name = L"Doctor";
			colDoctor->Width = 200;
			this->dataGridViewSchedule->Columns->Add(colDoctor);

			System::Windows::Forms::DataGridViewTextBoxColumn^ colEspecialidad = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			colEspecialidad->HeaderText = L"Especialidad";
			colEspecialidad->Name = L"Especialidad";
			colEspecialidad->Width = 230;
			this->dataGridViewSchedule->Columns->Add(colEspecialidad);

			this->panelSchedule->Controls->Add(this->labelScheduleTitle);
			this->panelSchedule->Controls->Add(this->labelSelectedDate);
			this->panelSchedule->Controls->Add(this->dataGridViewSchedule);

			// labelTimeSelection
			this->labelTimeSelection->AutoSize = true;
			this->labelTimeSelection->Font = (gcnew System::Drawing::Font(L"Arial", 11));
			this->labelTimeSelection->Location = System::Drawing::Point(400, 410);
			this->labelTimeSelection->Name = L"labelTimeSelection";
			this->labelTimeSelection->Size = System::Drawing::Size(100, 21);
			this->labelTimeSelection->TabIndex = 2;
			this->labelTimeSelection->Text = L"Seleccionar hora:";

			// comboBoxTime
			this->comboBoxTime->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxTime->Font = (gcnew System::Drawing::Font(L"Arial", 11));
			this->comboBoxTime->Location = System::Drawing::Point(520, 407);
			this->comboBoxTime->Name = L"comboBoxTime";
			this->comboBoxTime->Size = System::Drawing::Size(150, 29);
			this->comboBoxTime->TabIndex = 3;
			this->comboBoxTime->Items->Add(L"08:00");
			this->comboBoxTime->Items->Add(L"09:00");
			this->comboBoxTime->Items->Add(L"10:00");
			this->comboBoxTime->Items->Add(L"11:00");
			this->comboBoxTime->Items->Add(L"14:00");
			this->comboBoxTime->Items->Add(L"15:00");
			this->comboBoxTime->Items->Add(L"16:00");
			this->comboBoxTime->Items->Add(L"17:00");

			// buttonConfirm
			this->buttonConfirm->BackColor = System::Drawing::Color::FromArgb(0, 153, 76);
			this->buttonConfirm->Font = (gcnew System::Drawing::Font(L"Arial", 11, System::Drawing::FontStyle::Bold));
			this->buttonConfirm->ForeColor = System::Drawing::Color::White;
			this->buttonConfirm->Location = System::Drawing::Point(700, 407);
			this->buttonConfirm->Name = L"buttonConfirm";
			this->buttonConfirm->Size = System::Drawing::Size(120, 40);
			this->buttonConfirm->TabIndex = 4;
			this->buttonConfirm->Text = L"Confirmar";
			this->buttonConfirm->UseVisualStyleBackColor = false;
			this->buttonConfirm->Click += gcnew System::EventHandler(this, &horario::buttonConfirm_Click);

			// buttonCancel
			this->buttonCancel->BackColor = System::Drawing::Color::FromArgb(200, 0, 0);
			this->buttonCancel->Font = (gcnew System::Drawing::Font(L"Arial", 11, System::Drawing::FontStyle::Bold));
			this->buttonCancel->ForeColor = System::Drawing::Color::White;
			this->buttonCancel->Location = System::Drawing::Point(830, 407);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(120, 40);
			this->buttonCancel->TabIndex = 5;
			this->buttonCancel->Text = L"Cancelar";
			this->buttonCancel->UseVisualStyleBackColor = false;
			this->buttonCancel->Click += gcnew System::EventHandler(this, &horario::buttonCancel_Click);

			this->panelMain->Controls->Add(this->panelCalendar);
			this->panelMain->Controls->Add(this->panelSchedule);
			this->panelMain->Controls->Add(this->labelTimeSelection);
			this->panelMain->Controls->Add(this->comboBoxTime);
			this->panelMain->Controls->Add(this->buttonConfirm);
			this->panelMain->Controls->Add(this->buttonCancel);

			// horario
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1000, 480);
			this->Controls->Add(this->panelMain);
			this->Name = L"horario";
			this->Text = L"Solicitar Cita - Selecciona Horario";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewSchedule))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

	private:
		System::Void horario_Load(System::Object^ sender, System::EventArgs^ e) {
			// Mostrar cuadro de diálogo inicial
			MessageBox::Show(L"Por favor contacte al hospital para solicitar una cita", L"Solicitar Cita", 
				MessageBoxButtons::OK, MessageBoxIcon::Information);

			// Cargar datos de horarios de ejemplo
			LoadScheduleData(System::DateTime::Now);
		}

		System::Void monthCalendar_DateSelected(System::Object^ sender, System::Windows::Forms::DateRangeEventArgs^ e) {
			this->labelSelectedDate->Text = L"Fecha seleccionada: " + e->Start.ToString(L"dd/MM/yyyy");
			LoadScheduleData(e->Start);
			this->comboBoxTime->SelectedIndex = -1;
		}

		System::Void LoadScheduleData(System::DateTime fecha) {
			this->dataGridViewSchedule->Rows->Clear();

			// Datos de ejemplo de horarios disponibles
			array<System::String^>^ horarios = {
				L"08:00",
				L"09:00",
				L"10:00",
				L"11:00",
				L"14:00",
				L"15:00",
				L"16:00",
				L"17:00"
			};

			array<System::String^>^ doctores = {
				L"Dr. González",
				L"Dra. López",
				L"Dr. Martínez",
				L"Dra. García",
				L"Dr. Rodríguez",
				L"Dra. Fernández",
				L"Dr. Pérez",
				L"Dra. Sánchez"
			};

			array<System::String^>^ especialidades = {
				L"Medicina General",
				L"Cardiología",
				L"Dermatología",
				L"Pediatría",
				L"Oftalmología",
				L"Neurología",
				L"Ortopedia",
				L"Psicología"
			};

			for (int i = 0; i < 8; i++) {
				array<System::String^>^ fila = gcnew array<System::String^>(3);
				fila[0] = horarios[i];
				fila[1] = doctores[i];
				fila[2] = especialidades[i];
				this->dataGridViewSchedule->Rows->Add(fila);
			}
		}

		System::Void buttonConfirm_Click(System::Object^ sender, System::EventArgs^ e) {
			if (this->comboBoxTime->SelectedIndex == -1) {
				MessageBox::Show(L"Por favor seleccione una hora", L"Validación", 
					MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			if (this->dataGridViewSchedule->SelectedRows->Count == 0) {
				MessageBox::Show(L"Por favor seleccione un horario de la tabla", L"Validación", 
					MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			System::String^ fecha = this->labelSelectedDate->Text->Replace(L"Fecha seleccionada: ", L"");
			System::String^ hora = this->comboBoxTime->SelectedItem->ToString();
			System::String^ doctor = this->dataGridViewSchedule->SelectedRows[0]->Cells[1]->Value->ToString();
			System::String^ especialidad = this->dataGridViewSchedule->SelectedRows[0]->Cells[2]->Value->ToString();

			System::String^ mensaje = L"Cita confirmada:\n\nFecha: " + fecha + L"\nHora: " + hora + 
				L"\nDoctor: " + doctor + L"\nEspecialidad: " + especialidad;

			MessageBox::Show(mensaje, L"Cita Confirmada", MessageBoxButtons::OK, MessageBoxIcon::Information);
			this->Close();
		}

		System::Void buttonCancel_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}
	};
}
