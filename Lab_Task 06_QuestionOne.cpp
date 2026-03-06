#include <iostream>
using namespace std;

class WeatherStats
{
	public:
		static double calculateAverageTemperature(const double temps[], int size)	
		{
			if (size == 0)
				return 0;
			
			double sum = 0;
			for (int i = 0; i < size; i++)
			{
				sum += temps[i];
			}
			
			return sum / size;
		}
		
		static double getTemperatureFluctuation(const double temps[], int size)
		{
			if (size == 0) return 0;
			
			double maxTemp = temps[0];
			double minTemp = temps[0];
			
			for (int i = 1; i < size; i++)
			{
				if (temps[i] > maxTemp)
				{
					maxTemp = temps[i];
				}
				else if (temps[i] < minTemp)
				{
					minTemp = temps[i];
				}
				
			}
			
			return maxTemp - minTemp;
		}
};

int main()
{
	double temperatures[] = {25.5, 31.6, 28.1, 32.1};
	int size = 4;
	
	double avg = WeatherStats::calculateAverageTemperature(temperatures, size);
	double fluctuation = WeatherStats::getTemperatureFluctuation(temperatures, size);
	
	cout << "Average: " << avg << endl;
	cout << "Fluctuation: " << fluctuation << endl;
	
	return 0;
}