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

	void ExitProgram();					//	Выход из программы
	void ShowMedia();						//	Показ носителей информации
	void AddingMedia();					//	Добавление носителя информации
	void RemovingMedia();					//	Удаление носителя информации
	void ModificationOfDataStorageMedia();//	Модификация данных носителя информации
	void SearchMediaForGivenCcriterion();	//	Поиск носителя информации по заданному критерию
	void DownloadListMedia();				//	Загрузка списка носителей информации
	void SaveLlistOfMedia();				//	Сохранение списка носителей информации

	void S_ByNameManufacturer();			//	Поиск по имени производителя
	void S_ByModels();					//	Поиск по модели
	void S_ByContainerCarrier();			//	Поиск по ёмкости носителя
	void S_ByRecordingSpeedDVD_ROM();		//	Поиск по скорости записи DVD ROM
	void S_BySpindleSpeed();				//	Поиск по скорости вращения шпинделя
	void S_BySpeedUSB();					//	Поиск по скорости USB
	void S_ByNumber();					//	Поиск по номеру

	void AddDVD_ROM();					// Добавить DVD ROM
	void AddPortableHardDrive();			// Добавить Portable Hard Drive
	void AddUSBFlashDrive();				// Добавить USB Flash Drive

	bool ConfirmInput();								//	Подтверждение ввода

	void ChangeNameOfManufacturer();		//	Изменить именя производителя
	void ChangeModel();					//	Изменить модель
	void ChangeCapacityOfMedia();			//	Изменить ёмкость носителя
	void ChangeNumber();					//	Изменить количество

	void ChangeByRecordingSpeedDVD_ROM();	//	Изменить скорость записи DVD ROM
	void ChangeRotationSpeedOfSpindle();	//	Изменить скорость вращения шпинделя
	void ChangeSpeedUSB();				//	Изменить скорость USB
};

