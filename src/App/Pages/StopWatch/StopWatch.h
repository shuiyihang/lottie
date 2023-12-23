#ifndef __STOP_WATCH__
#define __STOP_WATCH__
#include "StopWatchView.h"
#include <Arduino.h>
#include <Print.h>

namespace Page
{
class StopWatch : public PageBase
{
public:
    StopWatch();
    virtual ~StopWatch();

    virtual void onCustomAttrConfig();
    virtual void onViewLoad();
    virtual void onViewDidLoad();
    virtual void onViewWillAppear();
    virtual void onViewDidAppear();
    virtual void onViewWillDisappear();
    virtual void onViewDidDisappear();
    virtual void onViewDidUnload();

private:
    void AttachEvent(lv_obj_t* obj);
    static void onEvent(lv_event_t* event);
    void onBtnClicked(lv_obj_t* btn);

    static void onTimerUpdate(lv_timer_t* timer);
private:
    StopWatchView View;


    lv_timer_t* timer;
    bool isStart = false;
    unsigned int time = 0;
};

}

#endif
