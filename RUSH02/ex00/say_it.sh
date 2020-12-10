#!/bin/sh

echo 'Quel nombre souhaitez vous entendre ?'
read NB
if [ ! -e rush-02 ]
then
	(make && make clean) > /dev/null
fi

VAR=`./rush-02 ${NB}`
echo ${VAR}
say -v Alex ${VAR}

