#include "SnakeInit.h"
#include <EngineCore/ConsoleWindow.h>
#include "Head.h"
#include "Body.h"


void SnakeInit::UserBeginPlay(ConsoleEngine* _MainEngine)
{
	_MainEngine->GetWindow()->SetScreenSize({3, 3});
	_MainEngine->SpawnActor<Head>();
	_MainEngine->SpawnActor<Body>();
}