#include "MainPageModel.h"
#include <cstdlib>

using namespace Page;



uint32_t MainPageModel::GetData()
{
    return lv_tick_get();
}

void MainPageModel::Init()
{
    account = new Account("MainPageModel", AccountSystem::Broker(), 0, this);
    account->Subscribe("SysConfig");
}

void MainPageModel::DeInit()
{
    if(account)
    {
        delete account;
        account = nullptr;
    }
}

void MainPageModel::SetSoundEnable(bool en)
{
    AccountSystem::SysConfig_Info_t info;
    info.soundEnable = en;
    info.cmd = AccountSystem::SYSCONFIG_CMD_SET;
    account->Notify("SysConfig", &info, sizeof(info));
}