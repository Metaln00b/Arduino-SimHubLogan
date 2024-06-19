#include <stdio.h>
#include <mcp_can.h>
#include <SPI.h>

MCP_CAN CAN0(10); // Set CS Pin

#define BUF_SIZE                    64

#define ENGINE_SPEED_FACTOR         35.5

char simhub_message_buf[BUF_SIZE];

void splitBytes(uint16_t num, uint8_t *lowByte, uint8_t *highByte) {
    *lowByte = (uint8_t)(num & 0xFF);
    *highByte = (uint8_t)((num >> 8) & 0xFF);
}

void setup() {
    Serial.begin(115200);
    SPI.begin();

    if (CAN0.begin(MCP_ANY, CAN_500KBPS, MCP_8MHZ) == CAN_OK)
    {
        Serial.println("MCP2515 Initialized Successfully!");
        delay(1000);
    }
    else
    {
        Serial.println("Error Initializing MCP2515...");
        delay(2000);
        setup();
    }
    CAN0.setMode(MCP_NORMAL);

    memset(simhub_message_buf, 0x0, BUF_SIZE);
}

void process_message() {
    unsigned int revs;
    unsigned int speed_kmh;
    unsigned int fuel_percent;
    int water_temperature_degC;
    int turn_left;
    int turn_right;
    int brake;
    int oil_temperature_degC;
    
    sscanf(simhub_message_buf, "%u&%u&%u&%d&%d&%d&%d&%d",
        &revs,
        &speed_kmh,
        &fuel_percent,
        &water_temperature_degC,
        &turn_left,
        &turn_right,
        &brake,
        &oil_temperature_degC
    );

    uint8_t light_state = 0b00000100;

    if (turn_left == 1)
    {
        light_state = light_state | 0b00100000;
    }
    if (turn_right == 1)
    {
        light_state = light_state | 0b01000000;
    }

    uint8_t data5de[4] = {light_state, 0x00, 0x00, 0x00};
    

    uint8_t calculated_revs = revs / ENGINE_SPEED_FACTOR;
    uint8_t calculated_speed = 0.61 * speed_kmh + 8.47;

    uint8_t data350[8] = {0b11001000, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    uint8_t data217[4] = {0x00, 0x00, 0x00, calculated_speed};
    uint8_t data186[1] = {calculated_revs};

    CAN0.sendMsgBuf(0x350, 0, 8, data350);
    CAN0.sendMsgBuf(0x186, 0, 1, data186);
    CAN0.sendMsgBuf(0x217, 0, 4, data217);
    CAN0.sendMsgBuf(0x5de, 0, 4, data5de);
}

void loop() {
    if (Serial.available() > 0)
    {
        Serial.readBytesUntil('{', simhub_message_buf, BUF_SIZE);
        int readCount = Serial.readBytesUntil('}', simhub_message_buf, BUF_SIZE);
        simhub_message_buf[min(readCount, BUF_SIZE - 1)] = 0x0;
        process_message();
        memset(simhub_message_buf, 0x0, BUF_SIZE);
    }
    
    delay(50);
}