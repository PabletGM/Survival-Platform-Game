#include "ObjectPooler.h"



ObjectPooler::ObjectPooler(int poolSize, limits limitsPlayer)
{
    limitsP = limitsPlayer;

}

shoot* ObjectPooler::ObtenerBala(Position p)
{
    if (balasDisponibles.empty()) {
        // Si no hay balas disponibles, crea una nueva
        // Obtener una bala, crear instancia
        shoot* bala1 = new shoot(limitsP,p);
        bala1->RestartPosShootEnPlayer();
        balasEnUso.push_back(bala1);
        return bala1;
    }
    else {
        // Si hay balas disponibles, toma una del pool
        shoot* bala1 = new shoot(limitsP, p);
        bala1 = balasDisponibles.back();
        balasDisponibles.pop_back();
        balasEnUso.push_back(bala1);
        return bala1;
    }
}

void ObjectPooler::Disparar(Position p)
{
    ObtenerBala(p);
}

// Inicializaci�n de la variable est�tica instance
ObjectPooler ObjectPooler::instance;

// Implementaci�n del constructor por defecto
ObjectPooler::ObjectPooler() 
{
    // Aqu� puedes realizar cualquier inicializaci�n necesaria para tu ObjectPooler
}

// Implementaci�n del m�todo getInstance para devolver la instancia singleton
ObjectPooler& ObjectPooler::getInstance() 
{
    return instance;
}

void ObjectPooler::DevolverBala(shoot* bala)
{
    bala->RestartPosShootEnPlayer();
    // Devuelve la bala al pool de disponibles
    balasEnUso.erase(std::remove(balasEnUso.begin(), balasEnUso.end(), bala), balasEnUso.end());
    balasDisponibles.push_back(bala);
}

void ObjectPooler::RenderBulletUsed(sf::RenderWindow& window)
{
    for (auto* bala : balasEnUso) 
    {
        bala->render(window);
    }
}

void ObjectPooler::UpdateBulletUsed()
{
    for (auto* bala : balasEnUso)
    {
        bala->update();
    }
}

