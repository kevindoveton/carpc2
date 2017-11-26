#include "systemvolume.h"

SystemVolume::SystemVolume(QObject *parent) : QObject(parent) {
}

void SystemVolume :: setMasterVolume(unsigned int volume) {
    emit volumeChanged();
    return _setMasterVolume((long)volume);
}

unsigned int SystemVolume :: getCurrentVolume() {
    return (unsigned int) _getCurrentVolume();
}

unsigned int SystemVolume :: increaseVolume() {
    return (unsigned int) _increaseVolume();
}

unsigned int SystemVolume :: decreaseVolume() {
    return (unsigned int) _decreaseVolume();
}

void SystemVolume :: _setMasterVolume(long volume)
{
    long min, max;
    snd_mixer_t *handle;
    snd_mixer_selem_id_t *sid;
    const char *card = "default";
    const char *selem_name = "Master";

    snd_mixer_open(&handle, 0);
    snd_mixer_attach(handle, card);
    snd_mixer_selem_register(handle, NULL, NULL);
    snd_mixer_load(handle);

    snd_mixer_selem_id_alloca(&sid);
    snd_mixer_selem_id_set_index(sid, 0);
    snd_mixer_selem_id_set_name(sid, selem_name);
    snd_mixer_elem_t* elem = snd_mixer_find_selem(handle, sid);

    snd_mixer_selem_get_playback_volume_range(elem, &min, &max);
    snd_mixer_selem_set_playback_volume_all(elem, volume * max / 100);

    snd_mixer_close(handle);
}

long SystemVolume :: _getCurrentVolume()
{
    long min, max;
    long volume = 0;

    snd_mixer_t *handle;
    snd_mixer_selem_id_t *sid;
    const char *card = "default";
    const char *selem_name = "Master";

    snd_mixer_open(&handle, 0);
    snd_mixer_attach(handle, card);
    snd_mixer_selem_register(handle, NULL, NULL);
    snd_mixer_load(handle);

    snd_mixer_selem_id_alloca(&sid);
    snd_mixer_selem_id_set_index(sid, 0);
    snd_mixer_selem_id_set_name(sid, selem_name);
    snd_mixer_elem_t* elem = snd_mixer_find_selem(handle, sid);

    snd_mixer_selem_get_playback_volume(elem, SND_MIXER_SCHN_MONO, &volume);
    snd_mixer_selem_get_playback_volume_range(elem, &min, &max);

    snd_mixer_close(handle);

    return long(((((float)volume/(float)max)*(100))+0.5));
}

long SystemVolume :: _decreaseVolume()
{
    long newVolume = 0;

    if (getCurrentVolume() >= 0 + _VOLUMECHANGE) // check that we won't go below minimum volume
        newVolume = getCurrentVolume() - _VOLUMECHANGE;
    else
        newVolume = 0;

    _setMasterVolume(newVolume);
    return newVolume;
}

long SystemVolume :: _increaseVolume()
{
    long newVolume = 0;

    if (getCurrentVolume() <= 100 - _VOLUMECHANGE) // check that we don't go above the max volume
        newVolume = getCurrentVolume() + _VOLUMECHANGE;
    else
        newVolume = 100;

    _setMasterVolume(newVolume);
    return newVolume;
}






