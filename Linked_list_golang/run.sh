#!/bin/bash

#??????
ALGO="Linked_list_golang"

red='\e[0;31m'
green='\e[0;32m'
l_green='\e[1;32m'
cyan='\e[1;36m'
nocolor='\e[0m'

EXE=main.go #??????

echo -e "${green}Building Project: $ALGO ..."



echo -e "Executing...\n"
echo -e "${cyan}---------------- $ALGO ----------------${nocolor}"
echo -e "${cyan}=========================================================${nocolor}"
go run $EXE

wait

echo -e "${cyan}=========================================================${nocolor}"
echo -e "\n${cyan}--------------- End of execution ---------------"
printf "\nCleaning up directory...${nocolor}\n"
