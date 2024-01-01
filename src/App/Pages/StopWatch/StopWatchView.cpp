#include "StopWatch.h"
using namespace Page;


void StopWatchView::TopInfo_Create(lv_obj_t* par)
{
    lv_obj_t* cont = lv_obj_create(par);
    lv_obj_remove_style_all(cont);
    lv_obj_set_size(cont, LV_HOR_RES, LV_VER_RES);
    lv_obj_align(cont, LV_ALIGN_TOP_MID, 0, 0);

    lv_obj_clear_flag(cont, LV_OBJ_FLAG_SCROLLABLE );
    lv_obj_set_style_bg_opa(cont,LV_OPA_COVER,0);
    lv_obj_set_style_bg_color(cont,lv_color_black(),0);

    ui.cont = cont;

    lv_obj_t *label = lv_label_create(cont);

    lv_obj_set_style_text_font(label, &lv_font_montserrat_36, 0);
    lv_obj_set_style_text_color(label,lv_color_white(),0);
    lv_label_set_text(label,"00:00.00");
    lv_obj_align_to(label, cont, LV_ALIGN_TOP_MID, 0, 63);
    lv_obj_set_size(label, LV_HOR_RES, 70);
   
    ui.label = label;

    ui.ctl_btn = Btn_Create(cont,60);

    ui.reset_btn = Btn_Create(cont,-60);

    lv_obj_t *label1 = lv_label_create(ui.ctl_btn);
    lv_label_set_text(label1, "Start");
    lv_obj_remove_style_all(label1);
    lv_obj_set_style_text_color(label1,lv_color_hex(0x6ccb65),0);
    lv_obj_set_style_text_font(label1, &lv_font_montserrat_14, 0);
    lv_obj_center(label1);
    ui.ctl_label = label1;

    lv_obj_t *label2 = lv_label_create(ui.reset_btn);
    lv_label_set_text(label2, "Reset");
    lv_obj_remove_style_all(label2);
    lv_obj_set_style_text_color(label2,lv_color_hex(0x9b9a9f),0);
    lv_obj_set_style_text_font(label2, &lv_font_montserrat_14, 0);
    lv_obj_center(label2);
    ui.reset_label = label2;
}

lv_obj_t* StopWatchView::Btn_Create(lv_obj_t* par,lv_coord_t x_ofs)
{
    lv_obj_t *btn = lv_btn_create(par);

    lv_obj_remove_style_all(btn);
    lv_obj_set_style_border_width(btn, 3, 0);
    lv_obj_set_style_border_color(btn, lv_color_black(), 0);
    lv_obj_set_style_outline_width(btn, 2,0);

    if (x_ofs > 0) {
        lv_obj_set_style_bg_color(btn, lv_color_hex(0x112913), 0);
        lv_obj_set_style_outline_color(btn, lv_color_hex(0x112913), 0);
        lv_obj_set_style_bg_color(btn, lv_color_hex(0x081609), LV_STATE_FOCUSED);
        lv_obj_set_style_outline_color(btn, lv_color_hex(0x081609), LV_STATE_FOCUSED);
    }
    else {
        lv_obj_set_style_outline_color(btn, lv_color_hex(0x1c1c1c), 0);
        lv_obj_set_style_bg_color(btn, lv_color_hex(0x1c1c1c), 0);
        lv_obj_set_style_bg_color(btn, lv_color_hex(0x0f0f0f), LV_STATE_FOCUSED);
        lv_obj_set_style_outline_color(btn, lv_color_hex(0x0f0f0f), LV_STATE_FOCUSED);
    }
    lv_obj_set_style_bg_opa(btn, LV_OPA_COVER, 0);
    // 设置按钮的样式，使其成为一个圆形按钮
    lv_obj_set_style_radius(btn, LV_RADIUS_CIRCLE, 0);

    lv_obj_set_size(btn, 70, 70);  // 设置按钮的宽度和高度

    lv_obj_align(btn, LV_ALIGN_CENTER, x_ofs, 80);

    return btn;

}
void StopWatchView::Create(lv_obj_t *root)
{
    lv_obj_remove_style_all(root);
    lv_obj_set_size(root, LV_HOR_RES, LV_VER_RES);
    lv_obj_set_style_bg_color(root, lv_color_black(), 0);
	lv_obj_set_style_bg_opa(root, LV_OPA_COVER, 0);

    TopInfo_Create(root);

    ui.group = lv_group_create();
    lv_indev_set_group(lv_get_indev(LV_INDEV_TYPE_ENCODER), ui.group);
    lv_group_add_obj(ui.group, ui.ctl_btn);
    lv_group_add_obj(ui.group, ui.reset_btn);
    lv_group_focus_obj(ui.ctl_btn);

}

void StopWatchView::Delete()
{
    lv_indev_set_group(lv_get_indev(LV_INDEV_TYPE_ENCODER), NULL);
    lv_obj_del(ui.cont);
    if(ui.group)
    {
        lv_group_del(ui.group);
        ui.group = nullptr;
    }
}