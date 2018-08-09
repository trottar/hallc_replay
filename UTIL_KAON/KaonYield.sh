#!/bin/bash

echo "Starting Kaon Yield Estimation"
echo "I take as arguments the Run Number, max number of events, and threshold current!"
RUNNUMBER=$1
MAXEVENTS=$2
THRESHOLD=$3
if [[ $1 -eq "" ]]; then
    echo "I need a Run Number!"
    exit 2
fi
if [[ $2 -eq "" && $3 -eq "" ]]; then
    echo "Only Run Number entered...I'll assume -1 events and threshold of 5 uA!" 
    MAXEVENTS=-1
    THRESHOLD=5
    elif [[ $2 -eq "" ]]; then
    echo "I need a Max Number of events!"
    exit 2
    elif [[ $3 -eq "" ]]; then
    echo "I need a Current Threshold!"
    exit 2    
fi
cd ../
echo -e "\n\nStarting Scaler Replay Script\n\n"
hcana -q "SCRIPTS/COIN/SCALERS/replay_coin_scalers.C($RUNNUMBER,100000)"
cd CALIBRATION/bcm_current_map/
root -b<<EOF
.x run.C("../../ROOTfiles/coin_replay_scalers_${RUNNUMBER}_150000.root")
EOF
mv bcmcurrent_$RUNNUMBER.param ../../PARAM/HMS/BCM/CALIB/bcmcurrent_$RUNNUMBER.param
cd ../../
echo -e "\n\nStarting Replay Script\n\n"
hcana -q "UTIL_KAON/scripts_Replay/replay_production_coin.C($RUNNUMBER,$MAXEVENTS)"
cd UTIL_KAON/scripts_KaonYield/
echo -e "\n\nYield Calculation\n\n"
root -l "run_KaonYield.C($RUNNUMBER,$MAXEVENTS,$THRESHOLD)"
