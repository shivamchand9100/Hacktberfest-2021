echo "Enter the number of processes: "
read n
for ((i=0; i<$n; i++))
do
echo -n "Enter Process Id: "
read pid[$i]
echo -n "Enter arrival time: "
read at[$i]
echo -n "Enter burst time: "
read bt[$i]
done
	for ((i = 0; i<$n; i++))
        do

            for((j = 0; j<`expr $n - $i - 1`; j++))
            do

                if [ ${at[j]} -gt ${at[$((j+1))]} ]
                then
                    temp=${at[j]}
                    at[$j]=${at[$((j+1))]}
                    at[$((j+1))]=$temp
                    temp=${bt[j]}
                    bt[$j]=${bt[$((j+1))]}
                    bt[$((j+1))]=$temp
                    temp=${pid[j]}
                    pid[$j]=${pid[$((j+1))]}
                    pid[$((j+1))]=$temp
                elif [ ${at[j]} -eq ${at[$((j+1))]} ]
                then
                        if [ ${pid[j]} -eq ${pid[$((j+1))]} ]
                        then
                            temp=${at[j]}
                            at[$j]=${at[$((j+1))]}
                            at[$((j+1))]=$temp
                            temp=${bt[j]}
                            bt[$j]=${bt[$((j+1))]}
                            bt[$((j+1))]=$temp
                            temp=${pid[j]}
                            pid[$j]=${pid[$((j+1))]}
                            pid[$((j+1))]=$temp
                        fi
                fi
            done
        done
	st[0]=0
        wt[0]=0
        for ((i=1; i<$n; i++))
        do
                st[$i]=`expr ${st[$((i-1))]} + ${bt[$((i-1))]} `
                wt[$i]=`expr ${st[$((i-1))]} - ${at[$((i-1))]}`
                if [ ${wt[$i]} -lt 0 ]
                then
                        wt[$i]=0
                fi
        done
        for ((i=0; i<$n; i++))
        do
                tat[$i]=`expr ${wt[$i]} + ${bt[$i]}`
        done
	
	tot_wt=0
        tot_tat=0
        echo  "PId" "BT" "AT" "WT" "TAT" "CT"
        for ((i=0; i<$n; i++))
        do
                tot_wt=`expr $tot_wt + ${wt[$i]}`
                tot_tat=`expr ${tat[$i]} + $tot_tat`
                ct=`expr ${at[$i]} + ${tat[$i]}`
               echo ${pid[$i]} ${bt[$i]} ${at[$i]} ${wt[$i]} ${tat[$i]} $ct
                echo "${bt[$i]}     ${at[$i]}     ${wt[$i]}       ${tat[$i]}         $ct"
        done
        #avgwt=`echo "scale=3; $total_wt / $n" | bc`
        echo -n "Average waiting time ="
        echo '%.3f\\n "$(($total_wt / $n))"'
        #avgtat=`echo "scale=3; $total_tat / $n" | bc`
        echo -n "Average turn around time ="
        echo '%.3f\\n "$(($total_tat / $n))"'
       	for ((i=0; i<$n; i++))
        do
                echo -n "P${pid[$i]}"
                echo -n ""
        done
	 for ((i=0; i<$n; i++))
        do
                echo -n "`expr ${at[$i]} + ${tat[$i]}`"
                echo -n ""          "
        done
        echo ""

