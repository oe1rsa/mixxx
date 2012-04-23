/**
* @file portmidienumerator.h
* @author Sean Pappalardo spappalardo@mixxx.org
* @date Thu 15 Mar 2012
* @brief This class handles discovery and enumeration of DJ controllers that appear under the PortMIDI cross-platform API.
*/

#ifndef PORTMIDIENUMERATOR_H
#define PORTMIDIENUMERATOR_H

#include "controllers/midi/midienumerator.h"

class PortMidiEnumerator : public MidiEnumerator {
    public:
        PortMidiEnumerator();
        virtual ~PortMidiEnumerator();
        QList<Controller*> queryDevices();
        bool needPolling() { return true; };
    private:
        QList<Controller*> m_devices;
};

#endif
