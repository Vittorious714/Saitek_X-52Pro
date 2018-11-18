#include "USBHost_t36.h"
#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include "Wire.h"
#include "RH_ASK.h"

#define TFT_DC 9
#define TFT_CS 10

#define COUNT_JOYSTICKS 1
#define CNT_DEVICES (sizeof(drivers)/sizeof(drivers[0]))

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
RH_ASK driver;

USBHost myusb_0;
USBHost myusb_1;

USBHub hub0(myusb_0);
USBHub hub1(myusb_1);

USBHIDParser hid0(myusb_0);
USBHIDParser hid1(myusb_1);


JoystickController joystick1[COUNT_JOYSTICKS](myusb_0);
MouseController mouse1(myusb_1);

USBDriver *drivers[] = {&hub0, &joystick1[0]};

int user_axis[64];
uint32_t buttons_prev = 0;
const char * driver_names[CNT_DEVICES] = {"Hub0", "joystick1[0D]"};
bool driver_active[CNT_DEVICES] = {false};
uint64_t joystick_full_notify_mask = (uint64_t) - 1;
const int numButtons = 16;

 



void setup()
{

  
  myusb_0.begin();
  if (!driver.init())
  tft.println("Radio init failed");
  
  
  tft.begin();
  tft.fillScreen(ILI9341_BLACK);
  tft.setTextSize(1.5);
  tft.setRotation(1);
  delay(2000);
  
  
}



