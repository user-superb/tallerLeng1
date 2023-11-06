#include <stdio.h>
#include "hora.h"

void verHora(horario *hora) {
    printf("[%d:%d:%d]\n", hora->hora, hora->minuto, hora->segundos);
}

void verHora2(horario *hora) {
    if (hora->hora >= 13) {
        printf("[%d:%d:%d] [PM]\n", hora->hora - 12, hora->minuto, hora->segundos);
    } else {
        printf("[%d:%d:%d] [AM]\n", hora->hora, hora->minuto, hora->segundos);
    }
}
