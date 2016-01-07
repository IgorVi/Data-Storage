
#include "DvdRom.h"

DvdRom::DvdRom() :
RecordingSpeed(0)
{
}

DvdRom::~DvdRom(){
}

void DvdRom::Print() const{
	std::cout << "Наименование:              \t" << InformationCarrier::GetDenomination() << std::endl;		//	наименование
	std::cout << "Имя производителя:         \t" << InformationCarrier::GetNameManufacturer() << std::endl;	//	имя производителя
	std::cout << "Модель:                    \t" << InformationCarrier::GetModel() << std::endl;				//	модель
	std::cout << "Количество:                \t" << InformationCarrier::GetCount() << std::endl;				//	количество
	std::cout << "Скорость записи:           \t" << RecordingSpeed << "x" << std::endl;
}

void DvdRom::Loading(std::ifstream& in){

	InformationCarrier::Loading(in);

	char string[MAX_LENGTH] = {};

	in >> RecordingSpeed;
	in.get();
}

void DvdRom::Save(std::ofstream &out) const{

	InformationCarrier::Save(out);

	out << RecordingSpeed << '\n';
}

void DvdRom::SetRecordingSpeed(const unsigned int n){
	RecordingSpeed = n;
}

unsigned int DvdRom::GetRecordingSpeed() const{
	return RecordingSpeed;
}