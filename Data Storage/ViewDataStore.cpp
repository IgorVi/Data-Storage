#include<iostream>

#include "ViewDataStore.h"
#include "DataManager.h"
#include "Menu.h"

ViewDataStore::ViewDataStore() :
MyDataManager(nullptr),
SearchMenu(nullptr),
MyMenu(nullptr),
AddMenu(nullptr),
C_Menu(nullptr),
index(-1)
{
	MyDataManager = new DataManager;
	
	MyDataManager->Loading();
}

ViewDataStore::~ViewDataStore()
{
	MyDataManager->Save();

	delete MyMenu;

	delete MyDataManager;
}

void ViewDataStore::Start(){
	
	menu_item<ViewDataStore> MyList[] {
			{ "Показ носителей информации", &ViewDataStore::ShowMedia },
			{ "Добавление носителя информации", &ViewDataStore::AddingMedia },
			{ "Удаление носителя информации", &ViewDataStore::RemovingMedia },
			{ "Модификация данных носителя информации", &ViewDataStore::ModificationOfDataStorageMedia },
//			{ "Поиск носителя информации по заданному критерию", &ViewDataStore::SearchMediaForGivenCcriterion },
			{ "Загрузка списка носителей информации", &ViewDataStore::DownloadListMedia },
			{ "Сохранение списка носителей информации", &ViewDataStore::SaveLlistOfMedia },
			{ "Выход из программы", &ViewDataStore::ExitProgram }
	};

	MyMenu = new Menu<ViewDataStore>(sizeof(MyList) / sizeof(MyList[0]), MyList, this);
	MyMenu->MenuShow();
}

void ViewDataStore::ExitProgram(){
	system("cls");

	std::cout << "Выйти из програмы?" << std::endl;
	if (ConfirmInput())								//	Подтверждение ввода
		MyMenu->SetExit(true);
}

void ViewDataStore::ShowMedia(){	//	Показ носителей информации
	system("cls");

	std::cout << "Показ носителей информации\n" << std::endl;
	MyDataManager->Print();

	_getch();
	system("cls");
}

void ViewDataStore::AddingMedia(){	//	Добавление носителя информации
	system("cls");

	std::cout << "Добавление носителя информации\n" << std::endl;

	static menu_item<ViewDataStore> AddList[] {
			{ "Добавить DVD ROM", &ViewDataStore::AddDVD_ROM },
			{ "Добавить Portable Hard Drive", &ViewDataStore::AddPortableHardDrive },
			{ "Добавить USB Flash Drive", &ViewDataStore::AddUSBFlashDrive }
	};

	AddMenu = new Menu<ViewDataStore>(sizeof(AddList) / sizeof(AddList[0]), AddList, this, { 0, 3 });

	AddMenu->MenuShow();

	delete AddMenu;
	
	system("cls");
}

void ViewDataStore::RemovingMedia(){	//	Удаление носителя информации
	SearchMediaForGivenCcriterion();

	if (!MyDataManager->Print(index)){
		std::cout << "Ошибка неверный номер носителя информации" << std::endl;
		_getch();
	}
	else{
		if (ConfirmInput())								//	Подтверждение ввода
			MyDataManager->RemovalByNumber(index);
	}
	index = -1;

	system("cls");
}

