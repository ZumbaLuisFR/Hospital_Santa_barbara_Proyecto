#pragma once
// UTF-8 encoding directive
#pragma execution_character_set("utf-8")

#using <System.dll>

using namespace System;
using namespace System::Text;
namespace HospitalSantabarbaraProyecto {
	using namespace System;
	using namespace System::Collections::Generic;

	// Estructura para Doctores
	public ref struct Doctor {
		String^ id;
		String^ nombre;
		String^ contrasena;
		String^ especialidad;
	};

	// Estructura para Enfermeros
	public ref struct Nurse {
		String^ id;
		String^ nombre;
		String^ contrasena;
	};

	// Estructura para Pacientes
	public ref struct Patient {
		String^ id;
		String^ nombre;
		String^ email;
		String^ telefono;
		String^ direccion;
		String^ contrasena;
	};

	// Estructura para Citas
	public ref struct Appointment {
		String^ idPaciente;
		String^ nombrePaciente;
		String^ doctor;
		String^ fecha;
		String^ hora;
		String^ razon;
	};

	// Estructura para Recetas
	public ref struct Recipe {
		String^ idPaciente;
		String^ nombrePaciente;
		String^ medicamentos;
		String^ dosis;
		String^ indicaciones;
		String^ fecha;
	};

	// Estructura para Historial Medico
	public ref struct MedicalHistory {
		String^ idPaciente;
		String^ nombrePaciente;
		String^ diagnostico;
		String^ tratamiento;
		String^ fecha;
		String^ doctor;
	};

