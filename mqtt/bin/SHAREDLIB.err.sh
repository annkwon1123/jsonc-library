#!/bin/bash

LIBDIR=$PROJ_PATH/mqtt/lib
SRCDIR=$PROJ_PATH/mqtt/src
BINDIR=$PROJ_PATH/mqtt/bin

echo "아 이거는 라이브러리 컴파일 다시해야함"
cd $LIBDIR
rm -rf mosquitto-build
mkdir mosquitto-build
cd $LIBDIR/mosquitto-build
cmake -DWITH_STATIC_LIBRARIES=ON $LIBDIR/mosquitto-2.0.22/
make
sudo make install
echo "라이브러리 컴파일 다시했고, 이제 소스 컴파일 해볼게."
cd $SRCDIR
make clean
make
echo "소스 컴파일 다시했고, 이제 실행해 볼게."
cd $BINDIR
./mqtt_sub
echo "제발 되면 좋겠다."
