#include "Item.h"
#include "ContentsConst.h"

bool Item::isMaxEnhanceLevel()
{
    bool ret = mEnhanceScore >= MAX_ENHANCE_SCORE;
    return ret;
}
