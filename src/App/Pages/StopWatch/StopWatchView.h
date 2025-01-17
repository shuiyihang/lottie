#ifndef __STOP_WATCH_VIEW_H
#define __STOP_WATCH_VIEW_H

#include "../Page.h"

namespace Page
{

class StopWatchView
{
private:
    void TopInfo_Create(lv_obj_t* par);
    lv_obj_t* Btn_Create(lv_obj_t* par,lv_coord_t x_ofs);
public:
    void Create(lv_obj_t* root);
    void Delete();

public:

    struct
    {
        lv_obj_t* cont;
        lv_obj_t* label;// 计数显示
        lv_obj_t* reset_btn;
        lv_obj_t* reset_label;
        lv_obj_t* ctl_btn;
        lv_obj_t* ctl_label;

        lv_group_t* group;
    }ui;
    
};


}
#endif