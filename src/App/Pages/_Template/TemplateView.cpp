#include "TemplateView.h"

using namespace Page;

void TemplateView::Create(lv_obj_t* root)
{
	lv_obj_t* img = lv_img_create(root);
	lv_img_set_src(img, Resource.GetImage("girl"));
	lv_obj_center(img);
	ui.canvas = img;

	ui.group = lv_group_create();
	lv_indev_set_group(lv_get_indev(LV_INDEV_TYPE_ENCODER), ui.group);

	lv_group_add_obj(ui.group, ui.canvas);
	lv_group_focus_obj(ui.canvas);

}
