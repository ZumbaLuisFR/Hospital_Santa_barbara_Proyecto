#pragma once
#pragma execution_character_set("utf-8")

#include "EmployeeData.h"

namespace HospitalSantabarbaraProyecto {

	using namespace System;

	public ref class PatientRegistrationResult {
	public:
		bool exitoso;
		String^ mensaje;

		PatientRegistrationResult(bool ok, String^ textoMensaje) {
			exitoso = ok;
			mensaje = textoMensaje;
		}
	};

	public ref class PatientController {
	public:
		static PatientRegistrationResult^ RegistrarPaciente(
			String^ pacienteID,
			String^ nombre,
			String^ cedula,
			String^ email,
			String^ telefono,
			String^ direccion,
			String^ contrasena
		) {
			if (pacienteID == nullptr) pacienteID = L"";
			if (nombre == nullptr) nombre = L"";
			if (cedula == nullptr) cedula = L"";
			if (email == nullptr) email = L"";
			if (telefono == nullptr) telefono = L"";
			if (direccion == nullptr) direccion = L"";
			if (contrasena == nullptr) contrasena = L"";

			pacienteID = pacienteID->Trim();
			nombre = nombre->Trim();
			cedula = cedula->Trim();
			email = email->Trim();
			telefono = telefono->Trim();
			direccion = direccion->Trim();

			if (nombre->Length == 0 || cedula->Length == 0 || email->Length == 0 ||
				telefono->Length == 0 || direccion->Length == 0 || contrasena->Length == 0) {
				return gcnew PatientRegistrationResult(false, L"Por favor complete todos los campos");
			}

			if (!email->Contains(L"@")) {
				return gcnew PatientRegistrationResult(false, L"Email inválido");
			}

			if (contrasena->Length < 4) {
				return gcnew PatientRegistrationResult(false, L"La contraseña debe tener al menos 4 caracteres");
			}

			Patient^ paciente = HospitalData::BuscarPaciente(pacienteID);
			if (paciente == nullptr) {
				paciente = gcnew Patient();
				paciente->id = pacienteID;
				HospitalData::pacientes->Add(paciente);
			}

			paciente->nombre = nombre;
			paciente->email = email;
			paciente->telefono = telefono;
			paciente->direccion = direccion;
			paciente->contrasena = contrasena;

			HospitalData::GuardarPacientes();
			HospitalData::usuarioActual = pacienteID;
			HospitalData::rolActual = L"Paciente";

			return gcnew PatientRegistrationResult(true, L"Paciente registrado correctamente");
		}
	};
}
