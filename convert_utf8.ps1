$files = @(
	"Hospital_Santa_barbara_Proyecto\PatientRegistrationForm.h",
	"Hospital_Santa_barbara_Proyecto\PatientRegistrationForm.cpp",
	"Hospital_Santa_barbara_Proyecto\MedicalNotesForm.h"
)

foreach ($file in $files) {
	$content = [System.IO.File]::ReadAllText($file, [System.Text.Encoding]::UTF8)
	$utf8bom = New-Object System.Text.UTF8Encoding $true
	[System.IO.File]::WriteAllText($file, $content, $utf8bom)
	Write-Host "Convertido a UTF-8 con BOM: $file"
}
