
#include<iostream>

#include "DataManager.h"


DataManager::~DataManager(){
	for (unsigned int i = 0U; i < vec.size(); ++i)
		delete vec[i];
}

void DataManager::Print() const{
	for (unsigned int i = 0U; i < vec.size(); ++i){
		std::cout << std::endl << i + 1 << std::endl;
		vec[i]->Print();
		std::cout << std::endl;
	}
}

void DataManager::Loading(const char* path){
	std::ifstream in;
	in.open(path, std::ios::in);

	for (unsigned int i = 0U; in; ++i){
		char buf[MAX_LENGTH] = "";

		in.getline(buf, MAX_LENGTH, '\n');

		if (!strcmp(buf, "DVD ROM")){
			InformationCarrier * tmp = new DvdRom;
			tmp->Loading(in);
			tmp->SetDenomination(buf);
			vec.push_back(tmp);
		}
		else if (!strcmp(buf, "Portable Hard Drive")){
			InformationCarrier* tmp = new PortableHardDrive;
			tmp->Loading(in);
			tmp->SetDenomination(buf);
			vec.push_back(tmp);
		}
		else if (!strcmp(buf, "USB Flash Drive")){
			InformationCarrier* tmp = new USBFlashDrive;
			tmp->Loading(in);
			tmp->SetDenomination(buf);
			vec.push_back(tmp);
		}
	}
	in.close();
}

void DataManager::Save(const char* path) const{
	std::ofstream out;
	out.open(path, std::ios::trunc | std::ios::out);

	for (unsigned int i = 0U; i < vec.size(); ++i)
		vec[i]->Save(out);

	out.close();
}

void DataManager::RemovalByNumber(const unsigned int i){
	if (i < vec.size()){
		delete vec[i];
		vec.erase(vec.begin() + i);
	}
}

int DataManager::SearchNameManufacturer(const char* s) const {	//	поиск по имени производителя
	for (unsigned int i = 0; i < vec.size(); ++i)
		if (!strcmp(vec[i]->GetNameManufacturer(), s))
			return i;

	return -1;
}

int DataManager::SearchModel(const char* s) const {	//	поиск по модели
	for (unsigned int i = 0; i < vec.size(); ++i)
		if (!strcmp(vec[i]->GetModel(), s))
			return i;

	return -1;
}

int DataManager::SearchContainerCarrier(const int n) const {	//	поиск по ёмкости носителя
	for (unsigned int i = 0; i < vec.size(); ++i)
		if (vec[i]->GetContainerCarrier() == n)
			return i;

	return -1;
}

int DataManager::SearchRecordingSpeedDVD_ROM(const int n) const {	//	поиск по скорости записи DVD ROM
	for (unsigned int i = 0; i < vec.size(); ++i)
		if (DvdRom * tmp = dynamic_cast<DvdRom*>(vec[i]))
			if (tmp->GetRecordingSpeed() == n)
				return i;

	return -1;
}

int DataManager::SearchSpindleSpeed(const int n) const {	//	поиск по скорости вращения шпинделя
	for (unsigned int i = 0; i < vec.size(); ++i)
		if (PortableHardDrive * tmp = dynamic_cast<PortableHardDrive*>(vec[i]))
			if (tmp->GetSpindleSpeed() == n)
				return i;

	return -1;
}

int DataManager::SearchSpeedUSB(const int n) const {	//	поиск по скорости USB
	for (unsigned int i = 0; i < vec.size(); ++i)
		if (USBFlashDrive * tmp = dynamic_cast<USBFlashDrive*>(vec[i]))
			if (tmp->GetUSBFlashDrive() == n)
				return i;

	return -1;
}

unsigned int DataManager::Add(const char* Denomination){	//	добавлене
	unsigned int index = -1;

	if (!strcmp("DVD ROM", Denomination)){
		InformationCarrier *tmp = new DvdRom;
		tmp->SetDenomination(Denomination);
		vec.push_back(tmp);
		index = vec.size() - 1;
	}
	else if (!strcmp("Portable Hard Drive", Denomination)){
		InformationCarrier* tmp = new PortableHardDrive;
		tmp->SetDenomination(Denomination);
		vec.push_back(tmp);
		index = vec.size() - 1;
	}
	else if (!strcmp("USB Flash Drive", Denomination)){
		InformationCarrier* tmp = new USBFlashDrive;
		tmp->SetDenomination(Denomination);
		vec.push_back(tmp);
		index = vec.size() - 1;
	}
	return index;
}


bool DataManager::ChangeNameManufacturer(unsigned const int i, const char* s){				//	изменить имя производителя
	if (i < vec.size()){
		vec[i]->SetNameManufacturer(s);
		return true;
	}
	return false;
}

bool DataManager::ChangeModel(unsigned const int i, const char* s){						//	изменить модель
	if (i < vec.size()){
		vec[i]->SetModel(s);
		return true;
	}
	return false;
}

bool DataManager::ChangeContainerCarrier(unsigned const int i, unsigned const int n){		//	изменить ёмкость носителя
	if (i < vec.size()){
		vec[i]->SetContainerCarrier(n);
		return true;
	}
	return false;
}

bool DataManager::ChangeCount(unsigned const int  i, unsigned const int n){				//	изменить количество
	if (i < vec.size()){
		vec[i]->SetCount(n);
		return true;
	}
	return false;
}

bool DataManager::ChangeRecordingSpeed(unsigned const int i, unsigned const int n){		//	изменить скорость записи DVD ROM
	if (i < vec.size()){
		if (DvdRom* tmp = dynamic_cast<DvdRom*>(vec[i])){
			tmp->SetRecordingSpeed(n);
			return true;
		}
	}
	return false;
}

bool DataManager::ChangeSpindleSpeed(unsigned const int i, unsigned const int n){			//	изменить скорость вращения шпинделя	PortableHardDrive
	if (i < vec.size()){
		if (PortableHardDrive* tmp = dynamic_cast<PortableHardDrive*>(vec[i])){
			tmp->SetSpindleSpeed(n);
			return true;
		}
	}
	return false;
}

bool DataManager::ChangeSpeedUSB(unsigned const int i, unsigned const int n){				//	изменить скорость USB	USBFlashDrive
	if (i < vec.size()){
		if (USBFlashDrive* tmp = dynamic_cast<USBFlashDrive*>(vec[i])){
			tmp->SetUSBFlashDrive(n);
			return true;
		}
	}
	return false;
}

bool DataManager::Print(unsigned const int i) const {							//	Печать по индексу
	if (i < vec.size()){
		vec[i]->Print();
		return true;
	}
	return false;
}


const char* DataManager::GetType(const int index){

	if (DvdRom * tmp = dynamic_cast<DvdRom*>(vec[index]))
		return "DVD ROM";

	if (PortableHardDrive * tmp = dynamic_cast<PortableHardDrive*>(vec[index]))
		return "Portable Hard Drive";
	
	if (USBFlashDrive * tmp = dynamic_cast<USBFlashDrive*>(vec[index]))
		return "USB Flash Drive";
}