#pragma once
class Item
{
public:
	void Test()
	{
	}

	void SetEnhanceScore(int _val)
	{
		mEnhanceScore = _val;
	}

	int GetEnhanceScore() const
	{
		return mEnhanceScore;
	}

	bool isMaxEnhanceLevel();

private:
	int mEnhanceScore = 0;
};