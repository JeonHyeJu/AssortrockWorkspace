#pragma once
// 컨텐츠의 헤더를 사용하기는 싫다.

class TextRpgCore
{
public:
	TextRpgCore();

	static void Start();

	static class APlayer& GetPlayer();

public:
};

