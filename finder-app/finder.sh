#!/bin/sh

if [ $# -lt 2 ]
then
    echo "Parameters."
    exit 1
fi

FILESDIR=$1
SEARCHSTR=$2

if [ ! -d $FILESDIR ]
then
    echo "Not a dir $FILESDIR"
    exit 1
fi

X=$(find $FILESDIR -type f | wc -l)
Y=$(grep -r $SEARCHSTR $FILESDIR | wc -l)

echo "The number of files are $X and the number of matching lines are $Y"