void loop()
{
  myusb_0.Task();
  tft.setCursor(05,05);
  tft.println("");

 
  uint64_t axis_00 = joystick1[0].getAxis(0);
  uint64_t axis_01 = joystick1[0].getAxis(1);
  uint64_t axis_02 = joystick1[0].getAxis(2);
  uint64_t axis_03 = joystick1[0].getAxis(3);
  uint64_t axis_04 = joystick1[0].getAxis(4);
  uint64_t axis_05 = joystick1[0].getAxis(5);
  uint64_t axis_06 = joystick1[0].getAxis(6);


 
  int roll_axis = axis_00;
  int pitch_axis = axis_01;
  int throttle_axis = axis_02;
  int flaps_axis = axis_03;
  int zoom_axis = axis_04;
  int yaw_axis = axis_05;
  int brakes_axis = axis_06;
  
  
  tft.setTextSize(2);
  tft.setTextColor(ILI9341_GREEN, ILI9341_BLACK);
  tft.println(" Joystick Inputs");
  tft.println("");
  
  tft.setTextSize(1);
  tft.setTextColor(ILI9341_CYAN, ILI9341_BLACK);
  tft.print(" Roll Input     ");
  tft.setTextColor(ILI9341_WHITE, ILI9341_BLACK);
  tft.print(roll_axis);
  tft.println("   ");
  tft.setTextColor(ILI9341_CYAN, ILI9341_BLACK);
  tft.print(" Pitch Input    ");
  tft.setTextColor(ILI9341_WHITE, ILI9341_BLACK);
  tft.print(pitch_axis);
  tft.println("   ");
  tft.setTextColor(ILI9341_CYAN, ILI9341_BLACK);
  tft.print(" Throttle Input ");
  tft.setTextColor(ILI9341_WHITE, ILI9341_BLACK);
  tft.print(throttle_axis);
  tft.println("   ");
  tft.setTextColor(ILI9341_CYAN, ILI9341_BLACK);
  tft.print(" Flaps Input    ");
  tft.setTextColor(ILI9341_WHITE, ILI9341_BLACK);
  tft.print(flaps_axis);
  tft.println("   ");
  tft.setTextColor(ILI9341_CYAN, ILI9341_BLACK);
  tft.print(" Zoom Input     ");
  tft.setTextColor(ILI9341_WHITE, ILI9341_BLACK);
  tft.print(zoom_axis);
  tft.println("   ");
  tft.setTextColor(ILI9341_CYAN, ILI9341_BLACK);
  tft.print(" Yaw Input      ");
  tft.setTextColor(ILI9341_WHITE, ILI9341_BLACK);
  tft.print(yaw_axis);
  tft.println("   ");
  tft.setTextColor(ILI9341_CYAN, ILI9341_BLACK);
  tft.print(" Brakes Input   ");
  tft.setTextColor(ILI9341_WHITE, ILI9341_BLACK);
  tft.println(brakes_axis);



 uint32_t buttonpress = joystick1[0].getButtons();
 uint32_t btn_01 = (buttonpress & 1);
 uint32_t btn_02 = (buttonpress & 2);
 uint32_t btn_03 = (buttonpress & 4);
 uint32_t btn_04 = (buttonpress & 8);
 uint32_t btn_05 = (buttonpress & 16);
 uint32_t btn_06 = (buttonpress & 32);
 uint32_t btn_07 = (buttonpress & 64);
 uint32_t btn_08 = (buttonpress & 128);
 uint32_t btn_09 = (buttonpress & 256);
 uint32_t btn_10 = (buttonpress & 512);
 uint32_t btn_11 = (buttonpress & 1024);
 uint32_t btn_12 = (buttonpress & 2048);
 uint32_t btn_13 = (buttonpress & 4096);
 uint32_t btn_14 = (buttonpress & 8192);
 uint32_t btn_15 = (buttonpress & 16384);
 uint32_t btn_16 = (buttonpress & 32768); 
 uint32_t btn_17 = (buttonpress & 65536);
 uint32_t btn_18 = (buttonpress & 131072);
 uint32_t btn_19 = (buttonpress & 262144);    
 uint32_t btn_20 = (buttonpress & 524288);
 uint32_t btn_21 = (buttonpress & 1048576);
 uint32_t btn_22 = (buttonpress & 2097152);     
 uint32_t btn_23 = (buttonpress & 4194304); 
 uint32_t btn_24 = (buttonpress & 8388608);
 uint32_t btn_25 = (buttonpress & 16777216);
 uint32_t btn_26 = (buttonpress & 33554432);
 uint32_t btn_27 = (buttonpress & 67108864);
 uint32_t btn_28 = (buttonpress & 134217728);
 uint32_t btn_29 = (buttonpress & 268435456);
 uint32_t btn_30 = (buttonpress & 536870912);
 uint32_t btn_31 = (buttonpress & 1073741824);
 uint32_t btn_32 = (buttonpress & 2147483648);


 
 bool btnval_01 = btn_01 == 1;
 bool btnval_02 = btn_02 == 2;
 bool btnval_03 = btn_03 == 4;
 bool btnval_04 = btn_04 == 8;
 bool btnval_05 = btn_05 == 16;
 bool btnval_06 = btn_06 == 32;
 bool btnval_07 = btn_07 == 64;
 bool btnval_08 = btn_08 == 128;
 bool btnval_09 = btn_09 == 256;
 bool btnval_10 = btn_10 == 512;
 bool btnval_11 = btn_11 == 1024;
 bool btnval_12 = btn_12 == 2048;
 bool btnval_13 = btn_13 == 4096;
 bool btnval_14 = btn_14 == 8192;
 bool btnval_15 = btn_15 == 16384;
 bool btnval_16 = btn_16 == 32768;
 bool btnval_17 = btn_17 == 65536;
 bool btnval_18 = btn_18 == 131072;
 bool btnval_19 = btn_19 == 262144;
 bool btnval_20 = btn_20 == 524288;
 bool btnval_21 = btn_21 == 1048576;
 bool btnval_22 = btn_22 == 2097152;
 bool btnval_23 = btn_23 == 4194304;
 bool btnval_24 = btn_24 == 8388608;
 bool btnval_25 = btn_25 == 16777216;
 bool btnval_26 = btn_26 == 33554432;
 bool btnval_27 = btn_27 == 67108864;
 bool btnval_28 = btn_28 == 134217728;
 bool btnval_29 = btn_29 == 268435456;
 bool btnval_30 = btn_30 == 536870912;
 bool btnval_31 = btn_31 == 1073741824;
 bool btnval_32 = btn_32 == 2147483648;

 
 tft.setTextSize(1.5);
 tft.print(btnval_01); tft.print("  "); tft.print(btnval_17); tft.println("  ");
 tft.print(btnval_02); tft.print("  "); tft.print(btnval_18); tft.println("  ");
 tft.print(btnval_03); tft.print("  "); tft.print(btnval_19); tft.println("  ");
 tft.print(btnval_04); tft.print("  "); tft.print(btnval_20); tft.println("  ");
 tft.print(btnval_05); tft.print("  "); tft.print(btnval_21); tft.println("  ");
 tft.print(btnval_06); tft.print("  "); tft.print(btnval_22); tft.println("  ");
 tft.print(btnval_07); tft.print("  "); tft.print(btnval_23); tft.println("  ");
 tft.print(btnval_08); tft.print("  "); tft.print(btnval_24); tft.println("  ");
 tft.print(btnval_09); tft.print("  "); tft.print(btnval_25); tft.println("  ");
 tft.print(btnval_10); tft.print("  "); tft.print(btnval_26); tft.println("  ");
 tft.print(btnval_11); tft.print("  "); tft.print(btnval_27); tft.println("  ");
 tft.print(btnval_12); tft.print("  "); tft.print(btnval_28); tft.println("  ");
 tft.print(btnval_13); tft.print("  "); tft.print(btnval_29); tft.println("  ");
 tft.print(btnval_14); tft.print("  "); tft.print(btnval_30); tft.println("  ");
 tft.print(btnval_15); tft.print("  "); tft.print(btnval_31); tft.println("  ");
 tft.print(btnval_16); tft.print("  "); tft.print(btnval_32); tft.println("  ");
 

}
