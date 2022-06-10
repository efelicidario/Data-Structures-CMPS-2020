#include "cmpslib19.h"
#include "easylogging++.h"



class Computer
{
    private:
        int cores;
        double processor_speed;
        int drive_size;
        int ram;
        string processor_type;

    public:
        Computer();
        Computer(int cores, double processor_speed, int drive_size, int ram, string processor_type);
        Computer(const Computer &pc);
        ~Computer();
        string ToString();

};



