#include "UIManager.h"


// Inicializaci�n de la variable est�tica instance
UIManager UIManager::instance;


UIManager::UIManager()
{
}

UIManager::~UIManager()
{
}

void UIManager::update(float deltaMS, sf::RenderWindow& window)
{
}

void UIManager::render(float deltaMS, sf::RenderWindow& window)
{
}

UIManager& UIManager::getInstance()
{
	return instance;
}
