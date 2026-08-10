

https://github.com/user-attachments/assets/61d25e78-6bf4-43de-bf4e-a0c22ba9418f


<p align="center">
  <a href="https://www.qt.io/" target="_blank"><img src="https://img.shields.io/badge/Qt-5.15.2-41CD52?style=for-the-badge&logo=qt&logoColor=white" alt="Qt"></a>
  <a href="https://en.cppreference.com/w/cpp/17" target="_blank"><img src="https://img.shields.io/badge/C++-17-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white" alt="C++17"></a>
  <a href="https://doc.qt.io/qt-5/qmlapplications.html" target="_blank"><img src="https://img.shields.io/badge/QML-UI-EE2A7B?style=for-the-badge&logo=qt&logoColor=white" alt="QML"></a>
</p>

<h1 align="center">⛽ Fuel Dispenser HMI Simulation</h1>

<p align="center">
  Modern fuel dispenser kiosk.
</p>

---

## Build & Run Instructions

```bash
make clean || true
qmake ../FuelDispenserHMI.pro CONFIG+=release
make -j$(nproc)
./FuelDispenserHMI

```powershell
mingw32-make clean
qmake ..\FuelDispenserHMI.pro CONFIG+=release
mingw32-make -j%NUMBER_OF_PROCESSORS%
release\FuelDispenserHMI.exe
