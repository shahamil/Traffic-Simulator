#ifndef TrafficLight_HEADER
#define TrafficLight_HEADER
class TrafficLight{

public:
	TrafficLight(int, int, int, char);
	//create default
	~TrafficLight();
	bool getStateRed();
	bool getStateYellow();
	bool getStateGreen();
	void setTimerCount(int);
	int getTimerCount() const;
	void setLightPos(int, int, int, int, int, int);
	void printLight();
	void setLightCycleDuration(int, int, int);
	void turnGreen();
	void turnRed();
	void turnYellow();
	char getDirection();
	int getTotalTime();
	int getGreenTime();
	int getYellowTime();
	int getRedTime();
	//create sometype of collision checker

private:
	//holds the current state of the traffic light
	bool redLight;
	bool yellowLight;
	bool greenLight;
	int timer;
	
	//coordinates
	int x, y; //green
	int a, b; // yellow
	int g, h; //red
	
	//variable to keep track of the timer
	//timer specified by the user
	//duration of each light
	int greenTime;
	int redTime;
	int yellowTime;
	
	//direction for either going vertical or horizontal
	char dir;
	int totalTime;



};

#endif