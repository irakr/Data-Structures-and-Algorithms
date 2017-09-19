#!/bin/bash
#######################################################################################
# This script provides a way to select between matrix or adjacency list implementation
#######################################################################################

ALGO="Basic Graph"

red='\e[0;31m'
green='\e[0;32m'
l_green='\e[1;32m'
cyan='\e[1;36m'
nocolor='\e[0m'

EXE=graph
make_arg=''

echo '          It seems that we have two kinds of Graph implementations available'
echo 'Select one of the implementations:'
echo '1. Adjacency list(Default)'
echo '2. Adjacency matrix'

read option
if [ $option -eq '1' ]; then
    make_arg=''
elif [ $option -eq '2' ]; then
    make_arg='-DMATRIX_IMPL'
elif [ $option -eq '' ]; then
    make_arg=''
else
    echo -e "${red} Wrong option!${nocolor}"
    exit
fi

echo -e "${green}Building Project: $ALGO ..."
make clean
if ! make DEFINES=$make_arg
then
        echo -e "${red}[Build failed]\nExiting...${nocolor}\n"
        exit 1
fi

echo -e "${l_green}[Build successful]"
echo -e "Executing..."
printf "\n"
echo -e "${cyan}---------------- $ALGO ----------------${nocolor}"
echo -e "${cyan}=========================================================${nocolor}"

./$EXE

wait

echo -e "${cyan}=========================================================${nocolor}"
echo -e "\n${cyan}--------------- End of execution ---------------"
printf "\nCleaning up directory...${nocolor}\n"

make clean
