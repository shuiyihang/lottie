#ifndef __MAINPAGE_PRESENTER_H
#define __MAINPAGE_PRESENTER_H

#include "MainPageView.h"
#include "MainPageModel.h"

namespace Page
{

class MainPage : public PageBase
{
public:
    typedef struct
    {
        uint16_t time;
        lv_color_t color;
    } Param_t;

public:
    MainPage();
    virtual ~MainPage();

    virtual void onCustomAttrConfig();
    virtual void onViewLoad();
    virtual void onViewDidLoad();
    virtual void onViewWillAppear();
    virtual void onViewDidAppear();
    virtual void onViewWillDisappear();
    virtual void onViewDidDisappear();
    virtual void onViewUnload();
    virtual void onViewDidUnload();

private:
    void Update();
    void AttachEvent(lv_obj_t* obj);
    static void onTimerUpdate(lv_timer_t* timer);
    static void onEvent(lv_event_t* event);

private:
    MainPageView View;
    MainPageModel Model;
    lv_timer_t* timer;

    uint8_t light_val = 50;
    bool sound_state = false;
    uint32_t redirect;// 到休息页面时间1分钟
};

}

#endif
