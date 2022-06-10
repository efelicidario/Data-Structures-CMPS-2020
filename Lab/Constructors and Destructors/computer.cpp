#include "computer.h"



// when putting your funcion bodies outside the class.. in a cpp file 
// ReturnType Classname::FunctionName(parameters)
Computer::Computer()
{
    LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
    cores = 0;
    processor_speed = 0;
    drive_size = 0;
    ram = 0;
    processor_type = "none";
    LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
}

Computer::Computer(int cores, double processor_speed, int drive_size, int ram, string processor_type)
{
    LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
    this->cores = cores;
    this->processor_speed = processor_speed;
    this->drive_size = drive_size;
    this->ram = ram;
    this->processor_type = processor_type;
    LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
}

Computer::Computer(const Computer& pc)
{
    LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
    this->cores = pc.cores;
    this->processor_speed = pc.processor_speed;
    this->drive_size = pc.drive_size;
    this->ram = pc.ram;
    this->processor_type = pc.processor_type;
    LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
}

Computer::~Computer()
{
	LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
}

string Computer::ToString()
{
	LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
	ostringstream out; // a temporary stream, use just like you would cout but it stays in memory

	out << processor_speed	<< " Ghz "		<< processor_type << " "
		<<  cores	<< " Cores"				<< endl
		<< drive_size		<< " Gb disk"	<< endl
		<< ram				<< " Gb ram"	<< endl;

  string temp = out.str(); // put all the text in the stream into a single string

	LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
	return(temp);
}



