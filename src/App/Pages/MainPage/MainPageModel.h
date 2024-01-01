#ifndef __MAINPAGE_MODEL_H
#define __MAINPAGE_MODEL_H

#include "App/Accounts/Account_Master.h"
#include "lvgl.h"
namespace Page
{

class MainPageModel
{
public:
    uint32_t TickSave;
    uint32_t GetData();

    void Init();
    void DeInit();
    void SetSoundEnable(bool en);
private:
     Account* account;
    
};



}

#endif
