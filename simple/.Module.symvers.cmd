cmd_/home/daniel/Escritorio/ues/simple/Module.symvers := sed 's/\.ko$$/\.o/' /home/daniel/Escritorio/ues/simple/modules.order | scripts/mod/modpost -m -a  -o /home/daniel/Escritorio/ues/simple/Module.symvers -e -i Module.symvers   -T -
