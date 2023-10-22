#!/bin/bash

if [ "$EUID" -ne 0 ]; then
  echo "Please run as root"
  exit 1
fi

rm -v /usr/include/{rinputlib.h,rstrlib.h}