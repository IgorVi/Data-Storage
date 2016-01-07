
#include "USBFlashDrive.h"

USBFlashDrive::USBFlashDrive() :
SpeedUSB(0)
{
}

USBFlashDrive::~USBFlashDrive()
{
}

void USBFlashDrive::Print() const{
	InformationCarrier::Print();
	std::cout << "Cкорость USB:              \t" << SpeedUSB << " МБ/c" << std::endl;
}

void USBFlashDrive::Loading(std::ifstream& in){

	InformationCarrier::Loading(in);

	in >> SpeedUSB;
	in.get();
}

void USBFlashDrive::Save(std::ofstream &out) const{

	InformationCarrier::Save(out);

	out << SpeedUSB << '\n';
}

void USBFlashDrive::SetUSBFlashDrive(const unsigned int n){
	SpeedUSB = n;
}

unsigned int USBFlashDrive::GetUSBFlashDrive() const{
	return SpeedUSB;
}