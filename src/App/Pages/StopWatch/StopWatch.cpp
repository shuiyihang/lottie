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
    SetCustomCacheEnable(false);
    SetCustomLoadAnimType(PageManager::LOAD_ANIM_OVER_LEFT, 500, lv_anim_path_bounce);
}

void StopWatch::onViewLoad()
{
    LV_LOG_USER("begin");
    View.Create(root);
    AttachEvent(View.ui.cont);
    AttachEvent(View.ui.ctl_btn);
    AttachEvent(View.ui.reset_btn);
}

void StopWatch::onViewDidLoad()
{
    LV_LOG_USER("begin");
}

void StopWatch::onViewWillAppear()
{
    LV_LOG_USER("begin");
    timer = lv_timer_create(onTimerUpdate,10,this);
    lv_timer_pause(timer);
    lv_obj_fade_in(root, 300, 0);
}

void StopWatch::onViewDidAppear()
{
    LV_LOG_USER("begin");
}

void StopWatch::onViewWillDisappear()
{
    LV_LOG_USER("begin");
    lv_obj_fade_out(root, 300, 0);
}

void StopWatch::onViewDidDisappear()
{
    LV_LOG_USER("begin");
    lv_timer_del(timer);
}

void StopWatch::onViewDidUnload()
{
    LV_LOG_USER("begin");
    View.Delete();
}

void StopWatch::AttachEvent(lv_obj_t* obj)
{
    lv_obj_add_event_cb(obj, onEvent, LV_EVENT_ALL, this);
}

void StopWatch::onBtnClicked(lv_obj_t* btn)
{
    if(btn == View.ui.ctl_btn){
        // 开始或暂停计数
        if(isStart == false){
            // 开始计数
            lv_timer_ready(timer);
            lv_timer_resume(timer);
            lv_label_set_text(View.ui.ctl_label,"Stop");
            isStart = true;
        }else{
            lv_timer_pause(timer);
            lv_label_set_text(View.ui.ctl_label,"Start");
            isStart = false;
        }
    }else if(btn == View.ui.reset_btn){
        // Serial.printf("btn2 \r\n");
        if (isStart == false) {
            time = 0;
            lv_label_set_text(View.ui.label, "00:00.00");
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
        if(obj == instance->View.ui.cont){
            instance->Manager->Pop();
        }else{
            instance->onBtnClicked(obj);
        }
    }
    
}

void StopWatch::onTimerUpdate(lv_timer_t* timer)
{
    StopWatch* instance = (StopWatch*)timer->user_data;
    instance->time++;
    lv_label_set_text_fmt(instance->View.ui.label,"%02d:%02d.%02d",(instance->time/100)/60,(instance->time/100)%60,instance->time%100);

}