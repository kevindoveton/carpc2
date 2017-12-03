# CarPC
This time built using QML and 2 years more dev experience...

## Requirements
- bluez
- Qt >= 5.9
- ofono
- vlc
- libvlc
- libvlc-dev

## Getting Started
1. Install everything

## Helpful Links
- https://www.raspberrypi.org/forums/viewtopic.php?t=189710
- http://headunit.viktorgino.me/

## Shairport-sync (airplay)
1. `git clone install avahi-daemon libavahi-client-dev`
2. `sudo apt install autoconf`
3. `autoreconf -i -f`
4. `sudo apt install libdaemon automake libtool libdaemon-dev libpopt-dev libconfig-dev`
5. `sudo apt install libssl-dev libsoxr-dev avahi-daemon libavahi-client-dev libpulse-dev`
6. `./configure --sysconfdir=/etc --with-alsa --with-pa --with-avahi --with-ssl=openssl --with-metadata --with-soxr --with-systemd --with-pipe --with-stdout`
