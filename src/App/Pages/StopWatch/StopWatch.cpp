#include "StopWatch.h"
using namespace Page;

StopWatch::StopWatch()
{
    
}
StopWatch::~StopWatch()
{

}
void StopWatch::onCustomAttrConfig()
{

}

void StopWatch::onViewLoad()
{
    View.Create(root);
    timer = lv_timer_create(onTimerUpdate,10,this);
    lv_timer_pause(timer);
    AttachEvent(View.ui.bottomInfo.ctl_btn);
    AttachEvent(View.ui.bottomInfo.reset_btn);
}

void StopWatch::onViewDidLoad()
{

}

void StopWatch::onViewWillAppear()
{

}

void StopWatch::onViewDidAppear()
{
    
}

void StopWatch::onViewWillDisappear()
{

}

void StopWatch::onViewDidDisappear()
{
    lv_timer_del(timer);
}

void StopWatch::onViewDidUnload()
{
    
}

void StopWatch::AttachEvent(lv_obj_t* obj)
{
    lv_obj_add_event_cb(obj, onEvent, LV_EVENT_PRESSED, this);
}

void StopWatch::onBtnClicked(lv_obj_t* btn)
{
    if(btn == View.ui.bottomInfo.ctl_btn){
        // 开始或暂停计数
        if(isStart == false){
            // 开始计数
            lv_timer_ready(timer);
            lv_timer_resume(timer);
            lv_label_set_text(View.ui.bottomInfo.ctl_label,"Stop");
            isStart = true;
        }else{
            lv_timer_pause(timer);
            lv_label_set_text(View.ui.bottomInfo.ctl_label,"Start");
            isStart = false;
        }
    }else if(btn == View.ui.bottomInfo.reset_btn){
        // Serial.printf("btn2 \r\n");
        if (isStart == false) {
            time = 0;
            lv_label_set_text(View.ui.topInfo.label, "00:00.00");
        }
    }
}

void StopWatch::onEvent(lv_event_t* event)
{
    StopWatch* instance = (StopWatch*)lv_event_get_user_data(event);
    lv_obj_t* obj = lv_event_get_current_target(event);
    lv_event_code_t code = lv_event_get_code(event);
    
    // Serial.printf("code:%d\r\n",code);
    if(code == LV_EVENT_PRESSED){
        instance->onBtnClicked(obj);
    }
    
}

void StopWatch::onTimerUpdate(lv_timer_t* timer)
{
    StopWatch* instance = (StopWatch*)timer->user_data;
    instance->time++;
    lv_label_set_text_fmt(instance->View.ui.topInfo.label,"%02d:%02d.%02d",(instance->time/100)/60,(instance->time/100)%60,instance->time%100);

}