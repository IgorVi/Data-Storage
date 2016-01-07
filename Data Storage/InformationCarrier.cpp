
#include "InformationCarrier.h"

InformationCarrier::InformationCarrier() :
ContainerCarrier(0),
NameManufacturer("Unknown"),
Model("Unknown"),
Denomination("Unknown"),
Count(0)
{
}


InformationCarrier::~InformationCarrier(){
}

void InformationCarrier::Print() const {
	std::cout << "Наименование:              \t" << Denomination << std::endl;		//	наименование
	std::cout << "Имя производителя:         \t" << NameManufacturer << std::endl;	//	имя производителя
	std::cout << "Модель:                    \t" << Model << std::endl;				//	модель
	std::cout << "Ёмкость носителя:          \t" << ContainerCarrier << " GB" << std::endl;	//	ёмкость носителя
	std::cout << "Количество:                \t" << Count << std::endl;				//	количество
}

void InformationCarrier::Loading(std::ifstream& in) {

	char string[MAX_LENGTH] = {};

	// Считывание данных из файла в переменные.

	//	in.getline(string, MAX_LENGTH, '\n');
	//	Denomination = string;

	in.getline(string, MAX_LENGTH, '\n');
	NameManufacturer = string;

	in.getline(string, MAX_LENGTH, '\n');
	Model = string;

	in >> ContainerCarrier;
	in.get();

	in >> Count;
	in.get();
}

void InformationCarrier::Save(std::ofstream &out) const{

	out << Denomination.c_str() << '\n' << NameManufacturer.c_str() << '\n' << Model.c_str() << '\n';

	out << ContainerCarrier << '\n' << Count << '\n';
}

void InformationCarrier::SetNameManufacturer(const char* s){
	NameManufacturer = s;
}

void InformationCarrier::SetModel(const char* s){
	Model = s;
}

void InformationCarrier::SetDenomination(const char* s){
	Denomination = s;
}

void InformationCarrier::SetContainerCarrier(const unsigned int n){
	ContainerCarrier = n;
}

void InformationCarrier::SetCount(const unsigned int n){
	Count = n;
}

const char* InformationCarrier::GetNameManufacturer() const{
	return NameManufacturer.c_str();
}

const char* InformationCarrier::GetModel() const{
	return Model.c_str();
}

const char* InformationCarrier::GetDenomination() const{
	return Denomination.c_str();
}

unsigned int InformationCarrier::GetContainerCarrier() const{
	return ContainerCarrier;
}

unsigned int InformationCarrier::GetCount() const{
	return Count;
}