#include <iostream>
#include <WS2tcpip.h>

#pragma comment (lib, "ws2_32.lib")//pr‰prozessorbefehl um die bibliothek Winsock 32 einzubinden

using namespace std;

void main()
{
	//starte Winsock
	WSADATA data;
	WORD version = MAKEWORD(2, 2);//aktuellste version "finden"
	int wsOk = WSAStartup(version, &data);
	if (wsOk != 0)
	{
		cout << "Starten des Sockets nicht mˆglich." << wsOk;
		return;
	}

	//binde den Socket an die ip adresse und den port
	SOCKET in = socket(AF_INET, SOCK_DGRAM, 0);//socket wird erstellt --> UDP
	sockaddr_in serverHint;
	serverHint.sin_addr.S_un.S_addr = ADDR_ANY;//benutze die n‰chstbeste netzwerkkarte
	serverHint.sin_family = AF_INET;
	serverHint.sin_port = htons(54000);//benutze den port 54000, konvertieren von kleinem zu groﬂem "endian"

	if (bind(in, (sockaddr*)& serverHint, sizeof(serverHint)) == SOCKET_ERROR)//ip, socket und port verbinden, 3-tupel
	{
		cout << "Anbinden des Sockets nicht mˆglich." << WSAGetLastError() << endl;
		return;
	}

	//hier steht die information des Clienten
	sockaddr_in client;
	int clientLength = sizeof(client);
	ZeroMemory(&client, sizeof(client));
	//hier ist die nachricht drinn
	char buf[1024];
	
	
	//starte eine schleife
	while (true)
	{
		ZeroMemory(buf, 1024);//speicher wird geleert

		//warte auf eine nachricht
		int bytesIn = recvfrom(in, buf, 1024, 0, (sockaddr*)&client, &clientLength);//buffer wird gef¸llt und die metadaten(clientinformationen) werden ¸bergeben
		if (bytesIn == SOCKET_ERROR)
		{
			cout << "ERROR w‰rend des Empfangens vom Client" << WSAGetLastError() << endl;
			continue;
		}

		//zeige die nachricht und die info des clienten
		char clientIp[256];
		ZeroMemory(clientIp, 256);

		inet_ntop(AF_INET, &client.sin_addr, clientIp, 256);

		cout << "Nachricht erhalten von" << clientIp << " : " << buf << endl;
	}

	//schlieﬂe den Socket
	closesocket(in);

	//beende den Socket
	WSACleanup();
}