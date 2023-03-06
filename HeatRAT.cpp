
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>


using namespace std;




void Help(string);

void Build();

void Preferences(string);

void Ports(string);

void Sessions(string);

void Choose(string, int);

HANDLE  hConsole;
int col = 9;
bool logoShow = true;
string space = "          ";
string command = "";
string line = "";
string something = "";
string curentUSER = "";

int main()
{
	system("cls");
	string logo = R"LOGO(....BBBBBB....BB.............BBBBBB.....BBB...............BBBBBBBBBBBBBBBBBBBB.............BBBBBB......BBB..............
....BBBBBB....BB.............BBBBB.......BB...............B.BBBBBB.BBBBBB.BBBB..............BBBBB.......BB..............
..............BB.....BBBBBBBBBBBB.........BBBBBB....BBBBB.....BB.....BB.....BB....BBBBB.....BBBB.........BBBBBB....BBBBB
..............BB.............BBB.....B.....BBBBB.....BBBB.....BB.....BB.....BB.............BBBB.....B....BBBBBB....BBBBB
..............BB.............BBB............BBBB.....BBBBBBBBBBBBBBBBBBBBBBBBB...........BBBBB............BBBBB....BBBBB
....BBBBBB....BB.....BBBBBBBBBB..............BBB.....BBBBBBBBBBBBBBBBBBBBBBBBB....BB.......BB..............BBBB....BBBBB
....BBBBB.....BB..............................BB.....BBBB.....BB.....BB.....BB....BBBB......................BBB....BBBBB
....BBBBBB....BB..................BBBBBBB.....BB.....BBBB.....BB.....BB.....BB....BBBBB..........BBBBBBB....BBB....BBBBB)LOGO";
	string comands_menu = "Modules\\Commands\\Menu.txt";
	string about = "Modules\\About\\about.txt";
	//string comands_port = "Modules\\Commands\\Ports.txt";
	//string comands_preferences = "Modules\\Commands\\Preferences.txt";
	//string comands_session = "Modules\\Commands\\Session.txt";
	//string comands_sessions = "Modules\\Commands\\Sessions.txt";
	string logs = "Modules\\Grabbed\\logs.txt";
	//string user = "Modules\\Grabbed\\users.txt";
	//string prefrences = "Modules\\Preferences\\ports.txt";
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	FlushConsoleInputBuffer(hConsole);
	SetConsoleTextAttribute(hConsole, col);
	HWND hWindowConsole = GetConsoleWindow();
	RECT r;
	GetWindowRect(hWindowConsole, &r);
	MoveWindow(hWindowConsole, r.left, r.top, 895, 500, TRUE);
	printf("\n\n\n\n\n\n\n\n\n\n%56sWelcome\n", space.c_str());
	printf("%55sYour name?\n", space.c_str());
	printf("%56s", space.c_str());
	col = 11;
	SetConsoleTextAttribute(hConsole, col);
	cin >> curentUSER;
	system("cls");


	while (true)
	{
		if (logoShow)
		{
			system("cls");
			col = 13;
			SetConsoleTextAttribute(hConsole, col);
			cout << logo<<endl;
			col = 9;
			SetConsoleTextAttribute(hConsole, col);
			printf("%40s-----------------------------------------\n",space.c_str());
			printf("%40s|                  Menu                 |\n", space.c_str());
			printf("%40s-----------------------------------------\n", space.c_str());
			printf("Hi %s!!!\n>>> !help ==for==> command list\n",curentUSER.c_str());
		}
		col = 6;
		SetConsoleTextAttribute(hConsole, col);
		printf(">>> ");
		col = 11;
		SetConsoleTextAttribute(hConsole, col);
		cin >> command;
		logoShow = false;
		if (command == "!help")
		{
			Help(comands_menu);
		}
		if (command == "!close")
		{
			abort();
		}
		if (command == "!about")
		{
			Help(about);
		}
		if (command == "!logs")
		{
			Help(logs);
		}
		if (command == "!build")
		{
			Build();
		}
		if (command == "!preferences") 
		{
			Preferences(logo);
		}
		if (command == "!ports")
		{
			Ports(logo);
		}
		if (command == "!sessions") 
		{
			Sessions(logo);
		}
		if (command == "!github")
		{
			cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			cout << "Creator (https://github.com/Nick-Vinesmoke)";
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			cout << "\n\n";
		}
		else if (command != "!help" && command != "!close" && command != "!about" && command != "!github" && command != "!logs" && command != "!build"&& command != "!preferences" && command != "!ports" && command != "!sessions")
		{
			cout << "\n\n";
			col = 4;
			SetConsoleTextAttribute(hConsole, col);
			printf("unknown command!!!");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			cout << "\n\n";
		}


	}
	
}

void Help(string path) 
{

	col = 8;
	SetConsoleTextAttribute(hConsole, col);
	cout << "\n\n";
	ifstream file(path);
	if (file.is_open()) 
	{
		while (getline(file, line))
		{
			cout << line << endl;
		}
	}
	else 
	{
		
		col = 4;
		SetConsoleTextAttribute(hConsole, col);
		printf("Fatal ERROR!!!");
	}
	file.close();
	line = "";
	col = 11;
	SetConsoleTextAttribute(hConsole, col);
	cout << "\n\n";
}


