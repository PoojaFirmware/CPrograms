// How can attributes be used to optimize memory usage in embedded systems? Write code for a structure and union that minimize memory waste.
// **Objective**: Explore the use of attributes for efficient memory management in embedded systems.

#include <stdio.h>
#include <stdint.h>

// define a packed structure to avoid padding 
struct __attribute__((packed)) Sensordata 
{
    uint8_t sensor_id; // 1 byte
    uint16_t temperature; // 2 bytes
    uint16_t humidity; // 2 bytes
    uint32_t pressure; // 4 bytes
};

// Define a union to overlay data and reduce memory usage
union SensorInfo
{
    struct Sensordata data; // Packed structure
    uint8_t raw_data[9];
};

int main()
{
    union SensorInfo sensor;

    sensor.data.sensor_id = 1;
    sensor.data.temperature = 250;
    sensor.data.humidity = 500;
    sensor.data.pressure = 1013325;

    printf("Sensor ID:%u\n", sensor.data.sensor_id);
    printf("Temperature:%.1fC\n", sensor.data.temperature / 10.0);
    printf("Humidity:%.1f%%\n", sensor.data.humidity / 10.0);
    printf("pressure:%u Pa\n", sensor.data.pressure);

    printf("raw data: ");
    for(int i = 0; i < sizeof(sensor.raw_data); i++)
    {
        printf("%02X", sensor.raw_data[i]);
    }
    printf("\n");

    return 0;
}
