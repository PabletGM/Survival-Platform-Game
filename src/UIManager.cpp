#include "UIManager.h"


// Inicialización de la variable estática instance
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
