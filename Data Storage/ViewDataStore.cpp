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
			{ "����� ��������� ����������", &ViewDataStore::ShowMedia },
			{ "���������� �������� ����������", &ViewDataStore::AddingMedia },
			{ "�������� �������� ����������", &ViewDataStore::RemovingMedia },
			{ "����������� ������ �������� ����������", &ViewDataStore::ModificationOfDataStorageMedia },
//			{ "����� �������� ���������� �� ��������� ��������", &ViewDataStore::SearchMediaForGivenCcriterion },
			{ "�������� ������ ��������� ����������", &ViewDataStore::DownloadListMedia },
			{ "���������� ������ ��������� ����������", &ViewDataStore::SaveLlistOfMedia },
			{ "����� �� ���������", &ViewDataStore::ExitProgram }
	};

	MyMenu = new Menu<ViewDataStore>(sizeof(MyList) / sizeof(MyList[0]), MyList, this);
	MyMenu->MenuShow();
}

void ViewDataStore::ExitProgram(){
	system("cls");

	std::cout << "����� �� ��������?" << std::endl;
	if (ConfirmInput())								//	������������� �����
		MyMenu->SetExit(true);
}

void ViewDataStore::ShowMedia(){	//	����� ��������� ����������
	system("cls");

	std::cout << "����� ��������� ����������\n" << std::endl;
	MyDataManager->Print();

	_getch();
	system("cls");
}

void ViewDataStore::AddingMedia(){	//	���������� �������� ����������
	system("cls");

	std::cout << "���������� �������� ����������\n" << std::endl;

	static menu_item<ViewDataStore> AddList[] {
			{ "�������� DVD ROM", &ViewDataStore::AddDVD_ROM },
			{ "�������� Portable Hard Drive", &ViewDataStore::AddPortableHardDrive },
			{ "�������� USB Flash Drive", &ViewDataStore::AddUSBFlashDrive }
	};

	AddMenu = new Menu<ViewDataStore>(sizeof(AddList) / sizeof(AddList[0]), AddList, this, { 0, 3 });

	AddMenu->MenuShow();

	delete AddMenu;
	
	system("cls");
}

void ViewDataStore::RemovingMedia(){	//	�������� �������� ����������
	SearchMediaForGivenCcriterion();

	if (!MyDataManager->Print(index)){
		std::cout << "������ �������� ����� �������� ����������" << std::endl;
		_getch();
	}
	else{
		if (ConfirmInput())								//	������������� �����
			MyDataManager->RemovalByNumber(index);
	}
	index = -1;

	system("cls");
}

void ViewDataStore::ModificationOfDataStorageMedia(){	//	����������� ������ �������� ����������
	SearchMediaForGivenCcriterion();

	if (!MyDataManager->Print(index))
		std::cout << "������ �������� ����� �������� ����������" << std::endl;
	else{

		std::cout << "\n����������� ������ �������� ����������" << std::endl;
		if (!strcmp(MyDataManager->GetType(index), "DVD ROM")){
			static menu_item<ViewDataStore> ChangeListDVD_ROM[] {
					{ "�������� ����� �������������", &ViewDataStore::ChangeNameOfManufacturer },
					{ "�������� ������", &ViewDataStore::ChangeModel },
					{ "�������� �������� ������ DVD ROM", &ViewDataStore::ChangeByRecordingSpeedDVD_ROM },
					{ "�������� ����������", &ViewDataStore::ChangeNumber }
			};

			C_Menu = new Menu<ViewDataStore>(sizeof(ChangeListDVD_ROM) / sizeof(ChangeListDVD_ROM[0]), ChangeListDVD_ROM, this, { 0, 9 });

			C_Menu->MenuShow();

			delete C_Menu;
		}
		else if (!strcmp(MyDataManager->GetType(index), "Portable Hard Drive")){
			static menu_item<ViewDataStore> ChangeListPortableHardDrive[] {
					{ "�������� ����� �������������", &ViewDataStore::ChangeNameOfManufacturer },
					{ "�������� ������", &ViewDataStore::ChangeModel },
					{ "�������� ������� ��������", &ViewDataStore::ChangeCapacityOfMedia },
					{ "�������� �������� �������� ��������", &ViewDataStore::ChangeRotationSpeedOfSpindle },
					{ "�������� ����������", &ViewDataStore::ChangeNumber }
			};

			C_Menu = new Menu<ViewDataStore>(sizeof(ChangeListPortableHardDrive) / sizeof(ChangeListPortableHardDrive[0]), ChangeListPortableHardDrive, this, { 0, 9 });

			C_Menu->MenuShow();

			delete C_Menu;
		}
		else if (!strcmp(MyDataManager->GetType(index), "USB Flash Drive")){
			static menu_item<ViewDataStore> ChangeListUSBFlashDrive[] {
					{ "�������� ����� �������������", &ViewDataStore::ChangeNameOfManufacturer },
					{ "�������� ������", &ViewDataStore::ChangeModel },
					{ "�������� ������� ��������", &ViewDataStore::ChangeCapacityOfMedia },
					{ "�������� ����������", &ViewDataStore::ChangeNumber },
					{ "�������� �������� USB", &ViewDataStore::ChangeSpeedUSB }
			};

			C_Menu = new Menu<ViewDataStore>(sizeof(ChangeListUSBFlashDrive) / sizeof(ChangeListUSBFlashDrive[0]), ChangeListUSBFlashDrive, this, { 0, 9 });

			C_Menu->MenuShow();

			delete C_Menu;
		}
	}

	index = -1;
	system("cls");
}

