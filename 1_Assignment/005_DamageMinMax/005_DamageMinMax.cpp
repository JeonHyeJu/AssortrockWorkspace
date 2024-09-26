// TextRPG002inheritance.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <conio.h>

//class PlayerSaveData
//{
//public:
//    int Hp;
//    int Att;
//};

const int NAMELEN = 10;

// 다중상속을 부정적으로 생각하는 사람이 많아요.
// 1. 다중상속을 제대로 못쓰니까.
// 2. 제대로 쓸줄 알아도 다른 사람들을 못믿으니까.

// 좀더 근본에 가까운 기능과 데이터들이 뭐냐를 판단하는 능력.
// 상속구조의 절대 금기.

class StatusUnit
{
protected:
    char Name[NAMELEN] = "NONE";
    int Hp = 100;
    int MinAtt = 10;
    int MaxAtt = 20;
    int Speed = 10;
    int Charm = 0;

    // 부모는 자식클래스가 뭔지 절대로 알아서는 안된다.
    //void Test(FightUnit& _Test)
    //{
    //}
};


class FightUnit : public StatusUnit
{
public:
    // void DamageLogic(int _Att)
    // class DamageData;

    // AttackLogic이라고 짓고

    //void AttackLogic(FightUnit& _DefUnit)
    //{
    //    _DefUnit.Hp -= MinAtt;
    //}

    // MinMax
    int GetDamage() const
    {
        // minAtt ~ MaxAtt 사이의 숫자가 리턴되는 함수를 만드세요.
        int RealAtt = MaxAtt - MinAtt + 1;
        return MinAtt + rand() % RealAtt;
    }

    // 클래스의 레퍼런스를 넣어주는것이 많은게 간단해 집니다.
    void DamageLogic(const FightUnit& _AttUnit)
    {
        // _AttUnit => 나를 공격하려는 상대
        Hp -= _AttUnit.GetDamage();
    }

    void DamageRender(const char* const _AttName, int _Att)
    {
        printf_s("%s 가 %s를 공격해서 %d의 데미지를 입혔습니다.\n", _AttName, Name, _Att);
    }

    const char* GetName() const
    {
        return Name;
    }

protected:


private:
};

// 컴포넌트 방식이라는 것과 차이가 거의 없다.
// 보통 상속구조와 컴포넌트 기반구조가 게임의 로직계를 지배하고 있다.
// 

class Player : public FightUnit
{
};

class Monster : public FightUnit
{

};


// 게임을 만들다보면
// 일반적인 로직클래스 Player
// 리소스 클래스 <= 
// 데이터 전담클래스가 <= 내부에 변수밖에 없다. 
// 맴버변수도 public을 사용합니다.

int main()
{
    Player NewPlayer;
    Monster NewMonster;
    NewMonster.DamageLogic(NewPlayer);

    // NewPlayer.
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
