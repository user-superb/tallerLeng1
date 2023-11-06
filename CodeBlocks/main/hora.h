#ifndef HORA_H_INCLUDED
#define HORA_H_INCLUDED

typedef struct {
    unsigned int hora;
    unsigned int minuto;
    unsigned int segundos;
} horario;

void verHora(horario *hora);
void verHora2(horario *hora);

#endif // HORA_H_INCLUDED
