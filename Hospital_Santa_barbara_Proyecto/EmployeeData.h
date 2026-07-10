#pragma once
// UTF-8 encoding directive
#pragma execution_character_set("utf-8")

#using <System.dll>

#include <nlohmann/json.hpp>
#include <string>
#include <vcclr.h>

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

	// Estructura para despacho de medicinas
	public ref struct MedicineDispatch {
		String^ idPaciente;
		String^ nombrePaciente;
		String^ medicina;
		String^ fechaEntrega;
		String^ historiaClinica;
		String^ responsable;
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
	private:
		static String^ RutaArchivoJson() {
			return System::IO::Path::Combine(
				System::IO::Path::GetDirectoryName(System::Reflection::Assembly::GetExecutingAssembly()->Location),
				L"hospital_data.json"
			);
		}

		static std::string ToUtf8(String^ value) {
			if (value == nullptr || value->Length == 0) return "";
			array<System::Byte>^ bytes = System::Text::Encoding::UTF8->GetBytes(value);
			pin_ptr<System::Byte> pinned = &bytes[0];
			return std::string(reinterpret_cast<char*>(pinned), bytes->Length);
		}

		static String^ FromUtf8(const std::string& value) {
			if (value.empty()) return L"";
			array<System::Byte>^ bytes = gcnew array<System::Byte>(static_cast<int>(value.size()));
			for (int i = 0; i < bytes->Length; i++) {
				bytes[i] = static_cast<System::Byte>(static_cast<unsigned char>(value[i]));
			}
			return System::Text::Encoding::UTF8->GetString(bytes);
		}

		static String^ JsonString(const nlohmann::json& item, const char* key) {
			if (!item.contains(key) || item[key].is_null()) return L"";
			return FromUtf8(item[key].get<std::string>());
		}

		static void InicializarPersonalPredeterminado() {
			// Los doctores y enfermeros se registran desde el login.
		}

		static void CargarPacientesDat() {
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
								String^ id = partes[0]->Replace(L"<PIPE_ESC>", L"<PIPE>")->Replace(L"<PIPE>", L"|");
								if (BuscarPaciente(id) == nullptr) {
									Patient^ p = gcnew Patient();
									p->id = id;
									p->nombre = partes[1]->Replace(L"<PIPE_ESC>", L"<PIPE>")->Replace(L"<PIPE>", L"|");
									p->email = partes[2]->Replace(L"<PIPE_ESC>", L"<PIPE>")->Replace(L"<PIPE>", L"|");
									p->telefono = partes[3]->Replace(L"<PIPE_ESC>", L"<PIPE>")->Replace(L"<PIPE>", L"|");
									p->direccion = partes[4]->Replace(L"<PIPE_ESC>", L"<PIPE>")->Replace(L"<PIPE>", L"|");
									p->contrasena = partes[5]->Replace(L"<PIPE_ESC>", L"<PIPE>")->Replace(L"<PIPE>", L"|");
									pacientes->Add(p);
								}
							}
						}
					}
					reader->Close();
					delete reader;
				}
			}
			catch (System::Exception^) {
			}
		}

	public:
		static List<Doctor^>^ doctores = gcnew List<Doctor^>();
		static List<Nurse^>^ enfermeros = gcnew List<Nurse^>();
		static List<Patient^>^ pacientes = gcnew List<Patient^>();
		static List<Appointment^>^ citas = gcnew List<Appointment^>();
		static List<Recipe^>^ recetas = gcnew List<Recipe^>();
		static List<MedicineDispatch^>^ despachosMedicinas = gcnew List<MedicineDispatch^>();
		static List<MedicalHistory^>^ historialMedico = gcnew List<MedicalHistory^>();

		static String^ usuarioActual = L"";
		static String^ rolActual = L""; // "Doctor", "Enfermero", "Paciente"

		static HospitalData() {
			InicializarPersonalPredeterminado();
			CargarDatosJson();
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
			GuardarDatosJson();
		}

		static void CargarPacientes() {
			CargarDatosJson();
		}

		static void GuardarDatosJson() {
			try {
				nlohmann::json datos;
				datos["doctores"] = nlohmann::json::array();
				datos["enfermeros"] = nlohmann::json::array();
				datos["pacientes"] = nlohmann::json::array();
				datos["citas"] = nlohmann::json::array();
				datos["recetas"] = nlohmann::json::array();
				datos["despachosMedicinas"] = nlohmann::json::array();
				datos["historialMedico"] = nlohmann::json::array();

				for each (Doctor^ d in doctores) {
					datos["doctores"].push_back({
						{ "id", ToUtf8(d->id) },
						{ "nombre", ToUtf8(d->nombre) },
						{ "contrasena", ToUtf8(d->contrasena) },
						{ "especialidad", ToUtf8(d->especialidad) }
					});
				}

				for each (Nurse^ n in enfermeros) {
					datos["enfermeros"].push_back({
						{ "id", ToUtf8(n->id) },
						{ "nombre", ToUtf8(n->nombre) },
						{ "contrasena", ToUtf8(n->contrasena) }
					});
				}

				for each (Patient^ p in pacientes) {
					datos["pacientes"].push_back({
						{ "id", ToUtf8(p->id) },
						{ "nombre", ToUtf8(p->nombre) },
						{ "email", ToUtf8(p->email) },
						{ "telefono", ToUtf8(p->telefono) },
						{ "direccion", ToUtf8(p->direccion) },
						{ "contrasena", ToUtf8(p->contrasena) }
					});
				}

				for each (Appointment^ c in citas) {
					datos["citas"].push_back({
						{ "idPaciente", ToUtf8(c->idPaciente) },
						{ "nombrePaciente", ToUtf8(c->nombrePaciente) },
						{ "doctor", ToUtf8(c->doctor) },
						{ "fecha", ToUtf8(c->fecha) },
						{ "hora", ToUtf8(c->hora) },
						{ "razon", ToUtf8(c->razon) }
					});
				}

				for each (Recipe^ r in recetas) {
					datos["recetas"].push_back({
						{ "idPaciente", ToUtf8(r->idPaciente) },
						{ "nombrePaciente", ToUtf8(r->nombrePaciente) },
						{ "medicamentos", ToUtf8(r->medicamentos) },
						{ "dosis", ToUtf8(r->dosis) },
						{ "indicaciones", ToUtf8(r->indicaciones) },
						{ "fecha", ToUtf8(r->fecha) }
					});
				}

				for each (MedicineDispatch^ d in despachosMedicinas) {
					datos["despachosMedicinas"].push_back({
						{ "idPaciente", ToUtf8(d->idPaciente) },
						{ "nombrePaciente", ToUtf8(d->nombrePaciente) },
						{ "medicina", ToUtf8(d->medicina) },
						{ "fechaEntrega", ToUtf8(d->fechaEntrega) },
						{ "historiaClinica", ToUtf8(d->historiaClinica) },
						{ "responsable", ToUtf8(d->responsable) }
					});
				}

				for each (MedicalHistory^ h in historialMedico) {
					datos["historialMedico"].push_back({
						{ "idPaciente", ToUtf8(h->idPaciente) },
						{ "nombrePaciente", ToUtf8(h->nombrePaciente) },
						{ "diagnostico", ToUtf8(h->diagnostico) },
						{ "tratamiento", ToUtf8(h->tratamiento) },
						{ "fecha", ToUtf8(h->fecha) },
						{ "doctor", ToUtf8(h->doctor) }
					});
				}

				System::IO::File::WriteAllText(RutaArchivoJson(), FromUtf8(datos.dump(4)), System::Text::Encoding::UTF8);
			}
			catch (System::Exception^) {
			}
		}

		static void CargarDatosJson() {
			try {
				String^ rutaArchivo = RutaArchivoJson();
				if (!System::IO::File::Exists(rutaArchivo)) {
					CargarPacientesDat();
					GuardarDatosJson();
					return;
				}

				String^ contenido = System::IO::File::ReadAllText(rutaArchivo, System::Text::Encoding::UTF8);
				nlohmann::json datos = nlohmann::json::parse(ToUtf8(contenido), nullptr, false);
				if (datos.is_discarded()) {
					return;
				}

				doctores->Clear();
				enfermeros->Clear();
				pacientes->Clear();
				citas->Clear();
				recetas->Clear();
				despachosMedicinas->Clear();
				historialMedico->Clear();

				if (datos.contains("doctores") && datos["doctores"].is_array()) {
					for (const auto& item : datos["doctores"]) {
						Doctor^ d = gcnew Doctor();
						d->id = JsonString(item, "id");
						d->nombre = JsonString(item, "nombre");
						d->contrasena = JsonString(item, "contrasena");
						d->especialidad = JsonString(item, "especialidad");
						doctores->Add(d);
					}
				}

				if (datos.contains("enfermeros") && datos["enfermeros"].is_array()) {
					for (const auto& item : datos["enfermeros"]) {
						Nurse^ n = gcnew Nurse();
						n->id = JsonString(item, "id");
						n->nombre = JsonString(item, "nombre");
						n->contrasena = JsonString(item, "contrasena");
						enfermeros->Add(n);
					}
				}

				if (datos.contains("pacientes") && datos["pacientes"].is_array()) {
					for (const auto& item : datos["pacientes"]) {
						Patient^ p = gcnew Patient();
						p->id = JsonString(item, "id");
						p->nombre = JsonString(item, "nombre");
						p->email = JsonString(item, "email");
						p->telefono = JsonString(item, "telefono");
						p->direccion = JsonString(item, "direccion");
						p->contrasena = JsonString(item, "contrasena");
						pacientes->Add(p);
					}
				}

				if (datos.contains("citas") && datos["citas"].is_array()) {
					for (const auto& item : datos["citas"]) {
						Appointment^ c = gcnew Appointment();
						c->idPaciente = JsonString(item, "idPaciente");
						c->nombrePaciente = JsonString(item, "nombrePaciente");
						c->doctor = JsonString(item, "doctor");
						c->fecha = JsonString(item, "fecha");
						c->hora = JsonString(item, "hora");
						c->razon = JsonString(item, "razon");
						citas->Add(c);
					}
				}

				if (datos.contains("recetas") && datos["recetas"].is_array()) {
					for (const auto& item : datos["recetas"]) {
						Recipe^ r = gcnew Recipe();
						r->idPaciente = JsonString(item, "idPaciente");
						r->nombrePaciente = JsonString(item, "nombrePaciente");
						r->medicamentos = JsonString(item, "medicamentos");
						r->dosis = JsonString(item, "dosis");
						r->indicaciones = JsonString(item, "indicaciones");
						r->fecha = JsonString(item, "fecha");
						recetas->Add(r);
					}
				}

				if (datos.contains("despachosMedicinas") && datos["despachosMedicinas"].is_array()) {
					for (const auto& item : datos["despachosMedicinas"]) {
						MedicineDispatch^ d = gcnew MedicineDispatch();
						d->idPaciente = JsonString(item, "idPaciente");
						d->nombrePaciente = JsonString(item, "nombrePaciente");
						d->medicina = JsonString(item, "medicina");
						d->fechaEntrega = JsonString(item, "fechaEntrega");
						d->historiaClinica = JsonString(item, "historiaClinica");
						d->responsable = JsonString(item, "responsable");
						despachosMedicinas->Add(d);
					}
				}

				if (datos.contains("historialMedico") && datos["historialMedico"].is_array()) {
					for (const auto& item : datos["historialMedico"]) {
						MedicalHistory^ h = gcnew MedicalHistory();
						h->idPaciente = JsonString(item, "idPaciente");
						h->nombrePaciente = JsonString(item, "nombrePaciente");
						h->diagnostico = JsonString(item, "diagnostico");
						h->tratamiento = JsonString(item, "tratamiento");
						h->fecha = JsonString(item, "fecha");
						h->doctor = JsonString(item, "doctor");
						historialMedico->Add(h);
					}
				}

				InicializarPersonalPredeterminado();
			}
			catch (System::Exception^) {
				InicializarPersonalPredeterminado();
			}
		}
	};
}
