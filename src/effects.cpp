#include "effects.h"

effects::effects()
{
}

// Inicialización de la variable estática instance
effects effects::instance;

effects& effects::getInstance()
{
	return instance;
}