	// Clase de datos global
	public ref class HospitalData {
	public:
		static List<Doctor^>^ doctores = gcnew List<Doctor^>();
		static List<Nurse^>^ enfermeros = gcnew List<Nurse^>();
		static List<Patient^>^ pacientes = gcnew List<Patient^>();
		static List<Appointment^>^ citas = gcnew List<Appointment^>();
		static List<Recipe^>^ recetas = gcnew List<Recipe^>();
		static List<MedicalHistory^>^ historialMedico = gcnew List<MedicalHistory^>();

		static String^ usuarioActual = L"";
		static String^ rolActual = L""; // "Doctor", "Enfermero", "Paciente"

		static HospitalData() {
			// Inicializar datos de prueba

			// Doctores predefinidos
			Doctor^ doc1 = gcnew Doctor();
			doc1->id = L"DOC001";
			doc1->nombre = L"Dr. Carlos Rodriguez";
			doc1->contrasena = L"1234";
			doc1->especialidad = L"Cardiología";
			doctores->Add(doc1);

			Doctor^ doc2 = gcnew Doctor();
			doc2->id = L"DOC002";
			doc2->nombre = L"Dra. Maria Lopez";
			doc2->contrasena = L"1234";
			doc2->especialidad = L"Pediatría";
			doctores->Add(doc2);

			// Enfermeros predefinidos
			Nurse^ enf1 = gcnew Nurse();
			enf1->id = L"ENF001";
			enf1->nombre = L"Juan Perez";
			enf1->contrasena = L"1234";
			enfermeros->Add(enf1);

			Nurse^ enf2 = gcnew Nurse();
			enf2->id = L"ENF002";
			enf2->nombre = L"Laura Garcia";
			enf2->contrasena = L"1234";
			enfermeros->Add(enf2);

			// Pacientes predefinidos
			Patient^ pac1 = gcnew Patient();
			pac1->id = L"PAC001";
			pac1->nombre = L"Antonio Martinez";
			pac1->email = L"antonio@email.com";
			pac1->telefono = L"555-1234";
			pac1->direccion = L"Calle Principal 123";
			pac1->contrasena = L"1234";
			pacientes->Add(pac1);

			Patient^ pac2 = gcnew Patient();
			pac2->id = L"PAC002";
			pac2->nombre = L"Maria Gonzalez";
			pac2->email = L"maria@email.com";
			pac2->telefono = L"555-5678";
			pac2->direccion = L"Avenida Central 456";
			pac2->contrasena = L"1234";
			pacientes->Add(pac2);

			// Citas de ejemplo
			Appointment^ cita1 = gcnew Appointment();
			cita1->idPaciente = L"PAC001";
			cita1->nombrePaciente = L"Antonio Martinez";
			cita1->doctor = L"Dr. Carlos Rodriguez";
			cita1->fecha = L"2024-01-15";
			cita1->hora = L"10:00 AM";
			cita1->razon = L"Revisión de salud";
			citas->Add(cita1);

			Appointment^ cita2 = gcnew Appointment();
			cita2->idPaciente = L"PAC002";
			cita2->nombrePaciente = L"Maria Gonzalez";
			cita2->doctor = L"Dra. Maria Lopez";
			cita2->fecha = L"2024-01-16";
			cita2->hora = L"02:30 PM";
			cita2->razon = L"Control de rutina";
			citas->Add(cita2);

			// Recetas de ejemplo
			Recipe^ rec1 = gcnew Recipe();
			rec1->idPaciente = L"PAC001";
			rec1->nombrePaciente = L"Antonio Martinez";
			rec1->medicamentos = L"Paracetamol";
			rec1->dosis = L"500mg cada 8 horas";
			rec1->indicaciones = L"Tomar después de las comidas";
			rec1->fecha = L"2024-01-10";
			recetas->Add(rec1);

			Recipe^ rec2 = gcnew Recipe();
			rec2->idPaciente = L"PAC002";
			rec2->nombrePaciente = L"Maria Gonzalez";
			rec2->medicamentos = L"Amoxicilina";
			rec2->dosis = L"250mg cada 6 horas";
			rec2->indicaciones = L"Completar el ciclo de 10 días";
			rec2->fecha = L"2024-01-12";
			recetas->Add(rec2);

			// Historial médico de ejemplo
			MedicalHistory^ hist1 = gcnew MedicalHistory();
			hist1->idPaciente = L"PAC001";
			hist1->nombrePaciente = L"Antonio Martinez";
			hist1->diagnostico = L"Gripe común";
			hist1->tratamiento = L"Reposo y medicamentos";
			hist1->fecha = L"2024-01-05";
			hist1->doctor = L"Dr. Carlos Rodriguez";
			historialMedico->Add(hist1);

			MedicalHistory^ hist2 = gcnew MedicalHistory();
			hist2->idPaciente = L"PAC001";
			hist2->nombrePaciente = L"Antonio Martinez";
			hist2->diagnostico = L"Hipertensión leve";
			hist2->tratamiento = L"Cambios en la dieta y ejercicio";
			hist2->fecha = L"2023-12-20";
			hist2->doctor = L"Dr. Carlos Rodriguez";
			historialMedico->Add(hist2);

			MedicalHistory^ hist3 = gcnew MedicalHistory();
			hist3->idPaciente = L"PAC002";
			hist3->nombrePaciente = L"Maria Gonzalez";
			hist3->diagnostico = L"Infección respiratoria";
			hist3->tratamiento = L"Antibióticos y reposo";
			hist3->fecha = L"2024-01-08";
			hist3->doctor = L"Dra. Maria Lopez";
			historialMedico->Add(hist3);

			// Cargar pacientes guardados
			CargarPacientes();
		}

		// Metodos de busqueda
		static Doctor^ BuscarDoctor(String^ id) {
			for each (Doctor^ d in doctores) {
				if (d->id == id) return d;
			}
			return nullptr;
		}

		static Nurse^ BuscarEnfermero(String^ id) {
			for each (Nurse^ e in enfermeros) {
				if (e->id == id) return e;
			}
			return nullptr;
		}

		static Patient^ BuscarPaciente(String^ id) {
			for each (Patient^ p in pacientes) {
				if (p->id == id) return p;
			}
			return nullptr;
		}

		static bool AutenticarDoctor(String^ id, String^ contrasena) {
			Doctor^ doc = BuscarDoctor(id);
			return doc != nullptr && doc->contrasena == contrasena;
		}

		static bool AutenticarEnfermero(String^ id, String^ contrasena) {
			Nurse^ enf = BuscarEnfermero(id);
			return enf != nullptr && enf->contrasena == contrasena;
		}

		static bool AutenticarPaciente(String^ id, String^ contrasena) {
			Patient^ pac = BuscarPaciente(id);
			return pac != nullptr && pac->contrasena == contrasena;
		}

		static Patient^ CrearPacienteTemporal(String^ id, String^ contrasena) {
			Patient^ nuevoPaciente = gcnew Patient();
			nuevoPaciente->id = id;
			nuevoPaciente->nombre = L"Paciente " + id;
			nuevoPaciente->email = L"paciente@email.com";
			nuevoPaciente->telefono = L"000-0000";
			nuevoPaciente->direccion = L"No especificada";
			nuevoPaciente->contrasena = contrasena;
			pacientes->Add(nuevoPaciente);
			GuardarPacientes();
			return nuevoPaciente;
		}

		static void GuardarPacientes() {
			try {
				String^ rutaArchivo = System::IO::Path::Combine(
					System::IO::Path::GetDirectoryName(System::Reflection::Assembly::GetExecutingAssembly()->Location),
					L"pacientes.txt"
				);

				System::IO::StreamWriter^ writer = gcnew System::IO::StreamWriter(rutaArchivo, false, System::Text::Encoding::UTF8);
				for each (Patient^ p in pacientes) {
					String^ linea = p->id + L"|" + p->nombre + L"|" + p->email + L"|" + p->telefono + L"|" + p->direccion + L"|" + p->contrasena;
					writer->WriteLine(linea);
				}
				writer->Close();
				delete writer;
			}
			catch (System::Exception^ ex) {
				System::Windows::Forms::MessageBox::Show(L"Error al guardar: " + ex->Message);
			}
		}

		static void CargarPacientes() {
			try {
				String^ rutaArchivo = System::IO::Path::Combine(
					System::IO::Path::GetDirectoryName(System::Reflection::Assembly::GetExecutingAssembly()->Location),
					L"pacientes.txt"
				);

				if (System::IO::File::Exists(rutaArchivo)) {
					System::IO::StreamReader^ reader = gcnew System::IO::StreamReader(rutaArchivo, System::Text::Encoding::UTF8);
					String^ linea = L"";

					while ((linea = reader->ReadLine()) != nullptr) {
						array<String^>^ partes = linea->Split('|');
						if (partes->Length == 6) {
							Patient^ p = gcnew Patient();
							p->id = partes[0];
							p->nombre = partes[1];
							p->email = partes[2];
							p->telefono = partes[3];
							p->direccion = partes[4];
							p->contrasena = partes[5];

							// Verificar que no exista ya
							if (BuscarPaciente(p->id) == nullptr) {
								pacientes->Add(p);
							}
						}
					}
					reader->Close();
					delete reader;
				}
			}
			catch (System::Exception^ ex) {
				System::Windows::Forms::MessageBox::Show(L"Error al cargar: " + ex->Message);
			}
		}
	};
}
