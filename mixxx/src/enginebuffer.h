/***************************************************************************
                          enginebuffer.h  -  description
                             -------------------
    begin                : Wed Feb 20 2002
    copyright            : (C) 2002 by Tue and Ken Haste Andersen
    email                : 
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef ENGINEBUFFER_H
#define ENGINEBUFFER_H

#include <qthread.h>
#include <qpushbutton.h>
#include <qmultilineedit.h>
#include <qslider.h>
#include "qknob.h"
#include <qstring.h>
#include <qlcdnumber.h>
//#include <semaphore.h>

#include "defs.h"
#include "engineobject.h"
#include "soundsource.h"
#include "controlpushbutton.h"
#include "controlpotmeter.h"
#include "controlrotary.h"
#include "dlgplaycontrol.h"
#include "dlgchannel.h"
#include "midiobject.h"
#include "soundsourceheavymp3.h"
/**
  *@author Tue and Ken Haste Andersen
*/

class EngineBuffer : public EngineObject, public QThread  {
 Q_OBJECT
public:
  double rate;
  EngineBuffer(DlgPlaycontrol *, DlgChannel *, MidiObject *, const char *);
  ~EngineBuffer();
  void newtrack(const char *);
  void start();
  CSAMPLE *process(const CSAMPLE *, const int);
public slots:
   void slotUpdatePlay(valueType);
   void slotUpdateRate(FLOAT_TYPE);
   void slotPosition(int);
signals:
   void position(int);   
private:
  void run();
  void stop();

  QSemaphore *requestStop;
  QSemaphore *buffersReadAhead;
//  sem_t *buffers_read_ahead;
  unsigned long int read_buffer_size;
  unsigned long int frontpos;
  double play_pos;
  CSAMPLE *readbuffer;
  void getchunk();
  void seek(FLOAT_TYPE);
  void checkread();
  void writepos();
  ControlPushButton *PlayButton;
  ControlPotmeter *rateSlider;
  ControlRotary *wheel;
  SoundSource *file;
  SAMPLE *temp;
  unsigned  chunk_size;
  unsigned long int filepos;
  FLOAT_TYPE filelength;
  int direction;
  long distance(const long, const long);
  CSAMPLE *buffer;
};
#endif
