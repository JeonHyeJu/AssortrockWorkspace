// Client.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.

// window가 제공하는 서버인터페이스의 헤더함수는 
// 이 두개의 헤더는 규칙이 있는데.
// 무조건 <window>보다 위여야 합니다.
#include <WinSock2.h>
// 윈도우가 아래여야 합니다.
// 통신규약이 윈도우보다 위입니다.
#include <Windows.h>
#include <WS2tcpip.h>
#include <vector>

#include <assert.h>

#include <thread>

#pragma comment (lib, "ws2_32") // <= 윈도우 서버 사용을 위한 라이브러리

#include <iostream>

void UserRecvThread(SOCKET _ClientSocket)
{
    std::wstring Name = L"UserThread" + std::to_wstring(_ClientSocket);
    ;

    SetThreadDescription(GetCurrentThread(), Name.c_str());

    while (true)
    {
        // ClientSocket == 접속자
        std::string Packet;
        Packet.resize(1024);
        // 상대가 무언가를 보내면 받을수가 있다.
        // 그 바이트 덩어리에 여러분들이 보낸 데이터가 날아올수 있습니다.
        // 상대가 패킷을 보낼때까지 영원히 기다립니다.
        recv(_ClientSocket, &Packet[0], Packet.size(), 0);

        std::cout << Packet << std::endl;
    }
}

int main()
{
    std::cout << "서버 테스트 시작\n";
    // Test TestInst;
    WSAData WsaData;
    int Error = WSAStartup(MAKEWORD(2, 2), &WsaData);

    if (SOCKET_ERROR == Error)
    {
        assert(false);
    }

    // 서버란 외부에서 데이터를 받기를 허용한 프로그램
    // 서버프로그램 서버 프로세스라고 합니다.
    // 포트는 뭐냐?
    // 내컴퓨터에 외부에서 데이터를 받기로 한 프로그램이 나 하나인가?
    // 아니겠죠? 
    // 던파 12000
    // 카카오톡  3000
    // 메이플 9800
    // 어떤 데이터가 왔어 3개의 프로그램중 어디로 가야할까요?
    // 그러면 겹치
    // 서버프로그래머들 사이에서 피해가 포트가 있다.
    // https://ko.wikipedia.org/wiki/TCP/UDP%EC%9D%98_%ED%8F%AC%ED%8A%B8_%EB%AA%A9%EB%A1%9D
    // 포트목록 사이트에 가보면 기본적으로 피해야할 포트들을 알수 있다.
    int Port = 30000;

    // 내가 데이터를 쏠대는 무조건 port를 지정해줘야 한다는 것을 통신규약으로 명시했어요. 포트를 지정해야 합니다.
    // 내가 통신포트를 열면

    // 주소를 지정해줘야 한다.
    // 그런데 이 주소에는 종류가 있다.
    // IP4
    SOCKADDR_IN Add = {};
    Add.sin_family = AF_INET; // ip4버전을 사용하겠다. AF_INET6 => ip6 버전 주소를 쓰겠다.
    Add.sin_port = htons(Port); // 포트지정

    //연결별 DNS 접미사. . . . :
    //링크 - 로컬 IPv6 주소 . . . . : fe80::a98a : ba49 : 8621 : e7ab % 14
    //IPv4 주소 . . . . . . . . . : 192.168.0.71 <= 대부분은 이 주소체계를 사용합니다.
    //서브넷 마스크 . . . . . . . : 255.255.255.0
    //기본 게이트웨이 . . . . . . : 192.168.0.1 <= 공유기 주소이다. 공유기 주소가 같으면 같은 프라이빗 네트워크안에 존재한다는 것.

    // 서버는 ip주소를 입력할 필요가 없다.
    // ip주소를 Add.sin_addr에 넣어서 복사해주는 함수
    // 리틀에디안 빅에디안 에 영향받지 않는 리틀에디안 정식규격으로 변환해준다.
    // CPU에 따라서 리틀에디안 빅에디안에서 오는 차이를 무시할수있게 도와주는 함수가 아래 함수이다.
    if (SOCKET_ERROR == inet_pton(AF_INET, "0.0.0.0", &Add.sin_addr))
    {
        assert(false);
    }

    // 윈도우에서 통신연결에 대한 권한을 가진 핸들 
    // 윈도우는 이 소켓을 통해서 함수들을 사용수 이께 
    // SOCK_STREAM 연결 지향형 TCP를 사용하겠다는 것.
    // TCP 통신 규약은 OSI 7계층과 랑 연관시켜서 제대로 설명해야 하기 때문에
    // 지금은 그냥 TCP 로 만드는 구나 정도만 생각해주시면 됩니다.
    SOCKET AcceptSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (INVALID_SOCKET == AcceptSocket)
    {
        assert(false);
    }
    
    // 바인드는 주소와 소켓을 연결시켜서 이 연결이 어떤 IP주소와 포트로 통신하는지 지정해주는 함수입니다.
    // IP6으로 하면 크기가 변경될수 있다.
    if (INVALID_SOCKET == bind(AcceptSocket, (const sockaddr*)&Add, sizeof(SOCKADDR_IN)))
    {
        assert(false);
    }

    // int BackLog = 512;

    int BackLog = 1;

    // 서버는 리슨을 호출했을때 열리는 겁니다.
    // 리슨 호출하면 서버 컴퓨터입니다.
    if (SOCKET_ERROR == listen(AcceptSocket, BackLog))
    {
        assert(false);
    }

    int AddressLen = sizeof(SOCKADDR_IN);
    SOCKADDR_IN ClientAdd;
    memset(&ClientAdd, 0, sizeof(ClientAdd));

    std::vector<std::shared_ptr<std::thread>> UserThread;

    while (true)
    {
        // 접속자를 직접 처리하겠다는 함수 이건 이제 통신버퍼를 설명해야 합니다.
        // 참고5t로 accept는 기본함수고 wsaaccept같은 멀티쓰레드 전용 비동기 접속함수가 있습니다
        // 100명 이하면 accept로도 충분한데 더 다수의 말도안되는 수의 접속자를 처리하려면
        // 그냥 일반 accpet함수가 아닌 wsaaccept와 iocp를 기반한 서버를 공부하시면 됩니다.
        // accept의 리턴값은 소켓입니다.
        // 접속자와의 연결을 의미하는 소켓을 리턴해줍니다.
        SOCKET ClientSocket = accept(AcceptSocket, (sockaddr*)&ClientAdd, &AddressLen);
        // 접속자.가 계속 들어올 것이므로 

        if (SOCKET_ERROR == ClientSocket)
        {
            std::cout << "유저가 접속에 실패했습니다" << std::endl;
            continue;
        }

        std::shared_ptr<std::thread> NewThread = std::make_shared<std::thread>(UserRecvThread, ClientSocket);
        UserThread.push_back(NewThread);

        std::cout << "접속 성공" << std::endl;
        int a = 0;
    }
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
