#include "MainPageView.h"
#include <stdarg.h>
#include <stdio.h>
using namespace Page;

static void _ui_anim_callback_set_opacity(lv_obj_t* obj, int32_t v)
{
   lv_obj_set_style_opa(obj, v, 0);
}

void ctl_appear_Animation( lv_obj_t *TargetObject, int delay)
{
	lv_anim_t PropertyAnimation_0;
	lv_anim_init(&PropertyAnimation_0);
	lv_anim_set_time(&PropertyAnimation_0, 500);
	lv_anim_set_var(&PropertyAnimation_0, TargetObject);
	lv_anim_set_exec_cb(&PropertyAnimation_0, (lv_anim_exec_xcb_t)_ui_anim_callback_set_opacity);
	lv_anim_set_values(&PropertyAnimation_0, 0, 255 );
	lv_anim_set_path_cb( &PropertyAnimation_0, lv_anim_path_linear);
	lv_anim_start(&PropertyAnimation_0);


	lv_anim_t PropertyAnimation_1;
	lv_anim_init(&PropertyAnimation_1);
	lv_anim_set_time(&PropertyAnimation_1, 500);
	lv_anim_set_var(&PropertyAnimation_1, TargetObject);
	lv_anim_set_exec_cb(&PropertyAnimation_1, (lv_anim_exec_xcb_t)lv_obj_set_y);
	lv_anim_set_values(&PropertyAnimation_1, -200, -90 );
	lv_anim_set_path_cb( &PropertyAnimation_1, lv_anim_path_linear);
	lv_anim_start(&PropertyAnimation_1);

}
void ctl_disppear_Animation( lv_obj_t *TargetObject, int delay)
{

	lv_anim_t PropertyAnimation_0;
	lv_anim_init(&PropertyAnimation_0);
	lv_anim_set_time(&PropertyAnimation_0, 500);
	lv_anim_set_var(&PropertyAnimation_0, TargetObject);
	lv_anim_set_exec_cb(&PropertyAnimation_0, (lv_anim_exec_xcb_t)_ui_anim_callback_set_opacity);
	lv_anim_set_values(&PropertyAnimation_0, 255, 0);
	lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_ease_in);
	lv_anim_start(&PropertyAnimation_0);

	lv_anim_t PropertyAnimation_1;
	lv_anim_init(&PropertyAnimation_1);
	lv_anim_set_time(&PropertyAnimation_1, 500);
	lv_anim_set_var(&PropertyAnimation_1, TargetObject);
	lv_anim_set_exec_cb(&PropertyAnimation_1, (lv_anim_exec_xcb_t)lv_obj_set_y);
	lv_anim_set_values(&PropertyAnimation_1, -90, -200);
	lv_anim_set_path_cb(&PropertyAnimation_1, lv_anim_path_linear);
	lv_anim_start(&PropertyAnimation_1);

}

///////////////////// FUNCTIONS ////////////////////
void MainPageView::ui_event_Screen2( lv_event_t * e) {
	MainPageView* instance = (MainPageView*)lv_event_get_user_data(e);
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);

	if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_BOTTOM) {
		lv_indev_wait_release(lv_indev_get_act());
		ctl_appear_Animation(instance->ui.ui_Panel2, 0);
		instance->notice = true;
	}
	if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_TOP) {

		lv_indev_wait_release(lv_indev_get_act());
		ctl_disppear_Animation(instance->ui.ui_Panel2, 0);
		instance->notice = false;
	}
}

