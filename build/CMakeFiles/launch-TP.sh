#!/bin/sh
bindir=$(pwd)
cd /home/e20170003790/Bureau/MASTER1/SEMESTRE_2/Projet_Moteur/src/
export 

if test "x$1" = "x--debugger"; then
	shift
	if test "xYES" = "xYES"; then
		echo "r  " > $bindir/gdbscript
		echo "bt" >> $bindir/gdbscript
		/usr/bin/gdb -batch -command=$bindir/gdbscript --return-child-result /home/e20170003790/Bureau/MASTER1/SEMESTRE_2/Projet_Moteur/build/TP 
	else
		"/home/e20170003790/Bureau/MASTER1/SEMESTRE_2/Projet_Moteur/build/TP"  
	fi
else
	"/home/e20170003790/Bureau/MASTER1/SEMESTRE_2/Projet_Moteur/build/TP"  
fi
