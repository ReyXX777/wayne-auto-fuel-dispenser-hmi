#ifndef DISPENSERCONTROLLER_H
#define DISPENSERCONTROLLER_H
#include <QObject>
#include <QTimer>
#include <QElapsedTimer>
#include <functional>
#include "../model/fueldispensermodel.h"
class DispenserController : public QObject
{
    Q_OBJECT
public:
    explicit DispenserController(QObject *parent = nullptr);
    void setModel(FuelDispenserModel* model);
    Q_INVOKABLE void startAutomatedDemo();
    Q_INVOKABLE void startDispensing();
private slots:
    void onSimulationTick();
private:
    FuelDispenserModel* m_model = nullptr;
    QTimer* m_timer = nullptr;
    QElapsedTimer m_elapsedTimer;
    double m_flowRate = 0.8;
    bool m_loop = false;
    int m_generation = 0; 
    enum State { Idle, Dispensing, Complete };
    State m_state = Idle;
    void simulateKeyPress(int index, int durationMs, std::function<void()> action);
};
#endif