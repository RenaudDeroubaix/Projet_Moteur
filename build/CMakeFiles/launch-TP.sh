#!/bin/sh
bindir=$(pwd)
cd /home/deroubaix/Bureau/MASTER/Master_1/Semestre_2/Projet_Moteur/src/
export 

if test "x$1" = "x--debugger"; then
	shift
	if test "xYES" = "xYES"; then
		echo "r  " > $bindir/gdbscript
		echo "bt" >> $bindir/gdbscript
		/usr/bin/gdb -batch -command=$bindir/gdbscript --return-child-result /home/deroubaix/Bureau/MASTER/Master_1/Semestre_2/Projet_Moteur/build/TP 
	else
		"/home/deroubaix/Bureau/MASTER/Master_1/Semestre_2/Projet_Moteur/build/TP"  
	fi
else
	"/home/deroubaix/Bureau/MASTER/Master_1/Semestre_2/Projet_Moteur/build/TP"  
fi
