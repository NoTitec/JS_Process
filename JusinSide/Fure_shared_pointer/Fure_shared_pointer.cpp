#include <iostream>

using namespace std;


class CBase abstract
{
protected:
    CBase() {}
public:
    virtual ~CBase() {}

public:
    // 완전 수동 버전 레퍼카운트 해제 함수
    unsigned int Release()
    {
        if (m_iRefCount-- == 0)
        {
            Free();
            delete this;
        }
        else
            return m_iRefCount;

        return 0;
    }

    // 셰어드 포인터 전용 (Deleter)
    void Release_Shared()
    {
        Free();
        delete this;
    }

    // 수동 레퍼카운트 증가 함수
    unsigned int AddRef()
    {
        return ++m_iRefCount;
    }

protected:
    // Release에서 호출하게될 사실상 소멸자 함수
    virtual void Free() {}

private:
    unsigned int m_iRefCount = { 0 };
};

class CChild : public CBase
{
protected:
    CChild() {}
public:
    virtual ~CChild() {}

protected:
    // override 잊으면 함수 스펙 바뀔때 대참사남
    virtual void Free() override
    {
        __super::Free();
        // 해제 코드
        cout << "하이2" << endl;
    }
};

class CChild2 final : public CChild
{
protected:
    CChild2() {}
public:
    virtual ~CChild2() {}

protected:
    virtual void Free() override
    {
        __super::Free();

        // 해제 코드
        cout << "하이" << endl;
    }

public:
    static CChild2* Create()
    {
        CChild2* pInstance = new CChild2;

        return pInstance;
    }
};

int main()
{
    // 수동 레퍼카운트
    /*CChild2* pObj2 = CChild2::Create();
    pObj2->Release();*/

    /*shared_ptr<CChild2> pObj(new CChild2, [](CChild2* pObj) {
          pObj->Release();
       });*/

    // 자동 레퍼카운트 관리
    shared_ptr<CChild2> pObj(CChild2::Create(), [](CChild2* pObj) {
        pObj->Release_Shared();
        });

    // 터짐
    //pObj->Release();
}
