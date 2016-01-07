#pragma once

#include<iostream>
#include<fstream>
#include "InformationCarrier.h"

class USBFlashDrive : public InformationCarrier
{
	unsigned int SpeedUSB;	//	скорость USB
public:
	USBFlashDrive();
	virtual ~USBFlashDrive();

	virtual void Print() const;
	virtual void Loading(std::ifstream& in);
	virtual void Save(std::ofstream &out) const;

	void SetUSBFlashDrive(const unsigned int n);
	unsigned int GetUSBFlashDrive() const;
};