void MainPageView::Create(lv_obj_t* root)
{
	ui.cont = lv_obj_create(root);
	lv_obj_set_size(ui.cont, 240, 320);
	lv_obj_clear_flag( ui.cont, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
	lv_obj_align(ui.cont, LV_ALIGN_TOP_MID, 0, 0);
	lv_obj_set_style_bg_color(ui.cont, lv_color_hex(0), LV_PART_MAIN | LV_STATE_DEFAULT );
	lv_obj_set_style_bg_opa(ui.cont, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src( ui.cont,Resource.GetImage("pikaq"), LV_PART_MAIN | LV_STATE_DEFAULT );
	lv_obj_set_style_bg_img_opa(ui.cont, 200, LV_PART_MAIN| LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_recolor(ui.cont, lv_color_hex(0xFBDA7B), LV_PART_MAIN| LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_recolor_opa(ui.cont, 60, LV_PART_MAIN| LV_STATE_DEFAULT);


	ui.ui_Panel1 = lv_obj_create(ui.cont);// 软件框
	lv_obj_set_size(ui.ui_Panel1, 236, 61);
	lv_obj_set_x( ui.ui_Panel1, 0 );
	lv_obj_set_y( ui.ui_Panel1, 122 );

	lv_obj_set_style_radius(ui.ui_Panel1, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui.ui_Panel1, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui.ui_Panel1, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui.ui_Panel1, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui.ui_Panel1, 5, LV_PART_MAIN | LV_STATE_DEFAULT);


	lv_obj_set_align( ui.ui_Panel1, LV_ALIGN_CENTER );
	lv_obj_set_flex_flow(ui.ui_Panel1,LV_FLEX_FLOW_ROW);
	lv_obj_set_flex_align(ui.ui_Panel1, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
	lv_obj_clear_flag( ui.ui_Panel1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
	lv_obj_set_style_bg_color(ui.ui_Panel1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
	lv_obj_set_style_bg_opa(ui.ui_Panel1, 125, LV_PART_MAIN| LV_STATE_DEFAULT);

	ui.ui_Image1 = lv_img_create(ui.ui_Panel1);// 秒表
	lv_img_set_src(ui.ui_Image1, Resource.GetImage("clock"));
	lv_obj_set_size(ui.ui_Image1, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
	lv_obj_add_flag( ui.ui_Image1, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
	lv_obj_clear_flag( ui.ui_Image1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

	ui.ui_Image2 = lv_img_create(ui.ui_Panel1);// 游戏
	lv_img_set_src(ui.ui_Image2, Resource.GetImage("game"));
	lv_obj_set_size(ui.ui_Image2, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
	lv_obj_add_flag( ui.ui_Image2, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
	lv_obj_clear_flag( ui.ui_Image2, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

	ui.ui_Image3 = lv_img_create(ui.ui_Panel1);// 系统信息
	lv_img_set_src(ui.ui_Image3, Resource.GetImage("setting"));
	lv_obj_set_size(ui.ui_Image3, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
	lv_obj_add_flag( ui.ui_Image3, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
	lv_obj_clear_flag( ui.ui_Image3, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

	ui.ui_Panel2 = lv_obj_create(ui.cont);// 下拉控制菜单
	lv_obj_set_size(ui.ui_Panel2, 236, 100);
	lv_obj_set_x( ui.ui_Panel2, 0 );
	lv_obj_set_y( ui.ui_Panel2, -200 );
	lv_obj_set_align( ui.ui_Panel2, LV_ALIGN_CENTER );
	lv_obj_clear_flag( ui.ui_Panel2, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
	lv_obj_set_style_radius(ui.ui_Panel2, 8, LV_PART_MAIN| LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui.ui_Panel2, lv_color_hex(0xA2A2A2), LV_PART_MAIN | LV_STATE_DEFAULT );
	lv_obj_set_style_bg_opa(ui.ui_Panel2, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

	ui.ui_Panel3 = lv_obj_create(ui.ui_Panel2);
	lv_obj_set_size(ui.ui_Panel3, 230, 40);
	lv_obj_set_x( ui.ui_Panel3, 0 );
	lv_obj_set_y( ui.ui_Panel3, -24 );
	lv_obj_set_align( ui.ui_Panel3, LV_ALIGN_CENTER );
	lv_obj_clear_flag( ui.ui_Panel3, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
	lv_obj_set_style_radius(ui.ui_Panel3, 10, LV_PART_MAIN| LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui.ui_Panel3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
	lv_obj_set_style_bg_opa(ui.ui_Panel3, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

	ui.ui_Image4 = lv_img_create(ui.ui_Panel3);
	lv_img_set_src(ui.ui_Image4, Resource.GetImage("sound"));
	lv_obj_set_size(ui.ui_Image4, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
	lv_obj_set_x( ui.ui_Image4, -90 );
	lv_obj_set_y( ui.ui_Image4, 0 );
	lv_obj_set_align( ui.ui_Image4, LV_ALIGN_CENTER );
	lv_obj_clear_flag( ui.ui_Image4, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
	lv_img_set_zoom(ui.ui_Image4,120);

	ui.ui_Switch1 = lv_switch_create(ui.ui_Panel3);
	lv_obj_set_size(ui.ui_Switch1, 45, 25);

	lv_obj_set_x( ui.ui_Switch1, 80 );
	lv_obj_set_y( ui.ui_Switch1, 0 );
	lv_obj_set_align( ui.ui_Switch1, LV_ALIGN_CENTER );
	lv_obj_add_state( ui.ui_Switch1, LV_STATE_CHECKED );     /// States

	lv_obj_set_style_radius(ui.ui_Switch1, 45, LV_PART_MAIN| LV_PART_INDICATOR| LV_STATE_DEFAULT);

	lv_obj_set_style_bg_color(ui.ui_Switch1, lv_color_hex(0x7F7F7F), LV_PART_MAIN|LV_PART_INDICATOR | LV_STATE_DEFAULT );
	lv_obj_set_style_bg_opa(ui.ui_Switch1, 255, LV_PART_MAIN|LV_PART_INDICATOR| LV_STATE_DEFAULT);

	lv_obj_set_style_bg_color(ui.ui_Switch1, lv_color_hex(0x349EF9), LV_PART_INDICATOR | LV_STATE_CHECKED );
	lv_obj_set_style_bg_opa(ui.ui_Switch1, 255, LV_PART_INDICATOR| LV_STATE_CHECKED);

	lv_obj_set_style_radius(ui.ui_Switch1, 20, LV_PART_KNOB| LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui.ui_Switch1, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT );
	lv_obj_set_style_bg_opa(ui.ui_Switch1, 255, LV_PART_KNOB| LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui.ui_Switch1, -3, LV_PART_KNOB| LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui.ui_Switch1, -3, LV_PART_KNOB| LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui.ui_Switch1, -3, LV_PART_KNOB| LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui.ui_Switch1, -3, LV_PART_KNOB| LV_STATE_DEFAULT);


	ui.ui_Panel4 = lv_obj_create(ui.ui_Panel2);
	lv_obj_set_width( ui.ui_Panel4, 230);
	lv_obj_set_height( ui.ui_Panel4, 40);
	lv_obj_set_x( ui.ui_Panel4, 0 );
	lv_obj_set_y( ui.ui_Panel4, 18 );
	lv_obj_set_align( ui.ui_Panel4, LV_ALIGN_CENTER );
	lv_obj_clear_flag( ui.ui_Panel4, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

	lv_obj_set_style_radius(ui.ui_Panel4, 10, LV_PART_MAIN| LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui.ui_Panel4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
	lv_obj_set_style_bg_opa(ui.ui_Panel4, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

	ui.ui_Image5 = lv_img_create(ui.ui_Panel4);
	lv_img_set_src(ui.ui_Image5, Resource.GetImage("light"));
	lv_obj_set_size(ui.ui_Image5, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
	lv_obj_set_x( ui.ui_Image5, -90 );
	lv_obj_set_y( ui.ui_Image5, 0 );
	lv_obj_set_align( ui.ui_Image5, LV_ALIGN_CENTER );
	lv_obj_clear_flag( ui.ui_Image5, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
	lv_img_set_zoom(ui.ui_Image5,120);

	ui.ui_Slider1 = lv_slider_create(ui.ui_Panel4);
	lv_slider_set_value(ui.ui_Slider1, 50, LV_ANIM_OFF);
	lv_obj_set_size(ui.ui_Slider1, 140, 10);
	lv_obj_set_x(ui.ui_Slider1, 30);
	lv_obj_set_y(ui.ui_Slider1, 0);
	lv_obj_set_align(ui.ui_Slider1, LV_ALIGN_CENTER);
	lv_obj_set_style_radius(ui.ui_Slider1, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui.ui_Slider1, lv_color_hex(0xD5EAFF), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui.ui_Slider1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

	lv_obj_set_style_radius(ui.ui_Slider1, 10, LV_PART_INDICATOR | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui.ui_Slider1, lv_color_hex(0x2095F6), LV_PART_INDICATOR | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui.ui_Slider1, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

	lv_obj_set_style_radius(ui.ui_Slider1, 10, LV_PART_KNOB | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui.ui_Slider1, lv_color_hex(0x2095F6), LV_PART_KNOB | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui.ui_Slider1, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui.ui_Slider1, 5, LV_PART_KNOB | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui.ui_Slider1, 5, LV_PART_KNOB | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui.ui_Slider1, 5, LV_PART_KNOB | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui.ui_Slider1, 5, LV_PART_KNOB | LV_STATE_DEFAULT);

	lv_obj_add_event_cb(lv_scr_act(), ui_event_Screen2, LV_EVENT_GESTURE, this);

	ui.group = lv_group_create();
    // lv_indev_set_group(lv_get_indev(LV_INDEV_TYPE_ENCODER), ui.group);

	lv_group_add_obj(ui.group, ui.ui_Image1);
	lv_group_add_obj(ui.group, ui.ui_Image2);
	lv_group_add_obj(ui.group, ui.ui_Image3);
	lv_group_focus_obj(ui.ui_Image2);
}


void MainPageView::Delete()
{
	if(ui.group != nullptr)
	{
		lv_group_del(ui.group);
		ui.group = nullptr;
	}
}