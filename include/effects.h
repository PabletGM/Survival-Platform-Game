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


    
    // Variable est�tica que almacena la �nica instancia de ObjectPooler
    static effects instance;
    static effects& getInstance(); // M�todo para obtener la instancia singleton





};