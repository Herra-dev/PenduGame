#include "HObject.h"

/**
 * @brief HObject::genereNombreHasard (static)
 * @param max
 * @return nbr
 *
 * retourne un nombre aléatoire entre 0 et max {(si max == 0) max = 1} //Pour éviter la division par zéro
 */
int HObject::genereNombreHasard(int max)
{
    srand(time(0));
    int nbr(0);
    if(max == 0)
        max = 1;
    nbr = rand() % max;

    std::cout << "nombre : " << nbr << std::endl;

    return nbr;
}
