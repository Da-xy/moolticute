#ifndef SETTINGSGUIBLE_H
#define SETTINGSGUIBLE_H

#include <QObject>
#include "ISettingsGui.h"
#include "DeviceSettingsBLE.h"

class MainWindow;

class SettingsGuiBLE : public DeviceSettingsBLE, public ISettingsGui
{
    Q_OBJECT
public:
    explicit SettingsGuiBLE(QObject* parent, MainWindow* mw);
    void loadParameters() override;
    void updateParam(MPParams::Param param, int val) override;
    void updateUI() override;
    void setupKeyboardLayout(bool onlyCheck) override;

    static const int NONE_INDEX = 0;
    static const int TAB_INDEX = 9;
    static const int ENTER_INDEX = 10;
    static const int SPACE_INDEX = 32;
    static const int DEFAULT_INDEX = 0xFFFF;

private:
    /**
     * @brief checkEnforceLayout
     * If enforce layout is enabled then using layout value
     * from MC setting instead of the fetched value from device.
     * @param param type, checked for usb/bt layout
     * @param val Fetched value from device
     */
    inline void checkEnforceLayout(MPParams::Param param, int &val);
};

#endif // SETTINGSGUIBLE_H
