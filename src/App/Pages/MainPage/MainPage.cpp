#include "MainPage.h"
#include "HAL/HAL.h"

using namespace Page;

MainPage::MainPage()
    : timer(nullptr)
{
}

MainPage::~MainPage()
{

}

void MainPage::onCustomAttrConfig()
{
    LV_LOG_USER("begin");
    SetCustomCacheEnable(true);
    SetCustomLoadAnimType(PageManager::LOAD_ANIM_OVER_BOTTOM, 500, lv_anim_path_bounce);
}

void MainPage::onViewLoad()
{
    LV_LOG_USER("begin");
    Model.Init();
    View.Create(root);

    AttachEvent(View.ui.cont);
    AttachEvent(View.ui.ui_Image1);
    AttachEvent(View.ui.ui_Image2);
    AttachEvent(View.ui.ui_Image3);
    // Model.TickSave = Model.GetData();
}

void MainPage::onViewDidLoad()
{
    LV_LOG_USER("begin");
}

void MainPage::onViewWillAppear()
{
    LV_LOG_USER("begin");
    Param_t param;
    param.color = lv_color_white();
    param.time = 100;

    PAGE_STASH_POP(param);

    lv_indev_set_group(lv_get_indev(LV_INDEV_TYPE_ENCODER), View.ui.group);
    lv_group_focus_obj(View.ui.ui_Image2);
    redirect = 0;
    timer = lv_timer_create(onTimerUpdate, param.time, this);
}

void MainPage::onViewDidAppear()
{
    StatusBar::SetStyle(StatusBar::STYLE_BLACK);
    LV_LOG_USER("begin");
}

void MainPage::onViewWillDisappear()
{
    LV_LOG_USER("begin");
}

void MainPage::onViewDidDisappear()
{
    LV_LOG_USER("begin");
    lv_timer_del(timer);
}

void MainPage::onViewUnload()
{
    LV_LOG_USER("begin");
}

void MainPage::onViewDidUnload()
{
    LV_LOG_USER("begin");
    View.Delete();
    Model.DeInit();
}

void MainPage::AttachEvent(lv_obj_t* obj)
{
    lv_obj_set_user_data(obj, this);
    lv_obj_add_event_cb(obj, onEvent, LV_EVENT_ALL, this);
}

void MainPage::Update()
{
    if(View.notice == true)
    {
        int lval = lv_slider_get_value(View.ui.ui_Slider1);
        if (light_val != lval) {
            light_val = lval;
            HAL::Backlight_SetGradual(light_val*10, 1000);
            // printf("slider val:%d\n", old_val);
        }
        bool sval = lv_obj_has_state(View.ui.ui_Switch1,LV_STATE_CHECKED);
        if(sound_state != sval){
            sound_state = sval;
            Model.SetSoundEnable(sval);
        }
    }
    redirect += 100;
    if(redirect > 60000){
        Manager->Push("Pages/Template");
    }
}

void MainPage::onTimerUpdate(lv_timer_t* timer)
{
    MainPage* instance = (MainPage*)timer->user_data;

    instance->Update();
}

void MainPage::onEvent(lv_event_t* event)
{
    MainPage* instance = (MainPage*)lv_event_get_user_data(event);
    LV_ASSERT_NULL(instance);

    lv_obj_t* obj = lv_event_get_current_target(event);
    lv_event_code_t code = lv_event_get_code(event);

    if(code == LV_EVENT_GESTURE || code == LV_EVENT_PRESSED)
    {
        instance->redirect = 0;
        if (obj == instance->View.ui.ui_Image1)
        {
            instance->Manager->Push("Pages/StopWatch");
        
        }else if(obj == instance->View.ui.ui_Image2){

        }else if(obj == instance->View.ui.ui_Image3){
            instance->Manager->Push("Pages/SystemInfos");
        }
    }
}
