#include "ObjectPooler.h"

ObjectPooler::ObjectPooler(int poolSize, limits limitsPlayer, Position pos)
{
    limitsP = limitsPlayer;
    p = pos;
}

shoot* ObjectPooler::ObtenerBala()
{
    if (balasDisponibles.empty()) {
        // Si no hay balas disponibles, crea una nueva
        // Obtener una bala, crear instancia
        shoot* bala1 = new shoot(limitsP, p);
        balasEnUso.push_back(bala1);
        return bala1;
    }
    else {
        // Si hay balas disponibles, toma una del pool
        shoot* bala = balasDisponibles.back();
        balasDisponibles.pop_back();
        balasEnUso.push_back(bala);
        return bala;
    }
}

void ObjectPooler::DevolverBala(shoot* bala)
{
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

