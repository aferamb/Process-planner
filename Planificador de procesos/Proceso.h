#ifndef PROCESO_H
#define PROCESO_H
#include <ctime>
using namespace std;

class Proceso
{
    private:
        int PID;
        int PPID = 1;
        time_t inicio; // Time when the process was created
        int tiempoDeVida;
        int prioridad;
        int nucleoAsignado;

        // Calculate tiempoDeVida based on the start time
        void calcularTiempoDeVida() {
            time_t ahora = time(nullptr);
            tiempoDeVida = static_cast<int>(difftime(ahora, inicio));
        }

        public:
        // Constructor
         Proceso(int pid, int ppid, std::time_t inicio, int tiempoDeVida, int prioridad, int nucleoAsignado); 

        // Getters
        int getPID() const;
        int getPPID() const;
        std::time_t getInicio() const;
        int getTiempoDeVida() const;
        int getPrioridad() const;
        int getNucleoAsignado() const;

        // Setters
        void setPPID(int ppid);
        void setInicio(std::time_t inicio);
        void setTiempoDeVida(int tiempoDeVida);
        void setPrioridad(int prioridad);
        void setNucleoAsignado(int nucleoAsignado);
};

#endif // PROCESO_H