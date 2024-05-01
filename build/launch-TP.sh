#!/bin/sh
bindir=$(pwd)
cd /home/orenu/Documents/Cours/OpenGl/Projet_Moteur/src/
export 

if test "x$1" = "x--debugger"; then
	shift
	if test "xYES" = "xYES"; then
		echo "r  " > $bindir/gdbscript
		echo "bt" >> $bindir/gdbscript
		/usr/bin/gdb -batch -command=$bindir/gdbscript --return-child-result /home/orenu/Documents/Cours/OpenGl/Projet_Moteur/build/TP 
	else
		"/home/orenu/Documents/Cours/OpenGl/Projet_Moteur/build/TP"  
	fi
else
	"/home/orenu/Documents/Cours/OpenGl/Projet_Moteur/build/TP"  
fi
