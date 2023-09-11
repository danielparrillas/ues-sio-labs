cmd_/home/daniel/Escritorio/ues/simple/modules.order := {   echo /home/daniel/Escritorio/ues/simple/simple.ko; :; } | awk '!x[$$0]++' - > /home/daniel/Escritorio/ues/simple/modules.order
