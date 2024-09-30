#pragma once

// class UEngineConst
// {
// 객체지향이라면 일반적인 전역요소를 허용하지 않는게 좋다.

// const일때는 선언과 구현을 분리 안해도 된다.

// 컴파일 타임 어써션

// const가 붙은 전역 변수의 경우에는 선언과 구현을 분리할 필요가 없다.
// 즉 const가 붙은 전역 변수에는 extern을 사용할 필요가 없다
const int LINECOUNT = 50;
const int NAMELEN = 20;

// }
