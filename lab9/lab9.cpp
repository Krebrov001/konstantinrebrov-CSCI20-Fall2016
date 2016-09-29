/* Created By: Konstanatin Rebrov
 * Created On: 9/28/2016
 * This program will create the Temperature Converter Class
 */
 
 #include <iostream>
 using namespace std;
 
class TemperatureConverter 
{
    public:
        TemperatureConverter()
        {
            kelvin_ = 0;
        }
       TemperatureConverter(int a)
        {
            kelvin_ = a;
        }
        void SetTempFromKelvin(double temp) {
            kelvin_ = temp;
        }
        double GetTempFromKelvin() {
            return kelvin_;
        }
        void SetTempFromCelsius(double temp) {
            kelvin_ = temp + 273.15;
        }
        void SetTempFromFahrenheit(double temp) {
            kelvin_ = (5.0 * (temp - 32.0) / 9.0) + 273.15;
        }
        double GetTempAsCelsius() {
            return kelvin_ - 273.15;
        }
        double GetTempAsFahrenheit() {
            return ((GetTempAsCelsius() * 9.0) / 5.0 + 32.0);
        }
        void PrintTemperatures() {
            cout << "Kelvin temperature: " << GetTempFromKelvin() << endl;
            cout << "Celsius temperature: " << GetTempAsCelsius() << endl;
            cout << "Fahrenheit temperature: " << GetTempAsFahrenheit() << endl;
        }
    private:
        double kelvin_;
};