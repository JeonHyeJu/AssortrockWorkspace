#pragma once
#include "EngineConst.h"
#include "Object.h"

class UStatusUnit : public UObject
{
public:
    void StatusRender();

protected:
    int Hp = 100;
    int MinAtt = 10;
    int MaxAtt = 20;
    int Speed = 10;

private:
};
