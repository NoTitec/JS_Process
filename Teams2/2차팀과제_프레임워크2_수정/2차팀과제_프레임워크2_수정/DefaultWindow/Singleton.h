#pragma once
template<typename T>
class CSingleton
{
public:
    static T& Get_Instance()
    {
        static T Instance;
        return Instance;
    }

protected:
    CSingleton() {};
    virtual ~CSingleton() {};
    CSingleton(const T& _instance) {};
    T& operator=(T&& _instance) {};
};