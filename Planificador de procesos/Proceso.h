#ifndef PROCESO_H
#define PROCESO_H
#include <iostream>

using namespace std;

class Proceso {
    private:
        static int contador_PID;    // Contador estático para asignar PID único
        int PID;                    // Identificador del proceso
        int PPID;                   // Identificador del proceso padre
        int inicio;                 // Minutos de inicio del proceso en minutos desde las 00:00
        int tiempoDeVida;           // Tiempo de vida del proceso en minutos
        int prioridad;              // Prioridad del proceso (0 = mayor prioridad, 9 = menor prioridad)
        int nucleoAsignado;         // Núcleo al que se asigna el proceso

        int tiempoEjecucion;        // Tiempo de ejecución del proceso en minutos

    public:
        // Constructor por defecto
        Proceso();
        Proceso(int ppid, int inicio, int tiempoDeVida, int prioridad);
        ~Proceso();

        // Getters
        int get_PID() const;
        int get_PPID() const;
        int get_inicio() const;
        int get_tiempo_de_vida() const;
        int get_prioridad() const;
        int get_nucleo_asignado() const;
        int get_tiempo_ejecucion() const;

        // Setters
        void set_PPID(int ppid);
        void set_inicio(int inicio);
        void set_tiempo_de_vida(int tiempoDeVida);
        void set_prioridad(int prioridad);
        void set_nucleo_asignado(int nucleoAsignado);
        void set_tiempo_ejecucion(int tiempoEjecucion);

        // Métodos
        void mostrar() const; // No probado
        //Proceso crear_proceso(); 
};

#endif // PROCESO_H