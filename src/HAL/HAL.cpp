#include "HAL/HAL.h"
#include "App/Configs/Version.h"

#define DISP_HOR_RES         CONFIG_SCREEN_HOR_RES
#define DISP_VER_RES         CONFIG_SCREEN_VER_RES
#define DISP_BUF_SIZE        CONFIG_SCREEN_BUFFER_SIZE
extern lv_color_t* lv_disp_buf_p;

void HAL::Init()
{
    Serial.begin(115200);
    Serial.println(VERSION_FIRMWARE_NAME);
    Serial.println("Version: " VERSION_SOFTWARE);
    Serial.println("Author: " VERSION_AUTHOR_NAME);

    // Move the malloc process to Init() to make sure that the largest heap can be used for this buffer.
    lv_disp_buf_p = static_cast<lv_color_t*>(malloc(DISP_BUF_SIZE * sizeof(lv_color_t)));
    if (lv_disp_buf_p == nullptr)
        LV_LOG_WARN("lv_port_disp_init malloc failed!\n");

    // HAL::BT_Init(); // ToDo: some of the process below will interrupt BLE connection, find it out
    HAL::Power_Init();
    HAL::Backlight_Init();
    HAL::Encoder_Init();
    HAL::Buzz_init();
    HAL::Audio_Init();
    HAL::SD_Init();
    HAL::I2C_Init(true);
    HAL::IMU_Init();

    HAL::Touch_Init();

    HAL::Audio_PlayMusic("Startup");
}

void HAL::Update()
{
    HAL::Power_Update();
    HAL::Encoder_Update();
    HAL::Audio_Update();
    HAL::IMU_Update();
    // HAL::BT_Update();
    __IntervalExecute(HAL::SD_Update(), 500);
}
// xtensa-esp32-elf-addr2line -pfiaC -e firmware.elf ADDRESS 0x40110234:0x3ffd4270 0x4011027b:0x3ffd4290 0x40110457:0x3ffd42b0 0x401105bf:0x3ffd4300 0x401108f9:0x3ffd4320 0x40110c79:0x3ffd43a0 0x401020ba:0x3ffd91a0 0x401021e6:0x3ffd9200 0x40118789:0x3ffd9230 0x40102a15:0x3ffd9270 0x40104005:0x3ffd9290 0x401041d9:0x3ffd92b0 0x40104005:0x3ffd92d0 0x4010403a:0x3ffd92f0 0x40100e2b:0x3ffd9400 0x40100f83:0x3ffd9430 0x401003d7:0x3ffd9470 0x400e5ff4:0x3ffd94e0 0x400e927a:0x3ffd9530 0x400d8438:0x3ffd9560