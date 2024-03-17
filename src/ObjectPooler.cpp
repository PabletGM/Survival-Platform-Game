#include "ObjectPooler.h"
#include <iostream>
#include <enemyManager.h>








//constructor

ObjectPooler::ObjectPooler(int poolSize, limits limitsPlayer)
{
    limitsP = limitsPlayer;
}

//destructor
ObjectPooler::~ObjectPooler()
{
}

//obtain bullet balasEnUso
shoot* ObjectPooler::ObtenerBala(Position p, bool directionRight)
{
    if (balasDisponibles.empty()) {
        // Si no hay balas disponibles, crea una nueva
        // Obtener una bala, crear instancia
        shoot* bala1 = new shoot(limitsP,p, directionRight);
        bala1->RestartPosShootEnPlayer();
        balasEnUso.push_back(bala1);
        return bala1;
    }
    else {
        // Si hay balas disponibles, toma una del pool
        shoot* bala1 = new shoot(limitsP, p, directionRight);
        bala1 = balasDisponibles.back();
        balasDisponibles.pop_back();
        balasEnUso.push_back(bala1);
        return bala1;
    }
}

//shoot and its direction
void ObjectPooler::Disparar(Position p, bool directionRight)
{
    ObtenerBala(p, directionRight);
}

// Inicialización de la variable estática instance
ObjectPooler ObjectPooler::instance;

// Implementación del constructor por defecto
ObjectPooler::ObjectPooler() 
{
    
}

// Implementación del método getInstance para devolver la instancia singleton
ObjectPooler& ObjectPooler::getInstance() 
{
    return instance;
}

//destroy a bullet
void ObjectPooler::DevolverBala(shoot* bala)
{
    bala->RestartPosShootEnPlayer();
    bala->RestartDirShootEnPlayer();
    // Devuelve la bala al pool de disponibles
    balasEnUso.erase(std::remove(balasEnUso.begin(), balasEnUso.end(), bala), balasEnUso.end());
    balasDisponibles.push_back(bala);
}

//render bullet 
void ObjectPooler::RenderBulletUsed(sf::RenderWindow& window)
{
    for (auto* bala : balasEnUso) 
    {
        bala->render(window);
    }
}

//update bullets position
void ObjectPooler::UpdateBulletUsed()
{
    //actualizamos balas disponibles a posicion del player
    for (auto* balaD : balasDisponibles)
    {
        balaD->RestartPosShootEnPlayer();
        balaD->RestartDirShootEnPlayer();
    }

    //actualizamos posicion de balas en uso
    for (auto* bala : balasEnUso)
    {
        bala->update();
    }
}


std::vector<shoot*>& ObjectPooler::getBalasEnUso()
{
    return balasEnUso;
}

//check if there is a collision between player and enemies
bool ObjectPooler::checkPositionCollisionEnemyVillain(sf::FloatRect boxColliderEnemy)
{
    for (auto* bala : balasEnUso)
    {
       
        //por cada box collier de bala a ver si coincide con el de enemy
        if (boxColliderEnemy.intersects(bala->getBoxColliderBala()))
        {
            //si coincide es que ha chocado una bala con enemy
            std::cout << "bala choca con enemy";
            return true;
        }
    }
    return false;
}

//create spawns enemies
void ObjectPooler::CreateSpawns()
{
    CreateSpawnsSuperVillain();
    CreateSpawnsVillain();

}

void ObjectPooler::CreateSpawnsSuperVillain()
{
    //spawns pre-created in places
    Position p1 = { 100,100 };
    Position p2 = { 300,300 };
    Position p3 = { 500,700 };
    //Position p4 = { 700,900 };
    //Position p5 = { 900,000 };

    for (int i = 0; i < enemySuperSpawns; ++i)
    {

        //switch to choose the enemy
        switch (i)
        {
            case 0:
                spawnsEnemySuperVillain[i].posX = p1.posX;
                spawnsEnemySuperVillain[i].posY = p1.posY;
                break;

            case 1:
                spawnsEnemySuperVillain[i].posX = p2.posX;
                spawnsEnemySuperVillain[i].posY = p2.posY;
                break;

            case 2:
                spawnsEnemySuperVillain[i].posX = p3.posX;
                spawnsEnemySuperVillain[i].posY = p3.posY;
                break;
            }

    }
}

void ObjectPooler::CreateSpawnsVillain()
{
    //spawns pre-created in places
    Position p1 = { 300,300 };
    Position p2 = { 1200,200 };
    Position p3 = { 1400,700 };
    //Position p4 = { 700,900 };
    //Position p5 = { 900,000 };

    for (int i = 0; i < enemySpawns; ++i)
    {

        //switch to choose the enemy
        switch (i)
        {
        case 0:
            spawnsEnemyVillain[i].posX = p1.posX;
            spawnsEnemyVillain[i].posY = p1.posY;
            break;

        case 1:
            spawnsEnemyVillain[i].posX = p2.posX;
            spawnsEnemyVillain[i].posY = p2.posY;
            break;

        case 2:
            spawnsEnemyVillain[i].posX = p3.posX;
            spawnsEnemyVillain[i].posY = p3.posY;
            break;
        }

    }
}

