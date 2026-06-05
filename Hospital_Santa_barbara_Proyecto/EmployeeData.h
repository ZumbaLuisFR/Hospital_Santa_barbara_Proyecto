#pragma once

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

	// Estructura para Historial Médico
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
			doc1->nombre = L"Dr. Carlos Rodríguez";
			doc1->contrasena = L"1234";
			doc1->especialidad = L"Cardiología";
			doctores->Add(doc1);

			Doctor^ doc2 = gcnew Doctor();
			doc2->id = L"DOC002";
			doc2->nombre = L"Dra. María López";
			doc2->contrasena = L"1234";
			doc2->especialidad = L"Pediatría";
			doctores->Add(doc2);

			// Enfermeros predefinidos
			Nurse^ enf1 = gcnew Nurse();
			enf1->id = L"ENF001";
			enf1->nombre = L"Juan Pérez";
			enf1->contrasena = L"1234";
			enfermeros->Add(enf1);

			Nurse^ enf2 = gcnew Nurse();
			enf2->id = L"ENF002";
			enf2->nombre = L"Laura García";
			enf2->contrasena = L"1234";
			enfermeros->Add(enf2);

			// Pacientes predefinidos
			Patient^ pac1 = gcnew Patient();
			pac1->id = L"PAC001";
			pac1->nombre = L"Antonio Martínez";
			pac1->email = L"antonio@email.com";
			pac1->telefono = L"555-1234";
			pac1->direccion = L"Calle Principal 123";
			pac1->contrasena = L"1234";
			pacientes->Add(pac1);

			// Citas de ejemplo
			Appointment^ cita1 = gcnew Appointment();
			cita1->idPaciente = L"PAC001";
			cita1->nombrePaciente = L"Antonio Martínez";
			cita1->doctor = L"Dr. Carlos Rodríguez";
			cita1->fecha = L"2024-01-15";
			cita1->hora = L"10:00 AM";
			cita1->razon = L"Revisión de salud";
			citas->Add(cita1);

			// Recetas de ejemplo
			Recipe^ rec1 = gcnew Recipe();
			rec1->idPaciente = L"PAC001";
			rec1->nombrePaciente = L"Antonio Martínez";
			rec1->medicamentos = L"Paracetamol";
			rec1->dosis = L"500mg cada 8 horas";
			rec1->indicaciones = L"Tomar después de las comidas";
			rec1->fecha = L"2024-01-10";
			recetas->Add(rec1);

			// Historial médico de ejemplo
			MedicalHistory^ hist1 = gcnew MedicalHistory();
			hist1->idPaciente = L"PAC001";
			hist1->nombrePaciente = L"Antonio Martínez";
			hist1->diagnostico = L"Gripe común";
			hist1->tratamiento = L"Reposo y medicamentos";
			hist1->fecha = L"2024-01-05";
			hist1->doctor = L"Dr. Carlos Rodríguez";
			historialMedico->Add(hist1);
		}

		// Métodos de búsqueda
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
			return nuevoPaciente;
		}
	};
}
