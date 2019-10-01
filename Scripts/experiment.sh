#!/bin/bash

cd $HOME
cd "Repositorios/Github/MemPlas-And-Path-Relinking/Instances/"

log=$HOME"/Repositorios/Github/MemPlas-And-Path-Relinking/Logs/results.csv"

echo "instance,strategy,result,time" > $log

for file in *
do
	if [ -f "$file" ]
	then
		echo "$file"
		./../Project/Debug/Project 1 1 1 "$PWD/$file" --strategy m --sizePopulation 150 --elite  0.3 --limitIterations 100 --sizePlasmideo 0.2 --cross 0.4 >> $log && echo "Ok"
	fi
done
