#!/bin/bash

red='\e[0;31m'
green='\e[0;32m'
l_green='\e[1;32m'
cyan='\e[1;36m'
nocolor='\e[0m'

EXE=sllist

echo -e "${green}Building Project: Singly Linked List ..."
make clean
make
wait
echo -e "${l_green}[Build successful]"
echo -e "Running the program...\n"
echo -e "${cyan}---------------- Singly Linked List ----------------${nocolor}"

./$EXE

wait

echo -e "\n${cyan}--------------- End of execution ---------------"
printf "\nCleaning up directory...${nocolor}\n"
make clean
