#include <vector>
#include <shoot.h>
#include "enemy.h"
#include "enemyVillain.h"
#include "enemySuperVillain.h"


class effects
{
public:
    // Constructor
    effects();


    
    // Variable est�tica que almacena la �nica instancia de ObjectPooler
    static effects instance;
    static effects& getInstance(); // M�todo para obtener la instancia singleton





};