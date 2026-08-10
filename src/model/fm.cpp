#include "fueldispensermodel.h"
#include <cmath>
static constexpr double EPS = 0.0001;
FuelDispenserModel::FuelDispenserModel(QObject *parent) : QObject(parent) {}
void FuelDispenserModel::setCurrentVolume(double v){ if(std::isnan(v))return; if(qAbs(m_currentVolume-v)<EPS)return; v=qBound(0.0,v,9999.99); m_currentVolume=v; emit currentVolumeChanged(); }
void FuelDispenserModel::setTotalCost(double v){ if(std::isnan(v))return; if(qAbs(m_totalCost-v)<EPS)return; v=qBound(0.0,v,99999.99); m_totalCost=v; emit totalCostChanged(); }
void FuelDispenserModel::setPricePerLiter(double v){ if(std::isnan(v))return; if(qAbs(m_pricePerLiter-v)<EPS)return; v=qBound(0.0,v,9999.99); m_pricePerLiter=v; emit pricePerLiterChanged(); }
void FuelDispenserModel::setSelectedGrade(int v){ if(v<-1||v>4)return; if(m_selectedGrade==v)return; m_selectedGrade=v; double p=0; switch(v){case Petrol:p=100;break;case E20:p=120;break;case E80:p=140;break;case Premium:p=140.06;break;case Diesel:p=180;break;default:p=0;break;} setPricePerLiter(p); emit selectedGradeChanged(); }
void FuelDispenserModel::setPresetAmount(double v){ if(std::isnan(v))return; if(qAbs(m_presetAmount-v)<EPS)return; v=qBound(0.0,v,99999.99); m_presetAmount=v; emit presetAmountChanged(); }
void FuelDispenserModel::setTargetVolume(double v){ if(std::isnan(v))return; if(qAbs(m_targetVolume-v)<EPS)return; v=qBound(0.0,v,9999.99); m_targetVolume=v; emit targetVolumeChanged(); }
void FuelDispenserModel::setSimulatedFuelIndex(int v){ if(m_simulatedFuelIndex==v)return; m_simulatedFuelIndex=v; emit simulatedFuelIndexChanged(); }
void FuelDispenserModel::setSimulatedKeypadIndex(int v){ if(m_simulatedKeypadIndex==v)return; m_simulatedKeypadIndex=v; emit simulatedKeypadIndexChanged(); }