void Build()
{
	string ports = "Modules\\Preferences\\ports.txt";
	bool openPort = false;


	cout << "\n\n";


	col = 8;
	SetConsoleTextAttribute(hConsole, col);
	printf("Host: ");
	col = 11;
	SetConsoleTextAttribute(hConsole, col);
	cin >> something;
	col = 8;
	SetConsoleTextAttribute(hConsole, col);
	printf("Port: ");
	col = 11;
	SetConsoleTextAttribute(hConsole, col);
	cin >> something;
	ifstream file(ports);
	if (file.is_open())
	{
		while (getline(file, line))
		{
			if (line == something)
			{
				openPort = true;
			}
		}
	}
	else
	{

		col = 4;
		SetConsoleTextAttribute(hConsole, col);
		printf("Fatal ERROR!!!");
		col = 11;
		SetConsoleTextAttribute(hConsole, col);
	}
	file.close();
	line = "";
	if (openPort) 
	{
		col = 8;
		SetConsoleTextAttribute(hConsole, col);
		printf("size KayLogs: ");
		col = 11;
		SetConsoleTextAttribute(hConsole, col);
		cin >> something;
		col = 8;
		SetConsoleTextAttribute(hConsole, col);
		printf("Name: ");
		col = 11;
		SetConsoleTextAttribute(hConsole, col);
		cin >> something;
		col = 8;
		SetConsoleTextAttribute(hConsole, col);
		printf(".exe name: ");
		col = 11;
		SetConsoleTextAttribute(hConsole, col);
		cin >> something;
		col = 8;
		SetConsoleTextAttribute(hConsole, col);
		printf("hide? (y/n) ");
		col = 11;
		SetConsoleTextAttribute(hConsole, col);
		cin >> something;
		col = 8;
		cout << "\n";
		SetConsoleTextAttribute(hConsole, col);
		printf("building...\n");
		printf("[");
		for (int i = 0; i <= 60; i++) 
		{
			printf("=");
			Sleep(500*(i/10));
		}
		printf("]\n\n");
		printf("fixing some errors...\n");
		printf("[");
		for (int i = 0; i <= 60; i++)
		{
			printf("=");
			Sleep(500);
		}
		printf("]\n\n");
		col = 4;
		SetConsoleTextAttribute(hConsole, col);
		printf("can't fix ERROR ==> 745\n");
		col = 11;
		SetConsoleTextAttribute(hConsole, col);

	}
	else
	{

		col = 4;
		SetConsoleTextAttribute(hConsole, col);
		printf("port %s is not open!!!", something.c_str());
		col = 11;
		SetConsoleTextAttribute(hConsole, col);
	}


	cout << "\n\n";

}



