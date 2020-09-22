#pragma once


#include "app-veriwell/multimedia/multimedia/multimedia.h"
#include <CoreMIDI/MIDIServices.h>
#include <AudioToolbox/AudioToolbox.h>

#if defined(_VERIWELL_MULTIMEDIA_MUSIC_MIDI_CORE_MIDI_LIBRARY)
   #define CLASS_DECL_VERIWELL_MULTIMEDIA_MUSIC_MIDI_CORE_MIDI  CLASS_DECL_EXPORT
#else
   #define CLASS_DECL_VERIWELL_MULTIMEDIA_MUSIC_MIDI_CORE_MIDI  CLASS_DECL_IMPORT
#endif


CFURLRef resource_sound_font_url(const char * psz, const char *pszExt);

#include "music_midi_core_audio_message_out.h"

#include "music_midi_core_audio_translation.h"

#include "music_midi_core_audio_exception.h"

#include "music_midi_core_audio_sequence.h"

#include "player/music_midi_core_audio_player.h"

#include "music_midi_core_audio_file.h"
          
#include "music_midi_core_audio_sequence_thread.h"

#include "music_midi_core_audio_midi.h"

#include "music_midi_core_audio_factory_exchange.h"
