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
					L"pacientes.dat"
				);

				System::IO::StreamWriter^ writer = gcnew System::IO::StreamWriter(rutaArchivo, false, System::Text::Encoding::UTF8);
				for each (Patient^ p in pacientes) {
					// Escapar caracteres especiales usando tokens que no contienen el separador '|'
					String^ id = (p->id == nullptr) ? L"" : p->id->Replace(L"<PIPE>", L"<PIPE_ESC>")->Replace(L"|", L"<PIPE>");
					String^ nombre = (p->nombre == nullptr) ? L"" : p->nombre->Replace(L"<PIPE>", L"<PIPE_ESC>")->Replace(L"|", L"<PIPE>");
					String^ email = (p->email == nullptr) ? L"" : p->email->Replace(L"<PIPE>", L"<PIPE_ESC>")->Replace(L"|", L"<PIPE>");
					String^ telefono = (p->telefono == nullptr) ? L"" : p->telefono->Replace(L"<PIPE>", L"<PIPE_ESC>")->Replace(L"|", L"<PIPE>");
					String^ direccion = (p->direccion == nullptr) ? L"" : p->direccion->Replace(L"<PIPE>", L"<PIPE_ESC>")->Replace(L"|", L"<PIPE>");
					String^ contrasena = (p->contrasena == nullptr) ? L"" : p->contrasena->Replace(L"<PIPE>", L"<PIPE_ESC>")->Replace(L"|", L"<PIPE>");

					String^ linea = id + L"|" + nombre + L"|" + email + L"|" + telefono + L"|" + direccion + L"|" + contrasena;
					writer->WriteLine(linea);
				}
				writer->Close();
				delete writer;
			}
			catch (System::Exception^ ex) {
				// Silencio en caso de error
			}
		}

		static void CargarPacientes() {
			try {
				String^ rutaArchivo = System::IO::Path::Combine(
					System::IO::Path::GetDirectoryName(System::Reflection::Assembly::GetExecutingAssembly()->Location),
					L"pacientes.dat"
				);

				if (System::IO::File::Exists(rutaArchivo)) {
					System::IO::StreamReader^ reader = gcnew System::IO::StreamReader(rutaArchivo, System::Text::Encoding::UTF8);
					String^ linea = L"";

					while ((linea = reader->ReadLine()) != nullptr) {
						if (linea->Length > 0) {
							array<String^>^ partes = linea->Split('|');
							if (partes->Length == 6) {
								// Desescapar tokens en el orden correcto
								String^ id = partes[0]->Replace(L"<PIPE_ESC>", L"<PIPE>")->Replace(L"<PIPE>", L"|");
								String^ nombre = partes[1]->Replace(L"<PIPE_ESC>", L"<PIPE>")->Replace(L"<PIPE>", L"|");
								String^ email = partes[2]->Replace(L"<PIPE_ESC>", L"<PIPE>")->Replace(L"<PIPE>", L"|");
								String^ telefono = partes[3]->Replace(L"<PIPE_ESC>", L"<PIPE>")->Replace(L"<PIPE>", L"|");
								String^ direccion = partes[4]->Replace(L"<PIPE_ESC>", L"<PIPE>")->Replace(L"<PIPE>", L"|");
								String^ contrasena = partes[5]->Replace(L"<PIPE_ESC>", L"<PIPE>")->Replace(L"<PIPE>", L"|");

								// Verificar que no exista ya antes de agregar
								if (BuscarPaciente(id) == nullptr) {
									Patient^ p = gcnew Patient();
									p->id = id;
									p->nombre = nombre;
									p->email = email;
									p->telefono = telefono;
									p->direccion = direccion;
									p->contrasena = contrasena;
									pacientes->Add(p);
								}
							}
						}
					}
					reader->Close();
					delete reader;
				}
			}
			catch (System::Exception^ ex) {
				// Silencio en caso de error
			}
		}
	};
}
