#!/bin/bash

if cmake -S . -B build && cmake --build build; then
	echo "Build successful."
else
	echo "CMake not found OR build failed. Exiting..."
	exit 1
fi

echo -n "Do you want to install kbchad? [y/N] "
read -r input

if [ "$input" == "Y" ] || [ "$input" == "y" ]; then
	sudo mv build/kbchad /usr/local/bin/ && echo "kbchad was installed."
else
	echo "Install canceled."
fi	

