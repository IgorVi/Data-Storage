#pragma once

#include<iostream>
#include<fstream>
#include<string>

#define MAX_LENGTH 256

class InformationCarrier
{
	std::string Denomination;		//	������������
	std::string NameManufacturer;	//	��� �������������
	std::string Model;				//	������
	unsigned int ContainerCarrier;	//	������� ��������
	unsigned int Count;				//	����������
public:
	InformationCarrier();
	virtual ~InformationCarrier() = 0;
	virtual void Print() const;
	virtual void Save(std::ofstream &out) const;
	virtual void Loading(std::ifstream& in);

	void SetNameManufacturer(const char*);
	void SetModel(const char*);
	void SetDenomination(const char*);
	void SetContainerCarrier(const unsigned int);
	void SetCount(const unsigned int);

	const char* GetNameManufacturer() const;
	const char* GetModel() const;
	const char* GetDenomination() const;
	unsigned int GetContainerCarrier() const;
	unsigned int GetCount() const;
};

