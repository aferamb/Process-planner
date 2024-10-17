#ifndef PROCESO_H
#define PROCESO_H
#include <ctime>
using namespace std;

class Proceso
{
    private:
        int PID;
        int PPID = 1;
        time_t inicio; // Time when the process is going to be executed
        int tiempoDeVida;
        int prioridad;
        int nucleoAsignado;

    public:
        // Constructor
        Proceso();
        Proceso(int pid, int ppid, std::time_t inicio, int tiempoDeVida, int prioridad); //int nucleoAsignado

        // Getters
        int get_PID() const;
        int get_PPID() const;
        time_t get_inicio() const;
        int get_tiempo_de_vida() const;
        int get_prioridad() const;
        int get_nucleo_asignado();

        // Setters
        void set_PPID(int ppid);
        void set_inicio(time_t inicio);
        void set_tiempo_de_vida(int tiempoDeVida);
        void set_prioridad(int prioridad);
        void set_nucleo_asignado(int nucleoAsignado);
};

#endif // PROCESO_H