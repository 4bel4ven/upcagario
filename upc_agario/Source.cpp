#include "juego.h"
#include "jugador.h"
#include "figura.h"
#include "circuloAleatorio.h"
#include "virus.h"
#include "vecFiguras.h"


int main(array<System::String^> ^args)
{
	System::Windows::Forms::Application::EnableVisualStyles();
	System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);

	System::Windows::Forms::Application::Run(gcnew upcagario::juego());
		return 0;
}