#!/bin/bash

#??????
ALGO="Dijkstra's Shortest Path Algorithm"

red='\e[0;31m'
green='\e[0;32m'
l_green='\e[1;32m'
cyan='\e[1;36m'
nocolor='\e[0m'

EXE=bst #??????

echo -e "${green}Building Project: $ALGO ..."
make clean
make
wait
echo -e "${l_green}[Build successful]"
echo -e "Running the program...\n"
echo -e "${cyan}---------------- $ALGO ----------------${nocolor}"

./$EXE

wait

echo -e "\n${cyan}--------------- End of execution ---------------"
printf "\nCleaning up directory...${nocolor}\n"
make clean
