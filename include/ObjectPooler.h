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