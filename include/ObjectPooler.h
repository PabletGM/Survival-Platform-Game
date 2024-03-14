#include <vector>
#include <shoot.h>


class ObjectPooler 
{
public:
    // Constructor
    ObjectPooler(int poolSize,limits limits);

    // Obtener una bala disponible
    shoot* ObtenerBala(Position p);

    void Disparar(Position p);

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

private:
    // Lista de balas disponibles
    std::vector<shoot*> balasDisponibles;

    // Lista de balas en uso
    std::vector<shoot*> balasEnUso;


    //player info
    limits limitsP;


};