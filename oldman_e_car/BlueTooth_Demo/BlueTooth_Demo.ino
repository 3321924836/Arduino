/*
  测试通信之前首先要了解一下通信的流程
  PC电脑连接单片机，单片机连接蓝牙模块
  在电脑上用串口发送AT指令到单片机
  单片机接收到指令后通过数字口9发送指令到蓝牙模块的RX端
  蓝牙模块接收指令后通过TX发送给单片机数字口8
  单片机通过数字口8接收指令后再通过usb线输出到pc电脑
  【连线】
  数字口8----TXD
  数字口9----RXD
  VCC-----VCC
  GND-----GND
 */
    #include <SoftwareSerial.h>
    SoftwareSerial BluetoothSerial(A9, A10); // RX, TX
    char value;       //用于中转数据
    void setup() {
        //打开串行通信，等待端口打开：
        Serial.begin(9600);
        while (!Serial) {
            ; // 等待串口连接。
        }
        Serial.println("Serial Connected!");

        // 设置蓝牙串口通讯的速率 HC06默认是9600
        BluetoothSerial.begin(9600);
    }

    void loop() { // 循环
        if (Serial.available()) {   //检测单片机串口状态
            value = Serial.read();
            BluetoothSerial.write(value);//蓝牙模块将数据发送给单片机
        }

        if (BluetoothSerial.available()) {//检测蓝牙模块串口状态
            value = BluetoothSerial.read();
            Serial.write(value); //单片机将指令发送到蓝牙模块
        }

    }
