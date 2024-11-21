#include <Arduino.h>
#include <IRremote.h>
#include <BleKeyboard.h>
#define IR_RECEIVER_PIN GPIO_NUM_23

BleKeyboard Ble_Keyboard("TEST_Board", "Espressif", 100); //编辑信息（蓝牙名称，设备制造商，电池电量）

void setup(){
  pinMode(IR_RECEIVER_PIN,INPUT);
  IrReceiver.begin(IR_RECEIVER_PIN);
  // Serial.begin(9600);
  Ble_Keyboard.begin();
}

void loop(){

  if (IrReceiver.decode()){
    // Serial.println(IrReceiver.decodedIRData.decodedRawData);


  if(Ble_Keyboard.isConnected()) { 
    if (IrReceiver.decodedIRData.decodedRawData == 3125149440)
    {
      Ble_Keyboard.print("e");
    }
  }
    IrReceiver.resume();
  }
}