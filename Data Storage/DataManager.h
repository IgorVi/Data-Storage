#pragma once

#include<vector>

#include"InformationCarrier.h"
#include"DvdRom.h"
#include"PortableHardDrive.h"
#include"USBFlashDrive.h"

class DataManager
{
	std::vector<InformationCarrier*> vec;
public:
	//DataManager();
	~DataManager();

	unsigned int Add(const char* Denomination);				//	добавлене
	void RemovalByNumber(const unsigned int);				//	удалени€(по номеру)

	bool ChangeNameManufacturer(unsigned const int i, const char*);				//	изменить (по номеру) им€ производител€
	bool ChangeModel(unsigned const int i, const char*);						//	изменить (по номеру) модель
	bool ChangeContainerCarrier(unsigned const int i, unsigned const int);		//	изменить (по номеру) Ємкость носител€
	bool ChangeCount(unsigned const int  i, unsigned const int);				//	изменить (по номеру) количество
	bool ChangeRecordingSpeed(unsigned const int i, unsigned const int);		//	изменить (по номеру) скорость записи DVD ROM
	bool ChangeSpindleSpeed(unsigned const int i, unsigned const int);			//	изменить (по номеру) скорость вращени€ шпиндел€	PortableHardDrive
	bool ChangeSpeedUSB(unsigned const int i, unsigned const int);				//	изменить (по номеру) скорость USB	USBFlashDrive

	int SearchNameManufacturer(const char* s) const;		//	поиск по имени производител€
	int SearchModel(const char* s) const;					//	поиск по модели
	int SearchContainerCarrier(const int) const;			//	поиск по Ємкости носител€
	int SearchRecordingSpeedDVD_ROM(const int) const;		//	поиск по скорости записи DVD ROM
	int SearchSpindleSpeed(const int) const;				//	поиск по скорости вращени€ шпиндел€
	int SearchSpeedUSB(const int) const;					//	поиск по скорости USB

	bool Print(unsigned const int i) const;					//	ѕечать по индексу
	void Print() const;										//	ѕечать
	void Loading(const char* = "DataStore.txt");			//	«агрузка
	void Save(const char* = "DataStore.txt") const;			//	—охранение

	const char* GetType(const int);
};

