#include "music.h"

music::music()
{
	Play();
}

music::~music()
{
	Stop();
}

// Inicialización de la variable estática instance
music music::instance;

music& music::getInstance()
{
	return instance;
}

void music::Play()
{
	musicObject.play();
}

void music::Stop()
{
	musicObject.stop();
}

void music::LoadMusic()
{
	musicObject.openFromFile(".. / sprites / music / music.mp3");
}
