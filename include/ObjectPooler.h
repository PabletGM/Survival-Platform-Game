#include <vector>
#include <shoot.h>

class ObjectPooler {
public:
    // Constructor
    ObjectPooler(int poolSize);

    // Obtener una bala disponible
    shoot* ObtenerBala();

    // Devolver una bala al pool
    void DevolverBala(shoot* bala);

private:
    // Lista de balas disponibles
    std::vector<shoot*> balasDisponibles;

    // Lista de balas en uso
    std::vector<shoot*> balasEnUso;
};