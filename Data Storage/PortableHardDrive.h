#pragma once

#include<iostream>
#include<fstream>
#include "InformationCarrier.h"

class PortableHardDrive : public InformationCarrier
{
	unsigned int SpindleSpeed;	//	скорость вращения шпинделя
public:
	PortableHardDrive();
	virtual ~PortableHardDrive();

	virtual void Print() const;
	virtual void Loading(std::ifstream& in);
	virtual void Save(std::ofstream &out) const;

	void SetSpindleSpeed(const unsigned int);
	unsigned int GetSpindleSpeed() const;
};