void ViewDataStore::ModificationOfDataStorageMedia(){	//	Модификация данных носителя информации
	SearchMediaForGivenCcriterion();

	if (!MyDataManager->Print(index))
		std::cout << "Ошибка неверный номер носителя информации" << std::endl;
	else{

		std::cout << "\nМодификация данных носителя информации" << std::endl;
		if (!strcmp(MyDataManager->GetType(index), "DVD ROM")){
			static menu_item<ViewDataStore> ChangeListDVD_ROM[] {
					{ "Изменить именя производителя", &ViewDataStore::ChangeNameOfManufacturer },
					{ "Изменить модель", &ViewDataStore::ChangeModel },
					{ "Изменить скорость записи DVD ROM", &ViewDataStore::ChangeByRecordingSpeedDVD_ROM },
					{ "Изменить количество", &ViewDataStore::ChangeNumber }
			};

			C_Menu = new Menu<ViewDataStore>(sizeof(ChangeListDVD_ROM) / sizeof(ChangeListDVD_ROM[0]), ChangeListDVD_ROM, this, { 0, 9 });

			C_Menu->MenuShow();

			delete C_Menu;
		}
		else if (!strcmp(MyDataManager->GetType(index), "Portable Hard Drive")){
			static menu_item<ViewDataStore> ChangeListPortableHardDrive[] {
					{ "Изменить именя производителя", &ViewDataStore::ChangeNameOfManufacturer },
					{ "Изменить модель", &ViewDataStore::ChangeModel },
					{ "Изменить ёмкость носителя", &ViewDataStore::ChangeCapacityOfMedia },
					{ "Изменить скорость вращения шпинделя", &ViewDataStore::ChangeRotationSpeedOfSpindle },
					{ "Изменить количество", &ViewDataStore::ChangeNumber }
			};

			C_Menu = new Menu<ViewDataStore>(sizeof(ChangeListPortableHardDrive) / sizeof(ChangeListPortableHardDrive[0]), ChangeListPortableHardDrive, this, { 0, 9 });

			C_Menu->MenuShow();

			delete C_Menu;
		}
		else if (!strcmp(MyDataManager->GetType(index), "USB Flash Drive")){
			static menu_item<ViewDataStore> ChangeListUSBFlashDrive[] {
					{ "Изменить именя производителя", &ViewDataStore::ChangeNameOfManufacturer },
					{ "Изменить модель", &ViewDataStore::ChangeModel },
					{ "Изменить ёмкость носителя", &ViewDataStore::ChangeCapacityOfMedia },
					{ "Изменить количество", &ViewDataStore::ChangeNumber },
					{ "Изменить скорость USB", &ViewDataStore::ChangeSpeedUSB }
			};

			C_Menu = new Menu<ViewDataStore>(sizeof(ChangeListUSBFlashDrive) / sizeof(ChangeListUSBFlashDrive[0]), ChangeListUSBFlashDrive, this, { 0, 9 });

			C_Menu->MenuShow();

			delete C_Menu;
		}
	}

	index = -1;
	system("cls");
}

void ViewDataStore::SearchMediaForGivenCcriterion(){	//	Поиск носителя информации по заданному критерию
	system("cls");

	std::cout << "Поиск носителя информации по заданному критерию\n" << std::endl;

	static menu_item<ViewDataStore> SearchList[] {
			{ "Поиск по имени производителя", &ViewDataStore::S_ByNameManufacturer },
			{ "Поиск по модели", &ViewDataStore::S_ByModels },
			{ "Поиск по ёмкости носителя", &ViewDataStore::S_ByContainerCarrier },
			{ "Поиск по скорости записи DVD ROM", &ViewDataStore::S_ByRecordingSpeedDVD_ROM },
			{ "Поиск по скорости вращения шпинделя", &ViewDataStore::S_BySpindleSpeed },
			{ "Поиск по скорости USB", &ViewDataStore::S_BySpeedUSB },
			{ "Поиск по номеру", &ViewDataStore::S_ByNumber }
	};

	SearchMenu = new Menu<ViewDataStore>(sizeof(SearchList) / sizeof(SearchList[0]), SearchList, this, { 0, 3 });

	SearchMenu->MenuShow();

	delete SearchMenu;

	system("cls");
}

void ViewDataStore::DownloadListMedia(){	//	Загрузка списка носителей информации
	system("cls");

	std::cout << "Загрузка списка носителей информации\n" << std::endl;
	std::cout << "Введите имя файла: ";
	char path[MAX_LENGTH];
	std::cin.getline(path, MAX_LENGTH);

	std::ifstream in;
	in.open(path, std::ios::_Nocreate);
	// Если файл удалось открыть.
	if (in){
		in.close();
		MyDataManager->Loading(path);
	}
	else{
		std::cout << "Файл с таким именем не существует" << std::endl;
		_getch();
	}

	system("cls");
}

void ViewDataStore::SaveLlistOfMedia(){	//	Сохранение списка носителей информацииинформации
	system("cls");

	std::cout << "Сохранение списка носителей информацииинформации\n" << std::endl;
	std::cout << "Введите имя файла: ";
	char path[MAX_LENGTH];
	std::cin.getline(path, MAX_LENGTH);

	MyDataManager->Save(path);

	system("cls");
}

void ViewDataStore::S_ByNameManufacturer(){			//	Поиск по имени производителя
	system("cls");

	std::cout << "Поиск по имени производителя\n" << std::endl;
	std::cout << "Введите имя производителя: ";
	char sSearch[MAX_LENGTH];
	std::cin.getline(sSearch, MAX_LENGTH);

	if ((index = MyDataManager->SearchNameManufacturer(sSearch)) == -1){
		std::cout << "По заданому критерию ничево ненайдено.\n" << std::endl;
		_getch();
	}
	else
		SearchMenu->SetExit(true);

	system("cls");
}

