#!/bin/bash

if [ $# -lt 2 ]
then
    echo "Parameters"
    exit 1
fi

WRITEFILE=$1
WRITESTR=$2

mkdir -p $(dirname $WRITEFILE)

echo $WRITESTR > $WRITEFILE
if [ $? -ne 0 ]
then
    echo "Error"
    exit 1
fi