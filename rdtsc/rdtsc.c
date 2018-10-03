/* gcc rdtsc.c -o rdtsc */

#include <stdio.h>
#include <stdint.h>

static inline uint64_t rdtsc(void)
{
    unsigned int eax, edx;
    asm volatile
    (
        "rdtsc" : "=a" (eax), "=d" (edx)
    );
    return ((uint64_t) edx << 32) | eax;
}

int main()
{
    uint64_t tmp = 0, tiempo1 = 0, tiempo2 = 0;
    double tiempo = 0;
    tiempo1 = rdtsc();
    //INICIO DEL ALGORIMO A MEDIR

    //FIN DEL ALGORITMO A MEDIR
    tiempo2 = rdtsc();
    tmp = tiempo2 - tiempo1;
    tiempo = (double) tmp / 1900000000; //ciclos de reloj por segundo de la maquina que lo corre 
    printf("\nCiclos de Reloj: %lu\n", tmp);
    printf("\nTiempo en Segundos: %f\n", tiempo);
    return 0;
}
