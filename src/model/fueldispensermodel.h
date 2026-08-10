#ifndef FUELDISPENSERMODEL_H
#define FUELDISPENSERMODEL_H

#include <QObject>
#include <QtMath>

class FuelDispenserModel : public QObject
{
    Q_OBJECT
    
    Q_PROPERTY(double currentVolume READ currentVolume WRITE setCurrentVolume NOTIFY currentVolumeChanged)
    Q_PROPERTY(double totalCost READ totalCost WRITE setTotalCost NOTIFY totalCostChanged)
    Q_PROPERTY(double pricePerLiter READ pricePerLiter WRITE setPricePerLiter NOTIFY pricePerLiterChanged)
    Q_PROPERTY(int selectedGrade READ selectedGrade WRITE setSelectedGrade NOTIFY selectedGradeChanged)
    Q_PROPERTY(double presetAmount READ presetAmount WRITE setPresetAmount NOTIFY presetAmountChanged)
    Q_PROPERTY(double targetVolume READ targetVolume WRITE setTargetVolume NOTIFY targetVolumeChanged)
    
    Q_PROPERTY(int simulatedFuelIndex READ simulatedFuelIndex WRITE setSimulatedFuelIndex NOTIFY simulatedFuelIndexChanged)
    Q_PROPERTY(int simulatedKeypadIndex READ simulatedKeypadIndex WRITE setSimulatedKeypadIndex NOTIFY simulatedKeypadIndexChanged)

public:
    explicit FuelDispenserModel(QObject *parent = nullptr);

    enum FuelGrade { None = -1, Petrol = 0, E20, E80, Premium, Diesel };
    Q_ENUM(FuelGrade)

    double currentVolume() const { return m_currentVolume; }
    double totalCost() const { return m_totalCost; }
    double pricePerLiter() const { return m_pricePerLiter; }
    int selectedGrade() const { return m_selectedGrade; }
    double presetAmount() const { return m_presetAmount; }
    double targetVolume() const { return m_targetVolume; }
    int simulatedFuelIndex() const { return m_simulatedFuelIndex; }
    int simulatedKeypadIndex() const { return m_simulatedKeypadIndex; }

    void setCurrentVolume(double val);
    void setTotalCost(double val);
    void setPricePerLiter(double val);
    void setSelectedGrade(int val);
    void setPresetAmount(double val);
    void setTargetVolume(double val);
    void setSimulatedFuelIndex(int val);
    void setSimulatedKeypadIndex(int val);

signals:
    void currentVolumeChanged();
    void totalCostChanged();
    void pricePerLiterChanged();
    void selectedGradeChanged();
    void presetAmountChanged();
    void targetVolumeChanged();
    void simulatedFuelIndexChanged();
    void simulatedKeypadIndexChanged();

private:
    double m_currentVolume = 0.0;
    double m_totalCost = 0.0;
    double m_pricePerLiter = 0.0;
    int m_selectedGrade = -1;
    double m_presetAmount = 0.0;
    double m_targetVolume = 0.0;
    int m_simulatedFuelIndex = -1; 
    int m_simulatedKeypadIndex = -1;
};
#endif