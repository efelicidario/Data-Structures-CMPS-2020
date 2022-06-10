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
        static int count;

    public:
        Computer();
        Computer(int cores, double processor_speed, int drive_size, int ram, string processor_type);
        Computer(const Computer &pc);
        ~Computer();
        string ToString();

        static int GetCount();
        friend bool Greater(const Computer & c1, const Computer & c2);
        friend bool Less(const Computer & c1, const Computer & c2);
        friend bool Equal(const Computer & c1, const Computer & c2);

};



