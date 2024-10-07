#include "BlackSmith.h"
#include "Player.h"
#include "Item.h"
#include <BaseSystem/EngineDebug.h>
#include <conio.h>

int GetProbability(int _minVal, int _maxVal)
{
	int ret = _minVal + rand() % (_maxVal - _minVal + 1);
	return ret;
}

bool IsEnhanceSuccessed()
{
	const int MIN_VAL = 1;
	const int MAX_VAL = 2;
	bool isSuccess = GetProbability(MIN_VAL, MAX_VAL) == MAX_VAL;
	return isSuccess;
}

void BlackSmith::InPlayer(UPlayer& _Player/*, int& Result*/)
{
	if (nullptr == ParentZone)
	{
		MSGASSERT("부모존이 세팅되지 않았습니다");
		return;
	}

	Item* itemForCheck = _Player.GetItem();
	if (!itemForCheck)
	{
		Item* item = new Item;
		_Player.Equip(item);
	}
	
	_Player.SetGold(1000000);

	srand(time(nullptr));

	while (true)
	{
		system("cls");
		_Player.StatusRender();
		std::cout << "1. 강화\n";
		std::cout << "2. 나간다\n";
		int Select = _getch();
		
		switch (Select)
		{
		case '1': {
			Enhance(_Player);
			break;
		}
		case '2':
			return;
		default:
			break;
		}
	}
}

void BlackSmith::Enhance(UPlayer& _Player)
{
	// 확률은 전부다 2분의 1
	// 1돈이 깎여야 한다. 플레이어의 강화 단계 * 100
	// 내가 현재 5강에 도전하고 있다. 그러면 500원씩 깍여야 한다.
	// 1~5까지는 실패가 실패확률은 있지만.
	// 다운되지는 않는다.
	// 6~10까지는 실패하면 1씩 다운된다.
	// 10~15는 0으로 실패하면 0으로 떨어진다.
	// 15강 이상이면 강화를 못하게 해야해한다.

	const int REQUIRED_MONEY_PER_TRY = 100;
	Item* playerItem = _Player.GetItem();
	if (!playerItem) {
		std::cout << "아이템이 없습니다." << std::endl;
		_getch();
		return;
	}

	int itemEnhanceScore = playerItem->GetEnhanceScore();
	int requiredMoney = (itemEnhanceScore + 1) * REQUIRED_MONEY_PER_TRY;
	int playerGold = _Player.GetGold();

	if (playerGold < requiredMoney) {
		std::cout << "돈 없음" << std::endl;
		_getch();
		return;
	}

	bool isMaxEnhanceLevel = playerItem->isMaxEnhanceLevel();
	if (isMaxEnhanceLevel) {
		std::cout << "강화 최고 등급" << std::endl;
		_getch();
		return;
	}

	int lastGold = playerGold - REQUIRED_MONEY_PER_TRY;
	_Player.SetGold(lastGold);

	bool isSuccessed = IsEnhanceSuccessed();
	if (isSuccessed)
	{
		itemEnhanceScore += 1;
		std::cout << "강화 성공" << std::endl;
	}
	else 
	{
		if (itemEnhanceScore >= 6 && itemEnhanceScore <= 10) {
			itemEnhanceScore -= 1;
		}
		else if (itemEnhanceScore >= 11) {
			itemEnhanceScore = 0;
		}
		std::cout << "강화 실패" << std::endl;
	}

	playerItem->SetEnhanceScore(itemEnhanceScore);
	std::cout << "현재 아이템 레벨: " << playerItem->GetEnhanceScore() << std::endl;
	_getch();
}