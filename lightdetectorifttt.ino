int phototransistor = A0;
int analog_value;
int light_threshold = 40;
bool sunlight;
bool sunlight_old;

void setup() {
}

void loop() {
    
    analog_value = analogRead(phototransistor);
    
    if (analog_value >= light_threshold)
    {
        sunlight = true;
    } 
    else 
    {
        sunlight = false;
    }
    
    if(sunlight != sunlight_old)
    {
        Particle.publish("sunlight", String(sunlight), PRIVATE);
        sunlight_old = sunlight;
    }

    delay(10000);
}
