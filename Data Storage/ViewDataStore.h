#pragma once

#include "DataManager.h"
#include "Menu.h"

class ViewDataStore
{
public:
	ViewDataStore();
	~ViewDataStore();
	void Start();
private:
	DataManager* MyDataManager;

	Menu<ViewDataStore>* MyMenu;
	Menu<ViewDataStore>* SearchMenu;
	Menu<ViewDataStore>* AddMenu;
	Menu<ViewDataStore>* C_Menu;

	unsigned int index;

	void ExitProgram();					//	����� �� ���������
	void ShowMedia();						//	����� ��������� ����������
	void AddingMedia();					//	���������� �������� ����������
	void RemovingMedia();					//	�������� �������� ����������
	void ModificationOfDataStorageMedia();//	����������� ������ �������� ����������
	void SearchMediaForGivenCcriterion();	//	����� �������� ���������� �� ��������� ��������
	void DownloadListMedia();				//	�������� ������ ��������� ����������
	void SaveLlistOfMedia();				//	���������� ������ ��������� ����������

	void S_ByNameManufacturer();			//	����� �� ����� �������������
	void S_ByModels();					//	����� �� ������
	void S_ByContainerCarrier();			//	����� �� ������� ��������
	void S_ByRecordingSpeedDVD_ROM();		//	����� �� �������� ������ DVD ROM
	void S_BySpindleSpeed();				//	����� �� �������� �������� ��������
	void S_BySpeedUSB();					//	����� �� �������� USB
	void S_ByNumber();					//	����� �� ������

	void AddDVD_ROM();					// �������� DVD ROM
	void AddPortableHardDrive();			// �������� Portable Hard Drive
	void AddUSBFlashDrive();				// �������� USB Flash Drive

	bool ConfirmInput();								//	������������� �����

	void ChangeNameOfManufacturer();		//	�������� ����� �������������
	void ChangeModel();					//	�������� ������
	void ChangeCapacityOfMedia();			//	�������� ������� ��������
	void ChangeNumber();					//	�������� ����������

	void ChangeByRecordingSpeedDVD_ROM();	//	�������� �������� ������ DVD ROM
	void ChangeRotationSpeedOfSpindle();	//	�������� �������� �������� ��������
	void ChangeSpeedUSB();				//	�������� �������� USB
};

