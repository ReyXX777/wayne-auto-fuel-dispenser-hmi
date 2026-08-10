#ifndef DC_H
#define DC_H

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

    void setModel(FuelDispenserModel *model);

    Q_INVOKABLE void startAutomatedDemo();
    Q_INVOKABLE void startDispensing();

private slots:
    void onSimulationTick();

private:
    FuelDispenserModel *m_model{nullptr};
    QTimer *m_timer{nullptr};
    QElapsedTimer m_elapsedTimer{};
    double m_flowRate{0.8};
    bool m_loop{false};
    int m_generation{0};

    enum class State { Idle, Dispensing, Complete };
    State m_state{State::Idle};

    void simulateKeyPress(int index, int durationMs, const std::function<void()> &action);
};

#endif // DC_H
