#!/bin/bash
set -ev

# previous win build with certificate passing
#docker run -t --name winbuilder -d \
#    -v $(pwd):/moolticute \
#    -v $HOME/cert.p12:/cert.p12 \
#    mooltipass/mc-win-builder
#
#docker run -t --name appimgbuilder -d \
#    -v $(pwd):/moolticute \
#    -v $HOME/cert.p12:/cert.p12 \
#    mooltipass/mc-appimage-builder

docker run -t --name winbuilder -d \
    -v $(pwd):/moolticute \
    mooltipass/mc-win-builder

docker run -t --name appimgbuilder -d \
    -v $(pwd):/moolticute \
    mooltipass/mc-appimage-builder

docker run -t --name mc-deb -d \
    -v $HOME/build-debs:/moolticute \
    mooltipass/mc-launchpad

docker ps
