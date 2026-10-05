/* tuneit.c -- Detect fundamental frequency of a sound
* Copyright (C) 2004, 2005  Mario Lang <mlang@delysid.org>
*
* Modified for rakarrack by Josep Andreu
* MIDIConverter.h  MIDIConverter definitions
*
* This is free software, placed under the terms of the
* GNU General Public License, as published by the Free Software Foundation.
* Please see the file COPYING for details.

  Updated by ablyss for Haiku OS with the help of AI
  Copyright 2026
*/

#include "jack.h"

#ifndef MIDICONVERTER_H_
#define MIDICONVERTER_H_

#include <math.h>
#include <stdlib.h>
#include <jack/midiport.h>
#include <alsa/asoundlib.h>
#include <midi2/Midi2Defs.h>
#include <midi2/MidiProducer.h>


struct Midi_Event {
 jack_nframes_t  time;
 int             len;    /* Length of MIDI message, in bytes. */
 jack_midi_data_t  *dataloc;
} ;



class MIDIConverter
{
public:
    MIDIConverter (char *jname);
  ~MIDIConverter ();


  float p_freq_ceiling; 
  float p_freq_floor;

  void ResetBuffers(); 
  float *efxoutl;
  float *efxoutr;
  signed short int *schmittBuffer;
  signed short int *schmittPointer;
  const char **notes;
  int note;
  float nfreq, afreq, freq;
  float TrigVal;
  int cents;
  void schmittFloat (int nframes, float *indatal, float *indatar);
  void setmidichannel (int channel);
  void panic ();
  void setTriggerAdjust (int val);
  void setVelAdjust (int val);

  int channel;
  int lanota;
  int nota_actual;
  int hay;
  int preparada;
  int ponla;
  int velocity;
  int moutdatasize;
  int ev_count; 
  int Moctave;

  float VelVal;
  jack_midi_data_t  moutdata[2048];  
  Midi_Event Midi_event[2048];
  snd_seq_t *port;


  BMidiLocalProducer* fHaikuMidiOut; 
  void MIDI_Send_Note_On (int nota);  
  void MIDI_Send_Note_Off (int nota); 
  int p_off_count_max;   // To replace the fixed '5'
  int p_stable_threshold; // To replace the fixed '2'
  float p_trigfact;       // To replace the fixed '0.5f'

private:
  int stable_count;  
  int off_count;
  void displayFrequency (float freq);
  void schmittInit (int size);
  void schmittS16LE (int nframes, signed short int *indata);
  void schmittFree ();


  int blockSize;



};

#endif /*MIDICONVERTER_H_ */