void ViewDataStore::SearchMediaForGivenCcriterion(){	//	����� �������� ���������� �� ��������� ��������
	system("cls");

	std::cout << "����� �������� ���������� �� ��������� ��������\n" << std::endl;

	static menu_item<ViewDataStore> SearchList[] {
			{ "����� �� ����� �������������", &ViewDataStore::S_ByNameManufacturer },
			{ "����� �� ������", &ViewDataStore::S_ByModels },
			{ "����� �� ������� ��������", &ViewDataStore::S_ByContainerCarrier },
			{ "����� �� �������� ������ DVD ROM", &ViewDataStore::S_ByRecordingSpeedDVD_ROM },
			{ "����� �� �������� �������� ��������", &ViewDataStore::S_BySpindleSpeed },
			{ "����� �� �������� USB", &ViewDataStore::S_BySpeedUSB },
			{ "����� �� ������", &ViewDataStore::S_ByNumber }
	};

	SearchMenu = new Menu<ViewDataStore>(sizeof(SearchList) / sizeof(SearchList[0]), SearchList, this, { 0, 3 });

	SearchMenu->MenuShow();

	delete SearchMenu;

	system("cls");
}

void ViewDataStore::DownloadListMedia(){	//	�������� ������ ��������� ����������
	system("cls");

	std::cout << "�������� ������ ��������� ����������\n" << std::endl;
	std::cout << "������� ��� �����: ";
	char path[MAX_LENGTH];
	std::cin.getline(path, MAX_LENGTH);

	std::ifstream in;
	in.open(path, std::ios::_Nocreate);
	// ���� ���� ������� �������.
	if (in){
		in.close();
		MyDataManager->Loading(path);
	}
	else{
		std::cout << "���� � ����� ������ �� ����������" << std::endl;
		_getch();
	}

	system("cls");
}

void ViewDataStore::SaveLlistOfMedia(){	//	���������� ������ ��������� ��������������������
	system("cls");

	std::cout << "���������� ������ ��������� ��������������������\n" << std::endl;
	std::cout << "������� ��� �����: ";
	char path[MAX_LENGTH];
	std::cin.getline(path, MAX_LENGTH);

	MyDataManager->Save(path);

	system("cls");
}

void ViewDataStore::S_ByNameManufacturer(){			//	����� �� ����� �������������
	system("cls");

	std::cout << "����� �� ����� �������������\n" << std::endl;
	std::cout << "������� ��� �������������: ";
	char sSearch[MAX_LENGTH];
	std::cin.getline(sSearch, MAX_LENGTH);

	if ((index = MyDataManager->SearchNameManufacturer(sSearch)) == -1){
		std::cout << "�� �������� �������� ������ ���������.\n" << std::endl;
		_getch();
	}
	else
		SearchMenu->SetExit(true);

	system("cls");
}

void ViewDataStore::S_ByModels(){						//	����� �� ������
	system("cls");

	std::cout << "����� �� ������\n" << std::endl;
	std::cout << "������� ��� ������: ";
	char sSearch[MAX_LENGTH];
	std::cin.getline(sSearch, MAX_LENGTH);

	if ((index = MyDataManager->SearchModel(sSearch)) == -1){
		std::cout << "�� �������� �������� ������ ���������.\n" << std::endl;
		_getch();
	}
	else
		SearchMenu->SetExit(true);

	system("cls");
}

