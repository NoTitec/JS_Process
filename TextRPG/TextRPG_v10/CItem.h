#pragma once
#include "CBase.h"
class CItem : public CBase
    
{
public:
    CItem();
    CItem(const char* _itemname, int _iattack, int _ihp);
    CItem(const char* _itemname, int _iattack, int _ihp, int _imoney);
    virtual ~CItem();

public:
    virtual void Render() override;

};

