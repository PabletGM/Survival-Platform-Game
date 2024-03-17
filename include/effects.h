#include <vector>
#include <shoot.h>
#include "enemy.h"
#include "enemyVillain.h"
#include "enemySuperVillain.h"


//no use, tried damage enemies sprite or shader
class effects
{
public:
    // Constructor
    effects();
    ~effects();


    
    // Variable estática que almacena la única instancia de ObjectPooler
    static effects instance;
    static effects& getInstance(); // Método para obtener la instancia singleton





};