//create new enemies each 2 o 3 seconds
void ObjectPooler::CreateNewEnemy()
{
    // Generar un número aleatorio entre 0 y 1 para elegir entre enemyVillain y enemySuperVillain
    int randomEnemyType = rand() % 2; // 0 o 1

    // Crear una posición aleatoria
    Position randomPosition;
    randomPosition.posX = rand() % limites.limitDerecho;
    randomPosition.posY = rand() % limites.limitAbajo;

    // Elegir el tipo de enemigo y crearlo
    enemy* newEnemy;
    if (randomEnemyType == 0) {
        newEnemy = new enemyVillain(randomPosition, limites);
    }
    else {
        newEnemy = new enemySuperVillain(randomPosition, limites);
    }

    // Agregar el nuevo enemigo al vector de enemigos
    m_enemies.push_back(newEnemy);
}


//eliminate death enemies
void ObjectPooler::EliminarEnemigosMuertos()
{
    // Recorrer el vector y eliminar los enemigos muertos
    for (auto it = m_enemies.begin(); it != m_enemies.end(); ) 
    {
        if ((*it)->muerto) {
            delete* it;  // Liberar la memoria del enemigo eliminado
            it = m_enemies.erase(it);
        }
        else 
        {
            ++it;
        }
    }
}



//create new enemies
void ObjectPooler::CreateEnemies(int numEnemiesVillain, int numEnemiesSuperVillain, limits limits)
{
    limites = limits;
    //inicializamos enemySuperVillain
    for (int i = 0;i < numEnemiesSuperVillain;i++)
    {

        enemy* e = new enemySuperVillain(spawnsEnemySuperVillain[i], limits);
        m_enemies.push_back(e);

    }

    //inicializamos enemyVillain
    for (int i = 0;i < numEnemiesVillain;i++)
    {

        enemy* e = new enemyVillain(spawnsEnemyVillain[i], limits);
        m_enemies.push_back(e);

    }
}


//render the alive enemies
void ObjectPooler::render(sf::RenderWindow& window)
{
    //iterador que recorre toda la lista de enemigos in game
    for (auto i = m_enemies.begin(); i < m_enemies.end(); i++)
    {
        //accedemos al objeto apuntado por iterador i, accedemos al contenido que apunta i
        enemy* currentEnemy = *i;
        //si el objeto existe
        if (currentEnemy)
        {
            if (currentEnemy != nullptr)
            {
                // Llamar al método render del objeto actual
                currentEnemy->render(window);
            }
        }
    }
}

//compare positions of player and enemies
bool ObjectPooler::playerIsDead(sf::FloatRect boxColliderPlayer)
{
    //comparamos posicion de player con todos los enemies
    for (auto i = m_enemies.begin(); i < m_enemies.end(); i++)
    {
        //accedemos al objeto apuntado por iterador i, accedemos al contenido que apunta i
        enemy* currentEnemy = *i;
        if (boxColliderPlayer.intersects(currentEnemy->getBoxColliderEnemy()))
        {
            //si no tiene invulerabilidad
            if (!invulnerability)
            {
                //pierde vida y pone invulnerabilidad por 1 segundo
                bool dead = LoseLife();
                if (dead) return true;
            }  
        }
    }
    return false;

}

//reference to actual lifes
int ObjectPooler::GetActualLifes()
{
    return actualLife;
}

//update enemies position
void ObjectPooler::update()
{
    //iterador que recorre toda la lista de enemigos in game
    for (auto i = m_enemies.begin(); i < m_enemies.end(); i++)
    {
        //accedemos al objeto apuntado por iterador i, accedemos al contenido que apunta i
        enemy* currentEnemy = *i;
        //si el objeto existe
        if (currentEnemy)
        {
            if (currentEnemy != nullptr)
            {
                // Llamar al método render del objeto actual
                currentEnemy->update();
            }
        }
    }

    //actualizamos muertos y destruimos enemigos que lo estan
    EliminarEnemigosMuertos();

    // Comprobar si la invulnerabilidad está activa
    if (invulnerability)
    {
        
        // Verificar si ha pasado el tiempo deseado (3 segundos)
        if (cronometro.getElapsedTime().asSeconds() >= 3.0f) {
            // Desactivar la invulnerabilidad
            invulnerability = false;
        }
    }
}

//put the invulnerability a true
void ObjectPooler::Invulnerability()
{
    invulnerability = true;
    cronometro.restart(); 
}


//lose a life and check if player is dead
bool ObjectPooler::LoseLife()
{
    // Verificar si el jugador ya está muerto
    if (actualLife <= 0) return true;

    // Aplicar la pérdida de vida al jugador
   --actualLife;

    // Activar la invulnerabilidad
    Invulnerability();

    // Devolver si el jugador está muerto o no
    return false;
    
}



