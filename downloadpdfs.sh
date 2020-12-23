for file in *.c*
do
	NUMBER=$(echo $file | sed 's/[^0-9]*//g')
	if test -e $NUMBER.pdf; then continue; fi
	VOL=$(($NUMBER / 100))
	NN=${NUMBER:1:2}
	URL=https://www.aceptaelreto.com/pub/problems/v00$VOL/$NN/st/problem.pdf
	wget $URL 
	mv problem.pdf $NUMBER.pdf
done
