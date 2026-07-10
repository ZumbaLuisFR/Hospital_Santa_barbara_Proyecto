#pragma once
#pragma execution_character_set("utf-8")

#include "EmployeeData.h"

namespace HospitalSantabarbaraProyecto {

	using namespace System;

	public ref class LoginResponse {
	public:
		bool exitoso;
		bool requiereRegistro;
		String^ rol;
		String^ mensaje;

		LoginResponse(bool ok, bool registro, String^ rolUsuario, String^ textoMensaje) {
			exitoso = ok;
			requiereRegistro = registro;
			rol = rolUsuario;
			mensaje = textoMensaje;
		}
	};

	public ref class AuthController {
	public:
		static LoginResponse^ IniciarSesion(String^ id, String^ contrasena) {
			if (id == nullptr) id = L"";
			if (contrasena == nullptr) contrasena = L"";

			id = id->Trim();

			if (id->Length == 0 || contrasena->Length == 0) {
				return gcnew LoginResponse(false, false, L"", L"Por favor complete todos los campos");
			}

			if (id->Length < 3) {
				return gcnew LoginResponse(false, false, L"", L"El ID debe tener al menos 3 caracteres");
			}

			if (contrasena->Length < 4) {
				return gcnew LoginResponse(false, false, L"", L"La contraseña debe tener al menos 4 caracteres");
			}

			if (HospitalData::AutenticarDoctor(id, contrasena)) {
				HospitalData::usuarioActual = id;
				HospitalData::rolActual = L"Doctor";
				return gcnew LoginResponse(true, false, L"Doctor", L"");
			}

			if (HospitalData::AutenticarEnfermero(id, contrasena)) {
				HospitalData::usuarioActual = id;
				HospitalData::rolActual = L"Enfermero";
				return gcnew LoginResponse(true, false, L"Enfermero", L"");
			}

			Patient^ paciente = HospitalData::BuscarPaciente(id);
			if (paciente != nullptr && HospitalData::AutenticarPaciente(id, contrasena)) {
				HospitalData::usuarioActual = id;
				HospitalData::rolActual = L"Paciente";
				return gcnew LoginResponse(true, false, L"Paciente", L"");
			}

			if (paciente == nullptr) {
				return gcnew LoginResponse(false, true, L"", L"El usuario no existe.");
			}

			return gcnew LoginResponse(false, false, L"", L"Credenciales inválidas. Intente nuevamente.");
		}
	};
}