void ViewDataStore::S_ByContainerCarrier(){			//	����� �� ������� ��������
	system("cls");

	std::cout << "����� �� ������� ��������\n" << std::endl;
	std::cout << "������� ������� ��������: ";
	int nSearch = 0;
	std::cin >> nSearch;
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());

	if ((index = MyDataManager->SearchContainerCarrier(nSearch)) == -1){
		std::cout << "�� �������� �������� ������ ���������.\n" << std::endl;
		_getch();
	}
	else
		SearchMenu->SetExit(true);

	system("cls");
}

void ViewDataStore::S_ByRecordingSpeedDVD_ROM(){		//	����� �� �������� ������ DVD ROM
	system("cls");

	std::cout << "����� �� �������� ������ DVD ROM\n" << std::endl;
	std::cout << "������� �������� ������ DVD ROM: ";
	int nSearch = 0;
	std::cin >> nSearch;
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());

	if ((index = MyDataManager->SearchRecordingSpeedDVD_ROM(nSearch)) == -1){
		std::cout << "�� �������� �������� ������ ���������.\n" << std::endl;
		_getch();
	}
	else
		SearchMenu->SetExit(true);

	system("cls");
}

void ViewDataStore::S_BySpindleSpeed(){				//	����� �� �������� �������� ��������
	system("cls");

	std::cout << "����� �� �������� �������� ��������\n" << std::endl;
	std::cout << "������� �������� �������� ��������: ";
	int nSearch = 0;
	std::cin >> nSearch;
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());

	if ((index = MyDataManager->SearchSpindleSpeed(nSearch)) == -1){
		std::cout << "�� �������� �������� ������ ���������.\n" << std::endl;
		_getch();
	}
	else
		SearchMenu->SetExit(true);

	system("cls");
}

void ViewDataStore::S_BySpeedUSB(){					//	����� �� �������� USB
	system("cls");

	std::cout << "����� �� �������� USB\n" << std::endl;
	std::cout << "������� �������� USB: ";
	int nSearch = 0;
	std::cin >> nSearch;
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());

	if ((index = MyDataManager->SearchSpeedUSB(nSearch)) == -1){
		std::cout << "�� �������� �������� ������ ���������.\n" << std::endl;
		_getch();
	}
	else
		SearchMenu->SetExit(true);

	system("cls");
}

void ViewDataStore::S_ByNumber(){						//	 	����� �� ������
	system("cls");

	std::cout << "����� �� ������\n" << std::endl;
	std::cout << "������� ����� �������� ����������: ";
	int nSearch = 0;

	std::cin >> nSearch;
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());

	index = --nSearch;
	
	SearchMenu->SetExit(true);

	system("cls");
}


bool ViewDataStore::ConfirmInput(){								//	������������� �����
	std::cout << "\n��� ������������� ������� ������� Enter" << std::endl;
	std::cout << "��� ������ ������� ������� Esc" << std::endl;

	int key;
	do{
		key = _getch();
	} while (key != Menu<ViewDataStore>::ESC && key != Menu<ViewDataStore>::ENTER);

	return key == Menu<ViewDataStore>::ENTER;
}

void ViewDataStore::AddDVD_ROM(){ // �������� DVD ROM
	system("cls");

	std::cout << "�������� DVD ROM\n" << std::endl;
	int i = MyDataManager->Add("DVD ROM");

	std::cout << "������� ��� �������������: ";
	char buf[MAX_LENGTH];
	std::cin.getline(buf, MAX_LENGTH);
	MyDataManager->ChangeNameManufacturer(i, buf);


	std::cout << "������� ��� ������: ";
	std::cin.getline(buf, MAX_LENGTH);
	MyDataManager->ChangeModel(i, buf);

	int tmp = 0;
	std::cout << "������� ����������: ";
	std::cin >> tmp;
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	MyDataManager->ChangeCount(i, tmp);

	std::cout << "������� �������� ������ DVD ROM: ";
	std::cin >> tmp;
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	MyDataManager->ChangeRecordingSpeed(i, tmp);

	AddMenu->SetExit(true);

	system("cls");
}

