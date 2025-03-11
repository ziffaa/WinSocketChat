//Main.cpp
#include <iostream>
#include "Socket.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int nChoice;
	int port = 24242; //�������� ����
	string ipAddress = "127.0.0.1"; //����� �������

	char receiveMessage[MAXSTRLEN];
	char sendMessage[MAXSTRLEN];

	cout << "1) Start server" << endl;
	cout << "2) Connect to server" << endl;
	cout << "3) Exit" << endl;
	cin >> nChoice;
	if (nChoice == 1)
	{
		ServerSocket server;
		cout << "Starting server..." << endl;
		//��������� ������
		server.StartHosting(port);
		while (true)
		{
			cout << "\tWaiting..." << endl;
			//�������� ������ �� �������
			//� ��������� � ���������� receiveMessage
			server.ReceiveData(receiveMessage, MAXSTRLEN);
			cout << "Received: " << receiveMessage << endl;
			//// !!!! 
			string Menu = "1. ����(30���)\n2. �������� ���(40���)\n3. ����������(25���)\n";
			if (strcmp(receiveMessage, "Menu") == 0)
			{
				server.SendDataMessage(Menu.c_str());
			}
			//���������� ������ �������

			string str = "";
			
			if (strcmp(receiveMessage, "1") == 0) 
			{
				str = "30 ���";
			}
			if (strcmp(receiveMessage, "2") == 0)
			{
				str = "40 ���";
			}
			if (strcmp(receiveMessage, "3") == 0)
			{
				str = "25 ���";
			}

			server.SendDataMessage(str.c_str());

			//���� ���� ��������� "end", ��������� ������

			if (strcmp(receiveMessage, "end") == 0 ||
				strcmp(sendMessage, "end") == 0)
				break;
		}
	}
	else if (nChoice == 2)
	{
		cout << "IP address = 127.0.0.1 " << endl;
			
		ClientSocket client;
		//������������ � �������
		client.ConnectToServer(ipAddress.c_str(), port);
		while (true)
		{
			//���������� ���������
		//���������� ������ �������
			cout << "������� ������ ��� �������� ";
			char buff[100];
			cin.ignore();
			cin.get(buff,100);
		
			client.SendDataMessage(buff);

			cout << "\tWaiting" << endl;

			//�������� �����
			client.ReceiveData(receiveMessage, MAXSTRLEN);
			cout << "Received: " << receiveMessage << endl;
			if (strcmp(receiveMessage, "end") == 0 ||
				strcmp(sendMessage, "end") == 0)
				break;
		}
		//��������� ����������
		client.CloseConnection();
	}
	else if (nChoice == 3)
		return 0;
}










