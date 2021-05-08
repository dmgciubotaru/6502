
#define DATA A0
#define SCLK A1
#define RCLK A2

void setData(uint8_t data)
{

	digitalWrite(RCLK, LOW);
	for (int i = 0; i < 8; i++)
	{
		digitalWrite(SCLK, LOW);
		digitalWrite(DATA, data&(1<<i));
		digitalWrite(SCLK, HIGH);
	}
	digitalWrite(RCLK, HIGH);
}



void setup() 
{
	pinMode(DATA, OUTPUT);
	pinMode(SCLK, OUTPUT);
	pinMode(RCLK, OUTPUT);
}

void loop()
{
	for (int i = 0; i < 0xFF; i++)
	{
		setData(i);
		delay(100);
	}

}
