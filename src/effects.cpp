#include "effects.h"

effects::effects()
{
}

effects::~effects()
{
}

// Inicializaci�n de la variable est�tica instance
effects effects::instance;

effects& effects::getInstance()
{
	return instance;
}
