// This #include statement was automatically added by the Particle IDE.
#include <JsonParserGeneratorRK.h>

// This #include statement was automatically added by the Particle IDE.
#include <Grove_Temperature_And_Humidity_Sensor.h>

#define DHT_PIN D3

DHT dht(DHT_PIN);

double temp;
double hum;

void upload(double temp, double hum)
{
    JsonWriterStatic<256> jw;
    {
        JsonWriterAutoObject obj (&jw);
        jw.insertKeyValue("temp",temp);
        jw.insertKeyValue("hum",hum);
    }
    Particle.publish("dht11", jw.getBuffer(), PRIVATE);
}    

void setup() 
{
    dht.begin();
    pinMode(DHT_PIN,INPUT);
}

void loop() 
{
    temp = dht.getTempCelcius();
    hum = dht.getHumidity();
    upload(temp, hum);
    delay(20000);
}