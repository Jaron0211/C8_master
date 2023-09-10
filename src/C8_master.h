/*
  Author: Jian Lun, Lee
  Date: 2023/09/10
  Version: 1.0.0
  Platform: ESP32-AIOT AirBox

  CAUTION:
  THIS CODE IS ONLY FOR TEST PURPOSE, DON'T USE IN COMMERCIAL.
*/

#ifndef C8_CO2
#define C8_CO2

#ifndef SoftwareSerial_h
#include <SoftwareSerial.h>
#endif


class C8_master {
  public:
    C8_master(int _com_port_tx, int _com_port_rx, int _timeout): com_port_tx(_com_port_tx), com_port_rx(_com_port_rx), timeout(_timeout)
    {
    };
    ~C8_master();

    uint16_t CRC16(uint8_t *dataarray, uint16_t datalen);

    void init(int baudrate);

    float ReadCO2();
    float ActiveReadCO2();

    int send_command[5] = {0x64, 0x69, 0x03, 0x5E, 0x4E};

  private:

    SoftwareSerial *C8_Serial;
    int com_port_tx ;
    int com_port_rx ;
    int timeout = 1000;
    unsigned long timer;
    
};
#endif