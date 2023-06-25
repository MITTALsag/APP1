#!/bin/bash

for i in client-TUTORIEL2 client-projetX client-crypteMove client-BayOfPigs client-crypteSeq client-planB client-Northwoods client-LostCause 
do 
    ./$i
    echo $?
    sleep 1
done