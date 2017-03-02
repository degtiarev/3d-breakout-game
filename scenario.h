#ifndef SCENARIO_H
#define SCENARIO_H


#include "application/gmlibwrapper.h"

class Simulator;


// qt
#include <QObject>



class Scenario : public GMlibWrapper {
    Q_OBJECT
public:
    using GMlibWrapper::GMlibWrapper;

    void    initializeScenario() override;
    void    cleanupScenario() override;

    void planeUp();
    void planeDown();
    void planeLeft();
    void planeRight();

private: std::shared_ptr <Simulator> _simulator;

};

#endif // SCENARIO_H
