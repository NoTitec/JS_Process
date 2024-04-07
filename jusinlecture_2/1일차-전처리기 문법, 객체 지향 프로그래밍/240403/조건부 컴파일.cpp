#include "stdafx.h"

// 조건부 컴파일 : 컴파일 이전에 조건을 비교하여 코드라인의 코드를 컴파일 할지 말지 지정하는 문법

// #if, #ifdef, #ifndef

// #if  (조건)  // if문의 시작과 동일한 기능
// #elif(조건)  // if문의 else if와 동일한 기능
// #else		// 앞선 조건이 모두 거짓이면 동작
// #endif		// 조건부 컴파일을 종료하겠다는 의미

#pragma region 전처리기if

//#define			NUMBER		3
//
//int main()
//{
//#if 5 > NUMBER	
//	cout << "5 보다 작다" << endl;
//
//#elif 5 < NUMBER
//	cout << "5 보다 크다" << endl;
//
//#else
//	cout << "5 와 같다" << endl;
//#endif
//
//	return 0;
//}

#pragma endregion 전처리기if

#pragma region 전처리기ifdef

//#ifdef(전처리기 정의 여부) // define으로 정의되어 있다면 실행
//#elif(전처리기 정의 여부) // define으로 정의되어 있다면 실행
//#else // define으로 정의되어 있지 않다면 실행
//#endif

//int main()
//{
//#ifdef _DEBUG
//	cout << "디버그 모드 입니다" << endl;
//#else
//	cout << "릴리즈 모드 입니다" << endl;
//#endif // DEBUG
//
//	return 0;
//}
#pragma endregion 전처리기ifdef


#pragma region 전처리기ifndef

//#ifndef(전처리기 정의 여부) // define으로 정의 되어 있지 않다면 실행
//#elif(전처리기 정의 여부) // define으로 정의 되어 있지 않다면  실행
//#else // 모두 정의되어 있지 않다면 실행
//#endif
#pragma endregion 전처리기ifdef