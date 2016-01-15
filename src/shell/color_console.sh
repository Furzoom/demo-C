#!/bin/bash

# parameter 'm'
# 0 for default color scheme
echo "Set to default color:"
echo -e "\033[31mSet red color for this line."
echo -e "Do not set color for default, this line is also red.\033[0m\n"

# 1 for setting bold
echo "Set bold:"
echo -e "There is a \033[1mBold\033[0m word in this line.\n"

# 2 for setting dim effect
echo "Set dim:"
echo -e "Find out \033[1mwhich\033[0m word is \033[2mdim\033[0m.\n"

# 5 for setting blink effect
echo "Set blink:"
echo -e "\033[5mFlash\033[0m\x21\n"

# 7 for reversing effect
echo "Reverse color:"
echo -e "\033[7mRreverse\033[0m color.\n"

# set foreground color 'm' parameter 30~37
echo "Foreground color:"
echo -e "\033[30m\033[47mWelcome to furzoom.com\x21 \033[0m"
echo -e "\033[31mWelcome to furzoom.com\x21 \033[0m"
echo -e "\033[32mWelcome to furzoom.com\x21 \033[0m"
echo -e "\033[33mWelcome to furzoom.com\x21 \033[0m"
echo -e "\033[34mWelcome to furzoom.com\x21 \033[0m"
echo -e "\033[35mWelcome to furzoom.com\x21 \033[0m"
echo -e "\033[36mWelcome to furzoom.com\x21 \033[0m"
echo -e "\033[37mWelcome to furzoom.com\x21 \033[0m"

# set background color 'm' parameter 40~47
echo -e "\nBackground color:"
echo -e "\033[40mWelcome to furzoom.com\x21 \033[0m"
echo -e "\033[41mWelcome to furzoom.com\x21 \033[0m"
echo -e "\033[42mWelcome to furzoom.com\x21 \033[0m"
echo -e "\033[43mWelcome to furzoom.com\x21 \033[0m"
echo -e "\033[44mWelcome to furzoom.com\x21 \033[0m"
echo -e "\033[45mWelcome to furzoom.com\x21 \033[0m"
echo -e "\033[46mWelcome to furzoom.com\x21 \033[0m"
echo -e "\033[47m\033[30mWelcome to furzoom.com\x21 \033[0m"

# 'u' and 's' parameters
echo -e "\n'u' and 's': "
echo -e -n "\033[7sHi, \033[31mI'll go"
sleep 3
echo -e "\033[8ufurzoom coming\n"
