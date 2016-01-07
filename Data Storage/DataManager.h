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

	unsigned int Add(const char* Denomination);				//	���������
	void RemovalByNumber(const unsigned int);				//	��������(�� ������)

	bool ChangeNameManufacturer(unsigned const int i, const char*);				//	�������� (�� ������) ��� �������������
	bool ChangeModel(unsigned const int i, const char*);						//	�������� (�� ������) ������
	bool ChangeContainerCarrier(unsigned const int i, unsigned const int);		//	�������� (�� ������) ������� ��������
	bool ChangeCount(unsigned const int  i, unsigned const int);				//	�������� (�� ������) ����������
	bool ChangeRecordingSpeed(unsigned const int i, unsigned const int);		//	�������� (�� ������) �������� ������ DVD ROM
	bool ChangeSpindleSpeed(unsigned const int i, unsigned const int);			//	�������� (�� ������) �������� �������� ��������	PortableHardDrive
	bool ChangeSpeedUSB(unsigned const int i, unsigned const int);				//	�������� (�� ������) �������� USB	USBFlashDrive

	int SearchNameManufacturer(const char* s) const;		//	����� �� ����� �������������
	int SearchModel(const char* s) const;					//	����� �� ������
	int SearchContainerCarrier(const int) const;			//	����� �� ������� ��������
	int SearchRecordingSpeedDVD_ROM(const int) const;		//	����� �� �������� ������ DVD ROM
	int SearchSpindleSpeed(const int) const;				//	����� �� �������� �������� ��������
	int SearchSpeedUSB(const int) const;					//	����� �� �������� USB

	bool Print(unsigned const int i) const;					//	������ �� �������
	void Print() const;										//	������
	void Loading(const char* = "DataStore.txt");			//	��������
	void Save(const char* = "DataStore.txt") const;			//	����������

	const char* GetType(const int);
};

