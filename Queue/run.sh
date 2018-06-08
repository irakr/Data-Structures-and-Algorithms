#!/bin/bash
#######################################################################################
# This script provides a way to select between matrix or adjacency list implementation
#######################################################################################

ALGO="Queue"

red='\e[0;31m'
green='\e[0;32m'
l_green='\e[1;32m'
cyan='\e[1;36m'
nocolor='\e[0m'

EXE=queue-test
make_arg=''

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
