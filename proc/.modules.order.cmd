cmd_/home/daniel/Escritorio/ues/proc/modules.order := {   echo /home/daniel/Escritorio/ues/proc/hello.ko; :; } | awk '!x[$$0]++' - > /home/daniel/Escritorio/ues/proc/modules.order
