#include <vector>
#include <shoot.h>
#include "enemy.h"
#include "enemyVillain.h"
#include "enemySuperVillain.h"

class ObjectPooler 
{
public:
    // Constructor
    ObjectPooler(int poolSize,limits limits);

    // Obtener una bala disponible
    shoot* ObtenerBala(Position p, bool directionRight);

    void Disparar(Position p, bool directionRight);

    // Constructor privado para evitar la creación de instancias
    ObjectPooler();
    // Variable estática que almacena la única instancia de ObjectPooler
    static ObjectPooler instance;
    static ObjectPooler& getInstance(); // Método para obtener la instancia singleton

    // Devolver una bala al pool
    void DevolverBala(shoot* bala);


    //renderizas balas en uso
    void RenderBulletUsed(sf::RenderWindow& window);

    //renderizas balas en uso
    void UpdateBulletUsed();

    std::vector<shoot*>& getBalasEnUso();

    //check position collision with enemy
    bool checkPositionCollisionEnemyVillain(sf::FloatRect boxColliderEnemy);

  
    void update();

    //renderizar enemies
    void render(sf::RenderWindow& window);

    bool playerIsDead(sf::FloatRect boxColliderEnemy);

private:
    // Lista de balas disponibles
    std::vector<shoot*> balasDisponibles;

    // Lista de balas en uso
    std::vector<shoot*> balasEnUso;


    //player info
    limits limitsP;

    Position playerPos;




public:

    //spawns de enemySuperVillain
    static const int enemySuperSpawns = 3;
    Position spawnsEnemySuperVillain[enemySuperSpawns];

    //spawns de enemyVillain
    static const int enemySpawns = 3;
    Position spawnsEnemyVillain[enemySpawns];

    void CreateEnemies(int numEnemiesVillain, int numEnemiesSuperVillain, limits limits);

    void CreateSpawns();
    void CreateSpawnsSuperVillain();
    void CreateSpawnsVillain();

    void CreateNewEnemy();

    //array con enemigos de pool
    std::vector<enemy*> m_enemies{};

    void EliminarEnemigosMuertos();

    limits limites;



};