void ViewDataStore::AddPortableHardDrive(){ // �������� Portable Hard Drive
	system("cls");

	std::cout << "�������� Portable Hard Drive\n" << std::endl;
	int i = MyDataManager->Add("Portable Hard Drive");

	std::cout << "������� ��� �������������: ";
	char buf[MAX_LENGTH];
	std::cin.getline(buf, MAX_LENGTH);
	MyDataManager->ChangeNameManufacturer(i, buf);


	std::cout << "������� ��� ������: ";
	std::cin.getline(buf, MAX_LENGTH);
	MyDataManager->ChangeModel(i, buf);

	std::cout << "������� ������� ��������: ";
	int tmp = 0;
	std::cin >> tmp;
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	MyDataManager->ChangeContainerCarrier(i, tmp);

	std::cout << "������� ����������: ";
	std::cin >> tmp;
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	MyDataManager->ChangeCount(i, tmp);

	std::cout << "������� �������� ��������	Portable Hard Drive: ";
	std::cin >> tmp;
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	MyDataManager->ChangeSpindleSpeed(i, tmp);

	AddMenu->SetExit(true);

	system("cls");
}

void ViewDataStore::AddUSBFlashDrive(){ // �������� USB Flash Drive
	system("cls");

	std::cout << "�������� USB Flash Drive\n" << std::endl;
	int i = MyDataManager->Add("USB Flash Drive");

	std::cout << "������� ��� �������������: ";
	char buf[MAX_LENGTH];
	std::cin.getline(buf, MAX_LENGTH);
	MyDataManager->ChangeNameManufacturer(i, buf);


	std::cout << "������� ��� ������: ";
	std::cin.getline(buf, MAX_LENGTH);
	MyDataManager->ChangeModel(i, buf);

	std::cout << "������� ������� ��������: ";
	int tmp = 0;
	std::cin >> tmp;
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	MyDataManager->ChangeContainerCarrier(i, tmp);

	std::cout << "������� ����������: ";
	std::cin >> tmp;
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	MyDataManager->ChangeCount(i, tmp);

	std::cout << "������� �������� USB	USBFlashDrive: ";
	std::cin >> tmp;
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	MyDataManager->ChangeSpeedUSB(i, tmp);

	AddMenu->SetExit(true);

	system("cls");
}


void ViewDataStore::ChangeNameOfManufacturer(){		//	�������� ����� �������������
	system("cls");

	std::cout << "������� ��� �������������: ";
	char buf[MAX_LENGTH];
	std::cin.getline(buf, MAX_LENGTH);
	MyDataManager->ChangeNameManufacturer(index, buf);

	C_Menu->SetExit(true);
}

void ViewDataStore::ChangeModel(){					//	�������� ������
	system("cls");

	char buf[MAX_LENGTH];
	std::cout << "������� ��� ������: ";
	std::cin.getline(buf, MAX_LENGTH);
	MyDataManager->ChangeModel(index, buf);

	C_Menu->SetExit(true);
}

void ViewDataStore::ChangeCapacityOfMedia(){			//	�������� ������� ��������
	system("cls");

	std::cout << "������� ������� ��������: ";
	int tmp = 0;
	std::cin >> tmp;
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	MyDataManager->ChangeContainerCarrier(index, tmp);

	C_Menu->SetExit(true);
}


void ViewDataStore::ChangeNumber(){					//	�������� ����������
	system("cls");

	int tmp = 0;
	std::cout << "������� ����������: ";
	std::cin >> tmp;
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	MyDataManager->ChangeCount(index, tmp);

	C_Menu->SetExit(true);
}

void ViewDataStore::ChangeByRecordingSpeedDVD_ROM(){	//	�������� �������� ������ DVD ROM
	system("cls");

	int tmp = 0;
	std::cout << "������� �������� ������ DVD ROM: ";
	std::cin >> tmp;
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	MyDataManager->ChangeRecordingSpeed(index, tmp);

	C_Menu->SetExit(true);
}

void ViewDataStore::ChangeRotationSpeedOfSpindle(){	//	�������� �������� �������� ��������
	system("cls");

	int tmp = 0;
	std::cout << "������� �������� �������� ��������: ";
	std::cin >> tmp;
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	MyDataManager->ChangeSpindleSpeed(index, tmp);

	C_Menu->SetExit(true);
}

void ViewDataStore::ChangeSpeedUSB(){				//	�������� �������� USB
	system("cls");

	int tmp = 0;
	std::cout << "������� �������� USB: ";
	std::cin >> tmp;
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	MyDataManager->ChangeSpeedUSB(index, tmp);

	C_Menu->SetExit(true);
}