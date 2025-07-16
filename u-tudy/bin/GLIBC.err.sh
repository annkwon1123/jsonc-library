#!/bin/bash

SRCDIR=../src
BINDIR=../bin

echo "아 이거 gcc 버전 문제라서 소스 컴파일 다시해야함."
cd $SRCDIR
make clean
make
cd $BINDIR
echo "소스 컴파일 다시했고, 이제 실행해 볼게."
./json
echo "되는가?? 안되면 gcc 버전 문제는 아님."
