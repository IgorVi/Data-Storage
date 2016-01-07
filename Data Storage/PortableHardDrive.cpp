
#include "PortableHardDrive.h"

PortableHardDrive::PortableHardDrive() :
SpindleSpeed(0)
{
}

PortableHardDrive::~PortableHardDrive()
{
}

void PortableHardDrive::Print() const{
	InformationCarrier::Print();
	std::cout << "Скорость вращения шпиндель:\t" << SpindleSpeed << " об/мин" << std::endl;
}

void PortableHardDrive::Loading(std::ifstream& in){

	InformationCarrier::Loading(in);

	in >> SpindleSpeed;
	in.get();
}

void PortableHardDrive::Save(std::ofstream &out) const{

	InformationCarrier::Save(out);

	out << SpindleSpeed << '\n';
}

void PortableHardDrive::SetSpindleSpeed(const unsigned int n){
	SpindleSpeed = n;
}

unsigned int PortableHardDrive::GetSpindleSpeed() const{
	return SpindleSpeed;
}