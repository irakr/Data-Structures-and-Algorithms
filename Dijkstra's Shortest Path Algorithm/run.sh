#!/bin/bash

#??????
ALGO="Dijkstra's Shortest Path Algorithm"

red='\e[0;31m'
green='\e[0;32m'
l_green='\e[1;32m'
cyan='\e[1;36m'
nocolor='\e[0m'

EXE=dijkstra #??????

echo -e "${green}Building Project: $ALGO ..."
make clean
make
wait
echo -e "${l_green}[Build successful]"
echo -e "Executing...\n"
echo -e "${cyan}---------------- $ALGO ----------------${nocolor}"
echo -e "${cyan}=========================================================${nocolor}"

./$EXE

wait

echo -e "${cyan}=========================================================${nocolor}"
echo -e "\n${cyan}--------------- End of execution ---------------"
printf "\nCleaning up directory...${nocolor}\n"
make clean