void ViewDataStore::S_ByModels(){						//	Поиск по модели
	system("cls");

	std::cout << "Поиск по модели\n" << std::endl;
	std::cout << "Введите имя модели: ";
	char sSearch[MAX_LENGTH];
	std::cin.getline(sSearch, MAX_LENGTH);

	if ((index = MyDataManager->SearchModel(sSearch)) == -1){
		std::cout << "По заданому критерию ничево ненайдено.\n" << std::endl;
		_getch();
	}
	else
		SearchMenu->SetExit(true);

	system("cls");
}

void ViewDataStore::S_ByContainerCarrier(){			//	Поиск по ёмкости носителя
	system("cls");

	std::cout << "Поиск по ёмкости носителя\n" << std::endl;
	std::cout << "Введите ёмкость носителя: ";
	int nSearch = 0;
	std::cin >> nSearch;
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());

	if ((index = MyDataManager->SearchContainerCarrier(nSearch)) == -1){
		std::cout << "По заданому критерию ничево ненайдено.\n" << std::endl;
		_getch();
	}
	else
		SearchMenu->SetExit(true);

	system("cls");
}

void ViewDataStore::S_ByRecordingSpeedDVD_ROM(){		//	Поиск по скорости записи DVD ROM
	system("cls");

	std::cout << "Поиск по скорости записи DVD ROM\n" << std::endl;
	std::cout << "Введите скорость записи DVD ROM: ";
	int nSearch = 0;
	std::cin >> nSearch;
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());

	if ((index = MyDataManager->SearchRecordingSpeedDVD_ROM(nSearch)) == -1){
		std::cout << "По заданому критерию ничево ненайдено.\n" << std::endl;
		_getch();
	}
	else
		SearchMenu->SetExit(true);

	system("cls");
}

void ViewDataStore::S_BySpindleSpeed(){				//	Поиск по скорости вращения шпинделя
	system("cls");

	std::cout << "Поиск по скорости вращения шпинделя\n" << std::endl;
	std::cout << "Введите скорость вращения шпинделя: ";
	int nSearch = 0;
	std::cin >> nSearch;
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());

	if ((index = MyDataManager->SearchSpindleSpeed(nSearch)) == -1){
		std::cout << "По заданому критерию ничево ненайдено.\n" << std::endl;
		_getch();
	}
	else
		SearchMenu->SetExit(true);

	system("cls");
}

void ViewDataStore::S_BySpeedUSB(){					//	Поиск по скорости USB
	system("cls");

	std::cout << "Поиск по скорости USB\n" << std::endl;
	std::cout << "Введите скорость USB: ";
	int nSearch = 0;
	std::cin >> nSearch;
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());

	if ((index = MyDataManager->SearchSpeedUSB(nSearch)) == -1){
		std::cout << "По заданому критерию ничево ненайдено.\n" << std::endl;
		_getch();
	}
	else
		SearchMenu->SetExit(true);

	system("cls");
}

void ViewDataStore::S_ByNumber(){						//	 	Поиск по номеру
	system("cls");

	std::cout << "Поиск по номеру\n" << std::endl;
	std::cout << "Введите номер носителя информации: ";
	int nSearch = 0;

	std::cin >> nSearch;
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());

	index = --nSearch;
	
	SearchMenu->SetExit(true);

	system("cls");
}


bool ViewDataStore::ConfirmInput(){								//	Подтверждение ввода
	std::cout << "\nДля подтверждения нажмите клавишу Enter" << std::endl;
	std::cout << "Для отмены нажмите клавишу Esc" << std::endl;

	int key;
	do{
		key = _getch();
	} while (key != Menu<ViewDataStore>::ESC && key != Menu<ViewDataStore>::ENTER);

	return key == Menu<ViewDataStore>::ENTER;
}

void ViewDataStore::AddDVD_ROM(){ // Добавить DVD ROM
	system("cls");

	std::cout << "Добавить DVD ROM\n" << std::endl;
	int i = MyDataManager->Add("DVD ROM");

	std::cout << "Введите имя производителя: ";
	char buf[MAX_LENGTH];
	std::cin.getline(buf, MAX_LENGTH);
	MyDataManager->ChangeNameManufacturer(i, buf);


	std::cout << "Введите имя модели: ";
	std::cin.getline(buf, MAX_LENGTH);
	MyDataManager->ChangeModel(i, buf);

	int tmp = 0;
	std::cout << "Введите количество: ";
	std::cin >> tmp;
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	MyDataManager->ChangeCount(i, tmp);

	std::cout << "Введите скорость записи DVD ROM: ";
	std::cin >> tmp;
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	MyDataManager->ChangeRecordingSpeed(i, tmp);

	AddMenu->SetExit(true);

	system("cls");
}

