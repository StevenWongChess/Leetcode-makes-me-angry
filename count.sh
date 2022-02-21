#!/usr/bin/env bash
clear
Array=("Stack-Queue" "Sorting" "BackTrack" "Greedy" "Binary-Search" "Bit" "Dict" "DP" "Linked-List" "Maths" "Slide-Window" "String" "Tree" "Two-Pointer")
ans=0
easy=0
medium=0
hard=0
for i in ${Array[@]}; do
	num=$(ls $i | grep cpp | wc -l)
	echo "$i:$num"
	ans=$((ans+num))
	e=$(ls $i | grep -E "E\d+\.cpp" | wc -l)
	m=$(ls $i | grep -E "M\d+\.cpp" | wc -l)
	h=$(ls $i | grep -E "H\d+\.cpp" | wc -l)
	easy=$((easy+e))
	medium=$((medium+m))
	hard=$((hard+h))
done
echo "done $ans Leetcode so far!"
echo "$easy easy, $medium medium, $hard hard"
