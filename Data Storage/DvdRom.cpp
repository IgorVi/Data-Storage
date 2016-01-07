
#include "DvdRom.h"

DvdRom::DvdRom() :
RecordingSpeed(0)
{
}

DvdRom::~DvdRom(){
}

void DvdRom::Print() const{
	std::cout << "������������:              \t" << InformationCarrier::GetDenomination() << std::endl;		//	������������
	std::cout << "��� �������������:         \t" << InformationCarrier::GetNameManufacturer() << std::endl;	//	��� �������������
	std::cout << "������:                    \t" << InformationCarrier::GetModel() << std::endl;				//	������
	std::cout << "����������:                \t" << InformationCarrier::GetCount() << std::endl;				//	����������
	std::cout << "�������� ������:           \t" << RecordingSpeed << "x" << std::endl;
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