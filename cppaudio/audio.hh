#ifndef _AUDIO_HH_
#define _AUDIO_HH_

/* default stl libs */
#include <filesystem>
#include <iostream>
#include <string>

/* linux headers */
#ifdef __linux__
#include <alsa/asoundlib.h>
#endif

class Audio {
public:
  /* constructor */
  Audio(std::string audioPath) {
    if (!std::filesystem::exists(audioPath)) {
      std::cout << "error: file does not exists!";
      return;
    }
    filePath = audioPath;
  }
  void Play() {}
  float GetVolume() { return volume; }
  void SetVolume(float volume) { this->volume = volume; }

private:
#ifdef __linux__
  snd_pcm_t *pcm;
#endif
  void Config() {
#ifdef __linux__
    snd_pcm_open(&pcm, "default", SND_PCM_STREAM_PLAYBACK, 0);

#endif
  }
  float volume = 1;
  std::string filePath;
  std::string extension;
};

#endif
