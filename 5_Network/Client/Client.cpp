#include <WinSock2.h>
#include <Windows.h>
#include <WS2tcpip.h>
#include <assert.h>
#pragma comment (lib, "ws2_32") // <= 윈도우 서버 사용을 위한 라이브러리
#include <iostream>
#include <conio.h>

int main()
{
    std::cout << "클라이언트 테스트 시작\n";
    WSAData WsaData;

    // 이 프로그램이 윈도우에게 서버를 사용하겠다고 알려주는 겁니다.
    int errorCode = WSAStartup(MAKEWORD(2, 2), &WsaData);
    if (SOCKET_ERROR == errorCode)
    {
        return false;
    }

    // TCP 통신용으로 만듬.
    SOCKET ClientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (INVALID_SOCKET == ClientSocket)
    {
        return false;
    }

    SOCKADDR_IN ClientAdd;
    ClientAdd.sin_family = AF_INET;
    ClientAdd.sin_port = htons(30000);

    // 서버같은 경우에는 문을 열어놓는 개념이고
    // 클라이언트는 그 열려있는 문으로 찾아가야 하는 개념이다.
    // 
    // 정확하게 IP주소를 입력해줘야 
    // 상대 ip주소가 변경되면

    // std::string Text;
    // std::cin >> Text;

    std::string IP = "192.168.0.71";
    // 로컬 주소입니다. 내 컴퓨터에 접속하겠다.
    // 굉장히 중요한게 로컬로 안되는게 글로벌로 될거라고 생각하지 말아라.
    // std::string IP = "127.0.0.1";
    if (SOCKET_ERROR == inet_pton(AF_INET, IP.c_str(), &ClientAdd.sin_addr))
    {
        return false;
    }

    std::cout << "아무키나 누르면 접속을 시작합니다." << std::endl;
    _getch();

    // 클라는 바인드를 할필요가 없다.
    // 커넥트가 내부에서 바인드를 실행해준다.
    if (SOCKET_ERROR == connect(ClientSocket, (const sockaddr*)&ClientAdd, sizeof(SOCKADDR_IN)))
    {
        std::cout << "접속 실패" << std::endl;
        _getch();
        return false;
    }

    std::cout << "접속 성공" << std::endl;
    while (true)
    {
        std::string Text;
        std::cin >> Text;
        send(ClientSocket, &Text[0], Text.size(), 0);
    }
}
