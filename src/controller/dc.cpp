#include "dc.h"
#include <QDebug>
DispenserController::DispenserController(QObject *parent) : QObject(parent) {
    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &DispenserController::onSimulationTick);
}
void DispenserController::setModel(FuelDispenserModel *model){ m_model=model; }
void DispenserController::simulateKeyPress(int index, int durationMs, std::function<void()> action){
    if(!m_model) return;
    int gen = m_generation;
    bool isKeypad = index>=100;
    int realIndex = isKeypad?index-100:index;
    if(isKeypad) m_model->setSimulatedKeypadIndex(realIndex);
    else m_model->setSimulatedFuelIndex(realIndex);
    if(action) action();
    QTimer::singleShot(durationMs, this, [this,isKeypad,gen](){
        if(!m_model || gen!=m_generation) return;
        if(isKeypad) m_model->setSimulatedKeypadIndex(-1);
        else m_model->setSimulatedFuelIndex(-1);
    });
}
void DispenserController::startDispensing(){
    if(!m_model) return;
    if(m_model->pricePerLiter()<=0.001 || m_model->presetAmount()<=0.001) return;
    double target = m_model->presetAmount()/m_model->pricePerLiter();
    if(target<=0.001) return;
    qDebug() << "AUTO START" << target << "L";
    m_model->setTargetVolume(target);
    m_model->setCurrentVolume(0.0);
    m_model->setTotalCost(0.0);
    m_state=Dispensing;
    m_elapsedTimer.start();
    m_timer->start(16);
}
void DispenserController::startAutomatedDemo(){
    if(!m_model) return;
    m_generation++;
    int gen=m_generation;
    m_state=Idle; m_timer->stop();
    m_model->setCurrentVolume(0.0); m_model->setTotalCost(0.0);
    m_model->setPresetAmount(0.0); m_model->setTargetVolume(0.0);
    m_model->setSelectedGrade(FuelDispenserModel::None);
    qDebug() << "DEMO GEN" << gen;
    QTimer::singleShot(1000,this,[this,gen](){ if(gen!=m_generation)return; simulateKeyPress(3,400,[this](){ m_model->setSelectedGrade(FuelDispenserModel::Premium); }); });
    QTimer::singleShot(2500,this,[this,gen](){ if(gen!=m_generation)return; simulateKeyPress(104,200,[this](){ m_model->setPresetAmount(5.0); }); });
    QTimer::singleShot(3000,this,[this,gen](){ if(gen!=m_generation)return; simulateKeyPress(110,200,[this](){ m_model->setPresetAmount(50.0); }); });
    QTimer::singleShot(3500,this,[this,gen](){ if(gen!=m_generation)return; simulateKeyPress(110,200,[this](){ m_model->setPresetAmount(500.0); }); });
    QTimer::singleShot(4200,this,[this,gen](){ if(gen!=m_generation)return; simulateKeyPress(111,400,[this](){ startDispensing(); }); });
}
void DispenserController::onSimulationTick(){
    if(!m_model || m_state!=Dispensing){ m_timer->stop(); return; }
    double dt=m_elapsedTimer.restart()/1000.0; if(dt<=0||dt>0.2) dt=0.016;
    double cur=m_model->currentVolume(); double tgt=m_model->targetVolume();
    if(cur>=tgt-0.001){ m_model->setCurrentVolume(tgt); m_model->setTotalCost(tgt*m_model->pricePerLiter()); m_state=Complete; m_timer->stop(); qDebug()<<"COMPLETE"; if(m_loop) QTimer::singleShot(3000,this,[this](){ startAutomatedDemo(); }); return; }
    double nv=cur+(m_flowRate*dt); if(nv>tgt) nv=tgt;
    m_model->setCurrentVolume(nv); m_model->setTotalCost(nv*m_model->pricePerLiter());
}