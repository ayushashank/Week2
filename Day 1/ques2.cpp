#include <iostream>
using namespace std;

class Inverter
{
private:
    int current;
    int voltage;

public:
    Inverter()
    {
        current = 0;
        voltage = 0;
    }
    Inverter(int current, int voltage)
    {
        this->current = current;
        this->voltage = voltage;
    }
    void setCurrent(int currents)
    {
        this->current = current;
    }
    int getCurrent()
    {
        return this->current;
    }
    void setVoltage(int voltage)
    {
        this->voltage = voltage;
    }
    int getVoltage()
    {
        return this->voltage;
    }
    int getPower()
    {
        return (this->current * this->voltage);
    }
};
class SolarPanels
{
private:
    int numOfPanels;

public:
    SolarPanels()
    {
        this->numOfPanels = 0;
    }
    SolarPanels(int panels)
    {
        this->numOfPanels = panels;
    }
    void setNumOfPanels(int panels)
    {
        this->numOfPanels = panels;
    }
    int getNumOfPanels()
    {
        return this->numOfPanels;
    }
};
class NonSolarInverters
{
private:
    int numOfBatteries;

public:
    NonSolarInverters()
    {
        this->numOfBatteries = 0;
    }
    NonSolarInverters(int batteries)
    {
        numOfBatteries = batteries;
    }
    void setNumOfBatteries(int batteries)
    {
        this->numOfBatteries = batteries;
    }
    int getNumOfBatteries()
    {
        return this->numOfBatteries;
    }
};
class PCU : public Inverter, public SolarPanels
{
private:
    int numOfBatteries;

public:
    PCU() : Inverter() {}
    PCU(int current, int voltage, int batteries) : Inverter(current, voltage)
    {
        this->numOfBatteries = batteries;
    }
    void setNumOfBatteries(int batteries)
    {
        this->numOfBatteries = batteries;
    }
    int getNumOfBatteries()
    {
        return this->numOfBatteries;
    }
};
class GTI : public Inverter
{
private:
    bool gridOn;
};
class Zelio : public Inverter
{
};
class Regalia : public Inverter
{
private:
    SolarPanels solarpanel;

public:
    Regalia() : Inverter(){};
    Regalia(int current, int voltage) : Inverter(current, voltage){};

    void setSolapanels(SolarPanels solarPanel)
    {
        this->solarpanel = solarpanel;
    }
    SolarPanels getSolarPanel()
    {
        return this->solarpanel;
    }
};
class ICruze : public Inverter, public NonSolarInverters
{
public:
    ICruze() : Inverter(), NonSolarInverters() {}
    ICruze(int current, int voltage, int batteries) : Inverter(current, voltage), NonSolarInverters(batteries) {}
};

int main()
{
    return 0;
}