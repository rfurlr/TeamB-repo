int tempSensor()
{

	int sensorPin = A0;
	int sensorValue = 0;
	int state = 0;
	sensorValue = analogRead(sensorPin);
	
	
	if(sensorValue > 155)
	{
		state = 2;
	}
	else if(sensorValue < 135)
	{
		state = 1;
	}
	else
	{
		state = 0;
	}
	
	return state;
}