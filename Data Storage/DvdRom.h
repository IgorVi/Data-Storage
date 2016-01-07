#pragma once

#include<iostream>
#include<fstream>
#include "InformationCarrier.h"

class DvdRom : public InformationCarrier
{
	unsigned int RecordingSpeed;	//	скорость записи
public:
	DvdRom();
	virtual ~DvdRom();

	void Print() const;
	void Save(std::ofstream &out) const;
	void Loading(std::ifstream& in);

	void SetRecordingSpeed(const unsigned int);
	unsigned int GetRecordingSpeed() const;
};