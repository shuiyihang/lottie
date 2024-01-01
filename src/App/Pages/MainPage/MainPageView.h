#ifndef __MAINPAGE_VIEW_H
#define __MAINPAGE_VIEW_H

#include "../Page.h"

namespace Page
{

class MainPageView
{
public:
    void Create(lv_obj_t* root);
    void Delete();
public:
    struct
    {
        lv_obj_t* cont;

        // 软件框
        lv_obj_t* ui_Panel1;
        lv_obj_t* ui_Image1;
        lv_obj_t* ui_Image2;
        lv_obj_t* ui_Image3;

        // 下拉控制
        lv_obj_t* ui_Panel2;
        lv_obj_t* ui_Panel3;
        lv_obj_t* ui_Image4;
        lv_obj_t* ui_Switch1;
        lv_obj_t* ui_Panel4;
        lv_obj_t* ui_Image5;
        lv_obj_t* ui_Slider1;

        lv_group_t* group;
    } ui;

    bool notice = false;// 通知栏是否下拉

private:
    static void ui_event_Screen2( lv_event_t * e);
};

}

#endif // !__VIEW_H