void Preferences(string logo)
{
	logoShow = true;
	system("cls");
	string comands_preferences = "Modules\\Commands\\Preferences.txt";
	while (true)
	{
		if (logoShow)
		{
			col = 13;
			SetConsoleTextAttribute(hConsole, col);
			cout << logo << endl;
			col = 9;
			SetConsoleTextAttribute(hConsole, col);
			printf("%40s-----------------------------------------\n", space.c_str());
			printf("%40s|              Preferences              |\n", space.c_str());
			printf("%40s-----------------------------------------\n", space.c_str());
			printf("Hi %s!!!\n>>> !help ==for==> command list\n", curentUSER.c_str());
		}
		col = 6;
		SetConsoleTextAttribute(hConsole, col);
		printf(">>> ");
		col = 11;
		SetConsoleTextAttribute(hConsole, col);
		cin >> command;
		logoShow = false;
		if (command == "!help")
		{
			Help(comands_preferences);
		}
		if (command == "!menu")
		{
			system("cls");
			logoShow = true;
			break;
		}
		if (command == "!network")
		{
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			cout << "\n\n";
			printf("testing...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(100);
			}
			printf("]\n");
			srand(time(NULL));
			int speed = rand() % (100 - 10) + 10;
			printf("download ===> %d\n", speed);
			printf("upload ===> %d", speed + rand() % (20 - -3) + -3);
			cout << "\n\n";
		}
		if (command == "!reset") 
		{
			string logs = "Modules\\Grabbed\\logs.txt";
			string user = "Modules\\Grabbed\\users.txt";
			string prefrences = "Modules\\Preferences\\ports.txt";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			cout << "\n\n";
			printf("wait...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(5);
			}
			printf("]\n");
			ofstream newfile;          
			newfile.open(prefrences); 
			if (newfile.is_open())
			{
				col = 2;
				SetConsoleTextAttribute(hConsole, col);
				printf("done!!!\n");
			}
			else
			{

				col = 4;
				SetConsoleTextAttribute(hConsole, col);
				printf("Fatal ERROR!!!\n");
			}
			newfile.close();
			ofstream newUser;
			newUser.open(user);
			if (newUser.is_open())
			{
				col = 2;
				SetConsoleTextAttribute(hConsole, col);
				printf("done!!!\n");
			}
			else
			{

				col = 4;
				SetConsoleTextAttribute(hConsole, col);
				printf("Fatal ERROR!!!\n");
			}
			newUser.close();
			ofstream newLogs;
			newLogs.open(logs);
			if (newLogs.is_open())
			{
				newLogs << "EMPTY";
				col = 2;
				SetConsoleTextAttribute(hConsole, col);
				printf("done!!!\n");
			}
			else
			{

				col = 4;
				SetConsoleTextAttribute(hConsole, col);
				printf("Fatal ERROR!!!\n");
			}
			newLogs.close();
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("done!!!\n");
			col = 9;
			SetConsoleTextAttribute(hConsole, col);
			system("pause");
			system("cls");
			logoShow = true;
			break;
		}
		if (command == "!update") 
		{
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			cout << "\n\n";
			printf("checking...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(100);
			}
			printf("]\n");
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("latest version installed\n");
			col = 9;
			SetConsoleTextAttribute(hConsole, col);
			cout << "\n\n";
		}
		if (command == "!errors")
		{
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			cout << "\n\n";
			printf("checking...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(2);
			}
			printf("]\n");
			srand(time(NULL));
			int max = rand() % (8 - 0) + 0;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			for (int i = 0; i < max; i++)
			{

				printf("ERROR ==> %d\n", rand() % (999 - 111) + 111);
			}
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			cout << "\n\n";
		}
		if (command == "!experimentalMode") 
		{
			cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("Do you want to turn on experimental mode? (y/n) ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			cin >> something;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			if (something == "y") 
			{
				printf("starting...\n");
				printf("[");
				for (int i = 0; i <= 60; i++)
				{
					printf("=");
					Sleep(2);
				}
				printf("]\n");
				col = 2;
				SetConsoleTextAttribute(hConsole, col);
				printf("done!!!\n");
				col = 9;
				SetConsoleTextAttribute(hConsole, col);
				system("pause");
				system("cls");
				logoShow = true;
				break;
			}
			if (something == "n")
			{
				printf("finishing...\n");
				printf("[");
				for (int i = 0; i <= 60; i++)
				{
					printf("=");
					Sleep(2);
				}
				printf("]\n");
				col = 2;
				SetConsoleTextAttribute(hConsole, col);
				printf("done!!!\n");
				col = 11;
				SetConsoleTextAttribute(hConsole, col);
				system("pause");
				system("cls");
				logoShow = true;
				break;
			}
			else if (something != "n" && something != "y") 
			{
				col = 4;
				SetConsoleTextAttribute(hConsole, col);
				printf("ERROR ==> 832\n");
				col = 11;
				SetConsoleTextAttribute(hConsole, col);
			}
		}
		else if (command != "!experimentalMode" && command != "!errors" && command != "!reset" && command != "!update" && command != "!network" && command != "!help" && command != "!menu")
		{
			cout << "\n\n";
			col = 4;
			SetConsoleTextAttribute(hConsole, col);
			printf("unknown command!!!\n");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			cout << "\n\n";
		}
	}
	

}


void Ports(string logo) 
{
	logoShow = true;
	string port = "";
	string curentPorts = R"P( )P";
	system("cls");
	string comands_port = "Modules\\Commands\\Ports.txt";
	string prefrences = "Modules\\Preferences\\ports.txt";
	while (true)
	{
		if (logoShow)
		{
			col = 13;
			SetConsoleTextAttribute(hConsole, col);
			cout << logo << endl;
			col = 9;
			SetConsoleTextAttribute(hConsole, col);
			printf("%40s-----------------------------------------\n", space.c_str());
			printf("%40s|                 Ports                 |\n", space.c_str());
			printf("%40s-----------------------------------------\n", space.c_str());
			printf("Hi %s!!!\n>>> !help ==for==> command list\n", curentUSER.c_str());
		}
		col = 9;
		SetConsoleTextAttribute(hConsole, col);
		printf(">>> ");
		col = 11;
		SetConsoleTextAttribute(hConsole, col);
		cin >> command;
		logoShow = false;
		if (command == "!help")
		{
			Help(comands_port);
		}
		if (command == "!menu")
		{
			system("cls");
			logoShow = true;
			break;
		}
		if (command == "!open")
		{
			cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("port number: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			cin >> port;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("type (TPC/UDP/ALL): ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			cin >> something;
			if (something != "TPC" && something != "UDP" && something != "ALL")
			{
				col = 4;
				SetConsoleTextAttribute(hConsole, col);
				printf("ERROR ==> 320\n");
				col = 11;
				SetConsoleTextAttribute(hConsole, col);
			}
			else 
			{
				col = 8;
				SetConsoleTextAttribute(hConsole, col);
				printf("opening...\n");
				printf("[");
				for (int i = 0; i <= 60; i++)
				{
					printf("=");
					Sleep(2);
				}
				printf("]\n");
				if (stoi(port) >= 1025 && stoi(port) <= 5000)
				{
					ofstream file(prefrences, ios::app);
					if (file.is_open())
					{
						file << port << endl;
					}
					else
					{

						col = 4;
						SetConsoleTextAttribute(hConsole, col);
						printf("Fatal ERROR!!!\n");
					}
					file.close();
					col = 2;
					SetConsoleTextAttribute(hConsole, col);
					printf("port number %s is open\n", port.c_str());
				}
				else
				{
					col = 4;
					SetConsoleTextAttribute(hConsole, col);
					printf("port reserved\n");
				}
				
			}
			cout << "\n\n";
		}
		if (command == "!close") 
		{
			cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("port number: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			cin >> port;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("closing...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(2);
			}
			printf("]\n");
			ifstream file(prefrences);
			if (file.is_open())
			{
				while (getline(file, line))
				{
					if (stoi(line) != stoi(port))
					{
						curentPorts.insert(curentPorts.length() - 1, line + "\n");
					}
				}
			}
			else
			{

				col = 4;
				SetConsoleTextAttribute(hConsole, col);
				printf("Fatal ERROR!!!\n");
			}
			file.close();
			line = "";
			curentPorts.pop_back();
			ofstream newfile;          // поток для записи
			newfile.open(prefrences); // окрываем файл для записи
			if (newfile.is_open())
			{
				newfile << curentPorts;
				col = 2;
				SetConsoleTextAttribute(hConsole, col);
				printf("port number %s is closed\n", port.c_str());
			}
			else
			{

				col = 4;
				SetConsoleTextAttribute(hConsole, col);
				printf("Fatal ERROR!!!\n");
			}
			newfile.close();
			cout << "\n\n";
		}
		if (command == "!closeAll") 
		{
			cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("closing...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(2);
			}
			printf("]\n");
			ofstream newfile;          // поток для записи
			newfile.open(prefrences); // окрываем файл для записи
			if (newfile.is_open())
			{
				col = 2;
				SetConsoleTextAttribute(hConsole, col);
				printf("done!!!\n");
			}
			else
			{

				col = 4;
				SetConsoleTextAttribute(hConsole, col);
				printf("Fatal ERROR!!!\n");
			}
			newfile.close();
			cout << "\n\n";
		}
		if (command == "!ports") 
		{

			cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			ifstream file(prefrences);
			if (file.is_open())
			{
				while (getline(file, line))
				{
					printf("========================================================================================================================\n");
					printf("port number ==================> %s\n", line.c_str());
					printf("port status ==================> ");
					col = 2;
					SetConsoleTextAttribute(hConsole, col);
					printf("[active]\n");
					col = 8;
					SetConsoleTextAttribute(hConsole, col);
					printf("port type ====================> ");
					col = 2;
					SetConsoleTextAttribute(hConsole, col);
					printf("[online]\n");
					col = 8;
					SetConsoleTextAttribute(hConsole, col);
					line.pop_back();
					printf("port IPv4 address ============> 196.128.0.%s\n", line.c_str());
					printf("port gateway =================> 196.128.%s.1\n", line.c_str());
					
				}
			}
			else
			{

				col = 4;
				SetConsoleTextAttribute(hConsole, col);
				printf("Fatal ERROR!!!\n");
			}
			printf("========================================================================================================================\n");
			
			file.close();
			line = "";
			cout << "\n\n";
		}
		if (command == "!test") 
		{
			int test = 0;
			srand(time(NULL));
			cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			ifstream file(prefrences);
			if (file.is_open())
			{
				while (getline(file, line))
				{
					col = 8;
					SetConsoleTextAttribute(hConsole, col);
					printf("checking...\n");
					printf("[");
					for (int i = 0; i <= 60; i++)
					{
						printf("=");
						Sleep(2);
					}
					printf("]\n");
					printf("port number %s ====> ", line.c_str());
					test = rand() % (10 - 1) + 1;
					switch (test)
					{
					case 1:
						col = 2;
						SetConsoleTextAttribute(hConsole, col);
						printf("[passed]\n");
						break;
					case 2:
						col = 2;
						SetConsoleTextAttribute(hConsole, col);
						printf("[passed]\n");
						break;
					case 3:
						col = 2;
						SetConsoleTextAttribute(hConsole, col);
						printf("[passed]\n");
						break;
					case 4:
						col = 2;
						SetConsoleTextAttribute(hConsole, col);
						printf("[passed]\n");
						break;
					case 5:
						col = 4;
						SetConsoleTextAttribute(hConsole, col);
						printf("[failed]\n");
						break;
					case 6:
						col = 2;
						SetConsoleTextAttribute(hConsole, col);
						printf("[passed]\n");
						break;
					case 7:
						col = 2;
						SetConsoleTextAttribute(hConsole, col);
						printf("[passed]\n");
						break;
					case 8:
						col = 2;
						SetConsoleTextAttribute(hConsole, col);
						printf("[passed]\n");
						break;
					case 9:
						col = 2;
						SetConsoleTextAttribute(hConsole, col);
						printf("[passed]\n");
						break;
					case 10:
						col = 2;
						SetConsoleTextAttribute(hConsole, col);
						printf("[passed]\n");
						break;
					default:
						col = 4;
						SetConsoleTextAttribute(hConsole, col);
						printf("Fatal ERROR!!!\n");
						break;
					}
				}
			}
			else
			{

				col = 4;
				SetConsoleTextAttribute(hConsole, col);
				printf("Fatal ERROR!!!\n");
			}
			file.close();
			line = "";
			cout << "\n\n";
		}
		else if (command != "!test" && command != "!ports" && command != "!closeAll" && command != "!close" && command != "!open" && command != "!menu" && command != "!help")
		{
			cout << "\n\n";
			col = 4;
			SetConsoleTextAttribute(hConsole, col);
			printf("unknown command!!!\n");
			col = 9;
			SetConsoleTextAttribute(hConsole, col);
			cout << "\n\n";
		}
	}




}



void Sessions(string logo) 
{
	logoShow = true;
	string name = "";
	string ip = "";
	string pc = "";
	string use = "";
	string date = "";
	string cunt = "";
	string os = "";
	string tim = "";
	string curentUsers = R"U( )U";
	int i = 0;
	int counte = 0;
	system("cls");
	string user = "Modules\\Grabbed\\users.txt";
	string comands_sessions = "Modules\\Commands\\Sessions.txt";
	while (true)
	{
		if (logoShow)
		{
			col = 13;
			SetConsoleTextAttribute(hConsole, col);
			cout << logo << endl;
			col = 9;
			SetConsoleTextAttribute(hConsole, col);
			printf("------------------------------------------------------------------------------------------------------------------------\n");
			printf("|                                                       Sessions                                                       |\n");
			printf("------------------------------------------------------------------------------------------------------------------------\n");
			printf("|          Name|              IP|              PC|            User|   Install_date|         Cuntry|             OS|Time|");
			printf("------------------------------------------------------------------------------------------------------------------------\n");
			ifstream file(user);
			if (file.is_open())
			{
				while (getline(file, line))
				{
					if (counte == 0 + (8 * i))
						name = line;
					if (counte == 1 + (8 * i))
						ip = line;
					if (counte == 2 + (8 * i))
						pc = line;
					if (counte == 3 + (8 * i))
						use = line;
					if (counte == 4 + (8 * i))
						date = line;
					if (counte == 5 + (8 * i))
						cunt = line;
					if (counte == 6 + (8 * i))
						os = line;
					if (counte == 7 + (8 * i)) 
					{
						tim = line;
						printf("|%14s|%16s|%16s|%16s|%15s|%15s|%15s|%4s|\n", name.c_str(), ip.c_str(), pc.c_str(), use.c_str(), date.c_str(), cunt.c_str(), os.c_str(), tim.c_str());
						printf("------------------------------------------------------------------------------------------------------------------------\n");
						i++;
					}
					counte++;
				}
			}
			else
			{

				col = 4;
				SetConsoleTextAttribute(hConsole, col);
				printf("Fatal ERROR!!!\n");
			}
			file.close();
			line = "";
			printf("Hi %s!!!\n   !help ==for==> command list\n", curentUSER.c_str());
		}
		col = 6;
		SetConsoleTextAttribute(hConsole, col);
		printf(">>> ");
		col = 11;
		SetConsoleTextAttribute(hConsole, col);
		cin >> command;
		logoShow = false;
		if (command == "!help") 
		{
			Help(comands_sessions);
		}
		if (command == "!menu")
		{
			system("cls");
			logoShow = true;
			break;
		}
		if (command == "!open")
		{
			cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("Name: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			cin >> name;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("IP: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			cin >> ip;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("PC: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			cin >> pc;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("User: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			cin >> use;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("Install_date: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			cin >> date;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("Cuntry: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			cin >> cunt;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("OS: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			cin >> os;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("Time: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			cin >> tim;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("opening...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(100*(i/5));
			}
			printf("]\n");
			ofstream file(user, ios::app);
			if (file.is_open())
			{
				file << name << endl;
				file << ip << endl;
				file << pc << endl;
				file << use << endl;
				file << date << endl;
				file << cunt << endl;
				file << os << endl;
				file << tim << endl;
				col = 9;
				SetConsoleTextAttribute(hConsole, col);
				printf("------------------------------------------------------------------------------------------------------------------------\n");
				printf("|                                                     New Session                                                      |\n");
				printf("------------------------------------------------------------------------------------------------------------------------\n");
				printf("|          Name|              IP|              PC|            User|   Install_date|         Cuntry|             OS|Time|");
				printf("------------------------------------------------------------------------------------------------------------------------\n");
				printf("|%14s|%16s|%16s|%16s|%15s|%15s|%15s|%4s|\n", name.c_str(), ip.c_str(), pc.c_str(), use.c_str(), date.c_str(), cunt.c_str(), os.c_str(), tim.c_str());
				printf("------------------------------------------------------------------------------------------------------------------------\n");
			}
			else
			{

				col = 4;
				SetConsoleTextAttribute(hConsole, col);
				printf("Fatal ERROR!!!\n");
			}
			file.close();
			cout << "\n\n";
			system("pause");
			system("cls");
			logoShow = true;
			Sessions(logo);
			break;
		}
		if (command == "!close")
		{
			cout << "\n\n";
			i = 0;
			counte = 0;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("Session number (remember everything starts from 0): ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			cin >> i;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			ifstream file(user);
			if (file.is_open())
			{
				while (getline(file, line))
				{
					if (counte >= 0 + (8 * i) && counte <= 7 + (8 * i))
					{
					}
					else
					{
						curentUsers.insert(curentUsers.length() - 1, line + "\n");
					}
					counte++;
				}
			}
			else
			{

				col = 4;
				SetConsoleTextAttribute(hConsole, col);
				printf("Fatal ERROR!!!\n");
			}
			curentUsers.pop_back();
			file.close();
			line = "";
			ofstream newfile;          // поток для записи
			newfile.open(user); // окрываем файл для записи
			if (newfile.is_open())
			{
				newfile << curentUsers;
				col = 2;
				SetConsoleTextAttribute(hConsole, col);
				printf("session number %d is closed\n", i);
			}
			else
			{

				col = 4;
				SetConsoleTextAttribute(hConsole, col);
				printf("Fatal ERROR!!!\n");
			}
			newfile.close();
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			system("cls");
			logoShow = true;
			Sessions(logo);
			break;
			cout << "\n\n";
		}
		
		if (command == "!closeAll")
		{
			cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("closing...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(2);
			}
			printf("]\n");
			ofstream newfile;          // поток для записи
			newfile.open(user); // окрываем файл для записи
			if (newfile.is_open())
			{
				col = 2;
				SetConsoleTextAttribute(hConsole, col);
				printf("done!!!\n");
			}
			else
			{

				col = 4;
				SetConsoleTextAttribute(hConsole, col);
				printf("Fatal ERROR!!!\n");
			}
			newfile.close();
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			system("pause");
			system("cls");
			logoShow = true;
			Sessions(logo);
			break;
			cout << "\n\n";
		}
		if (command == "!test")
		{
			i = 0;
			counte = 0;
			int test = 0;
			srand(time(NULL));
			cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			ifstream file(user);
			if (file.is_open())
			{
				
				while (getline(file, line))
				{
					if (counte == 0 + (8 * i)) 
					{
						col = 8;
						SetConsoleTextAttribute(hConsole, col);
						printf("checking...\n");
						printf("[");
						for (int i = 0; i <= 60; i++)
						{
							printf("=");
							Sleep(50);
						}
						printf("]\n");
						printf("%d.USER: %s ====> ",i, line.c_str());
						test = rand() % (10 - 1) + 1;
						switch (test)
						{
						case 1:
							col = 2;
							SetConsoleTextAttribute(hConsole, col);
							printf("[online]\n");
							break;
						case 2:
							col = 2;
							SetConsoleTextAttribute(hConsole, col);
							printf("[online]\n");
							break;
						case 3:
							col = 4;
							SetConsoleTextAttribute(hConsole, col);
							printf("[offline]\n");
							break;
						case 4:
							col = 2;
							SetConsoleTextAttribute(hConsole, col);
							printf("[online]\n");
							break;
						case 5:
							col = 4;
							SetConsoleTextAttribute(hConsole, col);
							printf("[offline]\n");
							break;
						case 6:
							col = 4;
							SetConsoleTextAttribute(hConsole, col);
							printf("[offline]\n");
							break;
						case 7:
							col = 2;
							SetConsoleTextAttribute(hConsole, col);
							printf("[online]\n");
							break;
						case 8:
							col = 2;
							SetConsoleTextAttribute(hConsole, col);
							printf("[online]\n");
							break;
						case 9:
							col = 4;
							SetConsoleTextAttribute(hConsole, col);
							printf("[ofline]\n");
							break;
						case 10:
							col = 2;
							SetConsoleTextAttribute(hConsole, col);
							printf("[online]\n");
							break;
						default:
							col = 4;
							SetConsoleTextAttribute(hConsole, col);
							printf("Fatal ERROR!!!\n");
							break;
						}
						cout << "\n";
						i++;
						
					}
					counte++;
					
				}
			}
			else
			{

				col = 4;
				SetConsoleTextAttribute(hConsole, col);
				printf("Fatal ERROR!!!\n");
			}
			file.close();
			line = "";
			cout << "\n\n";
		}
		if (command == "!choose")
		{
			cout << "\n\n";
			i = 0;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("Session number (remember everything starts from 0): ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			cin >> i;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			Choose(logo,i);
			break;
		}
		else if (command != "!test" && command != "!choose" && command != "!test" && command != "!closeAll" && command != "!close" && command != "!open" && command != "!help" && command != "!menu")
		{
			cout << "\n\n";
			col = 4;
			SetConsoleTextAttribute(hConsole, col);
			printf("unknown command!!!\n");
			col = 9;
			SetConsoleTextAttribute(hConsole, col);
			cout << "\n\n";
		}
	}
}





void Choose(string logo, int choose)
{
	logoShow = true;
	string name = "";
	string ip = "";
	string pc = "";
	string use = "";
	string date = "";
	string cunt = "";
	string os = "";
	string tim = "";
	int counte = 0;
	system("cls");
	string user = "Modules\\Grabbed\\users.txt";
	string proc = "Modules\\Grabbed\\processes.txt";
	string path = "";
	string comands_session = "Modules\\Commands\\Session.txt";
	col = 8;
	SetConsoleTextAttribute(hConsole, col);
	printf("Enter the path for downloading files: ");
	col = 11;
	SetConsoleTextAttribute(hConsole, col);
	cin >> path;
	system("cls");
	while (true)
	{
		if (logoShow)
		{
			col = 13;
			SetConsoleTextAttribute(hConsole, col);
			cout << logo << endl;
			col = 9;
			SetConsoleTextAttribute(hConsole, col);
			printf("------------------------------------------------------------------------------------------------------------------------\n");
			printf("|                                                    Sessions num %2d                                                   |\n",choose);
			printf("------------------------------------------------------------------------------------------------------------------------\n");
			printf("|          Name|              IP|              PC|            User|   Install_date|         Cuntry|             OS|Time|");
			printf("------------------------------------------------------------------------------------------------------------------------\n");
			ifstream file(user);
			if (file.is_open())
			{
				while (getline(file, line))
				{
					if (counte == 0 + (8 * choose))
						name = line;
					if (counte == 1 + (8 * choose))
						ip = line;
					if (counte == 2 + (8 * choose))
						pc = line;
					if (counte == 3 + (8 * choose))
						use = line;
					if (counte == 4 + (8 * choose))
						date = line;
					if (counte == 5 + (8 * choose))
						cunt = line;
					if (counte == 6 + (8 * choose))
						os = line;
					if (counte == 7 + (8 * choose))
					{
						tim = line;
						printf("|%14s|%16s|%16s|%16s|%15s|%15s|%15s|%4s|\n", name.c_str(), ip.c_str(), pc.c_str(), use.c_str(), date.c_str(), cunt.c_str(), os.c_str(), tim.c_str());
						printf("------------------------------------------------------------------------------------------------------------------------\n");
						break;
					}
					counte++;
				}
			}
			else
			{

				col = 4;
				SetConsoleTextAttribute(hConsole, col);
				printf("Fatal ERROR!!!\n");
			}
			file.close();
			line = "";
			col = 9;
			SetConsoleTextAttribute(hConsole, col);
			printf("Hi %s!!!\n   !help ==for==> command list\n", curentUSER.c_str());
		}
		col = 6;
		SetConsoleTextAttribute(hConsole, col);
		printf(">>> ");
		col = 11;
		SetConsoleTextAttribute(hConsole, col);
		cin >> command;
		logoShow = false;
		if (command == "!help")
		{
			Help(comands_session);

		}
		if (command == "!menu")
		{
			system("cls");
			logoShow = true;
			break;
		}
		if (command == "!screenshot")
		{
			cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("doing...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(2);
			}
			printf("]\n");
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("done!!!\n");
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("packing...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(2);
			}
			printf("]\n");
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("done!!!\n");
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("sending...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(1000);
			}
			printf("]\n");
			col = 4;
			SetConsoleTextAttribute(hConsole, col);
			printf("Fatal ERROR!!!\n");
			cout << "\n\n";
			//HRESULT URLDownloadToFile(
			//	LPUNKNOWN            pCaller,
			//	LPCTSTR              szURL,
			//	LPCTSTR              szFileName,
			//	_Reserved_ DWORD                dwReserved,
			//	LPBINDSTATUSCALLBACK lpfnCB
			//);

		}
		if (command == "!photoWebcam")
		{

			cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("doing...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(2);
			}
			printf("]\n");
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("done!!!\n");
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("packing...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(2);
			}
			printf("]\n");
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("done!!!\n");
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("sending...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(1000);
			}
			printf("]\n");
			col = 4;
			SetConsoleTextAttribute(hConsole, col);
			printf("Fatal ERROR!!!\n");
			cout << "\n\n";

		}
		if (command == "!openLink")
		{
			cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("link: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			cin >> something;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("opening...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(2);
			}
			printf("]\n");
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("done!!!\n");

			cout << "\n\n";
		}
		if (command == "!directory")
		{

			cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("wait...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(2);
			}
			printf("]\n");
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("C:\\\n");

			cout << "\n\n";

		}
		if (command == "!directoryContent")
		{

			cout << "\n\n";
			int file = 0;
			int type = 0;
			int much = 0;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("wait...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(10);
			}
			printf("]\n");
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			srand(time(NULL));

			much = rand() % (30 - 1) + 1;
			for (int i = 0; i <= file; i++)
			{
				file = rand() % (10 - 0) + 0;
				type = rand() % (10 - 0) + 0;
				switch (file)
				{
				case 0:
					printf("new folder");
					break;
				case 1:
					printf("image");
					break;
				case 2:
					printf("need");
					break;
				case 3:
					printf("application");
					break;
				case 4:
					printf("document");
					break;
				case 5:
					printf("my");
					break;
				case 6:
					printf("H8Jd6fe5");
					break;
				case 7:
					printf("374830847");
					break;
				case 8:
					printf("file");
					break;
				case 9:
					printf("_");
					break;
				case 10:
					printf("d3d9");
					break;
				default:
					break;
				}
				switch (type)
				{
				case 0:
					printf("\\");
					break;
				case 1:
					printf(".png");
					break;
				case 2:
					printf(".docx");
					break;
				case 3:
					printf(".exe");
					break;
				case 4:
					printf(".txt");
					break;
				case 5:
					printf(".pdf");
					break;
				case 6:
					printf(".jpg");
					break;
				case 7:
					printf(".zip");
					break;
				case 8:
					printf(".dll");
					break;
				case 9:
					printf(".dat");
					break;
				case 10:
					printf(".mp4");
					break;
				default:
					break;
				}
				cout << "\n";
			}
			

			cout << "\n\n";

		}
		if (command == "!createFolder")
		{
			cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("path to the folder and folder name, without spaces: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			cin >> something;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("creating...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(10);
			}
			printf("]\n");
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("folder %s created", something.c_str());
			cout << "\n\n";
		}
		if (command == "!deleteFolder")
		{

			cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("path to the folder and folder name, without spaces: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			cin >> something;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("deleting...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(10);
			}
			printf("]\n");
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("folder %s deleted", something.c_str());
			cout << "\n\n";

		}
		if (command == "!deleteFile")
		{

			cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("path to the file and file name, without spaces: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			cin >> something;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("deleting...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(10);
			}
			printf("]\n");
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("file %s deleted", something.c_str());
			cout << "\n\n";

		}
		if (command == "!downloadFile")
		{
			cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("path to the file on your computer and file name, without spaces: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			cin >> something;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("downloading...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(100*(i/2));
			}
			printf("]\n");
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("file %s downloaded", something.c_str());
			cout << "\n\n";


		}
		if (command == "!video")
		{
			float dur = 0;
			cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("duration in seconds: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			cin >> dur;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("recording...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep((dur*1000)/60);
			}
			printf("]\n");
			printf("saving...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(10*dur);
			}
			printf("]\n");
			printf("packing...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(5 * dur);
			}
			printf("]\n");
			printf("sending...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(100 * dur);
			}
			printf("]\n");
			col = 4;
			SetConsoleTextAttribute(hConsole, col);
			printf("Fatal ERROR!!!\n");
			cout << "\n\n";

		}
		if (command == "!audio")
		{

			float dur = 0;
			cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("duration in seconds: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			cin >> dur;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("recording...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep((dur * 1000) / 60);
			}
			printf("]\n");
			printf("saving...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(10 * dur);
			}
			printf("]\n");
			printf("packing...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(5 * dur);
			}
			printf("]\n");
			printf("sending...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(100 * dur);
			}
			printf("]\n");
			col = 4;
			SetConsoleTextAttribute(hConsole, col);
			printf("Fatal ERROR!!!\n");
			cout << "\n\n";

		}
		if (command == "!runFile")
		{

			cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("path to the file and file name, without spaces: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			cin >> something;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("wait...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(5);
			}
			printf("]\n");
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("file %s is run\n", something.c_str());
			cout << "\n\n";

		}
		if (command == "!volume")
		{

			cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("volume: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			cin >> something;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("wait...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(5);
			}
			printf("]\n");
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("volume is: %s\n", something.c_str());
			cout << "\n\n";

		}
		if (command == "!turnOff")
		{

			cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("wait...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(5);
			}
			printf("]\n");
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("done!!!\n");
			cout << "\n\n";

		}
		if (command == "!restart")
		{

			cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("wait...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(5);
			}
			printf("]\n");
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("done!!!\n");
			Sleep(300000);
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("Hi, again!!!\n");
			cout << "\n\n";

		}
		if (command == "!alt+f4")
		{
			cout << "\n\n";

			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("done!!!\n");
			cout << "\n\n";
		}
		if (command == "!crazyCursor")
		{

			cout << "\n\n";

			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("done!!!\n");
			cout << "\n\n";

		}
		if (command == "!wallpaper")
		{

			cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("path to the image on your PC and file name, without spaces: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			cin >> something;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("wait...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(5);
			}
			printf("]\n");
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("done!!!\n");
			cout << "\n\n";

		}
		if (command == "!move")
		{

			cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("path to the folder without spaces: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			cin >> something;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("moveing...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(500);
			}
			printf("]\n");
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("curent folder %s", something.c_str());
			cout << "\n\n";

		}
		if (command == "!rename")
		{
			cout << "\n\n";

			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("new name, without spaces: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			cin >> something;
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("curent name %s", something.c_str());
			cout << "\n\n";


		}
		if (command == "!encrypt")
		{
			cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("path to the file and file name, without spaces: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			cin >> something;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("encrypting...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(10);
			}
			printf("]\n");
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("file %s encrypted", something.c_str());
			cout << "\n\n";


		}
		if (command == "!decrypt")
		{

			cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("path to the file and file name, without spaces: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			cin >> something;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("decrypting...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(10);
			}
			printf("]\n");
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("file %s decrypted", something.c_str());
			cout << "\n\n";

		}
		if (command == "!logs")
		{

			cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("searching...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(2);
			}
			printf("]\n");
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("done!!!\n");
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("packing...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(2);
			}
			printf("]\n");
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("done!!!\n");
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("sending...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(1000);
			}
			printf("]\n");
			col = 4;
			SetConsoleTextAttribute(hConsole, col);
			printf("Fatal ERROR!!!\n");
			cout << "\n\n";

		}
		if (command == "!screamer")
		{
			cout << "\n\n";
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("done!!!\n");
			cout << "\n\n";

		}
		if (command == "!moveFile")
		{

			cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("path to the folder and file name without spaces: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			cin >> something;
			col = 8;
			printf("path to the new folder without spaces: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			cin >> something;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("moveing...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(500);
			}
			printf("]\n");
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("done!!!");
			cout << "\n\n";

		}
		if (command == "!lock")
		{

			cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("lock? (y/n): ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			cin >> something;
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("done!!!");
			cout << "\n\n";

		}
		if (command == "!downloadFolder")
		{

			cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("path to the folder, without spaces: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			cin >> something;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("downloading...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(1000 * (i / 2));
			}
			printf("]\n");
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("folder %s downloaded", something.c_str());
			cout << "\n\n";

		}
		if (command == "!processes")
		{
			Help(proc);


		}
		if (command == "!closeProces")
		{

			cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("proces: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			cin >> something;
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("done!!!");
			cout << "\n\n";

		}
		if (command == "!banTM")
		{

			cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("ban? (y/n): ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			cin >> something;
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("done!!!");
			cout << "\n\n";

		}
		if (command == "!message")
		{

			cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("massage, on spaces: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			cin >> something;
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("done!!!");
			cout << "\n\n";

		}
		if (command == "!CMDbomb")
		{


			cout << "\n\n";
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("done!!!");
			cout << "\n\n";

		}

	}
}

