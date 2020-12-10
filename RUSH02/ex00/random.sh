#!/bin/sh

NB=$RANDOM

if [ -e rush-02 ]
then
	echo "${NB} : `./rush-02 ${NB}`"
else
	(make && make clean) > /dev/null
	echo "${NB} : `./rush-02 ${NB}`"
fi