void ViewDataStore::AddPortableHardDrive(){ // Добавить Portable Hard Drive
	system("cls");

	std::cout << "Добавить Portable Hard Drive\n" << std::endl;
	int i = MyDataManager->Add("Portable Hard Drive");

	std::cout << "Введите имя производителя: ";
	char buf[MAX_LENGTH];
	std::cin.getline(buf, MAX_LENGTH);
	MyDataManager->ChangeNameManufacturer(i, buf);


	std::cout << "Введите имя модели: ";
	std::cin.getline(buf, MAX_LENGTH);
	MyDataManager->ChangeModel(i, buf);

	std::cout << "Введите ёмкость носителя: ";
	int tmp = 0;
	std::cin >> tmp;
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	MyDataManager->ChangeContainerCarrier(i, tmp);

	std::cout << "Введите количество: ";
	std::cin >> tmp;
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	MyDataManager->ChangeCount(i, tmp);

	std::cout << "Введите вращения шпинделя	Portable Hard Drive: ";
	std::cin >> tmp;
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	MyDataManager->ChangeSpindleSpeed(i, tmp);

	AddMenu->SetExit(true);

	system("cls");
}

void ViewDataStore::AddUSBFlashDrive(){ // Добавить USB Flash Drive
	system("cls");

	std::cout << "Добавить USB Flash Drive\n" << std::endl;
	int i = MyDataManager->Add("USB Flash Drive");

	std::cout << "Введите имя производителя: ";
	char buf[MAX_LENGTH];
	std::cin.getline(buf, MAX_LENGTH);
	MyDataManager->ChangeNameManufacturer(i, buf);


	std::cout << "Введите имя модели: ";
	std::cin.getline(buf, MAX_LENGTH);
	MyDataManager->ChangeModel(i, buf);

	std::cout << "Введите ёмкость носителя: ";
	int tmp = 0;
	std::cin >> tmp;
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	MyDataManager->ChangeContainerCarrier(i, tmp);

	std::cout << "Введите количество: ";
	std::cin >> tmp;
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	MyDataManager->ChangeCount(i, tmp);

	std::cout << "Введите скорость USB	USBFlashDrive: ";
	std::cin >> tmp;
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	MyDataManager->ChangeSpeedUSB(i, tmp);

	AddMenu->SetExit(true);

	system("cls");
}


void ViewDataStore::ChangeNameOfManufacturer(){		//	Изменить именя производителя
	system("cls");

	std::cout << "Введите имя производителя: ";
	char buf[MAX_LENGTH];
	std::cin.getline(buf, MAX_LENGTH);
	MyDataManager->ChangeNameManufacturer(index, buf);

	C_Menu->SetExit(true);
}

void ViewDataStore::ChangeModel(){					//	Изменить модель
	system("cls");

	char buf[MAX_LENGTH];
	std::cout << "Введите имя модели: ";
	std::cin.getline(buf, MAX_LENGTH);
	MyDataManager->ChangeModel(index, buf);

	C_Menu->SetExit(true);
}

void ViewDataStore::ChangeCapacityOfMedia(){			//	Изменить ёмкость носителя
	system("cls");

	std::cout << "Введите ёмкость носителя: ";
	int tmp = 0;
	std::cin >> tmp;
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	MyDataManager->ChangeContainerCarrier(index, tmp);

	C_Menu->SetExit(true);
}


void ViewDataStore::ChangeNumber(){					//	Изменить количество
	system("cls");

	int tmp = 0;
	std::cout << "Введите количество: ";
	std::cin >> tmp;
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	MyDataManager->ChangeCount(index, tmp);

	C_Menu->SetExit(true);
}

void ViewDataStore::ChangeByRecordingSpeedDVD_ROM(){	//	Изменить скорость записи DVD ROM
	system("cls");

	int tmp = 0;
	std::cout << "Введите скорость записи DVD ROM: ";
	std::cin >> tmp;
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	MyDataManager->ChangeRecordingSpeed(index, tmp);

	C_Menu->SetExit(true);
}

void ViewDataStore::ChangeRotationSpeedOfSpindle(){	//	Изменить скорость вращения шпинделя
	system("cls");

	int tmp = 0;
	std::cout << "Введите скорость вращения шпинделя: ";
	std::cin >> tmp;
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	MyDataManager->ChangeSpindleSpeed(index, tmp);

	C_Menu->SetExit(true);
}

void ViewDataStore::ChangeSpeedUSB(){				//	Изменить скорость USB
	system("cls");

	int tmp = 0;
	std::cout << "Введите скорость USB: ";
	std::cin >> tmp;
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	MyDataManager->ChangeSpeedUSB(index, tmp);

	C_Menu->SetExit(true);
}