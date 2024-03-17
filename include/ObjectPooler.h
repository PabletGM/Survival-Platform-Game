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
    ~ObjectPooler();

    // Obtain an available bullet
    shoot* ObtenerBala(Position p, bool directionRight);

    //shoot method
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

    //update balas en uso
    void UpdateBulletUsed();

    //array with bullets
    std::vector<shoot*>& getBalasEnUso();

    //check position collision with enemy
    bool checkPositionCollisionEnemyVillain(sf::FloatRect boxColliderEnemy);

  
    void update();

    //renderizar enemies
    void render(sf::RenderWindow& window);

    //collider with player and enemies
    bool playerIsDead(sf::FloatRect boxColliderEnemy);

    //actual lifes player
    int GetActualLifes();

private:
    // Lista de balas disponibles
    std::vector<shoot*> balasDisponibles;

    // Lista de balas en uso
    std::vector<shoot*> balasEnUso;


    //player info
    limits limitsP;



    int maxLife = 3;
    int actualLife = 3;
    bool isDead = false;

    //cronometro cambio animacion player
    sf::Clock cronometro;
    sf::Time tiempoDeseado = sf::seconds(3.0f);

    //lose life
    bool LoseLife();

    
    //invulnerability with losing life for 3 secs
    void Invulnerability();


    //invulerabilidad
    bool invulnerability = false;




public:

    //spawns de enemySuperVillain
    static const int enemySuperSpawns = 3;
    //spawns superVillain
    Position spawnsEnemySuperVillain[enemySuperSpawns];

    //spawns of enemy normal
    static const int enemySpawns = 3;
    Position spawnsEnemyVillain[enemySpawns];

    //create enemies and add to list
    void CreateEnemies(int numEnemiesVillain, int numEnemiesSuperVillain, limits limits);

    //crear spawns de enemies
    void CreateSpawns();
    void CreateSpawnsSuperVillain();
    void CreateSpawnsVillain();

    //each time a new enemy is spawned
    void CreateNewEnemy();

    //array con enemigos de pool
    std::vector<enemy*> m_enemies{};

    //method that eliminates dead enemies
    void EliminarEnemigosMuertos();

    //limits map
    limits limites;



};